#include "register.h"
#include <stdio.h>

int main(void)
{
    set_register(&s_R0, 257);
    printf("%x\n", s_R0);

    return 0;
}