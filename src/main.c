#include "stm8s.h"
#include "milis.h"

#include "delay.h"
#include <stdio.h>
#include "uart1.h"

#define _ISOC99_SOURCE
#define _GNU_SOURCE


void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);

    init_milis();
    init_uart1();
}

void delay_ms(uint16_t ms) {
    uint16_t  i;
    for (i=0; i<ms; i = i+1){
        _delay_us(250);
        _delay_us(248);
        _delay_us(250);
        _delay_us(250);
    }
}

int main(void)
{
    uint16_t pocet = 0;

    setup();

    while (1) {

        if(GPIO_ReadInputPin(GPIOD, GPIO_PIN_6)==RESET){
            pocet += 1;
            printf("aktualni pocet pruchodu je: %u\r\n",pocet);
            delay_ms(500);
        }

    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
