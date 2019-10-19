/*---------------------------------------------------------------------------------------------------
 SWOnOff.C
 Author: Alex Yang, Northwestern Polytechnic University, Fremont, CA
         Anthony Spano
 Date: 8/26/2013
 Description: Press switch 1 to move the LED from right to left. Lab question #1
 ---------------------------------------------------------------------------------------------------*/
#include <REG52.H> //Special function register declarations 
#define uint unsigned int //Define new data type for future use
#define uchar unsigned char
#include <intrins.h> //For calling _ crol_ function

sbit SW1=P2^4; //Get value from SW1
sbit LED1=P2^5; //Drive LED1
void delay(uint z) //Delay function declaration
{
uint x,y;
for(x=z; x>0; x--) //Run nested for loop to generate delay
for(y=415; y>0; y--);
}


void rotate()
{
        delay(170); //Delay 170ms
        P1 = _cror_(P1,1); //Rotationally Shift 1 bit toward right (0xBF)       
}

void main (void)
{
        uchar pressNum=0; //Set SW on and off for LED1
        //LED1=1;
        P1 = 0x7F;
        
        while (1)
        {
                if(SW1==0)
                {
                        delay(20); //Delay 20ms to debounce
                        if(SW1==0)
                        {
                                while(!SW1); //Wait for switch release
                                // switch on NEXT LED
                                if(pressNum==0) rotate();
                                if(pressNum==1) rotate(); //Switch off LED1
                                pressNum++;
                                if(pressNum==2) pressNum=0; //Reset
                        }
                }
        }
        
}
