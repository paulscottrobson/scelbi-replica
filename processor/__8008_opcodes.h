case 0x00: /**** halt ****/
	switch(phase) {
		case 0:updateDisplay(0,0,addr,mb);halt = 1;cycles+=(4);break;
		case 4:halt = 1;cycles+=(4);break;
	};break;
case 0x01: /**** halt ****/
	switch(phase) {
		case 0:updateDisplay(0,0,addr,mb);halt = 1;cycles+=(4);break;
		case 4:halt = 1;cycles+=(4);break;
	};break;
case 0x02: /**** rlc ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = ((a << 1) | (a >> 7)) & 0xFF;carry = a & 1;cycles+=(5);break;
		case 4:a = ((a << 1) | (a >> 7)) & 0xFF;carry = a & 1;cycles+=(5);break;
	};break;
case 0x03: /**** rnc ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (carry == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (carry == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x04: /**** adi $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x05: /**** rst 00 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x00,mb);pcix = (pcix + 1) & 7;ma = 0x00;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x00;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x06: /**** mvi a,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);a = mb;break;
	};break;
case 0x07: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x08: /**** inr b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = (b + 1) & 0xFF;pszValue = b;cycles+=(5);break;
		case 4:b = (b + 1) & 0xFF;pszValue = b;cycles+=(5);break;
	};break;
case 0x09: /**** dcr b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = (b + 255) & 0xFF;pszValue = b;cycles+=(5);break;
		case 4:b = (b + 255) & 0xFF;pszValue = b;cycles+=(5);break;
	};break;
case 0x0a: /**** rrc ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);carry = a & 1;a = ((a >> 1) | (a << 7)) & 0xFF;cycles+=(5);break;
		case 4:carry = a & 1;a = ((a >> 1) | (a << 7)) & 0xFF;cycles+=(5);break;
	};break;
case 0x0b: /**** rnz ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (pszValue != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (pszValue != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x0c: /**** aci $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x0d: /**** rst 08 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x08,mb);pcix = (pcix + 1) & 7;ma = 0x08;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x08;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x0e: /**** mvi b,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);b = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);b = mb;break;
	};break;
case 0x0f: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x10: /**** inr c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = (c + 1) & 0xFF;pszValue = c;cycles+=(5);break;
		case 4:c = (c + 1) & 0xFF;pszValue = c;cycles+=(5);break;
	};break;
case 0x11: /**** dcr c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = (c + 255) & 0xFF;pszValue = c;cycles+=(5);break;
		case 4:c = (c + 255) & 0xFF;pszValue = c;cycles+=(5);break;
	};break;
case 0x12: /**** ral ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);ma = a;ma = (ma << 1) | carry;carry = (ma >> 8) & 1;a = ma & 0xFF;cycles+=(5);break;
		case 4:ma = a;ma = (ma << 1) | carry;carry = (ma >> 8) & 1;a = ma & 0xFF;cycles+=(5);break;
	};break;
case 0x13: /**** rp ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if ((pszValue & 0x80) == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if ((pszValue & 0x80) == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x14: /**** sui $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x15: /**** rst 10 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x10,mb);pcix = (pcix + 1) & 7;ma = 0x10;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x10;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x16: /**** mvi c,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);c = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);c = mb;break;
	};break;
case 0x17: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x18: /**** inr d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = (d + 1) & 0xFF;pszValue = d;cycles+=(5);break;
		case 4:d = (d + 1) & 0xFF;pszValue = d;cycles+=(5);break;
	};break;
case 0x19: /**** dcr d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = (d + 255) & 0xFF;pszValue = d;cycles+=(5);break;
		case 4:d = (d + 255) & 0xFF;pszValue = d;cycles+=(5);break;
	};break;
case 0x1a: /**** rar ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);ma = a | (carry << 8);carry = ma & 1;a = (ma >> 1) & 0xFF;cycles+=(5);break;
		case 4:ma = a | (carry << 8);carry = ma & 1;a = (ma >> 1) & 0xFF;cycles+=(5);break;
	};break;
case 0x1b: /**** rpo ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (isParityEven(pszValue) == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (isParityEven(pszValue) == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x1c: /**** sbi $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x1d: /**** rst 18 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x18,mb);pcix = (pcix + 1) & 7;ma = 0x18;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x18;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x1e: /**** mvi d,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);d = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);d = mb;break;
	};break;
case 0x1f: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x20: /**** inr e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = (e + 1) & 0xFF;pszValue = e;cycles+=(5);break;
		case 4:e = (e + 1) & 0xFF;pszValue = e;cycles+=(5);break;
	};break;
case 0x21: /**** dcr e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = (e + 255) & 0xFF;pszValue = e;cycles+=(5);break;
		case 4:e = (e + 255) & 0xFF;pszValue = e;cycles+=(5);break;
	};break;
case 0x23: /**** rc ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (carry != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (carry != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x24: /**** ani $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a & mb;carry = 0;phase = 0;break;
		case 4:FETCH8();cycles+=(8);a = a & mb;carry = 0;break;
	};break;
case 0x25: /**** rst 20 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x20,mb);pcix = (pcix + 1) & 7;ma = 0x20;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x20;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x26: /**** mvi e,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);e = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);e = mb;break;
	};break;
case 0x27: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x28: /**** inr h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = (h + 1) & 0xFF;pszValue = h;cycles+=(5);break;
		case 4:h = (h + 1) & 0xFF;pszValue = h;cycles+=(5);break;
	};break;
case 0x29: /**** dcr h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = (h + 255) & 0xFF;pszValue = h;cycles+=(5);break;
		case 4:h = (h + 255) & 0xFF;pszValue = h;cycles+=(5);break;
	};break;
case 0x2b: /**** rz ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (pszValue == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (pszValue == 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x2c: /**** xri $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a ^ mb;carry = 0;phase = 0;break;
		case 4:FETCH8();cycles+=(8);a = a ^ mb;carry = 0;break;
	};break;
case 0x2d: /**** rst 28 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x28,mb);pcix = (pcix + 1) & 7;ma = 0x28;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x28;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x2e: /**** mvi h,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);h = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);h = mb;break;
	};break;
case 0x2f: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x30: /**** inr l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = (l + 1) & 0xFF;pszValue = l;cycles+=(5);break;
		case 4:l = (l + 1) & 0xFF;pszValue = l;cycles+=(5);break;
	};break;
case 0x31: /**** dcr l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = (l + 255) & 0xFF;pszValue = l;cycles+=(5);break;
		case 4:l = (l + 255) & 0xFF;pszValue = l;cycles+=(5);break;
	};break;
case 0x33: /**** rm ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if ((pszValue & 0x80) != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if ((pszValue & 0x80) != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x34: /**** ori $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a | mb;carry = 0;phase = 0;break;
		case 4:FETCH8();cycles+=(8);a = a | mb;carry = 0;break;
	};break;
case 0x35: /**** rst 30 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x30,mb);pcix = (pcix + 1) & 7;ma = 0x30;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x30;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x36: /**** mvi l,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);l = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);l = mb;break;
	};break;
case 0x37: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x3b: /**** rpe ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);if (isParityEven(pszValue) != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
		case 4:if (isParityEven(pszValue) != 0) { pcix = (pcix - 1) & 7; };cycles+=(4);break;
	};break;
case 0x3c: /**** cpi $1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;phase = 0;break;
		case 4:FETCH8();cycles+=(8);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;break;
	};break;
case 0x3d: /**** rst 38 ****/
	switch(phase) {
		case 0:updateDisplay(0,0,0x38,mb);pcix = (pcix + 1) & 7;ma = 0x38;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
		case 4:pcix = (pcix + 1) & 7;ma = 0x38;pctr[pcix] = ma & 0x3FFF;cycles+=(5);break;
	};break;
