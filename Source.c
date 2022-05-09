#include <TM4C123.h>
#include "SystickDelay.h"
#include "PortF.h"
#include "C:\Users\asr96\Downloads\Io.h"

int counter = 4;
int main()
{
	
	initPortF();
	GPIO_PORTF_DATA_R ^= (RED+GREEN+BLUE);
	delaySecond(60);
	GPIO_PORTF_DATA_R ^= (RED+GREEN+BLUE);
	
	
	while(counter){
		
		GPIO_PORTF_DATA_R  ^=(RED+GREEN+BLUE);
		delaySecond(1);
		if(!(GPIO_PORTF_DATA_R&0x0E)){counter--;}
		
	}
	
	
}	





