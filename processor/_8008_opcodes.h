case 0x00:			/**** hlt ****/
	if (phase & 1) { halt = 1; }
	break;
case 0x01:			/**** hlt ****/
	if (phase & 1) { halt = 1; }
	break;
case 0x02:			/**** rlc ****/
	if (phase & 1) { carry = (a >> 7) & 1;a = ((a << 1) & 255) | carry; }
	break;
case 0x03:			/**** rnc ****/
	if (phase & 1) { if (carry == 0) { pull(); }; }
	break;
case 0x04:			/**** adi $1 ****/
	if (phase & 2) { fetch() ; add(a,mb,0) ; a = pszValue; }
	break;
case 0x05:			/**** rst 00 ****/
	if (phase & 1) { temp16 = 0x00 ; push() ; goto(); }
	break;
case 0x06:			/**** mvi a,$1 ****/
	if (phase & 2) { fetch() ; a = mb; }
	break;
case 0x07:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x08:			/**** inr b ****/
	if (phase & 1) { b = pszValue = (b + 1) & 255; }
	break;
case 0x09:			/**** dcr b ****/
	if (phase & 1) { b = pszValue = (b + 255) & 255; }
	break;
case 0x0a:			/**** rrc ****/
	if (phase & 1) { carry = a & 1;a = (a >> 1) | (carry << 7); }
	break;
case 0x0b:			/**** rnz ****/
	if (phase & 1) { if (pszValue != 0) { pull(); }; }
	break;
case 0x0c:			/**** aci $1 ****/
	if (phase & 2) { fetch() ; add(a,mb,carry) ; a = pszValue; }
	break;
case 0x0d:			/**** rst 08 ****/
	if (phase & 1) { temp16 = 0x08 ; push() ; goto(); }
	break;
case 0x0e:			/**** mvi b,$1 ****/
	if (phase & 2) { fetch() ; b = mb; }
	break;
case 0x0f:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x10:			/**** inr c ****/
	if (phase & 1) { c = pszValue = (c + 1) & 255; }
	break;
case 0x11:			/**** dcr c ****/
	if (phase & 1) { c = pszValue = (c + 255) & 255; }
	break;
case 0x12:			/**** ral ****/
	if (phase & 1) { temp16 = (a << 1) | carry; a = temp16 & 255;carry = (temp16 >> 8) & 1; }
	break;
case 0x13:			/**** rp ****/
	if (phase & 1) { if ((pszValue & 0x80) == 0) { pull(); }; }
	break;
case 0x14:			/**** sui $1 ****/
	if (phase & 2) { fetch() ; sub(a,mb,0) ; a = pszValue; }
	break;
case 0x15:			/**** rst 10 ****/
	if (phase & 1) { temp16 = 0x10 ; push() ; goto(); }
	break;
case 0x16:			/**** mvi c,$1 ****/
	if (phase & 2) { fetch() ; c = mb; }
	break;
case 0x17:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x18:			/**** inr d ****/
	if (phase & 1) { d = pszValue = (d + 1) & 255; }
	break;
case 0x19:			/**** dcr d ****/
	if (phase & 1) { d = pszValue = (d + 255) & 255; }
	break;
case 0x1a:			/**** rar ****/
	if (phase & 1) { temp16 = a | (carry << 8);a = (temp16 >> 1) & 255;carry = temp16 & 1; }
	break;
case 0x1b:			/**** rpo ****/
	if (phase & 1) { if (isParityEven(pszValue) == 0) { pull(); }; }
	break;
case 0x1c:			/**** sbi $1 ****/
	if (phase & 2) { fetch() ; sub(a,mb,carry) ; a = pszValue; }
	break;
case 0x1d:			/**** rst 18 ****/
	if (phase & 1) { temp16 = 0x18 ; push() ; goto(); }
	break;
case 0x1e:			/**** mvi d,$1 ****/
	if (phase & 2) { fetch() ; d = mb; }
	break;
case 0x1f:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x20:			/**** inr e ****/
	if (phase & 1) { e = pszValue = (e + 1) & 255; }
	break;
