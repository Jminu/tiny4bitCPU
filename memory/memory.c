#include "memory.h"
#include "../fetcher/fetcher.h"
#include <string.h>
#include "../register/register.h"
#include <stdlib.h>
#include <stdio.h>

//16byte 메모리 정의
unsigned char memory[16] = {0};

void set_command_to_memory(char** parsed_command)
{
    if (strcmp(parsed_command[0], "MOV") == 0) //MOV : 0000, 즉시값 MOV : 1000
    {
        if (parsed_command[2][0] > 48 && parsed_command[2][0] < 57) //2번째 인자가 정수라면, '즉시값'
        {
            unsigned char immediate_value = atoi(parsed_command[2]);
            unsigned char dest_reg = get_register_code(parsed_command[1]);

            memory[PC] = 0x80 | dest_reg;
            PC++;
            memory[PC] = immediate_value;
            PC++;
        }
        else //2번째 인자가 레지스터 이름이면, '값복사'
        {
            unsigned char dest_reg = get_register_code(parsed_command[1]); //목적 레지스터 코드
            unsigned char src_reg = get_register_code(parsed_command[2]); //소스 레지스터 코드

            memory[PC] = (0x0 << 4) | ((dest_reg & 0x03) << 2) | src_reg & 0x03; //ex) 0000 0111: MOV R1 R3
            PC++;
        }
    }
}

void show_memory()
{
    for(int i = 0; i < 16; i++)
    {
        printf("=================\n");
        printf("0x%x\n", memory[i]);
    }
    printf("=================\n");
}