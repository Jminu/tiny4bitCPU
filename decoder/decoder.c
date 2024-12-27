#include "decoder.h"
#include "../memory/memory.h"
#include "../register/register.h"
#include "../fetcher/fetcher.h"
#include "../executor/executor.h"


//fetch해온 명령어를 해석
void decode()
{
    unsigned char mode = fetched_instruction.mode;
    unsigned char opcode = fetched_instruction.opcode;
    unsigned char operand = fetched_instruction.operand;

    switch (opcode)
    {
    case 0x00: //MOV
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
            unsigned char value = memory[PC + 1] & 0xf;

            unsigned char* dest_reg_address = get_register_address(dest_reg);

            mov_execute_immediate(dest_reg_address, value);
        }
    }
}
