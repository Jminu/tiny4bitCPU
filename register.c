// 4bit컴퓨터이므로 레지스터 하나가 4비트이다.
// 4bit레지스터 4개를 사용한다.
// R0 : 기본 연산 레지스터
// R1 : 데이터 보관용 레지스터
// R2 : 중간 결과 레지스터
// R3 : 비교 or 조건부 점프 레지스터
#include "register.h"

//register.h에 extern변수를 정의
unsigned char s_R0 = 0;
unsigned char s_R1 = 0;
unsigned char s_R2 = 0;
unsigned char s_R3 = 0;

//레지스터에 값 설정
void set_register(unsigned char* reg, unsigned char value)
{
    *reg = value;
    *reg &= BIT_MASK; //bit masking을 통한 상위 4개비트 무시
}