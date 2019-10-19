 /*----------------------------------------------------------------------------------------------
 combokey.C
 Author: Alex Yang, Northwestern Polytechnic University, Fremont, CA
         Anthony Spano
 Date: 8/27/2013
 Description: Pressing a button on the 4x4 keypad will display a number or letter
              on the seven segment display. Pressing 'c' and '2' at the same time
              will display the letter 't'. 
 ------------------------------------------------------------------------------------------------*/
#include <REG52.H> //Special function register declarations
#include <intrins.h>
#define uint unsigned int //Define new data type for future use
#define uchar unsigned char
//Keypad will connect to P2.0-P2.7
//7-Segment LED will connect to P1.0-P1.7 and Bit control will connect to P3.3
sbit buzz=P3^2; //Buzzer control
sbit SegLEDB1=P3^3;
void delay(uint z) //Delay function declaration
{
uint x,y;
for(x=z; x>0; x--)
for(y=415; y>0; y--);
}

void sevenSegmentNum(uchar num) // Declaration Of seven segment function
{
switch(num)
 {
 case 0: // Case for 0
 {
P1=0xC0;
break;
}
 case 1: // Case for 1
 {
P1=0xF9;
break;
}
 case 2: // Case for 2
 {
P1=0xA4;
break;
}
 case 3: // Case for 3
 {
P1=0xB0;
break;
}
case 4: // Case for 4
 {
P1=0x99;
break;
}
case 5: // Case for 5
 {
P1=0x92;
break;
}
case 6: // Case for 6
 {
P1=0x82;
break;
}
case 7: // Case for 7
 {
P1=0xF8;
break;
}
case 8: // Case for 8
 {
P1=0x80;
break;
}
case 9: // Case for 9
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
case 'a': // Case for a
 {
P1=0xA0;
break;
}
case 'b': // Case for b
 {
P1=0x83;
break;
}
case 'c': // Case for c
 {
P1=0xA7;
break;
}
case 'd': // Case for d

{
P1=0xA1;
break;
}
case 'e': // Case for e

{
P1=0x86;
break;
}
case 'f': // Case for f

{
P1=0x8E;
break;
}
case 'g': // Case for g

{
P1=0x90;
break;
}
case 'h': // Case for h

{
P1=0x8B;
break;
}
case 'i': // Case for i

{
P1=0xFB;
break;
}
case 'j': // Case for j

{
P1=0xF1;
break;
}
case 'k': // Case for k

{
P1=0x8F;
break;
}
case 'l': // Case for l

{
P1=0xC7;
break;
}
case 'm': // Case for m

{
P1=0xAA;
break;
}
case 'n': // Case for n

{
P1=0xAB;
break;
}
case 'o': // Case for o

{
P1=0xA3;
break;
}
case 'p': // Case for p

{
P1=0x8C;
break;
}
case 'q': // Case for q

{
P1=0x9A;
break;
}
case 'r': // Case for r

{
P1=0xAF;
break;
}
case 's': // Case for s

{
P1=0x92;
break;
}
case 't': // Case for t

{
P1=0x87;
break;
}
case 'u': // Case for u

{
P1=0xE3;
break;
}
case 'v': // Case for v

{
P1=0xC1;
break;
}
case 'w': // Case for w

{
P1=0x81;
break;
}
case 'x': // Case for x

{
P1=0xB9;
break;
}
case 'y': // Case for y
 {
P1=0x8D;
break;
}
case 'z': // Case for z
 {
P1=0xB3;
break;
}
 }
}
void main()
{
        uchar temp; //Read in P2 data
        SegLEDB1=0; //Switch off 7 segment Bit1
        buzz=0; //Switch off buzzer
        while(1)
        {
        /*----------------Scan 1st line------------------------------------*/
        P2=0xFE; //Scan first line
        temp=P2; //Read in P2
        temp=temp&0xF0; //Set b3-b0 = 0 in temp
        if(temp==0x70) //Press Key1
        {
                delay(20); //Delay 20ms to debounce
                temp=P2; //Check again
                temp=temp&0xF0;
                if(temp==0x70)
                {
                        while((P2&0xF0)==0x70); //Wait for switch release
                        buzz=1;
                        SegLEDB1=0;
                        sevenSegmentNum(1); //Display Key1
                        delay(5);
                buzz=0;
                }
        }
        if(temp==0xB0) //Press Key5
        {
                delay(20); //Delay 20ms to debounce
                temp=P2; //Check again
                temp=temp&0xF0;
                if(temp==0xB0)
                {
                        while((P2&0xF0)==0xB0); //Wait for switch release
                        buzz=1;
                        sevenSegmentNum(5); //Display Key5
                        delay(5);
                        buzz=0;
                }
        }
        if(temp==0xD0) //Press Key9
        {
                delay(20); //Delay 20ms to debounce
                temp=P2; //Check again
                temp=temp&0xF0;
                if(temp==0xD0)
                {
                        while((P2&0xF0)==0xD0); //Wait for switch release
                        buzz=1;
                        sevenSegmentNum(9); //Display Key9
                        delay(5);
                        buzz=0;
                }
        }
        if(temp==0xE0) //Press Key C // 1110 0000
        {
                delay(20); //Delay 20ms to debounce
                temp=P2; //Check again
                temp=temp&0xF0;
                if(temp==0xE0)
                {
                        sevenSegmentChar('c');
                        // if also pressing key 2
                        P2=0xFD; //Scan 2nd line
                        temp=P2; //Read in P2
                        temp=temp&0xF0; //Set b3-b0 = 0 in temp
                        while(temp==0x70) //Press Key2
                        {
                                //sevenSegmentChar('t');
                                delay(20); //Delay 20ms to debounce
                                temp=P2; //Check again
                                temp=temp&0xF0;
                                if(temp==0x70)
                                {
                                        sevenSegmentChar('t');
                                }
                        }
                        if((P2&0xF0)==0x60)
                        {
                                while((P2&0xF0)==0x60);
                                sevenSegmentChar('t');
                        }
                        else if((P2&0xF0)==0xE0)
                        {
                                while((P2&0xF0)==0xE0); //Wait for switch release
                                buzz=1;
                                sevenSegmentChar('c'); //Display Key C
                                delay(5);
                                buzz=0;
                        }
                }
        }
        /*----------------Scan 2nd line------------------------------------*/
        P2=0xFD; //Scan 2nd line
        temp=P2; //Read in P2
        temp=temp&0xF0; //Set b3-b0 = 0 in temp
        if(temp==0x70) //Press Key2
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Check again
        temp=temp&0xF0;
        if(temp==0x70)
        {
        while((P2&0xF0)==0x70); //Wait for switch release
        buzz=1;
        SegLEDB1=0;
        sevenSegmentNum(2); //Display Key2
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xB0) //Press Key6
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Check again
        temp=temp&0xF0;
        if(temp==0xB0)
        {
        while((P2&0xF0)==0xB0); //Wait for switch release
        buzz=1;
        sevenSegmentNum(6); //Display Key6
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xD0) //Press Key 0
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Check again
        temp=temp&0xF0;
        if(temp==0xD0)
        {
        while((P2&0xF0)==0xD0); //Wait for switch release
        buzz=1;
        sevenSegmentNum(0); //Display Key 0
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xE0) //Press Key d
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Check again
        temp=temp&0xF0;
        if(temp==0xE0)
        {
        while((P2&0xF0)==0xE0); //Wait for switch release
        buzz=1;
        sevenSegmentChar('d'); //Display Key d
        delay(5);
        buzz=0;
        }
        }
        /*----------------Scan 3rd line------------------------------------*/
        P2=0xFB; //Scan 3rd line
        temp=P2; //Read in P2
        temp=temp&0xF0; //Set b3-b0 = 0 in temp
        if(temp==0x70) //Press Key 3
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0x70)
        {
        while((P2&0xF0)==0x70); //Wait for switch release
        buzz=1;
        SegLEDB1=0;
        sevenSegmentNum(3); //Display Key 3
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xB0) //Press Key 7
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0xB0)
        {
        while((P2&0xF0)==0xB0); //Wait for switch release
        buzz=1;
        sevenSegmentNum(7); //Display Key 7
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xD0) //Press Key A
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0xD0)
        {
        while((P2&0xF0)==0xD0); //Wait for switch release
        buzz=1;
        sevenSegmentChar('a'); //Display Key A
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xE0) //Press Key e
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0xE0)
        {
        while((P2&0xF0)==0xE0); //Wait for switch release
        buzz=1;
        sevenSegmentChar('e'); //Display Key e
        delay(5);
        buzz=0;
        }
        }
        /*----------------Scan 4th line------------------------------------*/
        P2=0xF7; //Scan 4th line
        temp=P2; //Read in P2
        temp=temp&0xF0; //Set b3-b0 = 0 in temp
        if(temp==0x70) //Press Key 4
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0x70)
        {
        while((P2&0xF0)==0x70); //Wait for switch release
        buzz=1;
        SegLEDB1=0;
        sevenSegmentNum(4); //Display Key 4
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xB0) //Press Key 8
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0xB0)
        {
        while((P2&0xF0)==0xB0); //Wait for switch release
        buzz=1;
        sevenSegmentNum(8); //Display Key 8
        delay(5);
        buzz=0;
        }
        }
        if(temp==0xD0) //Press Key b
        {
        delay(20); //Delay 20ms to debounce
        temp=P2; //Read in P2
        temp=temp&0xF0;
        if(temp==0xD0)
        {
        while((P2&0xF0)==0xD0); //Wait for switch release
        buzz=1;
        sevenSegmentChar('b'); //Display Key b
        delay(5);
        buzz=0;
        }
        }
                if(temp==0xE0) //Press Key e
                {
                        delay(20); //Delay 20ms to debounce
                        temp=P2; //Read in P2
                        temp=temp&0xF0;
                        if(temp==0xE0)
                        {
                                while((P2&0xF0)==0xE0); //Wait for switch release
                                buzz=1;
                                sevenSegmentChar('f'); //Display Key f
                                delay(5);
                                buzz=0;
                        }
                }
        }

 
}
