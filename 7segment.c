#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

unsigned int i,j;
unsigned char FND_A[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

/**********************************************************************************/

void seg_loading(void)
{
    PORTA = 0b01000000;
	PORTC = 0x0;
}

/**********************************************************************************/

void seg_Start(void)
{
    while(j<=12)
    {
      PORTA = FND_A[j%10];
      PORTC = 0b00000111;

      _delay_ms(5); 

      PORTA = FND_A[j%10 - 1];
      PORTC = (j >= 1) ? 0b00001011 : 0b00001111;

      _delay_ms(5); 

      PORTA = FND_A[j%10 - 2];
      PORTC = (j >= 2) ? 0b00001101 : 0b00001111;

      _delay_ms(5); 

      PORTA = FND_A[j%10 - 3];
      PORTC = (j >= 3) ? 0b00001110 : 0b00001111;

      _delay_ms(5); 

	  i++;	

		if(j<=12)
            { 
			if(i>=50)  
		    	{
				i=0; j++;
			    }
		    }
		else
		    i,j = 0;
        }

		PORTA = 0b10000000;
	    PORTC = 0x0;
     	
		_delay_ms(100);		
 		
		seg_loading();
}

/**********************************************************************************/

void main(void)
{
	DDRA = 0xFF;
	DDRC = 0x0F;

	seg_loading();

	EIMSK = 0b00000001;
	EICRA = 0b00000010;
	SREG = 0x80;

	while(1);
}
 
/**********************************************************************************/

ISR(INT0_vect)
{
    seg_Start();
}
