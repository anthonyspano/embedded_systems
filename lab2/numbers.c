/*-----------------------------------------------------------------------------------------------
 File name: StaticDisply.C
 Author: Alex Yang, Northwestern Polytechnic University, Fremont, CA
		 Anthony Spano, 9/24/2019
 Date: 8/25/2013
 Description: This program is to display 0-9 and a-z in one 7-segament LED
 ---------------------------------------------------------------------------------------------*/
# include <reg52.h> // Header for 8051 uController, you must use it
// THE pin a OF seven segment display is connected to pin P1^0 of 8051
// THE pin b OF seven segment display is connected to pin P1^1 of 8051
// THE pin c OF seven segment display is connected to pin P1^2 of 8051
// THE pin d OF seven segment display is connected to pin P1^3 of 8051
// THE pin e OF seven segment display is connected to pin P1^4 of 8051
// THE pin f OF seven segment display is connected to pin P1^5 of 8051
// THE pin g OF seven segment display is connected to pin P1^6 of 8051
// Bit D1 is conncted to pin P2^0
// Bit D2 is conncted to pin P2^1
// Bit D3 is conncted to pin P2^2
// Bit D4 is conncted to pin P2^3
// This seven segment function will only work for common anode configuration
// for common cathode calculate the hex values by your own
#define uint unsigned int
#define uchar unsigned char
void delay(uint z) // Delay Function
{
 uint x, y;
 for(x=z; x>0; x--)
	for(y=415; y>0; y--);
}

