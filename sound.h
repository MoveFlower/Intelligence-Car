#ifndef __SOUND_H_
#define __SOUND_H_
#include"reg52.h"
//*超声波*//
//定义超声波模块端口
sbit Trig = P1^2;
sbit Echo = P1^3;

void chaoshengbo_init(void);
unsigned int GetDistance(void);

#endif

