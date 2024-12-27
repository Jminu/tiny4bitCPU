#include "memory.h"
#include "../fetcher/fetcher.h"
#include <string.h>
#include "../register/register.h"
#include <stdlib.h>
#include <stdio.h>

//16byte 메모리 정의
unsigned char memory[16] = {0};

//나눠진 어셈블리 코드를 메모리에 저장한다
void set_command_to_memory(char** parsed_command)
{
    if (strcmp(parsed_command[0], "MOV") == 0) //MOV : 0000, 즉시값 MOV : 1000
    {
        if (parsed_command[2][0] > 48 && parsed_command[2][0] < 57) //2번째 인자가 정수라면, '즉시값'
        {
            unsigned char immediate_value = atoi(parsed_command[2]);
            unsigned char dest_reg = get_register_code(parsed_command[1]);

            memory[PC] = 0x80 | dest_reg; //0x80 = 1000 (즉시값 MOV)
            memory[PC + 1] = immediate_value;
        }
        else //2번째 인자가 레지스터 이름이면, '값복사'
        {
            unsigned char dest_reg = get_register_code(parsed_command[1]); //목적 레지스터 코드
            unsigned char src_reg = get_register_code(parsed_command[2]); //소스 레지스터 코드

            memory[PC] = (0x0 << 4) | ((dest_reg & 0x03) << 2) | src_reg & 0x03; //ex) 0000 0111: MOV R1 R3
        }
    }
    else if (strcmp(parsed_command[0], "STR") == 0) //STR: 0010
    {
        char* extracted_memory_address = (char*)malloc(sizeof(char) * 16);
        unsigned char src_reg = get_register_code(parsed_command[1]);

        memory[PC] = 0x20 | src_reg; //0x20 = 0010 (STR 명령어)
        //만약 STR R3 [14]면, memory[i] = 0010 0011 이다.

        //저장할 메모리 주소를 추출한다. [15]라면 15를 추출해야함
        for (int i = 1; i < strlen(parsed_command[2]) - 1; i++)
        {
            char temp[2] = {parsed_command[2][i], '\0'};
            strcat(extracted_memory_address, temp);
        }

        unsigned char address = atoi(extracted_memory_address);

        //추출한 메모리 주소에 레지스터값을 저장
        memory[address] = src_reg;
    }
}


//메모리 상태 2진수로 보여준다.
void show_memory()
{
    int num = 0;
    printf("========================\n");
    printf("%-6s %-8s %s\n", "Index", "PC", "Binary"); // 헤더 추가
    printf("========================\n");

    for (int i = 0; i < 16; i++)
    {
        char pc_marker[4] = " "; // PC 표시용
        if (PC == i)
        {
            snprintf(pc_marker, sizeof(pc_marker), "PC");
        }

        printf("%-6d %-6s", i, pc_marker); // Index와 PC 표시

        unsigned char arr[8] = {0};
        num = memory[i];
        for (int j = 7; j >= 0; j--)
        {
            if (num != 0)
            {
                arr[j] = num % 2;
                num = num / 2;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            if (j == 4)
                printf(" "); // 4비트 단위로 공백 추가
            printf("%d", arr[j]);
        }
        printf("\n");
    }
    printf("========================\n");
}

