#include"sound.h"
#include"lcd.h"
unsigned int distance_cm = 0;  	//����
unsigned int overflow_count = 0;  //�������
unsigned int status = 0;		  //������ģ��״̬
unsigned int dis_count = 0;		  //����

unsigned char code ASCII[15]  = {'0','1','2','3','4','5','6','7','8','9','.','-','M'};
unsigned char      disbuff[4] = { 0,0,0,0,};

//������ģ���ʼ��
void chaoshengbo_init(void)
{
	Trig = 0;
	//TH2 = RCAP2H = 0;
	//TL2 = RCAP2L = 0;
	TH0 = TL0 = 0;
	TR0 = 0;	//�رն�ʱ��0
	ET0 = 1;	//����T0�ж�
}

//������ģ���ȡ����
unsigned int GetDistance(void)
{
	Trig = 1;	//���ʹ����ź�
	status = 1;	  //״̬1Ϊ���䳬����
	TH0 = 0;	  
	TL0 = 0;
	TR0 = 1;	//�򿪶�ʱ��0
	while(TL0 < 42)		//��������10us������
		;
	status = 2;	  //״̬2Ϊ�����곬������
	Trig = 0;
	TR0 = 0;
	TH0 = 0;
	TL0 = 0;
	overflow_count = 0;
	TR0 = 1;		  //�򿪶�ʱ��0
	while(Echo == 0)   //�����źŷ���ʱ
	{
		if(status == 5)		//״̬5��ʾ��ʱ
		{
			status = 0;
			distance_cm = 0;
			break ;	//ʧ��
		}
	}
	TR0 = 0;	//��ռ���
	TH0 = 0;
	TL0 = 0;
	overflow_count = 0;
	TR0 = 1;
	while(Echo == 1)	//���źŷ���ʱ����ʼ���㳤��
	{
		if(status == 5)	//statusΪ5ʱʧ��
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
	status = 0 ;	//׼���´η���
		
	  disbuff[0]=distance_cm%1000/100;
	  disbuff[1]=distance_cm%1000%100/10;
	  disbuff[2]=distance_cm%1000%10 %10;
	  DisplayOneChar(0, 1, ASCII[disbuff[0]]);
	  DisplayOneChar(1, 1, ASCII[10]);	//��ʾ��
	  DisplayOneChar(2, 1, ASCII[disbuff[1]]);
	  DisplayOneChar(3, 1, ASCII[disbuff[2]]);
	  DisplayOneChar(4, 1, ASCII[12]);	//��ʾM
	
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
		status = 5;		//��ʱ
	}
}