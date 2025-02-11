#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//파일 생성하는 함수
int create_new_file(char* path) //path: 파일 경로
{
    //파일 생성, read, write전용으로
    int fd = open(path, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }
    return fd; //파일디스크립터 반환
}

int open_existing_file(char* path)
{
    int fd = open(path, O_RDWR);
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
    exit(0); //정상종료
}
