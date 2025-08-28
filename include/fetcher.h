#ifndef FETCHER_H
#define FETCHER_H

typedef struct fetched_instruction
{
    unsigned char mode;
    unsigned char opcode;
    unsigned char operand;
} FETCHED_INSTRUCTION;

extern FETCHED_INSTRUCTION fetched_instruction;

FETCHED_INSTRUCTION fetch_instruction();

#endif //FETCHER_H