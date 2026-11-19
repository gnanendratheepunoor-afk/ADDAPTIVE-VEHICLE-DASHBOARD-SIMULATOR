#include "header.h"

extern void can1_receive(void) __irq;

int main(void)
{
    uart0_init();
    can1_init();

    IODIR0 |= (1<<10) |
              (1<<11) |
              (1<<12);

    VICIntEnable = (1<<26);

    VICVectCntl0 = 0x20 | 26;

    VICVectAddr0 = (unsigned int)can1_receive;

    C1IER = 1;

    while(1)
    {
        if(headlight)
            IOSET0 = (1<<10);
        else
            IOCLR0 = (1<<10);

        if(left_indicator)
            IOSET0 = (1<<11);
        else
            IOCLR0 = (1<<11);

        if(right_indicator)
            IOSET0 = (1<<12);
        else
            IOCLR0 = (1<<12);
    }
}