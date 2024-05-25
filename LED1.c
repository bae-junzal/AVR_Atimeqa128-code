#include<avr/io.h>
#include<avr/interrupt.h>

// INT 0부터 하나씩 다해보기

unsigned char led = 0x00;
unsigned char cnt = 0x00;

void main(void)
{
	DDRG = 0xFF; //출력 설정
	DDRB = 0xFF;
	DDRA = 0xFF;

	PORTA = led; 

	EIMSK = 0b00000001; //0 인터롭트 설정 
	EICRA = 0b00000010; // 하강엣지에 키겟다
	SREG = 0x80; //상태 비트설정

	while(1);
}

ISR(INT0_vect)
{
	cnt++;

	if(cnt % 2 == 0)
		PORTA = 0x00;
	else
		PORTA = 0x01;
}
