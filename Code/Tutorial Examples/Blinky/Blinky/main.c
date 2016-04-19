/*
 * Blinky.c
 *
 * Created: 01-04-2016 17:50:46
 * Author : Vaibhav
 */ 
#include <avr/io.h>
#include <util/delay.h>

#define LED 5

int main()
{
	DDRD = (1<<LED);           // Configure PORTD5 as output

	while(1)
	{
		PORTD = (1<<LED);        // Turn ON Led connected to PORTD5
		_delay_ms(1000);      // Wait for some time
		PORTD = (0<<LED);        // Turn OFF Led connected to PORTD5
		_delay_ms(1000);      // Wait for some time
	}
	return 0;
}