#include"sound.h"
#include"lcd.h"
unsigned int distance_cm = 0;  	//距离
unsigned int overflow_count = 0;  //溢出计数
unsigned int status = 0;		  //超声波模块状态
unsigned int dis_count = 0;		  //计数

unsigned char code ASCII[15]  = {'0','1','2','3','4','5','6','7','8','9','.','-','M'};
unsigned char      disbuff[4] = { 0,0,0,0,};

//超声波模块初始化
void chaoshengbo_init(void)
{
	Trig = 0;
	//TH2 = RCAP2H = 0;
	//TL2 = RCAP2L = 0;
	TH0 = TL0 = 0;
	TR0 = 0;	//关闭定时器0
	ET0 = 1;	//允许T0中断
}

//超声波模块获取距离
unsigned int GetDistance(void)
{
	Trig = 1;	//发送触发信号
	status = 1;	  //状态1为发射超声波
	TH0 = 0;	  
	TL0 = 0;
	TR0 = 1;	//打开定时器0
	while(TL0 < 42)		//产生超过10us的脉冲
		;
	status = 2;	  //状态2为发射完超声波后
	Trig = 0;
	TR0 = 0;
	TH0 = 0;
	TL0 = 0;
	overflow_count = 0;
	TR0 = 1;		  //打开定时器0
	while(Echo == 0)   //当无信号返回时
	{
		if(status == 5)		//状态5表示超时
		{
			status = 0;
			distance_cm = 0;
			break ;	//失败
		}
	}
	TR0 = 0;	//清空计数
	TH0 = 0;
	TL0 = 0;
	overflow_count = 0;
	TR0 = 1;
	while(Echo == 1)	//有信号返回时，开始计算长度
	{
		if(status == 5)	//status为5时失败
		{
			status = 0;
			distance_cm = 0;
			TR0 = 0;
			break ;
		}
	}
	dis_count = overflow_count * 65536 + TH0 * 256 + TL0;
	TR0 = 0;
	distance_cm = (unsigned int)( (long)(dis_count) * 34 / 10000);
	status = 0 ;	//准备下次发送
		
	  disbuff[0]=distance_cm%1000/100;
	  disbuff[1]=distance_cm%1000%100/10;
	  disbuff[2]=distance_cm%1000%10 %10;
	  DisplayOneChar(0, 1, ASCII[disbuff[0]]);
	  DisplayOneChar(1, 1, ASCII[10]);	//显示点
	  DisplayOneChar(2, 1, ASCII[disbuff[1]]);
	  DisplayOneChar(3, 1, ASCII[disbuff[2]]);
	  DisplayOneChar(4, 1, ASCII[12]);	//显示M
	
	return distance_cm;
}

void Timer0Int() interrupt 1
{
	TF0 = 0;
	overflow_count++;
	TH0 = 0;
	TL0 = 0;
	if(overflow_count == 2)
	{
		status = 5;		//超时
	}
}