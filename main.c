#include "register.h"
#include <stdio.h>
#include "memory.h"
#include "assembler.h"
#include "fetcher.h"
#include "decoder.h"
#include "filesystem.h"
#include "display.h"
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    ncurse_init(); // ncurse 초기화

    char* code = NULL; // 사용자가 입력한 코드
    char** parsed_code = NULL; // 파싱된 사용자 코드
    char file_name[100]; // 저장할 asm파일 이름

    mvprintw(1, 2, "Input FileName: ");
    getstr(file_name);

    int fd = create_new_file(file_name); //파일 생성함
    move(1, 2);
    clrtoeol();
    mvprintw(1, 2, "%d", fd);
    sleep(3);
    //show_files();


    while (1)
    {
        // 화면 초기화
        clear();

        // 메모리 상태, 레지스터 상태 표시
        draw_memory_view();
        draw_register_view(21, 2);

        // 명령어 입력
        mvprintw(23, 2, ">>> ");

        // 화면 업데이트
        refresh();
        code = input_command();

        if (strcmp(code, "quit") == 0)
        {
            break;
        }

        write_command_to_file(code, fd);
        parsed_code = parse_command(code);
        set_command_to_memory(parsed_code);
        fetch_instruction();
        decode();
    }

    endwin();
    return 0;
}
