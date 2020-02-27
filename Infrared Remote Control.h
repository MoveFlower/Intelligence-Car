
#ifndef __XUNJI_H_
#define __XUNJI_H_
//*四路循迹*//
//*检测到黑线时，高电平；没检测到时，低电平灯亮*//
//*定义循迹接口*//
#include"reg52.h"
#include"motor.h"
sbit p00=P0^0;//第一路
sbit p01=P0^1;//第二路
sbit p02=P0^2;//第三路
sbit p03=P0^3;//第四路

#endif

