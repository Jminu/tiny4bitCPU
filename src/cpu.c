#include "cpu.h"
#include "memory.h"

void load_register(unsigned char* reg, unsigned char mem_address)
{
    unsigned char temp = memory[mem_address] & 0x0F; //메모리에서 가져온 값 상위4비트 무시
    *reg = temp;
}