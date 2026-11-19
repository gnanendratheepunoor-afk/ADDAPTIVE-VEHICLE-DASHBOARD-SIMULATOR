#include "header.h"

unsigned int temperature;
unsigned int speed;
unsigned int fuel;

unsigned int headlight;
unsigned int left_indicator;
unsigned int right_indicator;

unsigned int dataA;
unsigned int dataB;

int main(void)
{
    uart0_init();
    adc_init();
    can1_init();
    eint_init();

    while(1)
    {
        temperature = adc_read(0);
        speed = adc_read(1);
        fuel = adc_read(2);

        headlight = (IOPIN0 & (1<<16)) ? 0 : 1;
        left_indicator = (IOPIN0 & (1<<3)) ? 0 : 1;
        right_indicator = (IOPIN0 & (1<<7)) ? 0 : 1;

        dataA = temperature |
                (speed<<10) |
                (fuel<<20);

        dataB = headlight |
                (left_indicator<<1) |
                (right_indicator<<2);

        can1_tx(0x123,dataA,dataB);

        delay_ms(500);
    }
}