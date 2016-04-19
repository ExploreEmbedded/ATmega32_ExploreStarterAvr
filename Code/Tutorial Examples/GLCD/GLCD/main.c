/*
 *  Program to demonstrate displaying of message on GLCD
 *
 * Created: 01/01/2015 8:25:05 PM
 *  Author: exploreembedded.com
 * note: Refer glcd.h file for Pin connections
 */ 

#include "glcd.h"	//User defined LCD library which conatins the lcd routines

/* start the main program */
int main(void) 
{
	
	  GLCD_Init();
	  GLCD_Printf("Hello World!");
	  GLCD_GoToLine(4);
	  GLCD_Printf("*&^%$#@!~");
	  GLCD_GoToLine(7);
	  GLCD_DisplayString("Well this is the end!");
	  while(1);
	 
}