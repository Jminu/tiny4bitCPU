#ifndef MEMORY_H
#define MEMORY_H

//메인메모리는 총 16바이트이다.
//4bit 컴퓨터이기 때문에, 0~2^4-1개의 주소 접근가능
//메모리는 번지당 1byte임

extern unsigned char memory[16]; //16byte


#endif //MEMORY_H