/*
 * FinalAVRProjectSolution.cpp
 *
 * Created: 11/13/2022 2:00:17 AM
 * Author : Dubuisson Samuel
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_OVF_vect){ // Timer 1 ISR, this is to fire the interrupt
	PORTB ^= (1 <<PORTB4 | 1 <<PORTB1); // to make both leds associated with these port numbers to blink
	TCNT1 = 65536 - (F_CPU/1024);; // 1 sec at 16 MHz
}


int main(void)
{
	DDRB |= (0x01 <<PORTB4 | 0x01 <<PORTB1);// register port B pin 5 and 1 respectively
	TCNT1 = 65536 - (F_CPU/1024); // 1 sec at 16 MHz
	TCCR1A = 0x00;
	TCCR1B = (1 << CS10) | (1 << CS12);; //  from Table 15-6. Clock Select Bit Description for 1024 it is CS12 (1), CS11(0), CS10(1)
	TIMSK1 = (1 << TOIE1); // overflow interrupt
	sei(); // Enable global interrupts by setting global interrupt enable bit in SREG
    /* Replace with your application code */
    while (1) 
    {
    }
}

