#ifndef CPU_H
#define CPU_H

#define BIT_MASK 0x0f //상위 4개 비트 무시

void load_register(unsigned char* reg, unsigned char* mem_address);
void store_memory(unsigned char* reg, unsigned char* mem_address);

#endif //CPU_H
