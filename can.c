#include "header.h"

void can1_init(void)
{
    VPBDIV = 1;

    PINSEL1 |= (1<<18) | (1<<20);

    C1MOD = 1;
    C1BTR = 0x001C001D;
    C1MOD = 0;
}

void can1_tx(unsigned int id,
              unsigned int data1,
              unsigned int data2)
{
    C1TFI1 = 0x00080000;
    C1TID1 = id;
    C1TDA1 = data1;
    C1TDB1 = data2;

    C1CMR = 0x21;

    while(!(C1GSR & (1<<3)));
}