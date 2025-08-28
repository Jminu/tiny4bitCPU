#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include "memory.h"
#include "register.h"
#include "display.h"

void draw_memory_view()
{
    int y = 1;
    int x = 2;

    mvprintw(y++, x, "=====================================");
    mvprintw(y++, x, "%-6s %-8s %s", "Index", "PC", "Binary");
    mvprintw(y++, x, "=====================================");

    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        char pc_marker[8] = "      "; // PC 표시용
        if (PC == i)
        {
            snprintf(pc_marker, sizeof(pc_marker), "PC -> ");
        }

        char bin_str[10]; // "0000 0000" + '\0';
        int memory_val = memory[i];
        dec_to_bin(bin_str, memory_val); // 2진수로 변환


        // printf로 한 줄에 출력하던 것을 mvprintw로 좌표에 맞게 출력
        mvprintw(y++, x, "%-6d %-8s %s", i, pc_marker, bin_str);
    }
    mvprintw(y++, x, "====================================");
}

// 10진수를 2진수로 변환해서 2진수 문자열 배열에 넣음
void dec_to_bin(char* bin_str, unsigned char dec)
{
    bin_str[9] = '\0'; // 끝 과 중간에 삽입
    bin_str[4] = ' ';

    for (int i = 7; i >= 0; i--)
    {
        int idx = i < 4 ? i : i + 1;
        bin_str[idx] = (dec % 2) + '0';
        dec = dec / 2;
    }
}

void ncurse_init()
{
    initscr();
    noecho();
    cbreak();
}
