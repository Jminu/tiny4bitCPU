#include "assembler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* input_command()
{
    static char command[80];
    fgets(command, sizeof(command), stdin); //공백을 포함하여 입력받음
    command[strlen(command) - 1] = '\0'; //마지막 개행문자 제거하고 NULL로 수정

    return command; //명령어 반환
}

char** parse_command(char* command)
{
    //동적메모리 할당
    char** parsed_command = malloc(3 * sizeof(char*)); //parsed_command -> | 주소1 | 주소2 | 주소 3|
    if (parsed_command == NULL)
    {
        fprintf(stderr, "memory allocation failed!");
        exit(1); //비정상 종료
    }

    int cnt = 0;
    char* ptr = strtok(command, " "); //공백 문자를 기준으로 문자열을 자른다. 포인터를 반환

    while (ptr != NULL && cnt < 3) //최대 3개까지 파싱
    {
        parsed_command[cnt] = ptr; //명령어 저장
        ptr = strtok(NULL, " "); //다음 문자열을 잘라서 포인터 반환
        cnt++;
    }

    while (cnt < 3)
    {
        parsed_command[cnt++] = NULL;
    }

    return parsed_command;
}