case 0x21:			/**** dcr e ****/
	if (phase & 1) { e = pszValue = (e + 255) & 255; }
	break;
case 0x22:			/**** db 22 ****/
	break;
case 0x23:			/**** rc ****/
	if (phase & 1) { if (carry != 0) { pull(); }; }
	break;
case 0x24:			/**** ani $1 ****/
	if (phase & 2) { fetch() ; a = pszValue = a & mb ; carry = 0; }
	break;
case 0x25:			/**** rst 20 ****/
	if (phase & 1) { temp16 = 0x20 ; push() ; goto(); }
	break;
case 0x26:			/**** mvi e,$1 ****/
	if (phase & 2) { fetch() ; e = mb; }
	break;
case 0x27:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x28:			/**** inr h ****/
	if (phase & 1) { h = pszValue = (h + 1) & 255; }
	break;
case 0x29:			/**** dcr h ****/
	if (phase & 1) { h = pszValue = (h + 255) & 255; }
	break;
case 0x2a:			/**** db 2a ****/
	break;
case 0x2b:			/**** rz ****/
	if (phase & 1) { if (pszValue == 0) { pull(); }; }
	break;
case 0x2c:			/**** xri $1 ****/
	if (phase & 2) { fetch() ; a = pszValue = a ^ mb ; carry = 0; }
	break;
case 0x2d:			/**** rst 28 ****/
	if (phase & 1) { temp16 = 0x28 ; push() ; goto(); }
	break;
case 0x2e:			/**** mvi h,$1 ****/
	if (phase & 2) { fetch() ; h = mb; }
	break;
case 0x2f:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x30:			/**** inr l ****/
	if (phase & 1) { l = pszValue = (l + 1) & 255; }
	break;
case 0x31:			/**** dcr l ****/
	if (phase & 1) { l = pszValue = (l + 255) & 255; }
	break;
case 0x32:			/**** db 32 ****/
	break;
case 0x33:			/**** rm ****/
	if (phase & 1) { if ((pszValue & 0x80) != 0) { pull(); }; }
	break;
case 0x34:			/**** ori $1 ****/
	if (phase & 2) { fetch() ; a = pszValue = a | mb ; carry = 0; }
	break;
case 0x35:			/**** rst 30 ****/
	if (phase & 1) { temp16 = 0x30 ; push() ; goto(); }
	break;
case 0x36:			/**** mvi l,$1 ****/
	if (phase & 2) { fetch() ; l = mb; }
	break;
case 0x37:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x38:			/**** db 38 ****/
	break;
case 0x39:			/**** db 39 ****/
	break;
case 0x3a:			/**** db 3a ****/
	break;
case 0x3b:			/**** rpe  ****/
	if (phase & 1) { if (isParityEven(pszValue) != 0) { pull(); }; }
	break;
case 0x3c:			/**** cpi $1 ****/
	if (phase & 2) { fetch() ; sub(a,mb,0); }
	break;
case 0x3d:			/**** rst 38 ****/
	if (phase & 1) { temp16 = 0x38 ; push() ; goto(); }
	break;
case 0x3e:			/**** mvi m,$1 ****/
	if (phase & 2) { fetch() ; read(); }
	if (phase & 4) { ma = (h << 8) | l ; write(); }
	break;
case 0x3f:			/**** ret ****/
	if (phase & 1) { pull(); }
	break;
case 0x40:			/**** jnc $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (carry == 0) { goto(); }; }
	break;
case 0x41:			/**** inp 00 ****/
	if (phase & 2) { ma = (0x00 << 8) | a;a = mb = inputPort(0x00); }
	break;
case 0x42:			/**** cnc $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (carry == 0) { push(); goto(); }; }
	break;
case 0x43:			/**** inp 01 ****/
	if (phase & 2) { ma = (0x01 << 8) | a;a = mb = inputPort(0x01); }
	break;
case 0x44:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x45:			/**** inp 02 ****/
	if (phase & 2) { ma = (0x02 << 8) | a;a = mb = inputPort(0x02); }
	break;
case 0x46:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x47:			/**** inp 03 ****/
	if (phase & 2) { ma = (0x03 << 8) | a;a = mb = inputPort(0x03); }
	break;
