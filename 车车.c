#include"reg52.h"
#include"��·ѭ��.h"
#include"sound.h"
#include"motor.h"
#include"lcd.h"

#define uchar unsigned char
#define uint  unsigned int


void main()
{
		InitLcd1602();//��ʼ��lcd1602
		LcdShowStr(0,0,"CAR IS RUNNING");//Һ����ʾ
		chaoshengbo_init();//������ģ���ʼ��
	  GetDistance();//��������ȡ����
		if(GetDistance() > 0 && GetDistance() <= 15)		//����ȡ�ľ������0��С�ڵ���15cmʱ
		{
			GO_FORWARD();							   //��ǰ������Ĭ����ʻ��ʽ�෴��
			GO_BACK();							  //����ת
			GO_LEFT();		
			GO_RIGHT();
			GO_FREE();
		}

}