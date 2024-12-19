#ifndef CPU_H
#define CPU_H

#define BIT_MASK 0x0f //상위 4개 비트 무시

typedef struct fetched_instruction
{
    char mode;
    char opcode;
    char operand;
} FETCHED_INSTRUNCTION;

FETCHED_INSTRUNCTION fetched_instruction = {0, 0, 0};

void load_register(unsigned char* reg, unsigned char* mem_address);
void store_memory(unsigned char* reg, unsigned char* mem_address);
void fetch_instruction();
void decode_instruction();

#endif //CPU_H