case 0x48:			/**** jnz $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (pszValue != 0) { goto(); }; }
	break;
case 0x49:			/**** inp 04 ****/
	if (phase & 2) { ma = (0x04 << 8) | a;a = mb = inputPort(0x04); }
	break;
case 0x4a:			/**** cnz $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (pszValue != 0) { push(); goto(); }; }
	break;
case 0x4b:			/**** inp 05 ****/
	if (phase & 2) { ma = (0x05 << 8) | a;a = mb = inputPort(0x05); }
	break;
case 0x4c:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x4d:			/**** inp 06 ****/
	if (phase & 2) { ma = (0x06 << 8) | a;a = mb = inputPort(0x06); }
	break;
case 0x4e:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x4f:			/**** inp 07 ****/
	if (phase & 2) { ma = (0x07 << 8) | a;a = mb = inputPort(0x07); }
	break;
case 0x50:			/**** jp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if ((pszValue & 0x80) == 0) { goto(); }; }
	break;
case 0x51:			/**** out 08 ****/
	if (phase & 2) { ma = (0x08 << 8) | a;mb = a;outputPort(0x08,a); }
	break;
case 0x52:			/**** cp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if ((pszValue & 0x80) == 0) { push(); goto(); }; }
	break;
case 0x53:			/**** out 09 ****/
	if (phase & 2) { ma = (0x09 << 8) | a;mb = a;outputPort(0x09,a); }
	break;
case 0x54:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x55:			/**** out 0a ****/
	if (phase & 2) { ma = (0x0a << 8) | a;mb = a;outputPort(0x0a,a); }
	break;
case 0x56:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x57:			/**** out 0b ****/
	if (phase & 2) { ma = (0x0b << 8) | a;mb = a;outputPort(0x0b,a); }
	break;
case 0x58:			/**** jpo $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (isParityEven(pszValue) == 0) { goto(); }; }
	break;
case 0x59:			/**** out 0c ****/
	if (phase & 2) { ma = (0x0c << 8) | a;mb = a;outputPort(0x0c,a); }
	break;
case 0x5a:			/**** cpo $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (isParityEven(pszValue) == 0) { push(); goto(); }; }
	break;
case 0x5b:			/**** out 0d ****/
	if (phase & 2) { ma = (0x0d << 8) | a;mb = a;outputPort(0x0d,a); }
	break;
case 0x5c:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x5d:			/**** out 0e ****/
	if (phase & 2) { ma = (0x0e << 8) | a;mb = a;outputPort(0x0e,a); }
	break;
case 0x5e:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x5f:			/**** out 0f ****/
	if (phase & 2) { ma = (0x0f << 8) | a;mb = a;outputPort(0x0f,a); }
	break;
case 0x60:			/**** jc $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (carry != 0) { goto(); }; }
	break;
case 0x61:			/**** out 10 ****/
	if (phase & 2) { ma = (0x10 << 8) | a;mb = a;outputPort(0x10,a); }
	break;
case 0x62:			/**** cc $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (carry != 0) { push(); goto(); }; }
	break;
case 0x63:			/**** out 11 ****/
	if (phase & 2) { ma = (0x11 << 8) | a;mb = a;outputPort(0x11,a); }
	break;
case 0x64:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x65:			/**** out 12 ****/
	if (phase & 2) { ma = (0x12 << 8) | a;mb = a;outputPort(0x12,a); }
	break;
case 0x66:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x67:			/**** out 13 ****/
	if (phase & 2) { ma = (0x13 << 8) | a;mb = a;outputPort(0x13,a); }
	break;
case 0x68:			/**** jz $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (pszValue == 0) { goto(); }; }
	break;
case 0x69:			/**** out 14 ****/
	if (phase & 2) { ma = (0x14 << 8) | a;mb = a;outputPort(0x14,a); }
	break;
case 0x6a:			/**** cz $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (pszValue == 0) { push(); goto(); }; }
	break;
case 0x6b:			/**** out 15 ****/
	if (phase & 2) { ma = (0x15 << 8) | a;mb = a;outputPort(0x15,a); }
	break;
