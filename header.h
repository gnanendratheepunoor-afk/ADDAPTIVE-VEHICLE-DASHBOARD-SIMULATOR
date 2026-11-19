#ifndef HEADER_H
#define HEADER_H

#include <lpc2129.h>

void delay_ms(unsigned int);
void uart0_init(void);
void uart0_tx(char);
void uart0_string(char *);
void uart0_num(unsigned int);

void adc_init(void);
unsigned int adc_read(unsigned int);

void can1_init(void);
void can1_tx(unsigned int, unsigned int, unsigned int);

void eint_init(void);
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
#endif