void bitOff(uchar D) //Switch Off D1-D4
{
if(D==1) P2=0xFF;
if(D==2) P2=0xFF;
if(D==3) P2=0xFF;
if(D==4) P2=0xFF;
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



void one(uint i)
{		
		uint refresh = 100;
		uint counter = refresh;
		for(i = 0; i < counter; i++)
	  {
			// hi
			bitSel(1); //Select one bit D3
			sevenSegmentChar(7); 
			delay(3);
			
			bitSel(2); //Select two bit D3
			sevenSegmentChar(8);
			delay(3);
	  }
	
		counter = refresh;
		// you
		for(i = 0; i < counter; i++)
		{
			// 24, 14, 20
			bitSel(1); //Select one bit D3
			sevenSegmentChar(24); 
			delay(2);
			
			bitSel(2); //Select two bit D3
			sevenSegmentChar(14);
			delay(2);
			
			bitSel(3); //Select two bit D3
			sevenSegmentChar(20);
			delay(2);
		}

		counter = refresh;
		// did
		for(i = 0; i < counter; i++)
		{
			bitSel(1); //Select one bit D3
			sevenSegmentChar(3); 
			delay(2);
			
			bitSel(2); //Select two bit D3
			sevenSegmentChar(8);
			delay(2);
			
			bitSel(3); //Select two bit D3
			sevenSegmentChar(3);
			delay(2);
		}
		
		counter = refresh;
//		// good
		for(i = 0; i < counter; i++)
		{
			bitSel(1); //Select one bit D3
			sevenSegmentChar(6); 
			delay(1);
			
			bitSel(2); //Select two bit D3
			sevenSegmentChar(14);
			delay(1);
			
			bitSel(3); //Select two bit D3
			sevenSegmentChar(14);
			delay(1);
			
			bitSel(4); //Select two bit D3
			sevenSegmentChar(3);
			delay(1);
			
		}
		counter = refresh;
//		
//	  // job
		for(i = 0; i < counter; i++)
		{
			bitSel(1); //Select two bit D3
			sevenSegmentChar(9);
			delay(2);
			bitSel(2); //Select two bit D3
			sevenSegmentChar(14);
			delay(2);
			bitSel(3); //Select two bit D3
			sevenSegmentChar(1);
			delay(2);
			
		}
	
}

void two(uint i)
{
	//drag from right to left
	uint refresh = 50;
	uint counter = refresh;
	
	// h 
	bitSel(4);
	sevenSegmentChar(7); 
	delay(400);
	
	// hi
	for(i = 0; i < counter; i++)
	{
		bitSel(3);
		sevenSegmentChar(7);
		delay(3);
		bitSel(4);
		sevenSegmentChar(8);
		delay(3);
	}
		
	// hi_
	for(i = 0; i < counter; i++)
	{
		bitSel(2);
		sevenSegmentChar(7);
		delay(2);
		bitSel(3);
		sevenSegmentChar(8);
		delay(2);
		bitSel(4);
		bitOff(4);
		delay(2);
	}
	
	
	// hi_y
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(7);
		delay(1);
		bitSel(2);
		sevenSegmentChar(8);
		delay(1);
		bitSel(3);
		bitOff(3);
		delay(1);
		bitSel(4);
		sevenSegmentChar(24); 
		delay(1);
	}
	
	
	// i_yo
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(8);
		delay(1);
		bitSel(2);
		bitOff(2);
		delay(1);
		bitSel(3);
		sevenSegmentChar(24);
		delay(1);
		bitSel(4);
		sevenSegmentChar(14);
		delay(1);
	}
	
	// _you
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		bitOff(1);
		delay(1);
		bitSel(2);
		sevenSegmentChar(24);
		delay(1);
		bitSel(3);
		sevenSegmentChar(14);
		delay(1);
		bitSel(4);
		sevenSegmentChar(20);
		delay(1);
	}



	// you_
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(24);
		delay(1);
		bitSel(2);
		sevenSegmentChar(14);
		delay(1);
		bitSel(3);
		sevenSegmentChar(20);
		delay(1);
		bitSel(4);
		bitOff(4);
		delay(1);
	}
	
	
	// ou_d
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(14);
		delay(1);
		bitSel(2);
		sevenSegmentChar(20);
		delay(1);
		bitSel(3);
		bitOff(3);
		delay(1);
		bitSel(4);
		sevenSegmentChar(3);
		delay(1);	
	}
	
	
	// u_di
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(20);
		delay(1);
		bitSel(2);
		bitOff(2);
		delay(1);
		bitSel(3);
		sevenSegmentChar(3);
		delay(1);
		bitSel(4);
		sevenSegmentChar(8);
		delay(1);	
	}
	
	
	// _did
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		bitOff(1);
		delay(1);
		bitSel(2);
		sevenSegmentChar(3);
		delay(1);
		bitSel(3);
		sevenSegmentChar(8);
		delay(1);
		bitSel(4);
		sevenSegmentChar(3);
		delay(1);		
	}
	
	
	// did_
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(3);
		delay(1);
		bitSel(2);
		sevenSegmentChar(8);
		delay(1);
		bitSel(3);
		sevenSegmentChar(3);
		delay(1);
		bitSel(4);
		bitOff(4);
		delay(1);		
	}
	
	
	// id_g
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(8);
		delay(1);
		bitSel(2);
		sevenSegmentChar(3);
		delay(1);
		bitSel(3);
		bitOff(3);
		delay(1);	
		bitSel(4);
		sevenSegmentChar(6);
		delay(1);		
	}
	
	
	// d_go
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(3);
		delay(1);
		bitSel(2);
		bitOff(2);
		delay(1);	
		bitSel(3);
		sevenSegmentChar(6);
		delay(1);	
		bitSel(4);
		sevenSegmentChar(14);
		delay(1);				
	}
	
	// _goo
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		bitOff(1);
		delay(1);	
		bitSel(2);
		sevenSegmentChar(6);
		delay(1);	
		bitSel(3);
		sevenSegmentChar(14);
		delay(1);		
		bitSel(4);
		sevenSegmentChar(14);
		delay(1);			
	}
	
	
	// good
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(6);
		delay(1);	
		bitSel(2);
		sevenSegmentChar(14);
		delay(1);		
		bitSel(3);
		sevenSegmentChar(14);
		delay(1);	
		bitSel(4);
		sevenSegmentChar(3);
		delay(1);		
	}
	
	
	// ood_
	for(i = 0; i < counter; i++)
	{
		bitSel(1);
		sevenSegmentChar(14);
		delay(1);		
		bitSel(2);
		sevenSegmentChar(14);
		delay(1);	
		bitSel(3);
		sevenSegmentChar(3);
		delay(1);	
		bitSel(4);
		bitOff(4);
		delay(1);		
	}
	
	
	// od_j
	for(i = 0; i < counter; i++)
	{	
		bitSel(1);
		sevenSegmentChar(14);
		delay(1);	
		bitSel(2);
		sevenSegmentChar(3);
		delay(1);	
		bitSel(3);
		bitOff(3);
		delay(1);		
		bitSel(4);
		sevenSegmentChar(9);
		delay(1);
	}
	
	
	// d_jo
	for(i = 0; i < counter; i++)
	{	
		bitSel(1);
		sevenSegmentChar(3);
		delay(1);	
		bitSel(2);
		bitOff(2);
		delay(1);		
		bitSel(3);
		sevenSegmentChar(9);
		delay(1);
		bitSel(4);
		sevenSegmentChar(14);
		delay(1);
	}
	
	
	// _job
	for(i = 0; i < counter; i++)
	{	
		bitSel(1);
		bitOff(2);
		delay(1);		
		bitSel(2);
		sevenSegmentChar(9);
		delay(1);
		bitSel(3);
		sevenSegmentChar(14);
		delay(1);
		bitSel(4);
		sevenSegmentChar(1);
		delay(1);
	}

	
}


void three()
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


void main ()
{
	uchar i; //Declare loop index
	while(1)
	{
			one(i);
		
			//two(i);
		
			//three();
		

		
	}
}

