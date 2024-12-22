// 4bit컴퓨터이므로 레지스터 하나가 4비트이다.
// 4bit레지스터 4개를 사용한다.
// R0 : 기본 연산 레지스터
// R1 : 데이터 보관용 레지스터
// R2 : 중간 결과 레지스터
// R3 : 비교 or 조건부 점프 레지스터
#include "register.h"

//register.h에 extern변수를 정의
unsigned char R0 = 0;
unsigned char R1 = 0;
unsigned char R2 = 0;
unsigned char R3 = 0;

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
