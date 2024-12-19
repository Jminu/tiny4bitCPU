#include "cpu.h"
#include "../register/register.h"
#include "../memory/memory.h"

void load_register(unsigned char* reg, unsigned char* mem_address)
{
    char temp = *mem_address;
    temp = temp & BIT_MASK;
    *reg = temp;
}

void store_memory(unsigned char* reg, unsigned char* mem_address)
{
    char temp = *reg;
    temp = temp & BIT_MASK; //하위 4비트만 유지
    *mem_address = temp;
}

FETCHED_INSTRUNCTION fetch_instruction(unsigned char* pc)
{
    fetched_instruction.opcode = 0;
    fetched_instruction.operand = 0;

    //mode추출
    char mode_temp = memory[*pc];
    mode_temp = (mode_temp >> 7) & 0x1;
    fetched_instruction.mode = mode_temp;

    //opcode추출
    char opcode_temp = memory[*pc];
    opcode_temp = (opcode_temp >> 4) & 0x7; //상위비트에서 4비트를 하위비트로 내림
    fetched_instruction.opcode = opcode_temp;

    //operand추출
    char operand_temp = memory[*pc] & 0xF;
    fetched_instruction.operand = operand_temp;

    return fetched_instruction; //opcode와 operand를 리턴
}