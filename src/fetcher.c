#include "fetcher.h"
#include "memory.h"
#include "register.h"

FETCHED_INSTRUCTION fetch_instruction()
{
    FETCHED_INSTRUCTION fetched_instruction = {0, 0, 0};

    unsigned char read_bytes = memory[PC]; // 한 바이트 읽어서, mode, opcode, operand로 나눈다
    unsigned char mode_temp = (read_bytes & 0x80) >> 7;
    unsigned char opcode_temp = (read_bytes & 0x70) >> 4;
    unsigned char operand_temp = read_bytes & 0xF;

    fetched_instruction.mode = mode_temp;
    fetched_instruction.opcode = opcode_temp;
    fetched_instruction.operand = operand_temp;

    return fetched_instruction; //opcode와 operand를 리턴
}