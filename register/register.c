// 4bit컴퓨터이므로 레지스터 하나가 4비트이다.
// 4bit레지스터 4개를 사용한다.
// R0 : 기본 연산 레지스터
// R1 : 데이터 보관용 레지스터
// R2 : 중간 결과 레지스터
// R3 : 비교 or 조건부 점프 레지스터
#include "register.h"
#include <string.h>
#include <stdio.h>


//register.h에 extern변수를 정의
unsigned char R0 = 0;
unsigned char R1 = 0;
unsigned char R2 = 0;
unsigned char R3 = 0;

unsigned char SR = 0; //state register, JEQ에서 사용하기 위함

//PC는 execution될때만 움직인다.
//code를 메모리에 load할때, fetch할때, decode할때 등등은 PC의 값을 복사하여 사용한다.
unsigned char PC = 0; //프로그램 카운터

//레지스터에 값 설정(즉시값 설정)
void set_register_immediate(unsigned char* reg, unsigned char value)
{
    *reg = value;
    *reg &= BIT_MASK; //bit masking을 통한 상위 4개비트 무시
}

//레지스터에 값 설정 (레지스터끼리 복사)
void set_register_copy(unsigned char* dest_reg, unsigned char* source_reg)
{
    *dest_reg = *source_reg;
}

unsigned char* get_register_address(unsigned char reg_code)
{
    switch (reg_code)
    {
    case 0x0:
        return &R0;
    case 0x1:
        return &R1;
    case 0x2:
        return &R2;
    case 0x3:
        return &R3;
    case 0x4:
        return &SR;
    default:
        return NULL;
    }
}

unsigned char get_register_code(unsigned char* reg)
{
    if (strcmp(reg, "R0") == 0)
        return 0x0;
    if (strcmp(reg, "R1") == 0)
        return 0x1;
    if (strcmp(reg, "R2") == 0)
        return 0x2;
    if (strcmp(reg, "R3") == 0)
        return 0x3;
    if (strcmp(reg, "SR") == 0)
        return 0x4;
    return -1; //잘못된 레지스터 이름
}

void show_register()
{
    printf("R0: %x R1: %x R2: %x R3: %x SR: %x\n", R0, R1, R2, R3, SR);
}
