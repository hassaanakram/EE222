#include<avr/io.h>
int main()
{
	DDRD = 0x00;    // Set port B as input
	DDRB = 0xFF;    // Set port C as output
	
	TCNT1 = 0;      // Initialize timer 1
	OCR1A = 62500;  // Set output compare register
	
	TCCR1A = 0x00;  // WGM13:WGM10 = 0100, CS12:CS10 = 010
	TCCR1B = 0x0A;
	
	unsigned char data;
	
	while(1)
	{
		if( (TIFR & 0x10) != 0 ) // Check OCF1A flag bit
		{
			TIFR |= 0x10;   // Clear flag
			data = PIND;    // Read port B
			
			if( (data & 0x80) == 0)
			PORTB = 'L';
			else
			PORTB = 'H';
		}
	}
}
