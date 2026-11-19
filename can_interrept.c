#include "header.h"

unsigned int received_id;
unsigned int received_dataA;
unsigned int received_dataB;

unsigned int temperature;
unsigned int speed;
unsigned int fuel;

unsigned int headlight;
unsigned int left_indicator;
unsigned int right_indicator;

void can1_receive(void) __irq
{
    received_id = C1RID;

    received_dataA = C1RDA;
    received_dataB = C1RDB;

    temperature = received_dataA & 0x3FF;

    speed = (received_dataA>>10)&0x3FF;

    fuel = (received_dataA>>20)&0x3FF;

    headlight = received_dataB & 1;

    left_indicator = (received_dataB>>1)&1;

    right_indicator = (received_dataB>>2)&1;

    C1CMR = 0x04;

    VICVectAddr = 0;

    uart0_string("Temperature: ");
    uart0_num(temperature);

    uart0_string("\r\nSpeed: ");
    uart0_num(speed);

    uart0_string("\r\nFuel: ");
    uart0_num(fuel);

    uart0_string("\r\nHeadlight: ");
    uart0_num(headlight);

    uart0_string("\r\nLeft Indicator: ");
    uart0_num(left_indicator);

    uart0_string("\r\nRight Indicator: ");
    uart0_num(right_indicator);

    uart0_string("\r\n----------------\r\n");
}