case 0x3e: /**** mvi m,$1 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH8();phase = 1;cycles+=(9);break;
		case 1:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:FETCH8();cycles+=(9);ma = ((h << 8)|l);WRITE();break;
	};break;
case 0x3f: /**** ret ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);pcix = (pcix - 1) & 7;cycles+=(5);break;
		case 4:pcix = (pcix - 1) & 7;cycles+=(5);break;
	};break;
case 0x40: /**** jnc $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (carry == 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (carry == 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x41: /**** inp 00 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x00,a);INPUTPORT(0x00);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x00);cycles+=(8);;break;
	};break;
case 0x42: /**** cnc $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (carry == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (carry == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x43: /**** inp 01 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x01,a);INPUTPORT(0x01);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x01);cycles+=(8);;break;
	};break;
case 0x44: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x45: /**** inp 02 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x02,a);INPUTPORT(0x02);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x02);cycles+=(8);;break;
	};break;
case 0x46: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x47: /**** inp 03 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x03,a);INPUTPORT(0x03);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x03);cycles+=(8);;break;
	};break;
case 0x48: /**** jnz $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (pszValue != 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (pszValue != 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x49: /**** inp 04 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x04,a);INPUTPORT(0x04);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x04);cycles+=(8);;break;
	};break;
case 0x4a: /**** cnz $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (pszValue != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (pszValue != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x4b: /**** inp 05 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x05,a);INPUTPORT(0x05);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x05);cycles+=(8);;break;
	};break;
case 0x4c: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x4d: /**** inp 06 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x06,a);INPUTPORT(0x06);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x06);cycles+=(8);;break;
	};break;
case 0x4e: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x4f: /**** inp 07 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x07,a);INPUTPORT(0x07);phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:INPUTPORT(0x07);cycles+=(8);;break;
	};break;
case 0x50: /**** jp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if ((pszValue & 0x80) == 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if ((pszValue & 0x80) == 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x51: /**** out 08 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x08,a);OUTPUTPORT(0x08,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x08,a);cycles+=(6);;break;
	};break;
case 0x52: /**** cp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if ((pszValue & 0x80) == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if ((pszValue & 0x80) == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x53: /**** out 09 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x09,a);OUTPUTPORT(0x09,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x09,a);cycles+=(6);;break;
	};break;
case 0x54: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x55: /**** out 0a ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0a,a);OUTPUTPORT(0x0a,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0a,a);cycles+=(6);;break;
	};break;
case 0x56: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x57: /**** out 0b ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0b,a);OUTPUTPORT(0x0b,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0b,a);cycles+=(6);;break;
	};break;
case 0x58: /**** jpo $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (isParityEven(pszValue) == 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (isParityEven(pszValue) == 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x59: /**** out 0c ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0c,a);OUTPUTPORT(0x0c,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0c,a);cycles+=(6);;break;
	};break;
case 0x5a: /**** cpo $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (isParityEven(pszValue) == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (isParityEven(pszValue) == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x5b: /**** out 0d ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0d,a);OUTPUTPORT(0x0d,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0d,a);cycles+=(6);;break;
	};break;
case 0x5c: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x5d: /**** out 0e ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0e,a);OUTPUTPORT(0x0e,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0e,a);cycles+=(6);;break;
	};break;
case 0x5e: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x5f: /**** out 0f ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x0f,a);OUTPUTPORT(0x0f,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x0f,a);cycles+=(6);;break;
	};break;
case 0x60: /**** jc $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (carry != 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (carry != 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x61: /**** out 10 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x10,a);OUTPUTPORT(0x10,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x10,a);cycles+=(6);;break;
	};break;
case 0x62: /**** cc $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (carry != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (carry != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x63: /**** out 11 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x11,a);OUTPUTPORT(0x11,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x11,a);cycles+=(6);;break;
	};break;
case 0x64: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x65: /**** out 12 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x12,a);OUTPUTPORT(0x12,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x12,a);cycles+=(6);;break;
	};break;
case 0x66: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x67: /**** out 13 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x13,a);OUTPUTPORT(0x13,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x13,a);cycles+=(6);;break;
	};break;
case 0x68: /**** jz $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (pszValue == 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (pszValue == 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x69: /**** out 14 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x14,a);OUTPUTPORT(0x14,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x14,a);cycles+=(6);;break;
	};break;
case 0x6a: /**** cz $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (pszValue == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (pszValue == 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x6b: /**** out 15 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x15,a);OUTPUTPORT(0x15,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x15,a);cycles+=(6);;break;
	};break;
case 0x6c: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x6d: /**** out 16 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x16,a);OUTPUTPORT(0x16,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x16,a);cycles+=(6);;break;
	};break;
case 0x6e: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x6f: /**** out 17 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x17,a);OUTPUTPORT(0x17,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x17,a);cycles+=(6);;break;
	};break;
case 0x70: /**** jm $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if ((pszValue & 0x80) != 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if ((pszValue & 0x80) != 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x71: /**** out 18 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x18,a);OUTPUTPORT(0x18,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x18,a);cycles+=(6);;break;
	};break;
case 0x72: /**** cm $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if ((pszValue & 0x80) != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if ((pszValue & 0x80) != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x73: /**** out 19 ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x19,a);OUTPUTPORT(0x19,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x19,a);cycles+=(6);;break;
	};break;
case 0x74: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x75: /**** out 1a ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1a,a);OUTPUTPORT(0x1a,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1a,a);cycles+=(6);;break;
	};break;
case 0x76: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x77: /**** out 1b ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1b,a);OUTPUTPORT(0x1b,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1b,a);cycles+=(6);;break;
	};break;
case 0x78: /**** jpe $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (isParityEven(pszValue) != 0) { pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (isParityEven(pszValue) != 0) { pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x79: /**** out 1c ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1c,a);OUTPUTPORT(0x1c,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1c,a);cycles+=(6);;break;
	};break;
case 0x7a: /**** cpe $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(10);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);if (isParityEven(pszValue) != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(10);if (isParityEven(pszValue) != 0) { pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF; };;break;
	};break;
case 0x7b: /**** out 1d ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1d,a);OUTPUTPORT(0x1d,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1d,a);cycles+=(6);;break;
	};break;
case 0x7c: /**** jmp $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x7d: /**** out 1e ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1e,a);OUTPUTPORT(0x1e,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1e,a);cycles+=(6);;break;
	};break;
case 0x7e: /**** call $2 ****/
	switch(phase) {
		case 0:updateDisplay(1,0,pctr[pcix],mb);FETCH16();phase = 1;cycles+=(11);break;
		case 1:updateDisplay(1,0,pctr[pcix]-1,ma & 0xFF);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;phase = 2;break;
		case 2:updateDisplay(0,0,pctr[pcix],ma >> 8);;phase = 0;break;
		case 4:FETCH16();cycles+=(11);pcix = (pcix + 1) & 7;pctr[pcix] = ma & 0x3FFF;;break;
	};break;
