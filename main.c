#include "register/register.h"
#include <stdio.h>
#include "cpu/cpu.h"
#include "memory/memory.h"


int main(void)
{
    set_register(&s_R0, 14);
    store_memory(&s_R0, &memory[0]);

    return 0;
}