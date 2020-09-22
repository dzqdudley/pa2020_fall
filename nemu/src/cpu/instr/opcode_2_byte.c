#include "cpu/instr.h"

make_instr_func(opcode_2_byte)
{
	int len = 1;
	uint8_t op = instr_fetch(eip + 1, 1);
	print_asm_1("op","",len,&op);
#ifdef NEMU_REF_INSTR
	len += __ref_opcode_2_byte_entry[op](eip + 1, op);
#else
	len += opcode_2_byte_entry[op](eip + 1, op);
#endif
	return len;
}
