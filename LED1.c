#include<avr/io.h>
#include<avr/interrupt.h>

// INT 0���� �ϳ��� ���غ���

unsigned char led = 0x00;
unsigned char cnt = 0x00;

void main(void)
{
	DDRG = 0xFF; //��� ����
	DDRB = 0xFF;
	DDRA = 0xFF;

	PORTA = led; 

	EIMSK = 0b00000001; //0 ���ͷ�Ʈ ���� 
	EICRA = 0b00000010; // �ϰ������� Ű�ٴ�
	SREG = 0x80; //���� ��Ʈ����

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
