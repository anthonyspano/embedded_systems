//Generate the new font “€” in CGRAM and display on LCD.

#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar code line1[]="User Def. Font";
uchar i; //Loop index
sbit lcdRS=P3^2;
sbit lcdRW=P3^3; 
sbit lcdEN=P3^4;
uchar code NewFont[]={0x06,0x09,0x1E,0x08,0x1E,0x09,0x06,0x00}; //Display temperature C 

void delay(uint z)
{
uint x,y;
for(x=z;x>0;x--) 
for(y=110;y>0;y--);
}
void writeCmd(uchar cmd)
{
lcdRS=0; //Low for command write-in 
P1=cmd; //Generate input command from P1 to LDC's DB0-DB7 
delay(5);
lcdEN=1; 
delay(4);
lcdEN=0;
}
void writeData(uchar D)
{
lcdRS=1; 
P1=D;
delay(5);
lcdEN=1;
delay(4);
lcdEN=0;
}
void init()
{
lcdEN=0;
writeCmd(0x38); //8 bits, 2 lines 5x7matrix display mode
writeCmd(0x0c); //Switch display on, cursor off, no blinking 
writeCmd(0x06); //Cursor -> right, Screen-> not change
writeCmd(0x01); //Clear screen
}
void main()
{
lcdRW=0; //Set to write mode 
init();
for(i=0;i<14;i++) //Display "User Def. Font" in 1st line
{ 
writeCmd(0x80+i); //Set display data in 1st line
writeData(line1[i]); 
delay(5);
}
for(i=0; i<10; i++)
{
writeCmd(0x40+0x08+i); //2st word address in CGRAM is 0x48;
writeData(NewFont[i]); //Each pixel line has one address
}
writeCmd(0x80+0x40); //Set display data in 2nd line
writeData(0x01); //Display new defined ascii code in 2nd word of CGRAM 
while(1);
}