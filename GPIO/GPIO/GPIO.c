#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>






unsigned char gucPin1 = 0;
unsigned char gucPin2 = 0;







void PortInit(void)
{

	DDRA = (0 << DDA7) | (0 << DDA6) | (0 << DDA5) | (0 << DDA4) 
		 | (0 << DDA3) | (0 << DDA2) | (0 << DDA1) | (0 << DDA0);
	PORTA = (0 << PA7) | (0 << PA6) | (0 << PA5) | (0 << PA4) 
	 	  | (0 << PA3) | (0 << PA2) | (0 << PA1) | (0 << PA0);
	PINA = (0 << PINA7) | (0 << PINA6) | (0 << PINA5) | (0 << PINA4) 
		 | (0 << PINA3) | (0 << PINA2) | (0 << PINA1) | (0 << PINA0);


	DDRB = (0 << DDB7) | (0 << DDB6) | (0 << DDB5) | (0 << DDB4) 
		 | (0 << DDB3) | (0 << DDB2) | (0 << DDB1) | (0 << DDB0);
	PORTB = (0 << PB7) | (0 << PB6) | (0 << PB5) | (0 << PB4) 
	 	  | (0 << PB3) | (0 << PB2) | (0 << PB1) | (0 << PB0);
	PINB = (0 << PINB7) | (0 << PINB6) | (0 << PINB5) | (0 << PINB4) 
		 | (0 << PINB3) | (0 << PINB2) | (0 << PINB1) | (0 << PINB0);


	DDRC = (0 << DDC7) | (0 << DDC6) | (0 << DDC5) | (0 << DDC4) 
		 | (0 << DDC3) | (0 << DDC2) | (0 << DDC1) | (0 << DDC0);
	PORTC = (0 << PC7) | (0 << PC6) | (0 << PC5) | (0 << PC4) 
		  | (0 << PC3) | (0 << PC2) | (0 << PC1) | (0 << PC0);
	PINC = (0 << PINC7) | (0 << PINC6) | (0 << PINC5) | (0 << PINC4) 
		 | (0 << PINC3) | (0 << PINC2) | (0 << PINC1) | (0 << PINC0);

	DDRD = (0 << DDD7) | (0 << DDD6) | (0 << DDD5) | (0 << DDD4) 
		 | (0 << DDD3) | (0 << DDD2) | (0 << DDD1) | (0 << DDD0);
	PORTD = (0 << PD7) | (0 << PD6) | (0 << PD5) | (0 << PD4) 
		 | (0 << PD3) | (0 << PD2) | (0 << PD1) | (0 << PD0);
	PIND = (0 << PIND7) | (0 << PIND6) | (0 << PIND5) | (0 << PIND4) 
		 | (0 << PIND3) | (0 << PIND2) | (0 << PIND1) | (0 << PIND0);


	DDRE = (0 << DDE7) | (0 << DDE6) | (0 << DDE5) | (0 << DDE4) 
		 | (0 << DDE3) | (0 << DDE2) | (0 << DDE1) | (0 << DDE0);
	PORTE = (0 << PE7) | (0 << PE6) | (0 << PE5) | (0 << PE4) 
		 | (0 << PE3) | (0 << PE2) | (0 << PE1) | (0 << PE0);
	PINE = (0 << PINE7) | (0 << PINE6) | (0 << PINE5) | (0 << PINE4) 
		 | (0 << PINE3) | (0 << PINE2) | (0 << PINE1) | (0 << PINE0);


	DDRF = (0 << DDF7) | (0 << DDF6) | (0 << DDF5) | (0 << DDF4) 
		 | (0 << DDF3) | (0 << DDF2) | (0 << DDF1) | (0 << DDF0);
	PORTF = (0 << PF7) | (0 << PF6) | (0 << PF5) | (0 << PF4) 
		  | (0 << PF3) | (0 << PF2) | (0 << PF1) | (0 << PF0);
	PINF = (0 << PINF7) | (0 << PINF6) | (0 << PINF5) | (0 << PINF4) 
		 | (0 << PINF3) | (0 << PINF2) | (0 << PINF1) | (0 << PINF0);


	DDRG = (0 << DDG4) 
		 | (0 << DDG3) | (0 << DDG2) | (1 << DDG1) | (1 << DDG0);
	PORTG = (0 << PG4) 
		 | (0 << PG3) | (0 << PG2) | (0 << PG1) | (0 << PG0);
	PING = (0 << PING4) 
		 | (0 << PING3) | (0 << PING2) | (0 << PING1) | (0 << PING0);
}


int main(void)
{
	PortInit();

    sei();
    
    
	while (1)
	{
		gucPin1 = (PIND >> PIND4);
		gucPin2 = (PIND >> PIND5);

		PORTG = (gucPin1) | (gucPin1) << 1;

	}

	return 0;

}
