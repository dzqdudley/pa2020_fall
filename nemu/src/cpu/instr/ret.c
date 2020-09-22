#include "cpu/instr.h"
/*
Put the implementations of `ret' instructions here.
*/
make_instr_func(ret){
    OPERAND src;
    src.type = OPR_MEM;
    src.data_size = data_size;
    src.addr = cpu.esp;
    operand_read(&src);
    cpu.esp += data_size / 8;
    cpu.eip = src.val;
    if (data_size == 16)
        cpu.eip &= 0xffff;
    print_asm_0("ret","",1);
    return 0;
}