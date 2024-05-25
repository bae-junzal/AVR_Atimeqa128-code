#include <avr/io.h>
#include <avr/interrupt.h>
           
void main(void)
{                
	// ��Ʈ �ʱ�ȭ
	DDRC = 0x01;		// ��Ʈ G ������� ����
	PORTC = 0x00;	        // ��Ʈ G�� �ʱⰪ ���
	              
	// ���ͷ�Ʈ �ʱ�ȭ
	TIMSK = 0x01;	        // TOIE0 = 1;
	TCCR0 = 0x07;	        // �Ϲݸ��, ���������� = CK/1024
	TCNT0 = 0x00;           // Ÿ�̸�/ī����0 �������� �ʱⰪ
	SREG = 0x80;	        // ���� ���ͷ�Ʈ �ο��̺� ��Ʈ I ��.
	
	while(1);		// ���� ����
}

// Ÿ�̸�/ī����0 �����÷ο� ���� ��ƾ
// ���ͷ�Ʈ �߻� �ֱ� 1/16,000,000 * 1024���� * 256 = about 16ms
ISR(TIMER0_OVF_vect)
{
	PORTC ^= 0x01;              
}

