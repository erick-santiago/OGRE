/*
 * Functions.cpp
 *
 *  Created on: Mar 21, 2020
 *      Author: esantiago
 */

#include <Functions.h>


float FixAngle(float angle){ // hmmm
	if(angle < 0)
		return angle + 360;
	else if (angle > 360)
		return angle - 360;
	return angle;
}

float Clamp(float min, float max, float val){
	if(val < min){
		return min;
	} else if (val > max){
		return max;
	}
	return val;
}

