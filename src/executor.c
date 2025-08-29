#include "../include/executor.h"
#include <stdlib.h>
#include "register.h"
#include "memory.h"
#include "filesystem.h"

extern unsigned char R0;
extern unsigned char R1;
extern unsigned char R2;
extern unsigned char R3;
extern unsigned char SR;

void mov_execute_copy(unsigned char* dest_reg, unsigned char* src_reg)
{
    set_register_copy(dest_reg, src_reg);
    PC += 1;
}

void mov_execute_immediate(unsigned char* dest_reg, unsigned char value)
{
    set_register_immediate(dest_reg, value);
    PC += 2;
}

void store_execute(unsigned char* source_reg, unsigned char memory_address)
{
    memory[memory_address] = *source_reg; //메모리에 레지스터값 저장
    PC += 2;
}

void load_execute(unsigned char* dest_reg, unsigned char memory_address)
{
    *dest_reg = memory[memory_address];
    PC += 2;
}

void add_execute(unsigned char* dest_reg, unsigned char* src_reg)
{
    *dest_reg = *dest_reg + *src_reg;
    PC += 1;
}

void sub_execute(unsigned char* dest_reg, unsigned char* src_reg)
{
    *dest_reg = *dest_reg - *src_reg;
    if (*dest_reg == 0) //만약, SUB R0 R1 했을때, 0이라면 R0과 R1이 같다
    {
        SR = 1; //상태 레지스터를 1로 만든다.
    }
    PC += 1;
}

void jmp_execute(unsigned char memory_address_to_jump)
{
    PC = memory_address_to_jump;
}

void jeq_execute(unsigned char memory_address_to_jeq)
{
    if (SR == 1) //상태 레지스터가 1이면
    {
        jmp_execute(memory_address_to_jeq); //특정 주소로 PC이동
    }
    else
    {
        PC += 1;
    }
}

/* 이거 방어코드 추가해야함 */
int hlt_execute()
{
    int current_fd = get_current_fd(); //현재 열고있는 파일 디스크립터
    save_file_and_quit(current_fd); //파일 닫고

    return 1;
}
