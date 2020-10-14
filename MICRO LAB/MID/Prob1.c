#include <mega32.h>
#include <delay.h>


int togle;
int i;
int left;
int right;

void main(void)
{

PORTA=0x00;
DDRA=0x00;


PORTB=0x00;
DDRB=0x00;

PORTC=0x00;
DDRC=0x00;


PORTD=0x00;
DDRD=0x00;


TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;


TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;


MCUCR=0x00;
MCUCSR=0x00;


TIMSK=0x00;

UCSRB=0x00;

ACSR=0x80;
SFIOR=0x00;

ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

    /**start from here*/
    DDRA = 0b11111111;
    DDRC = 0b00000000;
    togle = 1;
    i = 0;
    left = 1;
    right = 0;

    while (1)
    {
    // Place your code here
        if(PINC.0 == 0)
        {
            togle = togle*(-1);
            delay_ms(100);
        }

        if(togle == 1)
        {
            if(left == 1) i++;
            else if (right == 1) i--;

            if(i>=8)
            {
                right = 1;
                left = 0;
            }
            else if (i<=1)
            {
                right = 0;
                left = 1;
            }
            if(i == 1)PORTA = 0b00000001;
            else if(i == 2)PORTA = 0b00000010;
            else if(i == 3)PORTA = 0b00000100;
            else if(i == 4)PORTA = 0b00001000;
            else if(i == 5)PORTA = 0b00010000;
            else if(i == 6)PORTA = 0b00100000;
            else if(i == 7)PORTA = 0b01000000;
            else if(i == 8)PORTA = 0b10000000;
            delay_ms(100);
        }
        else if(togle == -1)
        {
            delay_ms(100);
        }


    }
}