case 0x7f: /**** out 1f ****/
	switch(phase) {
		case 0:updateDisplay(0,1,0x1f,a);OUTPUTPORT(0x1f,a);phase = 1;cycles+=(6);break;
		case 1:updateDisplay(0,0,pctr[pcix],a);;phase = 0;break;
		case 4:OUTPUTPORT(0x1f,a);cycles+=(6);;break;
	};break;
case 0x80: /**** add a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = a;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = a;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x81: /**** add b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = b;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = b;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x82: /**** add c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = c;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = c;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x83: /**** add d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = d;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = d;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x84: /**** add e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = e;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = e;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x85: /**** add h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = h;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = h;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x86: /**** add l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = l;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = l;carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x87: /**** add m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);carry = 0;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x88: /**** adc a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = a;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = a;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x89: /**** adc b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = b;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = b;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8a: /**** adc c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = c;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = c;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8b: /**** adc d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = d;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = d;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8c: /**** adc e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = e;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = e;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8d: /**** adc h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = h;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = h;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8e: /**** adc l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = l;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = l;temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x8f: /**** adc m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);temp16 = a + mb + carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x90: /**** sub a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = a;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = a;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x91: /**** sub b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = b;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = b;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x92: /**** sub c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = c;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = c;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x93: /**** sub d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = d;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = d;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x94: /**** sub e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = e;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = e;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x95: /**** sub h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = h;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = h;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x96: /**** sub l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = l;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = l;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x97: /**** sub m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0x98: /**** sbb a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = a;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = a;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x99: /**** sbb b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = b;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = b;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9a: /**** sbb c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = c;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = c;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9b: /**** sbb d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = d;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = d;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9c: /**** sbb e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = e;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = e;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9d: /**** sbb h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = h;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = h;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9e: /**** sbb l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = l;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
		case 4:mb = l;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;cycles+=(5);break;
	};break;
case 0x9f: /**** sbb m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;a = mb;break;
	};break;
case 0xa0: /**** ana a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & a;carry = 0;cycles+=(5);break;
		case 4:a = a & a;carry = 0;cycles+=(5);break;
	};break;
case 0xa1: /**** ana b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & b;carry = 0;cycles+=(5);break;
		case 4:a = a & b;carry = 0;cycles+=(5);break;
	};break;
case 0xa2: /**** ana c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & c;carry = 0;cycles+=(5);break;
		case 4:a = a & c;carry = 0;cycles+=(5);break;
	};break;
case 0xa3: /**** ana d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & d;carry = 0;cycles+=(5);break;
		case 4:a = a & d;carry = 0;cycles+=(5);break;
	};break;
case 0xa4: /**** ana e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & e;carry = 0;cycles+=(5);break;
		case 4:a = a & e;carry = 0;cycles+=(5);break;
	};break;
case 0xa5: /**** ana h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & h;carry = 0;cycles+=(5);break;
		case 4:a = a & h;carry = 0;cycles+=(5);break;
	};break;
case 0xa6: /**** ana l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a & l;carry = 0;cycles+=(5);break;
		case 4:a = a & l;carry = 0;cycles+=(5);break;
	};break;
case 0xa7: /**** ana m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a & mb;carry = 0;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);a = a & mb;carry = 0;break;
	};break;
case 0xa8: /**** xra a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ a;carry = 0;cycles+=(5);break;
		case 4:a = a ^ a;carry = 0;cycles+=(5);break;
	};break;
case 0xa9: /**** xra b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ b;carry = 0;cycles+=(5);break;
		case 4:a = a ^ b;carry = 0;cycles+=(5);break;
	};break;
case 0xaa: /**** xra c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ c;carry = 0;cycles+=(5);break;
		case 4:a = a ^ c;carry = 0;cycles+=(5);break;
	};break;
case 0xab: /**** xra d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ d;carry = 0;cycles+=(5);break;
		case 4:a = a ^ d;carry = 0;cycles+=(5);break;
	};break;
case 0xac: /**** xra e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ e;carry = 0;cycles+=(5);break;
		case 4:a = a ^ e;carry = 0;cycles+=(5);break;
	};break;
case 0xad: /**** xra h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ h;carry = 0;cycles+=(5);break;
		case 4:a = a ^ h;carry = 0;cycles+=(5);break;
	};break;
case 0xae: /**** xra l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a ^ l;carry = 0;cycles+=(5);break;
		case 4:a = a ^ l;carry = 0;cycles+=(5);break;
	};break;
case 0xaf: /**** xra m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a ^ mb;carry = 0;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);a = a ^ mb;carry = 0;break;
	};break;
case 0xb0: /**** ora a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | a;carry = 0;cycles+=(5);break;
		case 4:a = a | a;carry = 0;cycles+=(5);break;
	};break;
case 0xb1: /**** ora b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | b;carry = 0;cycles+=(5);break;
		case 4:a = a | b;carry = 0;cycles+=(5);break;
	};break;
case 0xb2: /**** ora c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | c;carry = 0;cycles+=(5);break;
		case 4:a = a | c;carry = 0;cycles+=(5);break;
	};break;
case 0xb3: /**** ora d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | d;carry = 0;cycles+=(5);break;
		case 4:a = a | d;carry = 0;cycles+=(5);break;
	};break;
case 0xb4: /**** ora e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | e;carry = 0;cycles+=(5);break;
		case 4:a = a | e;carry = 0;cycles+=(5);break;
	};break;
case 0xb5: /**** ora h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | h;carry = 0;cycles+=(5);break;
		case 4:a = a | h;carry = 0;cycles+=(5);break;
	};break;
case 0xb6: /**** ora l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a | l;carry = 0;cycles+=(5);break;
		case 4:a = a | l;carry = 0;cycles+=(5);break;
	};break;
case 0xb7: /**** ora m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = a | mb;carry = 0;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);a = a | mb;carry = 0;break;
	};break;
case 0xb8: /**** cmp a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = a;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = a;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xb9: /**** cmp b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = b;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = b;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xba: /**** cmp c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = c;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = c;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xbb: /**** cmp d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = d;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = d;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xbc: /**** cmp e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = e;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = e;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xbd: /**** cmp h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = h;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = h;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xbe: /**** cmp l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);mb = l;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
		case 4:mb = l;carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;cycles+=(5);break;
	};break;
case 0xbf: /**** cmp m ****/
	switch(phase) {
		case 0:updateDisplay(1,0,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);carry = 0;temp16 = a - mb - carry;mb = temp16 & 0xFF;carry = (temp16 >> 8) & 1;pszValue = mb;break;
	};break;
