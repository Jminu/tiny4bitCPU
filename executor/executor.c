#include "executor.h"
#include "../fetcher/fetcher.h"
#include "../register/register.h"
#include "../memory/memory.h"

extern unsigned char R0;
extern unsigned char R1;
extern unsigned char R2;
extern unsigned char R3;

void mov_execute_copy(unsigned char *dest_reg, unsigned char *src_reg)
{
    set_register_copy(dest_reg, src_reg);
    PC += 1;
}

void mov_execute_immediate(unsigned char* dest_reg, unsigned char value)
{
    set_register_immediate(dest_reg, value);
    PC += 2;
}

void store_execute(unsigned char *source_reg, unsigned char memory_address)
{
    memory[memory_address] = *source_reg; //메모리에 레지스터값 저장
    PC += 2;
}