/***************************************************************************************************
                                   ExploreEmbedded	
 ****************************************************************************************************
 * File:   glcd.h
 * Version: 15.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: Contains the GLCD port configurations, CMD list, function prototypes

The libraries have been tested on ExploreEmbedded development boards. We strongly believe that the 
library works on any of development boards for respective controllers. However, ExploreEmbedded 
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information 
related to updates. 


GNU GENERAL PUBLIC LICENSE: 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 

Errors and omissions should be reported to codelibraries@exploreembedded.com
 **************************************************************************************************/



/***************************************************************************************************
                             Revision History
 ****************************************************************************************************
15.0: Initial version 
 ***************************************************************************************************/
#ifndef _GLCD_H_
#define _GLCD_H_

#include <avr\io.h>
#include "stdutils.h"



/***************************************************************************************************
                                 GLCD PORT Configuration
 ***************************************************************************************************/
#define M_GlcdDataBus	PORTA
#define M_GlcdDataBusDirection DDRA
#define M_GlcdDataBusInput PINA

#define M_GlcdControlBus PORTC
#define M_GlcdControlBusDirection DDRC

#define GLCD_RS 0
#define GLCD_RW 1
#define GLCD_EN 2
#define GLCD_CS1 3
#define GLCD_CS2 4
#define GLCD_D7 7


#define M_GlcdClearBit(x)   util_BitClear((M_GlcdControlBus),(x))
#define M_GlcdSetBit(x)     util_BitSet((M_GlcdControlBus),(x))

/**************************************************************************************************/










/***************************************************************************************************
                 PreCompile configurations to enable/disable the functions
 ***************************************************************************************************
PreCompile configuration to enable or disable the API's.
 1.Required interfaces can be enabled/disabled by configuring its respective macros to 1/0.
 2. By default all the API's are enabled except for FLOAT display.
 3. Displaying of floating number takes huge controller resources and need to be enabled only 
    if required. This implies for other interfaces as well. 
 ***************************************************************************************************/
#define    Enable_GLCD_DisplayString          1
#define    Enable_GLCD_DisplayDecimalNumber   1
#define    Enable_GLCD_DisplayHexNumber       1
#define    Enable_GLCD_DisplayBinaryNumber    1
#define    Enable_GLCD_DisplayFloatNumber     1
#define    Enable_GLCD_Printf                 1
#define    Enable_GLCD_DisplayLogo            1
/**************************************************************************************************/





/***************************************************************************************************
                             Commonly used LCD macros/Constants
***************************************************************************************************/
#define BlankSpace ' '

#define C_GlcdDisplayDefaultDigits_U8            0xffu // Will display the exact digits in the number
#define C_GlcdMaxDigitsToDisplay_U8              10u   // Max decimal/hexadecimal digits to be displayed
#define C_GlcdNumOfBinDigitsToDisplay_U8         16u   // Max bits of a binary number to be displayed
#define C_GlcdMaxDigitsToDisplayUsingPrintf_U8   C_GlcdDisplayDefaultDigits_U8 /* Max dec/hexadecimal digits to be displayed using printf */


#define C_GlcdFirstLine_U8 0x00u
#define C_GlcdLastLine_U8 0x07u
#define C_FirstLineNumberAddress_U8 0xB8
#define C_LastLineNumberAddress_U8  0xBF


#define C_MaxBarGraphs_U8 0x04
#define C_LookUpOffset_U8 0x20
/**************************************************************************************************/





/***************************************************************************************************
                                 Struct/Enums used
 ***************************************************************************************************/
typedef struct{
	uint8_t PageNum;
	uint8_t LineNum;
	uint8_t CursorPos;
	uint8_t Invertdisplay;
}GLCD_Config;
/**************************************************************************************************/





/***************************************************************************************************
                             Function Prototypes
 ***************************************************************************************************/
void GLCD_Init();
void GLCD_Clear();
void GLCD_SetCursor(uint8_t pageNumber,uint8_t lineNumber,uint8_t CursorPosition);
void GLCD_GetCursor(uint8_t *page_ptr,uint8_t *line_ptr,uint8_t *cursor_ptr);
void GLCD_GoToPage(uint8_t pageNumber);
void GLCD_GoToLine(uint8_t var_lineNumber_u8);
void GLCD_GoToNextLine();
void GLCD_EnableDisplayInversion();
void GLCD_DisableDisplayInversion();
void GLCD_DisplayChar(uint8_t var_lcdData_u8);
void GLCD_DisplayString(char *ptr_stringPointer_u8);
void GLCD_ScrollMessage(uint8_t var_lineNumber_u8, char *ptr_msgPointer_u8);
void GLCD_DisplayDecimalNumber(uint32_t var_DecNumber_u32, uint8_t var_numOfDigitsToDisplay_u8);
void GLCD_DisplayHexNumber(uint32_t var_hexNumber_u32,uint8_t var_numOfDigitsToDisplay_u8);
void GLCD_DisplayBinaryNumber(uint32_t var_binNumber_u32, uint8_t var_numOfBitsToDisplay_u8);
void GLCD_DisplayFloatNumber(double var_floatNum_f32);
void GLCD_Printf(const char *argList, ...);
void GLCD_DisplayLogo();
void GLCD_DisplayVerticalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8);
void GLCD_DisplayHorizontalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8);
/**************************************************************************************************/
#endif
