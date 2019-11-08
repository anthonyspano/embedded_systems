/*--------------------------------------------------------------------------
Author: Alex Yang
Northwestern Polytechnic University, Fremont, CA
Date: 9/2/2013
Description: Switch one LED on and off by external interrupt
---------------------------------------------------------------------------*/
#include<reg52.h>

#define uint unsigned int
#define uchar unsigned char
sbit LED1=P1^0;
sbit Key=P3^5; //External interrupt signal is connected to P3.5
sbit ExInt=P3^2;


void delay(uint z) // Delay Function
{
 uint x, y;
 for(x=z; x>0; x--)
	for(y=415; y>0; y--);
}


void sevenSegmentNum(uchar num) // Declaration Of seven segment function
{
 switch(num)
 {
	case 0: //Case for 0
 {
	P1=0xC0;
	break;
 }
 case 1: //Case for 1
 {
	P1=0xF9;
	break;
 }
 case 2: //Case for 2
 {
	P1=0xA4;
	break;
 }
 case 3: //Case for 3
 {
	P1=0xB0;
	break;
 }
 case 4:
	//Case for 4
 {
	P1=0x99;
	break;
 }
 case 5: //Case for 5
 {
	P1=0x92;
	break;
 }
 case 6: //Case for 6
 {
	P1=0x82;
	break;
 }
 case 7: //Case for 7
 {
	P1=0xF8;
	break;
 }
 case 8: //Case for 8
 {
	P1=0x80;
 break;
 }
case 9: //Case for 9
 {
	P1=0x98;
	break;
 }
}

}

void sevenSegmentChar(uchar alph)
{
 switch(alph)
 {
case 0: //Case for a
 {
P1=0xA0;
break;
}
case 1: //Case for b
 {
P1=0x83;
break;
}
case 2: //Case for c
 {
P1=0xA7;
break;
}
case 3: //Case for d
 {
P1=0xA1;
break;
}
case 4: //Case for e
 {
P1=0x86;
break;
}
case 5: //Case for f
 {
P1=0x8E;
break;
}
case 6: //Case for g

{
P1=0x90;
break;
}
case 7: //Case for h

{
P1=0x8B;
break;
}
case 8: //Case for i

{
P1=0xFB;
break;
}
case 9: //Case for j

{
P1=0xF1;
break;
}
case 10: //Case for k

{
P1=0x8F;
break;
}
case 11: //Case for l

{
P1=0xC7;
break;
}
case 12: //Case for m

{
P1=0xAA;
break;
}
case 13: //Case for n

{
P1=0xAB;
break;
}
case 14: //Case for o

{
P1=0xA3;
break;
}
case 15: //Case for p

{
P1=0x8C;
break;
}
case 16: //Case for q

{
P1=0x9A;
break;
}
case 17: //Case for r

{
P1=0xAF;
break;
}
case 18: //Case for s

{
P1=0x92;
break;
}
case 19: //Case for t

{
P1=0x87;
break;
}
case 20: //Case for u

{
P1=0xE3;
break;
}
case 21: //Case for v

{
P1=0xC1;
break;
}
case 22: //Case for w
 {
P1=0x81;
break;
}
case 23: //Case for x
 {
P1=0xB9;
break;
}
case 24: //Case for y
 {
P1=0x8D;
break;
}
case 25: //Case for z
 {
P1=0xB3;
break;
}
 }
}
void bitSel(uchar D) //Select D1-D4
{
switch(D)
{
case 1: //Select D1
{
P2=0xFE;
break;
}
case 2: //Select D2
{
P2=0xFD;
break;
}
case 3: //Select D3
{
P2=0xFB;
break;
}
case 4: //Select D4
{
P2=0xF7;
break;
}
}
}


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


void count()
{
	// 10-99
	int h, i, j, r, t, repeat;
	j = 0;
	repeat = 1;
	
	for(t = 0; t < 10; t++)
	{
		for(h = 0; h < 10; h++)
		{
			for(i = 0; j < 10; i++)
			{
				for(r = 0; r < repeat; r++)
				{
					bitSel(1);
					sevenSegmentNum(t);
					delay(1);
					bitSel(2);
					sevenSegmentNum(h);
					delay(1);
					bitSel(3); 
					sevenSegmentNum(j);
					delay(1);
					bitSel(4);
					sevenSegmentNum(i);
					delay(1);					
				}
					
				if(i == 9)
				{
					// set i to -1 because of increment
					i = -1;
					j++;
				}
				
			}
			j = 0;
			
		}
		
		h = 0;
		
	}		
		
}

int cnt = 0;
int num = 0;
int b3num, b2num, b1num, b0num;
int ON = 1;

void main()
{
	ISRInit();
	//LED1=0;
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
		
		b3num = num/1000;
		b2num = (num%1000)/100;
		b1num = ((num%1000)%100)/10;
		b0num = ((num%1000)%100)%10;
		
		bitSel(1);
		sevenSegmentNum(b3num);
		delay(1);
		bitSel(2);
		sevenSegmentNum(b2num);
		delay(1);
		bitSel(3);
		sevenSegmentNum(b1num);
		delay(1);
		bitSel(4);
		sevenSegmentNum(b0num);
		delay(1);
			
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
		num++;
		cnt = 0;
	}
	
}



