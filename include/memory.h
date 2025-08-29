#ifndef MEMORY_H
#define MEMORY_H

//메인메모리는 총 16바이트이다.
//4bit 컴퓨터이기 때문에, 0~2^4-1개의 주소 접근가능
//메모리는 번지당 1byte임

#define MEMORY_SIZE 16

extern unsigned char memory[MEMORY_SIZE]; //16byte
void set_command_to_memory(char** parsed_command);

#endif //MEMORY_H
