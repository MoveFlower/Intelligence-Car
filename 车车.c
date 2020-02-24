#include"reg52.h"
#include"四路循迹.h"
#include"sound.h"
#include"motor.h"
#include"lcd.h"

#define uchar unsigned char
#define uint  unsigned int


void main()
{
		InitLcd1602();//初始化lcd1602
		LcdShowStr(0,0,"CAR IS RUNNING");//液晶显示
		chaoshengbo_init();//超声波模块初始化
	  GetDistance();//超声波获取距离
		if(GetDistance() > 0 && GetDistance() <= 15)		//若获取的距离大于0且小于等于15cm时
		{
			GO_FORWARD();							   //先前进（与默认行驶方式相反）
			GO_BACK();							  //再右转
			GO_LEFT();		
			GO_RIGHT();
			GO_FREE();
		}

}