/*
 * Lab8Header.c
 *
 *  Created on: Nov 22, 2015
 *      Author: Kyle
 */

#include <DSP28x_Project.h>
#include "DSP_KB.h"
#include "Lab8Header.h"

void init_xybuffers(){
	int i;
	for(i = 0;i<4;i++){
		xArray[i] = 0;
		yArray[i] = 0;
	}

}
interrupt void weirdThings_ISR(void){




}

interrupt void IIRlowpass_ISR(void){

	unsigned int input = ADC_get();

	*xstart = input;
	xstart++;
	cBuffer = xstart;

	int i;
	float out = 0;
	float out2 = 0;
	unsigned int temp;
	for(i = 0;i<sizeof(xArray);i++){
		cBuffer--;
		if(cBuffer < xArrayStart){
			cBuffer = xArrayEnd;
		}
		temp = *cBuffer;
		out += bCoef[i]*temp;


	}
	if(xstart>xArrayEnd){
		xstart = xArrayStart;
	}

	cBuffer = ystart;

	for(i = 1;i<sizeof(yArray);i++){
		cBuffer--;
		if(cBuffer < yArrayStart){
			cBuffer = yArrayEnd;
		}
		temp = *cBuffer;
		out2 += aCoef[i]*temp;
	}
	out = out - out2;
	*ystart = out;

	ystart++;
	if(ystart>yArrayEnd){
		ystart = yArrayStart;
	}
	DAC_set(out);

}

