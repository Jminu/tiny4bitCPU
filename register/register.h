#ifndef REGISTER_H
#define REGISTER_H

//하위 4개의 비트만 필요하므로 상위 4개의 비트는 무시하도록 해야한다. -> bit mask사용
#define BIT_MASK 0x0f //상위 4개 비트 무시

//extern으로 외부에서 사용 가능하도록
extern unsigned char R0;
extern unsigned char R1;
extern unsigned char R2;
extern unsigned char R3;

extern unsigned char PC; //프로그램 카운터

void set_register_immediate(unsigned char* reg, unsigned char value);
void set_register_copy(unsigned char* reg1, unsigned char* reg2);
unsigned char get_register_code(unsigned char* reg);

#endif //REGISTER_H
