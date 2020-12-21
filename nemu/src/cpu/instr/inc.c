#include "cpu/instr.h"
/*
Put the implementations of `inc' instructions here.
*/

static void instr_execute_1op(){
    operand_read(&opr_src);
    print_asm_1("inc","",1+opr_src.data_size/8,&opr_src);
    opr_src.val=alu_add(sign_ext(opr_src.val,opr_src.data_size),1,opr_src.data_size);
    operand_write(&opr_src);
}
make_instr_impl_1op(inc, rm, v);
make_instr_impl_1op(inc, r, v);
