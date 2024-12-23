#include "register/register.h"
#include <stdio.h>
#include "cpu/cpu.h"
#include "memory/memory.h"
#include "assembler/assembler.h"


int main(void)
{
    char* input_command = NULL;
    char** parsed_command = NULL;

    while(1)
    {
        printf(">>>");
        input_command = input_command(); //명렁어 입력 ex) MOV R0 5
        parsed_command = parsed_command(input_command); //명령어 파싱


    }
}