#include <avr/io.h>
#include <avr/interrupt.h>
           
void main(void)
{                
	// 포트 초기화
	DDRC = 0x01;		// 포트 G 출력으로 설정
	PORTC = 0x00;	        // 포트 G에 초기값 출력
	              
	// 인터럽트 초기화
	TIMSK = 0x01;	        // TOIE0 = 1;
	TCCR0 = 0x07;	        // 일반모드, 프리스케일 = CK/1024
	TCNT0 = 0x00;           // 타이머/카운터0 레지스터 초기값
	SREG = 0x80;	        // 전역 인터럽트 인에이블 비트 I 셋.
	
	while(1);		// 무한 루프
}

// 타이머/카운터0 오버플로우 서비스 루틴
// 인터럽트 발생 주기 1/16,000,000 * 1024분주 * 256 = about 16ms
ISR(TIMER0_OVF_vect)
{
	PORTC ^= 0x01;              
}

