#include <stdbool.h>
#include <avr/io.h>

const int pin = 7;

int main(void)
{
    DDRB |= 1 << pin;

    while (true)
    {
        volatile long int i;
        for (i = 0; i < 50000; i++)
          ;
        PORTB |= 1 << pin;
        for (i = 0; i < 50000; i++)
          ;
        PORTB &= ~(1 << pin);
    }

    return 0;
}
