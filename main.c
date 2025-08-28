#include "register.h"
#include <stdio.h>
#include "memory.h"
#include "assembler.h"
#include "fetcher.h"
#include "decoder.h"
#include "filesystem.h"

int main(void)
{
    char* code = NULL;
    char** parsed_code = NULL;

    char* file_name;

    printf("파일이름 입력 : ");
    scanf("%s", file_name); //유저에게서 파일이름 받음
    getchar(); //버퍼에서 개행문자 빼줌

    int fd = create_new_file(file_name); //파일 생성함
    show_files();

    while (1)
    {
        printf(">>>");
        code = input_command(); //명렁어 입력 ex) MOV R0 5
        write_command_to_file(code, fd); //파일에 작성
        parsed_code = parse_command(code); //코드 파싱
        set_command_to_memory(parsed_code); //코드를 메모리로 load
        fetch_instruction(); //fetch code
        decode(); //decode
        show_memory();
        show_register();
    }
}
