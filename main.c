#include "register/register.h"
#include <stdio.h>
#include "cpu/cpu.h"
#include "memory/memory.h"
#include "assembler/assembler.h"
#include "fetcher/fetcher.h"
#include "decoder/decoder.h"


int main(void)
{
    char* code = NULL;
    char** parsed_code = NULL;

    while(1)
    {
        printf(">>>");
        code = input_command(); //명렁어 입력 ex) MOV R0 5
        parsed_code = parse_command(code); //코드 파싱
        printf("%s\n %s\n %s\n", parsed_code[0], parsed_code[1], parsed_code[2]);
        set_command_to_memory(parsed_code); //코드를 메모리로 load
        show_memory();
        fetch_instruction(); //fetch code
        decoder(); //decode
    }
}
