#include <16F628A.h>

#fuses HS

#use delay(clock=4MHz)
#use rs232(XMIT=pin_b2, BAUD=9600)

#define A pin_a0
#define B pin_a1
#define C pin_a2
#define t0_freq 84
#define buffer_size 8

int array[buffer_size];
int cont;

int main (void){

	while(true) {
		while(!input(pin_a0));
		output_toggle(pin_b0);
		array[cont] = input_a() & 0b111;
		cont++;
		if(cont == buffer_size)
			cont = 0;
		while(input(pin_a0));
	}

	return 0;
}
