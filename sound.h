#ifndef __SOUND_H_
#define __SOUND_H_
#include"reg52.h"
//*������*//
//���峬����ģ��˿�
sbit Trig = P1^2;
sbit Echo = P1^3;

void chaoshengbo_init(void);
unsigned int GetDistance(void);

#endif