case 0x6c:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x6d:			/**** out 16 ****/
	if (phase & 2) { ma = (0x16 << 8) | a;mb = a;outputPort(0x16,a); }
	break;
case 0x6e:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x6f:			/**** out 17 ****/
	if (phase & 2) { ma = (0x17 << 8) | a;mb = a;outputPort(0x17,a); }
	break;
case 0x70:			/**** jm $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if ((pszValue & 0x80) != 0) { goto(); }; }
	break;
case 0x71:			/**** out 18 ****/
	if (phase & 2) { ma = (0x18 << 8) | a;mb = a;outputPort(0x18,a); }
	break;
case 0x72:			/**** cm $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if ((pszValue & 0x80) != 0) { push(); goto(); }; }
	break;
case 0x73:			/**** out 19 ****/
	if (phase & 2) { ma = (0x19 << 8) | a;mb = a;outputPort(0x19,a); }
	break;
case 0x74:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x75:			/**** out 1a ****/
	if (phase & 2) { ma = (0x1a << 8) | a;mb = a;outputPort(0x1a,a); }
	break;
case 0x76:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x77:			/**** out 1b ****/
	if (phase & 2) { ma = (0x1b << 8) | a;mb = a;outputPort(0x1b,a); }
	break;
case 0x78:			/**** jpe  $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (isParityEven(pszValue) != 0) { goto(); }; }
	break;
case 0x79:			/**** out 1c ****/
	if (phase & 2) { ma = (0x1c << 8) | a;mb = a;outputPort(0x1c,a); }
	break;
case 0x7a:			/**** cpe  $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; if (isParityEven(pszValue) != 0) { push(); goto(); }; }
	break;
case 0x7b:			/**** out 1d ****/
	if (phase & 2) { ma = (0x1d << 8) | a;mb = a;outputPort(0x1d,a); }
	break;
case 0x7c:			/**** jmp $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; goto(); }
	break;
case 0x7d:			/**** out 1e ****/
	if (phase & 2) { ma = (0x1e << 8) | a;mb = a;outputPort(0x1e,a); }
	break;
case 0x7e:			/**** call $2 ****/
	if (phase & 2) { fetch(); temp16 = mb; }
	if (phase & 4) { fetch(); temp16 = (mb << 8) | temp16 ; push(); goto(); }
	break;
case 0x7f:			/**** out 1f ****/
	if (phase & 2) { ma = (0x1f << 8) | a;mb = a;outputPort(0x1f,a); }
	break;
case 0x80:			/**** add a ****/
	if (phase & 1) { add(a,a,0);a = pszValue; }
	break;
case 0x81:			/**** add b ****/
	if (phase & 1) { add(a,b,0);a = pszValue; }
	break;
case 0x82:			/**** add c ****/
	if (phase & 1) { add(a,c,0);a = pszValue; }
	break;
case 0x83:			/**** add d ****/
	if (phase & 1) { add(a,d,0);a = pszValue; }
	break;
case 0x84:			/**** add e ****/
	if (phase & 1) { add(a,e,0);a = pszValue; }
	break;
case 0x85:			/**** add h ****/
	if (phase & 1) { add(a,h,0);a = pszValue; }
	break;
case 0x86:			/**** add l ****/
	if (phase & 1) { add(a,l,0);a = pszValue; }
	break;
case 0x87:			/**** add m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; add(a,m,0); a = pszValue; }
	break;
case 0x88:			/**** adc a ****/
	if (phase & 1) { add(a,a,carry);a = pszValue; }
	break;
case 0x89:			/**** adc b ****/
	if (phase & 1) { add(a,b,carry);a = pszValue; }
	break;
case 0x8a:			/**** adc c ****/
	if (phase & 1) { add(a,c,carry);a = pszValue; }
	break;
case 0x8b:			/**** adc d ****/
	if (phase & 1) { add(a,d,carry);a = pszValue; }
	break;
case 0x8c:			/**** adc e ****/
	if (phase & 1) { add(a,e,carry);a = pszValue; }
	break;
case 0x8d:			/**** adc h ****/
	if (phase & 1) { add(a,h,carry);a = pszValue; }
	break;
