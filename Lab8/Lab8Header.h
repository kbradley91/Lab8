/*
 * Lab8Header.h
 *
 *  Created on: Nov 22, 2015
 *      Author: Kyle
 */

#ifndef LAB8HEADER_H_
#define LAB8HEADER_H_

static int upORdown = 0; //0 means going up, 1 means going down
static unsigned int reverbDelay = 1;
void calcPosition();
void moveDelay();

interrupt void weirdThings_ISR(void);


interrupt void IIRlowpass_ISR(void);

static double aCoef[4] = {
		1,
		-2.7363,
		2.5062,
		-0.7679

};
static double bCoef[4] = {
		0.0002527,
		 0.0007582,
		0.0007582,
		0.0002527

};

static unsigned int dBuffer[1024];
static unsigned int * dStart = &dBuffer[0];
static unsigned int * dEnd = &dBuffer[1023];
static unsigned int * currentPos = &dBuffer[0];
static unsigned int * delayPos = &dBuffer[0];


static unsigned int xArray[4];
static unsigned int * xstart = &xArray[0];
static unsigned int * cBuffer = &xArray[0]; //cBuffer intialized to xarry for some unknown reason
static unsigned int * xArrayStart = &xArray[0];
static unsigned int * xArrayEnd = &xArray[3];

static unsigned int yArray[4];
static unsigned int * ystart = &yArray[0];
static unsigned int * yArrayStart = &yArray[0];
static unsigned int * yArrayEnd = &yArray[3];

interrupt void IIRlowpass_ISR(void);
void init_xybuffers();





#endif /* LAB8HEADER_H_ */
