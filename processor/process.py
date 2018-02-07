# ********************************************************************
#
#						Process 8008.def
#
# ********************************************************************

import re,sys

class Processor(object):
	def __init__(self):
		self.cNames = "nc,nz,p,po,c,z,m,pe".split(",")
		self.cCode = [ "@carry == 0","@psz != 0","(@psz & 0x80) == 0","isParityEven(@psz) == 0", \
					   "@carry != 0","@psz == 0","(@psz & 0x80) != 0","isParityEven(@psz) != 0" ]					   
		self.rSubs = ["@"+x for x in "a,b,c,d,e,h,l,?".split(",")]
		self.rNames = "a,b,c,d,e,h,l".split(",")

	def process(self,s,opcode,divisor):
		s = s.replace("@cycles","cycles+=")
		s = s.replace("@mem","((h << 8)|l)")
		s = s.replace("@read()","READ()")
		s = s.replace("@write()","WRITE()")
		s = s.replace("@fetch8()","FETCH8()")
		s = s.replace("@fetch16()","FETCH16()")
		s = s.replace("@halt()","halt = 1")
		s = s.replace("@push()","pcix = (pcix + 1) & 7")		
		s = s.replace("@pull()","pcix = (pcix - 1) & 7")		
		s = s.replace("@goto()","pctr[pcix] = ma & 0x3FFF")
		s = s.replace("@input(","INPUTPORT(")
		s = s.replace("@output(","OUTPUTPORT(")
		s = s.replace("@add()","temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1")
		s = s.replace("@sub()","temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1")

		s = s.replace("@test",self.cCode[(opcode >> 3) & 7])
		s = s.replace("@carry","carry")
		s = s.replace("@psz","pszValue")		
		s = s.replace("@pc","pctr[pcix]")
		s = s.replace("@port","{0:02x}".format((opcode >> 1) & 0x1F))
		s = s.replace("@rst","{0:02x}".format(opcode & 0x38	))

		s = s.replace("@n",self.cNames[(opcode >> 3) & 7])
		s = s.replace("@r",self.rSubs[int(opcode/divisor) & 7])
		for r in self.rNames:
			s = s.replace("@"+r,r)
		return s

class Phase(object):
	def __init__(self,code,led1,led2,addr,data):
		self.code = code
		self.led1 = (led1 == '*')
		self.led2 = (led2 == '*')
		self.addr = addr
		self.data = data

class Generator(object):
	def __init__(self,cycles,mnemonic,divisor):
		self.cycles = cycles
		self.mnemonic = mnemonic
		self.divisor = divisor
		self.phases = []
	def add(self,phase):
		self.phases.append(phase)
	def getCode(self,phase,isSlow):
		code = self.phases[phase].code
		if code[-1] != ";":
			code = code + ";"
		if isSlow:
			update = "updateDisplay({0},{1},{2},{3})".format(1 if self.phases[phase].led1 else 0, \
						1 if self.phases[phase].led2 else 0,self.phases[phase].addr,self.phases[phase].data)
			code = update + ";" + code
		if len(self.phases) > 1 and isSlow:
			code = code + "phase = {0};".format((phase + 1) % len(self.phases))
		if phase == 0:
			code = code + "@cycles({0});".format(self.cycles)
		return code

proc = Processor()

src = open("8008.def").readlines()
# comments
src = [x[:x.find("#")] if x.find("#") >= 0 else x for x in src]
# tabs and spaces, remove blank lines
src = [x.replace("\t"," ").strip() for x in src if x.strip() != ""]
# this is the generators for each opcode
generators = [ None ] * 256
lastGenerator = None

for line in src:
	# is it a new opcode line.
	m = re.match('^([0-9a-fA-F\,\.]+)\s+(\d+)\s+\"(.*)\"\s*$',line)
	if m is not None:
		# convert the opcode range to an actual range
		oprange = m.group(1)+".."+m.group(1) if len(m.group(1)) == 2 else m.group(1)
		oprange = oprange if oprange.find(",") >= 0 else oprange+",1"
		div = int(oprange[-1])
		oprange = range(int(oprange[:2],16),int(oprange[4:6],16)+1,div)
		# create a new generator, make it last one
		lastGenerator = Generator(int(m.group(2)),m.group(3),div)
		# copy it into every opcode, checking for duplicates.
		for op in oprange:
			assert generators[op] is None,"Duplicate ${0:02x}".format(op)
			generators[op] = lastGenerator
	# is it a code line.
	m = re.match("^\d\:\[(.*?)\]\s*(.*)$",line)
	if m is not None:
		# create phase object and add to last generator defined.
		display = m.group(1).split(",")		
		assert len(display) == 4
		lastGenerator.add(Phase(m.group(2).strip(),display[0],display[1],display[2],display[3]))
#
#	Get the mnemonics
#
mnemonics = [ None ] * 256
for opcode in range(0,256):
	if generators[opcode] is not None:
		mnemonics[opcode] = proc.process(generators[opcode].mnemonic,opcode,generators[opcode].divisor)
	else:
		mnemonics[opcode] = "db {0:02x}".format(opcode)
xmnemonics = ",".join('"'+x+'"' for x in mnemonics)
assert xmnemonics.find("@") < 0
open("__8008_mnemonics.h","w").write("static const char *_mnemonics[] = { "+xmnemonics + "};\n\n")
#
#	Generate the opcode sequences for every opcode.
#
h = open("__8008_opcodes.h","w")
for opcode in range(0,256):
	if generators[opcode] is not None:
		gen = generators[opcode]
		fullCode = ""
		for phase in range(0,len(gen.phases)):
			fullCode = fullCode + proc.process(gen.getCode(phase,False),opcode,gen.divisor)

		h.write("case 0x{0:02x}: /**** {1} ****/\n".format(opcode,mnemonics[opcode]))
		h.write("\tswitch(phase) {\n")
		for phase in range(0,len(gen.phases)):
			code = proc.process(gen.getCode(phase,True),opcode,gen.divisor)
			h.write("\t\tcase {0}:{1}break;\n".format(phase,code))
		h.write("\t\tcase 4:{0}break;\n".format(fullCode))
		h.write("\t};break;\n")
h.close()