case 0x8e:			/**** adc l ****/
	if (phase & 1) { add(a,l,carry);a = pszValue; }
	break;
case 0x8f:			/**** adc m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; add(a,m,carry); a = pszValue; }
	break;
case 0x90:			/**** sub a ****/
	if (phase & 1) { sub(a,a,0);a = pszValue; }
	break;
case 0x91:			/**** sub b ****/
	if (phase & 1) { sub(a,b,0);a = pszValue; }
	break;
case 0x92:			/**** sub c ****/
	if (phase & 1) { sub(a,c,0);a = pszValue; }
	break;
case 0x93:			/**** sub d ****/
	if (phase & 1) { sub(a,d,0);a = pszValue; }
	break;
case 0x94:			/**** sub e ****/
	if (phase & 1) { sub(a,e,0);a = pszValue; }
	break;
case 0x95:			/**** sub h ****/
	if (phase & 1) { sub(a,h,0);a = pszValue; }
	break;
case 0x96:			/**** sub l ****/
	if (phase & 1) { sub(a,l,0);a = pszValue; }
	break;
case 0x97:			/**** sub m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; sub(a,m,0); a = pszValue; }
	break;
case 0x98:			/**** sbb a ****/
	if (phase & 1) { sub(a,a,carry);a = pszValue; }
	break;
case 0x99:			/**** sbb b ****/
	if (phase & 1) { sub(a,b,carry);a = pszValue; }
	break;
case 0x9a:			/**** sbb c ****/
	if (phase & 1) { sub(a,c,carry);a = pszValue; }
	break;
case 0x9b:			/**** sbb d ****/
	if (phase & 1) { sub(a,d,carry);a = pszValue; }
	break;
case 0x9c:			/**** sbb e ****/
	if (phase & 1) { sub(a,e,carry);a = pszValue; }
	break;
case 0x9d:			/**** sbb h ****/
	if (phase & 1) { sub(a,h,carry);a = pszValue; }
	break;
case 0x9e:			/**** sbb l ****/
	if (phase & 1) { sub(a,l,carry);a = pszValue; }
	break;
case 0x9f:			/**** sbb m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; sub(a,m,carry); a = pszValue; }
	break;
case 0xa0:			/**** and a ****/
	if (phase & 1) { a = pszValue = a & a ; carry = 0; }
	break;
case 0xa1:			/**** and b ****/
	if (phase & 1) { a = pszValue = a & b ; carry = 0; }
	break;
case 0xa2:			/**** and c ****/
	if (phase & 1) { a = pszValue = a & c ; carry = 0; }
	break;
case 0xa3:			/**** and d ****/
	if (phase & 1) { a = pszValue = a & d ; carry = 0; }
	break;
case 0xa4:			/**** and e ****/
	if (phase & 1) { a = pszValue = a & e ; carry = 0; }
	break;
case 0xa5:			/**** and h ****/
	if (phase & 1) { a = pszValue = a & h ; carry = 0; }
	break;
case 0xa6:			/**** and l ****/
	if (phase & 1) { a = pszValue = a & l ; carry = 0; }
	break;
case 0xa7:			/**** and m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ;  a = pszValue = a & mb ; carry = 0; }
	break;
case 0xa8:			/**** xra a ****/
	if (phase & 1) { a = pszValue = a ^ a ; carry = 0; }
	break;
case 0xa9:			/**** xra b ****/
	if (phase & 1) { a = pszValue = a ^ b ; carry = 0; }
	break;
case 0xaa:			/**** xra c ****/
	if (phase & 1) { a = pszValue = a ^ c ; carry = 0; }
	break;
case 0xab:			/**** xra d ****/
	if (phase & 1) { a = pszValue = a ^ d ; carry = 0; }
	break;
case 0xac:			/**** xra e ****/
	if (phase & 1) { a = pszValue = a ^ e ; carry = 0; }
	break;
case 0xad:			/**** xra h ****/
	if (phase & 1) { a = pszValue = a ^ h ; carry = 0; }
	break;
case 0xae:			/**** xra l ****/
	if (phase & 1) { a = pszValue = a ^ l ; carry = 0; }
	break;
