#include "header.h"

void eint_init(void)
{
    PINSEL0 |= (1<<3);
    PINSEL0 |= (1<<7);

    PINSEL1 |= (1<<14);

    EXTMODE = 7;
    EXTPOLAR = 0;
}