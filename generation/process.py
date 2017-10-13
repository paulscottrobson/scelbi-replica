import re

class InstructionPhase:
	def __init__(self,definition):		
		m = re.match("^(\d)\:\s*([0\*][0\*])\s*([A-Za-z0-9\$\@\:\?\<\>\|\(\)]+)\s+(.+)$",definition)
		assert m is not None,"Bad source line "+definition
		self.phaseNumber = int(m.group(1))
		self.statusLights = [ 1 if x == '*' else 0 for x in m.group(2) ]		
		p = m.group(3).split(":")
		self.display = [ ":".join(p[:-1]),p[-1]]
		self.code = m.group(4)
		#print(definition)
		#print(self.phaseNumber,self.statusLights,self.display,self.code)		

	def getPhaseNumber(self):
		return self.phaseNumber

	def getCode(self):
		code = ""
		code = code + "$SETSTATUSLED({0},{1});".format(self.statusLights[0],self.statusLights[1])
		code = code + "$SETBUSLED({0},{1});".format(self.display[0],self.display[1])
		return code + self.code

class Instruction:
	def __init__(self,definition):
		m = re.match("^([0-9A-F\-\,]+)\s*\"(.*)\"\s*(\d+)\s*$",definition)
		assert m is not None,"Bad source line "+definition
		self.mnemonic = m.group(2).upper().strip()
		self.cycles = int(m.group(3))
		range = m.group(1)
		if len(range) == 2:
			range = range + "-"+range
		if len(range) == 5:	
			range = range + ",1"
		self.first = int(range[:2],16)
		self.last = int(range[3:5],16)
		self.step = int(range[-1],16)
		self.phases = {}
		self.phaseCount = 0

		#print(definition,self.first,self.last,self.step,self.mnemonic,self.cycles)
		#print(self.getOpcodes())

	def getOpcodes(self):
		return range(self.first,self.last+self.step,self.step)

	def getMnemonic(self,opcode):
		return self.process(self.mnemonic,opcode)

	def process(self,text,opcode):
		text = text.replace("@C","NC,NZ,P,PO,C,Z,M,PE".split(",")[(opcode >> 3) & 7])
		text = text.replace("@D","ABCDEHLM"[(opcode >> 3) & 7])
		text = text.replace("@HL","(($H << 8)|L)")
		text = text.replace("@O","0x{0:02X}".format(opcode))
		text = text.replace("@P","{0:02X}".format((opcode >> 1) & 0x1F))
		text = text.replace("@R","{0:02X}".format(opcode & 0x38))
		text = text.replace("@S","ABCDEHLM"[(opcode >> 0) & 7])
		return text

	def addPhase(self,phase):
		assert phase.getPhaseNumber() == self.phaseCount+1,"Phases out of order"
		self.phaseCount = self.phaseCount + 1
		self.phases[self.phaseCount] = phase

	def render(self,opcode,format):
		code = "/* 0x{0:02X} {1} */\n".format(opcode,self.getMnemonic(opcode))
		for phase in range(self.phaseCount,0,-1):
			code = code + "if ($PHASE == {0}) {{\n".format(phase)
			if phase == 1:
				code = code + "\t$CYCLES = $CYCLES + {0};\n".format(self.cycles)
			code = code + "\t$PHASE = {0};\n".format(0 if phase == self.phaseCount else phase+1)
			code = code + "\t"+self.phases[phase].getCode()+";"+"\n"
			code = code + "}\n"
			code = code.replace(";;",";")
			code = self.process(code,opcode)
		if format == "C":			
			return code.replace("$","")
		if format == "J":
			while code.find("$") >= 0:
				m = re.search("\$([A-Z]+)",code)
				code = code.replace("$"+m.group(1),"this."+m.group(1).lower())
			return code
		raise Exception("No such format")

src = [x.replace("\t"," ").strip() for x in open("8008.def").readlines()]
src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
src = [x.strip() for x in src if x.strip() != ""]

instructions = {}
currentInstruction = None
mnemonics = [ None ] * 256

for s in src:
	if re.match("^\d\:",s) is not None:
		phase = InstructionPhase(s)
		currentInstruction.addPhase(phase)
		print(phase.getCode())

	else:
		currentInstruction = Instruction(s)
		for opc in currentInstruction.getOpcodes():
			assert opc not in instructions,"Duplicate ${0:x} ${1}".format(opc,s)
			instructions[opc] = currentInstruction
			mnemonics[opc] = currentInstruction.getMnemonic(opc).lower()

for i in range(0,256):
	if mnemonics[i] is None:
		mnemonics[i] = "byte {0:02x}".format(i)
wmnemonics = ",".join(['"'+x+'"' for x in mnemonics])

open("_8008_mnemonics.h","w").write("static const char *_mnemonics[] = { "+wmnemonics+ "};")

for opcode in range(0,256):
	if opcode in instructions:
		print(instructions[opcode].render(opcode,"J"))