case 0xaf:			/**** xra m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ;  a = pszValue = a ^ mb ; carry = 0; }
	break;
case 0xb0:			/**** ora a ****/
	if (phase & 1) { a = pszValue = a | a ; carry = 0; }
	break;
case 0xb1:			/**** ora b ****/
	if (phase & 1) { a = pszValue = a | b ; carry = 0; }
	break;
case 0xb2:			/**** ora c ****/
	if (phase & 1) { a = pszValue = a | c ; carry = 0; }
	break;
case 0xb3:			/**** ora d ****/
	if (phase & 1) { a = pszValue = a | d ; carry = 0; }
	break;
case 0xb4:			/**** ora e ****/
	if (phase & 1) { a = pszValue = a | e ; carry = 0; }
	break;
case 0xb5:			/**** ora h ****/
	if (phase & 1) { a = pszValue = a | h ; carry = 0; }
	break;
case 0xb6:			/**** ora l ****/
	if (phase & 1) { a = pszValue = a | l ; carry = 0; }
	break;
case 0xb7:			/**** ora m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ;  a = pszValue = a | mb ; carry = 0; }
	break;
case 0xb8:			/**** cmp a ****/
	if (phase & 1) { sub(a,a,0); }
	break;
case 0xb9:			/**** cmp b ****/
	if (phase & 1) { sub(a,b,0); }
	break;
case 0xba:			/**** cmp c ****/
	if (phase & 1) { sub(a,c,0); }
	break;
case 0xbb:			/**** cmp d ****/
	if (phase & 1) { sub(a,d,0); }
	break;
case 0xbc:			/**** cmp e ****/
	if (phase & 1) { sub(a,e,0); }
	break;
case 0xbd:			/**** cmp h ****/
	if (phase & 1) { sub(a,h,0); }
	break;
case 0xbe:			/**** cmp l ****/
	if (phase & 1) { sub(a,l,0); }
	break;
case 0xbf:			/**** cmp m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; sub(a,m,0); }
	break;
case 0xc0:			/**** mov a,a ****/
	if (phase & 1) { a = a; }
	break;
case 0xc1:			/**** mov a,b ****/
	if (phase & 1) { a = b; }
	break;
case 0xc2:			/**** mov a,c ****/
	if (phase & 1) { a = c; }
	break;
case 0xc3:			/**** mov a,d ****/
	if (phase & 1) { a = d; }
	break;
case 0xc4:			/**** mov a,e ****/
	if (phase & 1) { a = e; }
	break;
case 0xc5:			/**** mov a,h ****/
	if (phase & 1) { a = h; }
	break;
case 0xc6:			/**** mov a,l ****/
	if (phase & 1) { a = l; }
	break;
case 0xc7:			/**** mov a,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; a = mb; }
	break;
case 0xc8:			/**** mov b,a ****/
	if (phase & 1) { b = a; }
	break;
case 0xc9:			/**** mov b,b ****/
	if (phase & 1) { b = b; }
	break;
case 0xca:			/**** mov b,c ****/
	if (phase & 1) { b = c; }
	break;
case 0xcb:			/**** mov b,d ****/
	if (phase & 1) { b = d; }
	break;
case 0xcc:			/**** mov b,e ****/
	if (phase & 1) { b = e; }
	break;
case 0xcd:			/**** mov b,h ****/
	if (phase & 1) { b = h; }
	break;
case 0xce:			/**** mov b,l ****/
	if (phase & 1) { b = l; }
	break;
case 0xcf:			/**** mov b,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; b = mb; }
	break;
case 0xd0:			/**** mov c,a ****/
	if (phase & 1) { c = a; }
	break;
case 0xd1:			/**** mov c,b ****/
	if (phase & 1) { c = b; }
	break;
case 0xd2:			/**** mov c,c ****/
	if (phase & 1) { c = c; }
	break;
case 0xd3:			/**** mov c,d ****/
	if (phase & 1) { c = d; }
	break;
case 0xd4:			/**** mov c,e ****/
	if (phase & 1) { c = e; }
	break;
