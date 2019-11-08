#include<reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit LED1=P1^0;
sbit Key=P3^5; //External interrupt signal is connected to P3.5
sbit ExInt=P3^2;


//- PPC PT2 PS PT1 PX1 PT0 PX0
void ISRInit()
{
	ExInt=1; //External Interrupt
	EA=1; //Enable global interrupt
	EX0=1; //Enable external interrupt 0
	IT0=1; //Edge trigger
	
	// timer
	TH0 = 0;
	TL0 = 0;
	TMOD = 0x01;
	ET0 = 1;
	TR0 = 1;
}

int ON = 1;
int cnt = 0;

void main()
{
	ISRInit();
	P1 = 0xFE;
	while(1)
	{
		if(Key == 0)
		{
			if(ON == 0) { ON = 1; }
			else if(ON == 1) { ON = 0; } 
			ExInt=0; //Generate external interrupt signal
		}
		
		else if(Key == 1)
		{
			ExInt = 1;
		}
		
			
	}
}

void Start() interrupt 0
{
	if(ON == 0)
	{
		cnt = 15;	
	}
	else if(ON == 1)
	{
		cnt = 0;
	}
}



void Timer() interrupt 1
{
	TH0 = 0;
	TL0 = 0;
	cnt++;
	if(cnt == 14)
	{
		P1 = _crol_(P1,1);
		cnt = 0;
	}
	
}



