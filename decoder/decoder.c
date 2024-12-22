#include "decoder.h"
#include "../memory/memory.h"
#include "../register/register.h"
#include "../fetcher/fetcher.h"
#include "../cpu/cpu.h"

void decoder()
{
    unsigned char mode = fetched_instruction.mode;
    unsigned char opcode = fetched_instruction.opcode;
    unsigned char operand = fetched_instruction.operand;

    switch (opcode)
    {
    case 0x00: //MOV
        if (mode == 0x00) //값 복사 (1byte로 처리)
        {
            unsigned char dest = (operand >> 2) & 0x3; //operand중에서 상위 2비트 추출
            unsigned char source = operand & 0x3; //operand에서 하위 2비트 추출

            set_register_copy(&dest, &source); //source의 값을 dest로 복사
        }
        else //즉시값 사용 (1바이트: 명령어 + 레지스터,  다음 1바이트: 즉시값)
        {
            unsigned char dest = operand;
            unsigned char value = memory[PC + 1]; //다음 주소에서 데이터 가져옴
            set_register_immediate(&dest, value);
        }
    case 0x01: //LOAD
        unsigned char dest_reg = operand;
        unsigned char source_mem_address = PC + 1; //메모리의 데이터는 현재 pc의 다음주소에
        load_register(&dest_reg, source_mem_address); //레지스터에 load
    case 0x02: //STR

    case 0x03:
    }
}