case 0xd5:			/**** mov c,h ****/
	if (phase & 1) { c = h; }
	break;
case 0xd6:			/**** mov c,l ****/
	if (phase & 1) { c = l; }
	break;
case 0xd7:			/**** mov c,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; c = mb; }
	break;
case 0xd8:			/**** mov d,a ****/
	if (phase & 1) { d = a; }
	break;
case 0xd9:			/**** mov d,b ****/
	if (phase & 1) { d = b; }
	break;
case 0xda:			/**** mov d,c ****/
	if (phase & 1) { d = c; }
	break;
case 0xdb:			/**** mov d,d ****/
	if (phase & 1) { d = d; }
	break;
case 0xdc:			/**** mov d,e ****/
	if (phase & 1) { d = e; }
	break;
case 0xdd:			/**** mov d,h ****/
	if (phase & 1) { d = h; }
	break;
case 0xde:			/**** mov d,l ****/
	if (phase & 1) { d = l; }
	break;
case 0xdf:			/**** mov d,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; d = mb; }
	break;
case 0xe0:			/**** mov e,a ****/
	if (phase & 1) { e = a; }
	break;
case 0xe1:			/**** mov e,b ****/
	if (phase & 1) { e = b; }
	break;
case 0xe2:			/**** mov e,c ****/
	if (phase & 1) { e = c; }
	break;
case 0xe3:			/**** mov e,d ****/
	if (phase & 1) { e = d; }
	break;
case 0xe4:			/**** mov e,e ****/
	if (phase & 1) { e = e; }
	break;
case 0xe5:			/**** mov e,h ****/
	if (phase & 1) { e = h; }
	break;
case 0xe6:			/**** mov e,l ****/
	if (phase & 1) { e = l; }
	break;
case 0xe7:			/**** mov e,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; e = mb; }
	break;
case 0xe8:			/**** mov h,a ****/
	if (phase & 1) { h = a; }
	break;
case 0xe9:			/**** mov h,b ****/
	if (phase & 1) { h = b; }
	break;
case 0xea:			/**** mov h,c ****/
	if (phase & 1) { h = c; }
	break;
case 0xeb:			/**** mov h,d ****/
	if (phase & 1) { h = d; }
	break;
case 0xec:			/**** mov h,e ****/
	if (phase & 1) { h = e; }
	break;
case 0xed:			/**** mov h,h ****/
	if (phase & 1) { h = h; }
	break;
case 0xee:			/**** mov h,l ****/
	if (phase & 1) { h = l; }
	break;
case 0xef:			/**** mov h,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; h = mb; }
	break;
case 0xf0:			/**** mov l,a ****/
	if (phase & 1) { l = a; }
	break;
case 0xf1:			/**** mov l,b ****/
	if (phase & 1) { l = b; }
	break;
case 0xf2:			/**** mov l,c ****/
	if (phase & 1) { l = c; }
	break;
case 0xf3:			/**** mov l,d ****/
	if (phase & 1) { l = d; }
	break;
case 0xf4:			/**** mov l,e ****/
	if (phase & 1) { l = e; }
	break;
case 0xf5:			/**** mov l,h ****/
	if (phase & 1) { l = h; }
	break;
case 0xf6:			/**** mov l,l ****/
	if (phase & 1) { l = l; }
	break;
case 0xf7:			/**** mov l,m ****/
	if (phase & 2) { ma = (h << 8) | l ; read() ; l = mb; }
	break;
case 0xf8:			/**** mov m,a ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = a ; write(); }
	break;
case 0xf9:			/**** mov m,b ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = b ; write(); }
	break;
case 0xfa:			/**** mov m,c ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = c ; write(); }
	break;
case 0xfb:			/**** mov m,d ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = d ; write(); }
	break;
case 0xfc:			/**** mov m,e ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = e ; write(); }
	break;
case 0xfd:			/**** mov m,h ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = h ; write(); }
	break;
case 0xfe:			/**** mov m,l ****/
	if (phase & 2) { ma = (h << 8) | l ; mb = l ; write(); }
	break;
case 0xff:			/**** hlt ****/
	if (phase & 1) { halt = 1; }
	break;
