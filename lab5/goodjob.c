/*----------------------------------------------------------------------------------
Author: Northwestern Polytechnic University, Fremont, CA
Alex Yang
Date: 9/1/2013
Description: Display string “1.234” on 16x2 LCD, and connect
 P1.0~1.7 to LCD data line 0~7
-----------------------------------------------------------------------------------*/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table[]="hi! you did a good job!";
sbit lcdEN=P2^2; //Connect P2.0~P2.2 to LCD 3 control lines
sbit lcdRW=P2^1;
sbit lcdRS=P2^0;
uchar num;
int s = (sizeof(table)/sizeof(uchar))-1;


void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
	for(y=415;y>0;y--);
}
void writeCmd(uchar cmd)
{
	lcdRS=0; //Low for command write-in
	P1=cmd; //Generate input command from P1 to LDC's DB0-DB7
	delay(5);
	lcdEN=1; //Generate logic high pulse
	delay(4);
	lcdEN=0;
}
void writeData(uchar D)
{
	lcdRS=1; //High for display data write-in
	P1=D;
	delay(5);
	lcdEN=1;
	delay(4);
	lcdEN=0;
}
void init()
{
	lcdEN=0; //Logic Low is “Enable”
	writeCmd(0x38); //8 bits, 2 lines 5x7matrix display mode
	writeCmd(0x0c); //Switch display on, cursor off, no blinking
	writeCmd(0x06); //Memory index increase, Cursor -> right, Screen-> not change
	writeCmd(0x01); //Clear screen
}
void main()
{
	lcdRW=0; //Set to write mode
	init();

	while(1) {
	writeCmd(0x80); //Set display data 1st address

	for(num=0;num<s;num++)
	{
		writeData(table[num]);
		delay(50);
	}
	
	writeCmd(0x07);
	
 }
	
}