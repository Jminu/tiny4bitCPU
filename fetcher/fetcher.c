#include "fetcher.h"
#include "../memory/memory.h"
#include "../register/register.h"

FETCHED_INSTRUCTION fetched_instruction  = {0, 0, 0};

FETCHED_INSTRUCTION fetch_instruction()
{
    fetched_instruction.opcode = 0;
    fetched_instruction.operand = 0;

    //mode추출
    char mode_temp = memory[PC];
    mode_temp = (mode_temp >> 7) & 0x1; //7 right비트연산 후 상위비트 전부 무시
    fetched_instruction.mode = mode_temp;

    //opcode추출
    char opcode_temp = memory[PC];
    opcode_temp = (opcode_temp >> 4) & 0x7; //상위비트에서 4비트를 하위비트로 내림
    fetched_instruction.opcode = opcode_temp;

    //operand추출
    char operand_temp = memory[PC] & 0xF; //상위 4비트 무시
    fetched_instruction.operand = operand_temp;

    return fetched_instruction; //opcode와 operand를 리턴
}