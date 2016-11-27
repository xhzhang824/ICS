#include "cpu/exec/template-start.h"

#define instr xor

static void do_execute () {
    DATA_TYPE result = op_dest->val ^ op_src->val;
    DATA_TYPE mask8 = (DATA_TYPE)0xFF;

    OPERAND_W(op_dest, result);

    cpu.ZF = result ? 0 : 1;
    cpu.CF = 0;
    cpu.OF = 0;
    cpu.PF = Check_Parity_Flag(result&mask8);

    cpu.SF = MSB(result);

    print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"
