#include "SystictIO.h"
#include "SystickDelay.h"

static void initSystickTimer(void){
	// disable systict ctrl register
	NVIC_ST_CTRL_R = 0x00;
	// reload max_value 24 bit--> F
	NVIC_ST_RELOAD_R	|= 0x00FFFFFF;
	// set current with initial value
	NVIC_ST_CURRENT_R = 0;
	// enable Systick with micro clock --> 101
	NVIC_ST_CTRL_R |= 0x05;
}

static void setDelayOneMilliS(void){
	NVIC_ST_CTRL_R = 0x00;
	NVIC_ST_RELOAD_R =0x0001387F; // setting 1ms/(1/80MHz) --> 80000
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= 0x05;
	while((NVIC_ST_CTRL_R &0x00010000) == 0){}
	NVIC_ST_CTRL_R = 0x00;
}

void genericDelay(unsigned long time){
	int i;
	for(i = 0 ; i < time ; i++){
		setDelayOneMilliS();
	}
		
}

static void delayOneSec(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 15999999;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= 0x05;
	while((NVIC_ST_CTRL_R &0x00010000) == 0){}
	NVIC_ST_CTRL_R = 0x00;

}

void delaySecond(unsigned long timeSec){
	int i;
	for(i = 0 ; i < timeSec ; i++){
		delayOneSec();
	}	

}










