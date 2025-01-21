#ifndef ISA_H
#define ISA_H

#define MOV 0x0 //레지스터에 저장
#define LOAD 0x1 //메모리값을 register load
#define STR Ox2 //register값을 메모리에 store
#define ADD 0x3 //두 레지스터값 더함
#define SUB 0x4 //두 레지스터값 뺌
#define JMP 0x5 //지정된 메모리 주소로 점프
#define JEQ 0x6 //비교 결과 같으면 점프
#define HLT 0x7 //프로그램 종료



#endif //ISA_H
