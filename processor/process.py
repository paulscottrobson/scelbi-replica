#
#	Process 8008.def
#
import sys,re

class Opcode(object):
	def __init__(self,mnemonic,cycles,divisor):
		self.mnemonic = mnemonic
		self.cycles = cycles
		self.divisor = divisor
		self.phases = []

	def process(self,s,opcode):
		s = s.replace("@mahl","ma = (h << 8) | l")
		s = s.replace("@port","{0:02x}".format((opcode >> 1) & 0x1F))
		s = s.replace("@addr","{0:02x}".format(opcode & 0x38))
		s = s.replace("@tname",Opcode.testName[(opcode >> 3) & 7])
		s = s.replace("@test",Opcode.testCode[(opcode >> 3) & 7])
		s = s.replace("@r","abcdehlm"[int(opcode / self.divisor) & 7])
		return s

	def add(self,phaseCode):
		self.phases.append(phaseCode)

Opcode.testName = [ "nc","nz","p","po","c","z","m","pe "]

Opcode.testCode = 	[ 	"carry == 0",					\
						"pszValue != 0",				\
						"(pszValue & 0x80) == 0",		\
						"isParityEven(pszValue) == 0",	\
						"carry != 0",					\
						"pszValue == 0",				\
						"(pszValue & 0x80) != 0",		\
						"isParityEven(pszValue) != 0" 	\
					]

src = [x.replace("\t"," ") for x in open("8008.def").readlines()]
src = [x if x.find("#") < 0 else x[:x.find("#")] for x in src]
src = [x.strip() for x in src if x.strip() != ""]

opcodes = [ None ] * 256
mnemonics = [ 'db {0:02x}'.format(i) for i in range(0,256) ]
lastOpcode = None

for l in src:
	processed = False
	m = re.match('^([0-9A-Fa-f\-\,]+)\s*(\d+)\s*"(.*)"$',l)
	if m is not None:
		processed = True
		rg = m.group(1) if len(m.group(1)) > 2 else m.group(1)+"-"+m.group(1)
		rg = rg if len(rg) == 7 else rg+",1"
		lastOpcode = Opcode(m.group(3),int(m.group(2)),int(rg[-1]))
		for opc in range(int(rg[:2],16),int(rg[3:5],16)+1,int(rg[-1])):
			assert opcodes[opc] is None
			opcodes[opc] = lastOpcode
			mnemonics[opc] = lastOpcode.process(m.group(3),opc)
	m = re.match("^(\d)\:\s*(.*)$",l)
	if m is not None:
		lastOpcode.add(m.group(2))
		processed = True
	assert processed

for i in range(0,256):
	if opcodes[i] is None:
		opcodes[i] = Opcode(mnemonics[i],4,1)
		opcodes[i].add("")

# Mnemonics.
open("_8008_mnemonics.h","w").write(",".join(['"'+x+'"' for x in mnemonics])+"\n")
# Phases for each instruction.
open("_8008_phasecount.h","w").write(",".join([str(len(opcodes[i].phases)) for i in range(0,256)])+"\n")
# Cycles for each instruction.
open("_8008_cycles.h","w").write(",".join([str(opcodes[i].cycles) for i in range(0,256)])+"\n")
# Code for each instruction.
h = open("_8008_opcodes.h","w")
for opc in range(0,256):
	h.write("case 0x{0:02x}:\t\t\t/**** {1} ****/\n".format(opc,mnemonics[opc]))
	for phase in range(0,len(opcodes[opc].phases)):
		code = opcodes[opc].phases[phase]
		if code != "":
			code = opcodes[opc].process(code,opc) + ";"
			h.write("\tif (phase & {0}) {{ {1} }}\n".format(1 << phase,code))
	h.write("\tbreak;\n")
h.close()