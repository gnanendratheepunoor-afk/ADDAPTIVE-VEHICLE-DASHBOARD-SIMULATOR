#include "header.h"

void uart0_init(void)
{
    PINSEL0 |= 0x00000005;

    U0LCR = 0x83;
    U0DLL = 97;
    U0DLM = 0;

    U0LCR = 0x03;
    U0FCR = 0x07;
}

void uart0_tx(char ch)
{
    while(!(U0LSR & 0x20));

    U0THR = ch;
}

void uart0_string(char *s)
{
    while(*s)
    {
        uart0_tx(*s++);
    }
}

void uart0_num(unsigned int n)
{
    char a[10];
    int i=0;

    if(n==0)
    {
        uart0_tx('0');
        return;
    }

    while(n>0)
    {
        a[i++]=n%10+'0';
        n=n/10;
    }

    while(i>0)
    {
        uart0_tx(a[--i]);
    }
}