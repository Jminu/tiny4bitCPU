#include "util.h"
#include <stdlib.h>
#include <string.h>

unsigned char extract_address(char* parsed_command)
{
    unsigned char* extracted_memory_address = (char*)malloc(sizeof(char) * 16);
    unsigned char* addr = extracted_memory_address;

    for (int i = 1; i < strlen(parsed_command) - 1; i++)
    {
        *addr = parsed_command[i];
        addr++;
    }
    *addr = '\0';
    unsigned char address = atoi(extracted_memory_address);
    free(extracted_memory_address);

    return address;
}