case 0xc0: /**** mov a,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = a;cycles+=(5);break;
		case 4:a = a;cycles+=(5);break;
	};break;
case 0xc1: /**** mov a,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = b;cycles+=(5);break;
		case 4:a = b;cycles+=(5);break;
	};break;
case 0xc2: /**** mov a,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = c;cycles+=(5);break;
		case 4:a = c;cycles+=(5);break;
	};break;
case 0xc3: /**** mov a,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = d;cycles+=(5);break;
		case 4:a = d;cycles+=(5);break;
	};break;
case 0xc4: /**** mov a,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = e;cycles+=(5);break;
		case 4:a = e;cycles+=(5);break;
	};break;
case 0xc5: /**** mov a,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = h;cycles+=(5);break;
		case 4:a = h;cycles+=(5);break;
	};break;
case 0xc6: /**** mov a,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);a = l;cycles+=(5);break;
		case 4:a = l;cycles+=(5);break;
	};break;
case 0xc7: /**** mov a,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);a = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);a = mb;break;
	};break;
case 0xc8: /**** mov b,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = a;cycles+=(5);break;
		case 4:b = a;cycles+=(5);break;
	};break;
case 0xc9: /**** mov b,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = b;cycles+=(5);break;
		case 4:b = b;cycles+=(5);break;
	};break;
case 0xca: /**** mov b,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = c;cycles+=(5);break;
		case 4:b = c;cycles+=(5);break;
	};break;
case 0xcb: /**** mov b,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = d;cycles+=(5);break;
		case 4:b = d;cycles+=(5);break;
	};break;
case 0xcc: /**** mov b,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = e;cycles+=(5);break;
		case 4:b = e;cycles+=(5);break;
	};break;
case 0xcd: /**** mov b,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = h;cycles+=(5);break;
		case 4:b = h;cycles+=(5);break;
	};break;
case 0xce: /**** mov b,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);b = l;cycles+=(5);break;
		case 4:b = l;cycles+=(5);break;
	};break;
case 0xcf: /**** mov b,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);b = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);b = mb;break;
	};break;
case 0xd0: /**** mov c,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = a;cycles+=(5);break;
		case 4:c = a;cycles+=(5);break;
	};break;
case 0xd1: /**** mov c,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = b;cycles+=(5);break;
		case 4:c = b;cycles+=(5);break;
	};break;
case 0xd2: /**** mov c,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = c;cycles+=(5);break;
		case 4:c = c;cycles+=(5);break;
	};break;
case 0xd3: /**** mov c,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = d;cycles+=(5);break;
		case 4:c = d;cycles+=(5);break;
	};break;
case 0xd4: /**** mov c,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = e;cycles+=(5);break;
		case 4:c = e;cycles+=(5);break;
	};break;
case 0xd5: /**** mov c,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = h;cycles+=(5);break;
		case 4:c = h;cycles+=(5);break;
	};break;
case 0xd6: /**** mov c,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);c = l;cycles+=(5);break;
		case 4:c = l;cycles+=(5);break;
	};break;
case 0xd7: /**** mov c,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);c = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);c = mb;break;
	};break;
case 0xd8: /**** mov d,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = a;cycles+=(5);break;
		case 4:d = a;cycles+=(5);break;
	};break;
case 0xd9: /**** mov d,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = b;cycles+=(5);break;
		case 4:d = b;cycles+=(5);break;
	};break;
case 0xda: /**** mov d,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = c;cycles+=(5);break;
		case 4:d = c;cycles+=(5);break;
	};break;
case 0xdb: /**** mov d,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = d;cycles+=(5);break;
		case 4:d = d;cycles+=(5);break;
	};break;
case 0xdc: /**** mov d,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = e;cycles+=(5);break;
		case 4:d = e;cycles+=(5);break;
	};break;
case 0xdd: /**** mov d,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = h;cycles+=(5);break;
		case 4:d = h;cycles+=(5);break;
	};break;
case 0xde: /**** mov d,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);d = l;cycles+=(5);break;
		case 4:d = l;cycles+=(5);break;
	};break;
case 0xdf: /**** mov d,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);d = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);d = mb;break;
	};break;
case 0xe0: /**** mov e,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = a;cycles+=(5);break;
		case 4:e = a;cycles+=(5);break;
	};break;
case 0xe1: /**** mov e,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = b;cycles+=(5);break;
		case 4:e = b;cycles+=(5);break;
	};break;
case 0xe2: /**** mov e,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = c;cycles+=(5);break;
		case 4:e = c;cycles+=(5);break;
	};break;
case 0xe3: /**** mov e,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = d;cycles+=(5);break;
		case 4:e = d;cycles+=(5);break;
	};break;
case 0xe4: /**** mov e,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = e;cycles+=(5);break;
		case 4:e = e;cycles+=(5);break;
	};break;
case 0xe5: /**** mov e,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = h;cycles+=(5);break;
		case 4:e = h;cycles+=(5);break;
	};break;
case 0xe6: /**** mov e,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);e = l;cycles+=(5);break;
		case 4:e = l;cycles+=(5);break;
	};break;
case 0xe7: /**** mov e,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);e = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);e = mb;break;
	};break;
case 0xe8: /**** mov h,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = a;cycles+=(5);break;
		case 4:h = a;cycles+=(5);break;
	};break;
case 0xe9: /**** mov h,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = b;cycles+=(5);break;
		case 4:h = b;cycles+=(5);break;
	};break;
case 0xea: /**** mov h,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = c;cycles+=(5);break;
		case 4:h = c;cycles+=(5);break;
	};break;
case 0xeb: /**** mov h,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = d;cycles+=(5);break;
		case 4:h = d;cycles+=(5);break;
	};break;
case 0xec: /**** mov h,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = e;cycles+=(5);break;
		case 4:h = e;cycles+=(5);break;
	};break;
case 0xed: /**** mov h,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = h;cycles+=(5);break;
		case 4:h = h;cycles+=(5);break;
	};break;
case 0xee: /**** mov h,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);h = l;cycles+=(5);break;
		case 4:h = l;cycles+=(5);break;
	};break;
case 0xef: /**** mov h,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);h = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);h = mb;break;
	};break;
case 0xf0: /**** mov l,a ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = a;cycles+=(5);break;
		case 4:l = a;cycles+=(5);break;
	};break;
case 0xf1: /**** mov l,b ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = b;cycles+=(5);break;
		case 4:l = b;cycles+=(5);break;
	};break;
case 0xf2: /**** mov l,c ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = c;cycles+=(5);break;
		case 4:l = c;cycles+=(5);break;
	};break;
case 0xf3: /**** mov l,d ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = d;cycles+=(5);break;
		case 4:l = d;cycles+=(5);break;
	};break;
case 0xf4: /**** mov l,e ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = e;cycles+=(5);break;
		case 4:l = e;cycles+=(5);break;
	};break;
case 0xf5: /**** mov l,h ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = h;cycles+=(5);break;
		case 4:l = h;cycles+=(5);break;
	};break;
case 0xf6: /**** mov l,l ****/
	switch(phase) {
		case 0:updateDisplay(0,0,pctr[pcix],mb);l = l;cycles+=(5);break;
		case 4:l = l;cycles+=(5);break;
	};break;
