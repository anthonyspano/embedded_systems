//Read keypad and display on LCD.

#include <REG52.H> //Special function register declarations 
#include <intrins.h>
#define uint unsigned int 
#define uchar unsigned char //Keypad will connect to P2.0-P2.7 //7-Segment LED will connect to P1.0-P1.7 and Bit control will connect to P3.3
sbit lcdRS=P3^2;
sbit lcdRW=P3^3;
sbit lcdEN=P3^4;
void delay(uint z) { 
    uint x, y;
    for (x = z; x > 0; x--) {
        for (y = 415; y > 0; y--);
    }
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
void main() {
    uchar temp; //Read in P2 data 
	lcdRW=0; //Set to write mode
    init(); //Switch off 7 segment Bit1 
    while (1) {
        /*----------------Scan 1st line------------------------------------*/
        P2 = 0xFE; //Scan first line 
        temp = P2; //Read in P2 
        temp = temp & 0xF0; //Set b3-b0 = 0 in temp 
        if (temp == 0x70) //Press Key1 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again temp=temp&0xF0; 
            if (temp == 0x70) {
                while ((P2 & 0xF0) == 0x70); //Wait for switch release 
                writeData('1'); //Display Key1 
                delay(5);
            }
        }
        if (temp == 0xB0) //Press Key5 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xB0) {
                while ((P2 & 0xF0) == 0xB0); //Wait for switch release 
                writeData('5'); //Display Key5 
                delay(5);
            }
        }
        if (temp == 0xD0) //Press Key9 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xD0) {
                while ((P2 & 0xF0) == 0xD0); //Wait for switch release 
                writeData('9'); //Display Key9 
                delay(5);
            }
        }
        if (temp == 0xE0) //Press Key C 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xE0) {
                while ((P2 & 0xF0) == 0xE0); //Wait for switch release 
                writeData('c'); //Display Key C 
                delay(5);
            }
        }
        /*----------------Scan 2nd line------------------------------------*/
        P2 = 0xFD; //Scan 2nd line 
        temp = P2; //Read in P2 
        temp = temp & 0xF0; //Set b3-b0 = 0 in temp 
        if (temp == 0x70) //Press Key2 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0x70) {
                while ((P2 & 0xF0) == 0x70); //Wait for switch release 
                writeData('2'); //Display Key2 
                delay(5);
            }
        }
        if (temp == 0xB0) //Press Key6 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xB0) {
                while ((P2 & 0xF0) == 0xB0); //Wait for switch release 
                writeData('6'); //Display Key6 
                delay(5);
            }
        }
        if (temp == 0xD0) //Press Key 0 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xD0) {
                while ((P2 & 0xF0) == 0xD0); //Wait for switch release 
                writeData('0'); //Display Key 0 
                delay(5);
            }
        }
        if (temp == 0xE0) //Press Key d 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Check again 
            temp = temp & 0xF0;
            if (temp == 0xE0) {
                while ((P2 & 0xF0) == 0xE0); //Wait for switch release 
                writeData('d'); //Display Key d 
                delay(5);
            }
        }
        /*----------------Scan 3rd line------------------------------------*/
        P2 = 0xFB; //Scan 3rd line 
        temp = P2; //Read in P2 
        temp = temp & 0xF0; //Set b3-b0 = 0 in temp 
        if (temp == 0x70) //Press Key 3 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2
            temp = temp & 0xF0;
            if (temp == 0x70) {
                while ((P2 & 0xF0) == 0x70); //Wait for switch release 
                writeData('3'); //Display Key 3 
                delay(5);
            }
        }
        if (temp == 0xB0) //Press Key 7 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xB0) {
                while ((P2 & 0xF0) == 0xB0); //Wait for switch release 
                writeData('7'); //Display Key 7 
                delay(5);
            }
        }
        if (temp == 0xD0) //Press Key A 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xD0) {
                while ((P2 & 0xF0) == 0xD0); //Wait for switch release 
                writeData('a'); //Display Key A 
                delay(5);
            }
        }
        if (temp == 0xE0) //Press Key e 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xE0) {
                while ((P2 & 0xF0) == 0xE0); //Wait for switch release 
                writeData('e'); //Display Key e 
                delay(5);
            }
        }
        /*----------------Scan 4th line------------------------------------*/
        P2 = 0xF7; //Scan 4th line 
        temp = P2; //Read in P2 
        temp = temp & 0xF0; //Set b3-b0 = 0 in temp 
        if (temp == 0x70) //Press Key 4 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0x70) {
                while ((P2 & 0xF0) == 0x70); //Wait for switch release 
								writeData('4'); //Display Key 4 
                delay(5);
            }
        }
        if (temp == 0xB0) //Press Key 8 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xB0) {
                while ((P2 & 0xF0) == 0xB0); //Wait for switch release 
                writeData('8'); //Display Key 8 
                delay(5);
            }
        }
        if (temp == 0xD0) //Press Key b 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xD0) {
                while ((P2 & 0xF0) == 0xD0); //Wait for switch release 
                writeData('b'); //Display Key b 
                delay(5);
            }
        }
        if (temp == 0xE0) //Press Key e 
        {
            delay(20); //Delay 20ms to debounce 
            temp = P2; //Read in P2 
            temp = temp & 0xF0;
            if (temp == 0xE0) {
                while ((P2 & 0xF0) == 0xE0); //Wait for switch release
								writeData('f'); //Display Key f 
								writeCmd(0x14);
                delay(5);
            }
        }
				writeCmd(0x80);
    }
}



