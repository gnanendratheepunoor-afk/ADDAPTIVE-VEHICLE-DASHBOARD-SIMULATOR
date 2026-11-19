#include "header.h"

void adc_init(void)
{
    PINSEL1 |= (1<<22) | (1<<24) | (1<<26);

    AD0CR = 0x00200600;
}

unsigned int adc_read(unsigned int channel)
{
    unsigned int result;

    AD0CR &= ~(0xFF);

    AD0CR |= (1<<channel);
    AD0CR |= (1<<24);

    while(!(AD0GDR & (1<<31));

    result = (AD0GDR>>6)&0x3FF;

    return result;
}