case 0xf7: /**** mov l,m ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);READ();phase = 1;cycles+=(8);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);l = mb;phase = 0;break;
		case 4:ma = ((h << 8)|l);READ();cycles+=(8);l = mb;break;
	};break;
case 0xf8: /**** mov m,a ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = a;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = a;cycles+=(7);WRITE();break;
	};break;
case 0xf9: /**** mov m,b ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = b;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = b;cycles+=(7);WRITE();break;
	};break;
case 0xfa: /**** mov m,c ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = c;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = c;cycles+=(7);WRITE();break;
	};break;
case 0xfb: /**** mov m,d ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = d;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = d;cycles+=(7);WRITE();break;
	};break;
case 0xfc: /**** mov m,e ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = e;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = e;cycles+=(7);WRITE();break;
	};break;
case 0xfd: /**** mov m,h ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = h;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = h;cycles+=(7);WRITE();break;
	};break;
case 0xfe: /**** mov m,l ****/
	switch(phase) {
		case 0:updateDisplay(1,1,((h << 8)|l),mb);ma = ((h << 8)|l);mb = l;phase = 1;cycles+=(7);break;
		case 1:updateDisplay(0,0,pctr[pcix],mb);WRITE();phase = 0;break;
		case 4:ma = ((h << 8)|l);mb = l;cycles+=(7);WRITE();break;
	};break;
case 0xff: /**** halt ****/
	switch(phase) {
		case 0:updateDisplay(0,0,addr,mb);halt = 1;cycles+=(4);break;
		case 4:halt = 1;cycles+=(4);break;
	};break;
