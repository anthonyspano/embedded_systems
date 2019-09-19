///*----------------------------------------------------------------------------------------------
// File Name: ShiftBlinking.C
// Author: Alex Yang, Northwestern Polytechnic University, Fremont, CA
//				 Anthony Spano
// Date: 8/24/2013
//			 9/18/2019
// Description: The program is to blink 7 LEDs by left-shift, calling function
//from library.
// --------------------------------------------------------------------------------------------*/

//#include <reg52.h> //Special function register declarations
//#include <intrins.h> //For calling _ crol_ function
//#define uint unsigned int //Define new data type for future use

//void delay(uint z) //Delay function declaration
//{
//	uint x,y;
//	for(x=z; x>0; x--) //Run nested for loop to generate delay
//	for(y=415; y>0; y--);
//}

//void main (void)
//{

//// #1
////	P1 = 0xFE; // Switch on LED 1 
////	while (1)
////	{
////		while(P1 != 0x7F)  // while furthest (right) light is not on 
////		{
////			delay(170); //Delay 170ms
////			P1 = _crol_(P1,1); //Rotationally Shift 1 bit toward left
////		}

////		while(P1 != 0xFE)  // while furthest (left) light is not on 
////		{
////			delay(170); //Delay 170ms
////			P1 = _cror_(P1,1); //Rotationally Shift 1 bit toward right
////		}

////	}
//	
//// #2
////	P1 = 0x7E;
////	while(1)
////	{
//			// start from outside and go in
////		delay(170);
////		P1 = 0x7E;
////	
////		delay(170);
////		P1 = 0xBD;
////	
////		delay(170);
////		P1 = 0xDB;

////		delay(170);
////		P1 = 0xE7;

////		delay(170);
////		P1 = 0xDB;

////		delay(170);
////		P1 = 0xBD;
////	}	
//	
//	
//// #3
//	P1 = 0xE7;
//	while(1)
//	{
//		// start from inside and go out
//		// 3,6
//		delay(170);
//		P1 = 0xDB;
//		
//		// 2,7
//		delay(170);
//		P1 = 0xBD;
//		
//		// 1,8
//		delay(170);
//		P1 = 0x7E;
//	  
//		// 2,7
//		delay(170);
//		P1 = 0xBD;
//		
//		// 3,6
//		delay(170);
//		P1 = 0xDB;
//	
//		// 4,5
//		delay(170);
//		P1 = 0xE7;

//	
//	}
//	
//}

