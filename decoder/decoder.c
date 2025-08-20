#include "decoder.h"
#include "../memory/memory.h"
#include "../register/register.h"
#include "../fetcher/fetcher.h"
#include "../executor/executor.h"
#include "../isa/isa.h"
#include <stdio.h>


//fetch해온 명령어를 해석
void decode()
{
    FETCHED_INSTRUCTION fetched_instruction;

    unsigned char mode = fetched_instruction.mode;
    unsigned char opcode = fetched_instruction.opcode;
    unsigned char operand = fetched_instruction.operand;

    unsigned char PC_temp = PC;

    switch (opcode)
    {
    case MOV: //MOV
        if (mode == 0x0) //값 복사 (1byte로 처리)
        {
            // 레지스터 2개 알아냄
            unsigned char dest_reg = (operand >> 2) & 0x3;
            unsigned char src_reg = operand & 0x3;

            unsigned char* dest_reg_address = get_register_address(dest_reg);
            unsigned char* src_reg_address = get_register_address(src_reg);

            mov_execute_copy(dest_reg_address, src_reg_address);
        }
        else //mode == 0x1, 즉시값 사용 0x1 (1바이트: 명령어 + 레지스터,  다음 1바이트: 즉시값)
        {
            unsigned char dest_reg = operand & 0x3;
            unsigned char value = memory[PC_temp + 1] & 0xf;

            unsigned char* dest_reg_address = get_register_address(dest_reg);

            mov_execute_immediate(dest_reg_address, value);
        }
        break;
    case LOAD: //LOAD data from memory to register
        if (mode == 0x0)
        {
            unsigned char dest_reg = operand & 0x3;
            unsigned char* dest_reg_address = get_register_address(dest_reg);
            unsigned char src_memory_address = memory[PC_temp + 1] & 0xf;

            load_execute(dest_reg_address, src_memory_address);
        }
        break;
    case STR: //STR data register to memory
        if (mode == 0x0)
        {
            unsigned char src_reg = operand & 0x3;
            unsigned char* src_reg_address = get_register_address(src_reg);
            unsigned char dest_memory_address = memory[PC_temp + 1] & 0xf; //메모리의 어디에 저장할지 주소를 가져옴

            store_execute(src_reg_address, dest_memory_address);
        }
        break;
    case ADD: //ADD command
        if (mode == 0x0)
        {
            unsigned char dest_reg = (operand >> 2) & 0x3; //목적 레지스터 두번 right shift한다음 하위 2개만 추출
            unsigned char src_reg = operand & 0x3; //그냥 하위 2개만 추출

            add_execute(get_register_address(dest_reg), get_register_address(src_reg));
        }
        break;
    case SUB: //SUB command
        if (mode == 0x0)
        {
            unsigned char dest_reg = (operand >> 2) & 0x3;
            unsigned char src_reg = operand & 0x3;

            sub_execute(get_register_address(dest_reg), get_register_address(src_reg));
        }
        break;
    case JMP: //JMP command
        if (mode == 0x0) //0x00모드는 절대주소로 점프
        {
            //주소는 0~15까지만 존재한다.
            unsigned char dest_memory_address = operand; //JMP는 단일항 연산자, 그냥 operand의 값이 점프 할 주소임
            jmp_execute(dest_memory_address); //점프실행
        }
        break;
    case JEQ: //JEQ command
        if (mode == 0x0)
        {
            unsigned char dest_memory_address = operand; //점프할 주소
            jeq_execute(dest_memory_address); //JEQ실행
        }
        break;
    case HLT: //HLT명령어는 피연산자가 필요없다. 상위 4비트만 추출하면됨=opcode
        if (mode == 0x0)
        {
            hlt_execute();
        }
        break;
    }
}
