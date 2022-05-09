#include "PortF.h"
#include "C:\Users\asr96\Downloads\Io.h"

void initPortF(void){
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0){};
	// lock portF
	GPIO_PORTF_LOCK_R |= GPIO_LOCK_KEY;
	// enable changes on portF --> RED
	GPIO_PORTF_CR_R |= RED;
	// disable analog fn
	GPIO_PORTF_AMSEL_R &=~(RED+BLUE+GREEN);	
	// clear PCTL
	GPIO_PORTF_PCTL_R &= ~0x000000F0;
	// disable alternate fn --> RED
	GPIO_PORTF_AFSEL_R &= ~(RED+BLUE+GREEN);
	// set direction of pf1 output 1
	GPIO_PORTF_DIR_R |= (RED+BLUE+GREEN);
	// set digital fn
	GPIO_PORTF_DEN_R |= (RED+BLUE+GREEN);		
	// SET initial value off for pf1	
	GPIO_PORTF_DATA_R |=~(RED+BLUE+GREEN); 	
	

}


