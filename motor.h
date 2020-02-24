//*电机驱动*//
//*定义电机接口*//

#ifndef __MOTOR_H_
#define __MOTOR_H_
#include"reg52.h"
sbit ENA=P0^0;
sbit ENB=P0^1;
sbit ML1=P0^2;
sbit ML2=P0^3;
sbit MR1=P0^5;
sbit MR2=P0^6;

void GO_FORWARD(void);
void GO_BACK(void);
void GO_LEFT(void);
void GO_RIGHT(void);
void GO_FREE(void);

#endif



