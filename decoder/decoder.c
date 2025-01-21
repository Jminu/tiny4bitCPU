#include "decoder.h"
#include "../memory/memory.h"
#include "../register/register.h"
#include "../fetcher/fetcher.h"
#include "../executor/executor.h"
#include <stdio.h>


//fetch해온 명령어를 해석
void decode()
{
    unsigned char mode = fetched_instruction.mode;
    unsigned char opcode = fetched_instruction.opcode;
    unsigned char operand = fetched_instruction.operand;

    unsigned char PC_temp = PC;

    switch (opcode)
    {
    case 0x0: //MOV
        if (mode == 0x00) //값 복사 (1byte로 처리)
        {
            unsigned char dest_reg = (operand >> 2) & 0x3;
            unsigned char src_reg = operand & 0x3;

            unsigned char* dest_reg_address = get_register_address(dest_reg);
            unsigned char* src_reg_address = get_register_address(src_reg);

            mov_execute_copy(dest_reg_address, src_reg_address);
        }
        else //즉시값 사용 0x1 (1바이트: 명령어 + 레지스터,  다음 1바이트: 즉시값)
        {
            unsigned char dest_reg = operand & 0x3;
            unsigned char value = memory[PC_temp + 1] & 0xf;

            unsigned char* dest_reg_address = get_register_address(dest_reg);

            mov_execute_immediate(dest_reg_address, value);
        }
        break;
    case 0x1: //LOAD data from memory to register
        if (mode == 0x00)
        {
            unsigned char dest_reg = operand & 0x3;
            unsigned char* dest_reg_address = get_register_address(dest_reg);
            unsigned char src_memory_address = memory[PC_temp + 1] & 0xf;

            load_execute(dest_reg_address, src_memory_address);
        }
        break;
    case 0x2: //STR data register to memory
        if (mode == 0x00)
        {
            unsigned char src_reg = operand & 0x3;
            unsigned char* src_reg_address = get_register_address(src_reg);
            unsigned char dest_memory_address = memory[PC_temp + 1] & 0xf; //메모리의 어디에 저장할지 주소를 가져옴

            store_execute(src_reg_address, dest_memory_address);
        }
        break;
    case 0x3: //ADD command
        if (mode == 0x00)
        {
            unsigned char dest_reg = (operand >> 2) & 0x3; //목적 레지스터 두번 right shift한다음 하위 2개만 추출
            unsigned char src_reg = operand & 0x3; //그냥 하위 2개만 추출

            add_execute(get_register_address(dest_reg), get_register_address(src_reg));
        }
        break;
    case 0x4: //SUB command
        if (mode == 0x00)
        {
            unsigned char dest_reg = (operand >> 2) & 0x3;
            unsigned char src_reg = operand & 0x3;

            sub_execute(get_register_address(dest_reg), get_register_address(src_reg));
        }
        break;
    case 0x5: //JMP command

    }
}
