/*	Author:Giang To lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Lock_States {Lock_Start, Lock_Locked, Lock_UnLockedX, Lock_UnlockedY} Lock_State;




void Lock_Toggle(){

        unsigned char X = PINA & 0x01;
	unsigned char Y = PINA & 0x02;
	unsigned char out = PINA & 0x04;
	unsigned char in = PINA & 0x08;

	switch(Lock_State){

		case Lock_Start:
			Lock_State = Lock_Locked;
			break;

		case Lock_Locked:

			if(in){
				Lock_State = Lock_Locked;
			}
			else{
				if()
			}

			break;
	
		case Count_Increment:
			if(tmpA == 0x01){
				Count_State = Count_Increment;
			}
			else {
				Count_State = Count_Init;
			}

			break;

		case Count_Decrement:

			if(tmpA == 0x02){
				Count_State = Count_Decrement;
			}
			else{
				Count_State = Count_Init;
			}
			break;

		case Count_Reset:

			if(tmpA == 0x03){
				Count_State = Count_Reset;
			}
			else{
				Count_State = Count_Init;
			}
			break;

		default:
			Count_State = Count_Start;
			break;

		}

}	

int main(void) {

    /* Insert DDR and PORT initializations */

    DDRA = 0x00;PORTA = 0xFF;
    DDRC = 0xFF;PORTC = 0x00;

    Count_State = Count_Start;

    /* Insert your solution below */

    while (1) {
	Count_Toggle();
    }

    return 1;

}



