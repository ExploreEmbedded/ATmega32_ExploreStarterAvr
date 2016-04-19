/*
 * 7Segment.c
 *
 * Created: 05-04-2016 10:06:59
 * Author : Vaibhav
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define Segment   0x01


int main() {
	char seg_code[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	int cnt;

	/* Configure the ports as output */
	DDRB = 0xff;               // Data lines
	DDRD = 0x01;               // Control signal PORTD0

	while (1)
	{
		
		for (cnt = 0x00; cnt < 0x10; cnt++)   // loop to display 0-F
		{
			
			PORTD = Segment;
			PORTB = seg_code[cnt];
			_delay_ms(300);
			
		}
	}
}