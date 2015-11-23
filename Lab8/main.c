/*
 * main.c
 */
#include <DSP28x_Project.h>
#include "DSP_KB.h"
#include "Lab8Header.h"


unsigned long ISRvalue = &weirdThings_ISR;
int main(void) {
	
	DisableDog();
	CPUinit();
	EALLOW;
	outputEnable();
	LCDinit();
	LCDclear();
	initADC();
	DAC_init();
	init_xybuffers();
	timerINIT(ISRvalue, samplingRate);
	while(1){

	}

	return 0;
}

