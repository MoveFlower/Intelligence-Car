#include"motor.h"
void GO_FORWARD(void)
{
	 ENA=1;
	 ENB=1;
	 ML1=1;
   ML2=0;
   MR1=1;
   MR2=0;
}

void GO_BACK(void)
{
	 ENA=1;
	 ENB=1;
	 ML1=0;
   ML2=1;
   MR1=0;
   MR2=1;
}

void GO_LEFT(void)
{
	 ENA=1;
	 ENB=1;
	 ML1=0;
   ML2=0;
   MR1=1;
   MR2=0;
}

void GO_RIGHT(void)
{
	 ENA=1;
	 ENB=1;
	 ML1=1;
   ML2=0;
   MR1=0;
   MR2=0;
}

void GO_FREE(void)
{
	 ENA=0;
	 ENB=0;
//	 ML1=1;
//   ML2=0;
//   MR1=0;
//   MR2=0;
}