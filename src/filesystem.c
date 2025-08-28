#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ncurses.h>

static int fd;

//파일 생성하는 함수
int create_new_file(char* path) //path: 파일 경로
{
    //파일 생성, read, write전용으로
    fd = open(path, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }
    mvprintw(1, 2, "File created successfully");
    return fd; //파일디스크립터 반환
}

int open_existing_file(char* path)
{
    fd = open(path, O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }
    return fd;
}

void save_file_and_quit(int fd)
{
    if (fd != -1) //인자로 받은 fd가 정상이라면
    {
        close(fd); //파일 닫는다.
        printf("file close and save successfully!\n");
    }
}

//사용자가 어셈블리 명령어를 입력하면, 파일에 쓴다
void write_command_to_file(char* command_by_user, int fd) //인자1: 사용자가입력한 명령어, 인자2: 사용중인 파일 디스크립터
{
    if (fd == -1)
    {
        perror("Error opening file");
        exit(-1); //비정상종료
    }

    char buffer[80]; //버퍼를 생성
    bzero(buffer, 80);
    strcpy(buffer, command_by_user); //버퍼에 넣어두고
    write(fd, buffer, strlen(buffer)); //파일에 명령어를 씀
    write(fd, "\n", 1); //개행문자 추가
}

int get_current_fd()
{
    return fd;
}

//유저가 생성한 소스코드파일을 보여준다
void show_files()
{
    DIR* directory;
    struct dirent* entry;

    // 현재 디렉토리를 엽니다. 만약 다른 디렉토리라면 경로를 지정하세요.
    directory = opendir(".");
    if (directory == NULL)
    {
        perror("디렉토리 열기 실패");
        return;
    }

    printf("'.asm' 파일 목록:\n");
    // 디렉토리 내의 항목을 순회합니다.
    while ((entry = readdir(directory)) != NULL)
    {
        // 일반 파일인지 확인합니다.
        if (entry->d_type == DT_REG)
        {
            char* filename = entry->d_name;
            size_t len = strlen(filename);
            // 파일 이름 길이가 4 이상이어야 ".asm" 확장자가 존재할 수 있음
            if (len >= 4 && strcmp(filename + len - 4, ".asm") == 0)
            {
                printf("%s\n", filename);
            }
        }
    }
    closedir(directory);
}
