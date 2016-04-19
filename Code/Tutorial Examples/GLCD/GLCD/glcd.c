#include <stdarg.h>
#include <avr\pgmspace.h>
#include "glcd.h"
#include "delay.h"


GLCD_Config GLCD;



const uint8_t ARR_GlcdFont_U8[][7] PROGMEM= {
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff}, /* 0x00  */
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff}, /* 0x10  */
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
		{0xff,0xff,0xff,0xff,0xff,0x00,0xff},
        {0x00,0x00,0x00,0x00,0x00,0xff,0xff}, /* Space 0x20 */
        {0x00,0x00,0x4f,0x00,0x00,0x00,0xff}, /* ! */
        {0x00,0x07,0x00,0x07,0x00,0x00,0xff}, /* " */
        {0x14,0x7f,0x14,0x7f,0x14,0x00,0xff}, /* # */
        {0x24,0x2a,0x7f,0x2a,0x12,0x00,0xff}, /* 0x */
        {0x23,0x13,0x08,0x64,0x62,0x00,0xff}, /* % */
        {0x36,0x49,0x55,0x22,0x20,0x00,0xff}, /* & */
        {0x00,0x05,0x03,0x00,0x00,0x00,0xff}, /* ' */
        {0x00,0x1c,0x22,0x41,0x00,0x00,0xff}, /* ( */
        {0x00,0x41,0x22,0x1c,0x00,0x00,0xff}, /* ) */
        {0x14,0x08,0x3e,0x08,0x14,0x00,0xff}, /* // */
        {0x08,0x08,0x3e,0x08,0x08,0x00,0xff}, /* + */
        {0x50,0x30,0x00,0x00,0x00,0x00,0xff}, /* , */
        {0x08,0x08,0x08,0x08,0x08,0x00,0xff}, /* - */
        {0x00,0x60,0x60,0x00,0x00,0x00,0xff}, /* . */
        {0x20,0x10,0x08,0x04,0x02,0x00,0xff}, /* / */
        {0x3e,0x51,0x49,0x45,0x3e,0x00,0xff}, /* 0 0x30 */
        {0x40,0x42,0x7f,0x40,0x40,0x00,0xff}, /* 1 */
        {0x42,0x61,0x51,0x49,0x46,0x00,0xff}, /* 2 */
        {0x21,0x41,0x45,0x4b,0x31,0x00,0xff}, /* 3 */
        {0x18,0x14,0x12,0x7f,0x10,0x00,0xff}, /* 4 */
        {0x27,0x45,0x45,0x45,0x39,0x00,0xff}, /* 5 */
        {0x3c,0x4a,0x49,0x49,0x30,0x00,0xff}, /* 6 */
        {0x01,0x71,0x09,0x05,0x03,0x00,0xff}, /* 7 */
        {0x36,0x49,0x49,0x49,0x36,0x00,0xff}, /* 8 */
        {0x06,0x49,0x49,0x29,0x1e,0x00,0xff}, /* 9 */
        {0x00,0x36,0x36,0x00,0x00,0x00,0xff}, /* : */
        {0x00,0x56,0x36,0x00,0x00,0x00,0xff}, /* ; */
        {0x08,0x14,0x22,0x41,0x00,0x00,0xff}, /* < */
        {0x14,0x14,0x14,0x14,0x14,0x00,0xff}, /* = */
        {0x00,0x41,0x22,0x14,0x08,0x00,0xff}, /* > */
        {0x02,0x01,0x51,0x09,0x06,0x00,0xff}, /* ? */
        {0x3e,0x41,0x5d,0x55,0x1e,0x00,0xff}, /* @ 0x40 */
        {0x7e,0x11,0x11,0x11,0x7e,0x00,0xff}, /* A */
        {0x7f,0x49,0x49,0x49,0x36,0x00,0xff}, /* B */
        {0x3e,0x41,0x41,0x41,0x22,0x00,0xff}, /* C */
        {0x7f,0x41,0x41,0x22,0x1c,0x00,0xff}, /* D */
        {0x7f,0x49,0x49,0x49,0x41,0x00,0xff}, /* E */
        {0x7f,0x09,0x09,0x09,0x01,0x00,0xff}, /* F */
        {0x3e,0x41,0x49,0x49,0x7a,0x00,0xff}, /* G */
        {0x7f,0x08,0x08,0x08,0x7f,0x00,0xff}, /* H */
        {0x00,0x41,0x7f,0x41,0x00,0x00,0xff}, /* I */
        {0x20,0x40,0x41,0x3f,0x01,0x00,0xff}, /* J */
        {0x7f,0x08,0x14,0x22,0x41,0x00,0xff}, /* K */
        {0x7f,0x40,0x40,0x40,0x40,0x00,0xff}, /* L */
        {0x7f,0x02,0x0c,0x02,0x7f,0x00,0xff}, /* M */
        {0x7f,0x04,0x08,0x10,0x7f,0x00,0xff}, /* N */
        {0x3e,0x41,0x41,0x41,0x3e,0x00,0xff}, /* O */
        {0x7f,0x09,0x09,0x09,0x06,0x00,0xff}, /* P 0x50 */
        {0x3e,0x41,0x51,0x21,0x5e,0x00,0xff}, /* Q */
        {0x7f,0x09,0x19,0x29,0x46,0x00,0xff}, /* R */
        {0x26,0x49,0x49,0x49,0x32,0x00,0xff}, /* S */
        {0x01,0x01,0x7f,0x01,0x01,0x00,0xff}, /* T */
        {0x3f,0x40,0x40,0x40,0x3f,0x00,0xff}, /* U */
        {0x1f,0x20,0x40,0x20,0x1f,0x00,0xff}, /* V */
        {0x3f,0x40,0x38,0x40,0x3f,0x00,0xff}, /* W */
        {0x63,0x14,0x08,0x14,0x63,0x00,0xff}, /* X */
        {0x07,0x08,0x70,0x08,0x07,0x00,0xff}, /* Y */
        {0x61,0x51,0x49,0x45,0x43,0x00,0xff}, /* Z */
        {0x00,0x7f,0x41,0x41,0x00,0x00,0xff}, /* [ */
        {0x02,0x04,0x08,0x10,0x20,0x00,0xff}, /* \ */
        {0x00,0x41,0x41,0x7f,0x00,0x00,0xff}, /* ] */
        {0x04,0x02,0x01,0x02,0x04,0x00,0xff}, /* ^ */
        {0x40,0x40,0x40,0x40,0x40,0x00,0xff}, /* _ */
        {0x00,0x00,0x03,0x05,0x00,0x00,0xff}, /* ` 0x60 */
        {0x20,0x54,0x54,0x54,0x78,0x00,0xff}, /* a */
        {0x7F,0x44,0x44,0x44,0x38,0x00,0xff}, /* b */
        {0x38,0x44,0x44,0x44,0x44,0x00,0xff}, /* c */
        {0x38,0x44,0x44,0x44,0x7f,0x00,0xff}, /* d */
        {0x38,0x54,0x54,0x54,0x18,0x00,0xff}, /* e */
        {0x04,0x04,0x7e,0x05,0x05,0x00,0xff}, /* f */
        {0x08,0x54,0x54,0x54,0x3c,0x00,0xff}, /* g */
        {0x7f,0x08,0x04,0x04,0x78,0x00,0xff}, /* h */
        {0x00,0x44,0x7d,0x40,0x00,0xff,0xff}, /* i */
        {0x20,0x40,0x44,0x3d,0x00,0xff,0xff}, /* j */
        {0x7f,0x10,0x28,0x44,0x00,0xff,0xff}, /* k */
        {0x41,0x7f,0x40,0x00,0xff,0xff,0xff}, /* l */
        {0x7c,0x04,0x7c,0x04,0x78,0x00,0xff}, /* m */
        {0x7c,0x08,0x04,0x04,0x78,0x00,0xff}, /* n */
        {0x38,0x44,0x44,0x44,0x38,0x00,0xff}, /* o */
        {0x7c,0x14,0x14,0x14,0x08,0x00,0xff}, /* p 0x70 */
        {0x08,0x14,0x14,0x14,0x7c,0x00,0xff}, /* q */
        {0x7c,0x08,0x04,0x04,0x00,0xff,0xff}, /* r */
        {0x48,0x54,0x54,0x54,0x24,0x00,0xff}, /* s */
        {0x04,0x04,0x3f,0x44,0x44,0x00,0xff}, /* t */
        {0x3c,0x40,0x40,0x20,0x7c,0x00,0xff}, /* u */
        {0x1c,0x20,0x40,0x20,0x1c,0x00,0xff}, /* v */
        {0x3c,0x40,0x30,0x40,0x3c,0x00,0xff}, /* w */
        {0x44,0x28,0x10,0x28,0x44,0x00,0xff}, /* x */
        {0x0c,0x50,0x50,0x50,0x3c,0x00,0xff}, /* y */
        {0x44,0x64,0x54,0x4c,0x44,0x00,0xff}, /* z */
        {0x08,0x36,0x41,0x41,0x00,0x00,0xff}, /* { */
        {0x00,0x00,0x77,0x00,0x00,0x00,0xff}, /* | */
        {0x00,0x41,0x41,0x36,0x08,0x00,0xff}, /* } */
        {0x08,0x08,0x2a,0x1c,0x08,0x00,0xff}, /* <- */
        {0x08,0x1c,0x2a,0x08,0x08,0x00,0xff}, /* -> */
        {0xff,0xff,0xff,0xff,0xff,0x00,0xff}, /*  0x80 */
};



/*************************************************************************************************
                                Local Functions
*************************************************************************************************/
static void glcd_CmdWrite( uint8_t var_lcdCmd_u8);
static void glcd_DataWrite( uint8_t var_data_u8);
static void glcd_BusyCheck();
static void glcd_SelectPage0();
static void glcd_SelectPage1();
/************************************************************************************************/
								


/**************************************************************************************************
void GLCD_Init
***************************************************************************************************
 * Function name:  GLCD_Init
 * I/P Arguments:  none
 * Return value    : none

 * description  :This function is used to initialize the GLCD.
                 
**************************************************************************************************/
void GLCD_Init()
{
	M_GlcdControlBusDirection = C_PortOutput_U8; /* Configure the data bus and Control bus as Output */
    M_GlcdDataBusDirection = C_PortOutput_U8;


    /* Select the Page0/Page1 and Enable the GLCD */
    glcd_SelectPage0();
    glcd_CmdWrite(0x3f);
    glcd_SelectPage1();
    glcd_CmdWrite(0x3f);
    DELAY_ms(10);

    /* Select the Page0/Page1 and Enable the GLCD */
    glcd_SelectPage0();
    glcd_CmdWrite(0xc0);
    glcd_SelectPage1();
    glcd_CmdWrite(0xc0);

   /* Clear the complete LCD and move the cursor to beginning of page0*/
    GLCD_Clear();
}










/***************************************************************************************************
                         void GLCD_Clear()
 ***************************************************************************************************
 * I/P Arguments: none.
 * Return value    : none

 * description  :This function clears the LCD and moves the cursor to beginning of first line on page0
 ***************************************************************************************************/
void GLCD_Clear()
{
    uint8_t line,cursor,inversion;

    inversion = GLCD.Invertdisplay;
	GLCD.Invertdisplay = 0x00;
	
    for(line=0;line<8;line++)  /* loop through all the 8lines to clear the display */
    {
         GLCD_GoToLine(line);  /* Go to beginning of the specified line on page0 */
        
        for(cursor=0;cursor<128;cursor++) /* Clear all the 128 pixels of selected line */
        {
            if(cursor==64)  /* Has the cursor reached end of page0 */
            {
                GLCD_GoToPage(1); /*  then set it to beginning of page1 */
                
            }
            glcd_DataWrite(0x00); /* Clear each pixel by displaying blank */
        }
    }
	
	GLCD.Invertdisplay = inversion;

    GLCD_GoToLine(0);
}













/***************************************************************************************************
      void GLCD_SetCursor(uint8_t pageNumber,uint8_t lineNumber,uint8_t CursorPosition)
 ***************************************************************************************************
 * I/P Arguments: char row,char col
                 row -> line number(line1=1, line2=2),
                        For 2line LCD the I/P argument should be either 1 or 2.
                 col -> char number.
                        For 16-char LCD the I/P argument should be between 0-15.
 * Return value    : none

 * description  :This function moves the Cursor to specified position

                   Note:If the Input(Line/Char number) are out of range 
                        then no action will be taken
 ***************************************************************************************************/
 /* TODO: change the var names, Add logic for page handling */
void GLCD_SetCursor(uint8_t pageNumber,uint8_t lineNumber,uint8_t CursorPosition)
{
    if(    ((pageNumber == 0x00)   || (pageNumber == 0x01))
	    && ((lineNumber >=0x00)    && (lineNumber <= C_GlcdLastLine_U8))
	    && ((CursorPosition>=0x00) && (CursorPosition <= 63)) )
	  {
	    if(pageNumber==0x00)  /* Check for page number and set accordingly */
         {
           glcd_SelectPage0();
         }
        else
	     {
            glcd_SelectPage1();
	      }	 

        GLCD.PageNum = pageNumber; /* Keep the track of page selected */
        GLCD.LineNum=lineNumber | C_FirstLineNumberAddress_U8; /* Select the specified line number */
        GLCD.CursorPos=CursorPosition |0x40; /* Select the specified cursor position */
        glcd_CmdWrite(GLCD.CursorPos); /* Command the LCD to move to specified page,line,cursor*/
        glcd_CmdWrite(GLCD.LineNum);
	}
}







void GLCD_GetCursor(uint8_t *page_ptr,uint8_t *line_ptr,uint8_t *cursor_ptr)
{

    *page_ptr=GLCD.PageNum;
    *line_ptr=GLCD.LineNum;
    *cursor_ptr=GLCD.CursorPos;
}



/***************************************************************************************************
                      void GLCD_GoToPage(uint8_t pageNumber)
 ***************************************************************************************************
 * I/P Arguments: uint8_t: Line number.
 * Return value    : none

 * description  :This function moves the Cursor to beginning of the specified line.
        If the requested line number is out of range, it will not move the cursor.

     Note: The line numbers run from 1 to Maxlines,
 ***************************************************************************************************/
 /* TODO: change the desp and variable name */
void GLCD_GoToPage(uint8_t pageNumber)
{

    if((pageNumber==0) || (pageNumber ==1))
    { /* for 128/64 GLCD only page 0&1 are supported.
        Select the specified page and move the cursor accordingly */
        if(pageNumber == 0)
        {

            glcd_SelectPage0();
        }
        else
        {
            glcd_SelectPage1();
        }
        GLCD.PageNum=pageNumber;
        GLCD.CursorPos=0x40;
        glcd_CmdWrite(GLCD.LineNum);
        glcd_CmdWrite(GLCD.CursorPos);
    }
}







/***************************************************************************************************
                         void GLCD_GoToLine(uint8_t var_lineNumber_u8)
 ***************************************************************************************************
 * I/P Arguments: uint8_t: Line number.
 * Return value    : none

 * description  :This function moves the Cursor to beginning of the specified line.
        If the requested line number is out of range, it will not move the cursor.

     Note: The line numbers run from 0 to Maxlines-1, For 128x64 the line numbers will be 0-7
***************************************************************************************************/
/* Todo: All constants for the magic numbers */
void  GLCD_GoToLine(uint8_t var_lineNumber_u8)
{
    if(var_lineNumber_u8 <= C_GlcdLastLine_U8)
    {   /* If the line number is within range
         then move it to specified line on page0 and keep track*/
        GLCD.LineNum = var_lineNumber_u8+C_FirstLineNumberAddress_U8;
        GLCD_GoToPage(0);
    }
}





/***************************************************************************************************
                         void  GLCD_GoToNextLine()
 ***************************************************************************************************
 * I/P Arguments: none
 * Return value    : none

 * description  :This function moves the Cursor to beginning of the next line.
        If the cursor is on last line and NextLine command is issued then 
        it will move the cursor to first line.
 ***************************************************************************************************/
void  GLCD_GoToNextLine()
{
    /*Increment the current line number.
      In case it exceeds the limit, rool it back to first line */
    GLCD.LineNum++;
    if(GLCD.LineNum > C_LastLineNumberAddress_U8)
      GLCD.LineNum = C_FirstLineNumberAddress_U8;
    GLCD_GoToPage(0); /* Finally move it to next line on page0 */
}




void GLCD_EnableDisplayInversion()
{
	GLCD.Invertdisplay = 0xff;
}



void GLCD_DisableDisplayInversion()
{
	GLCD.Invertdisplay = 0x00;
}




/***************************************************************************************************
                       void GLCD_DisplayChar( char var_lcdData_u8)
 ***************************************************************************************************
 * I/P Arguments: ASCII value of the char to be displayed.
 * Return value    : none

 * description  : This function sends a character to be displayed on LCD.
                  Any valid ascii value can be passed to display respective character

 ***************************************************************************************************/
 /* Add the comments for decoding the character, Even offset handling*/
void GLCD_DisplayChar(uint8_t var_lcdData_u8)
{
    uint8_t dat,*ptr;


    if(((GLCD.PageNum == 0x01) && (GLCD.CursorPos>=0x7c)) || (var_lcdData_u8=='\n'))
    {
        /* If the cursor has reached to end of line on page1
        OR NewLine command is issued Then Move the cursor to next line */
        GLCD_GoToNextLine();
    }
       if(var_lcdData_u8!='\n') /* TODO */
    {
        ptr= &ARR_GlcdFont_U8[var_lcdData_u8][0]; /* Get the address of the Character pattern from LookUp */
        while(1)
        {
            if((GLCD.PageNum == 0x00) && (GLCD.CursorPos==0x80))
            {
                /* If the cursor has reached to end of line on page0
                     Then Move the cursor to Page1 */
                GLCD_GoToPage(1);
            }

            dat= pgm_read_byte(ptr++);/* Get the data to be displayed for LookUptable*/

            if(dat==0xff) /* Exit the loop if End of char is encountered */
                break;

            glcd_DataWrite(dat); /* Display the data and keep track of cursor */
            GLCD.CursorPos++;
        }
    }
}






/***************************************************************************************************
                       void GLCD_DisplayString(char *ptr_stringPointer_u8)
 ***************************************************************************************************
 * I/P Arguments: String(Address of the string) to be displayed.
 * Return value    : none

 * description  :
               This function is used to display the ASCII string on the lcd.
                 1.The ptr_stringPointer_u8 points to the first char of the string
                    and traverses till the end(NULL CHAR)and displays a char each time.

 ***************************************************************************************************/
#if (Enable_GLCD_DisplayString==1)
void GLCD_DisplayString(char *ptr_stringPointer_u8)
{
    while((*ptr_stringPointer_u8)!=0)
        GLCD_DisplayChar(*ptr_stringPointer_u8++); // Loop through the string and display char by char
}
#endif







/***************************************************************************************************
               void GLCD_ScrollMessage(uint8_t var_lineNumber_u8, char *ptr_msgPointer_u8)
 ***************************************************************************************************
 * I/P Arguments: 
                  uint8_t  : Line number on which the message has to be scrolled
                  char *: pointer to the string to be scrolled                      

 * Return value    : none

 * description  :This function scrolls the given message on the specified line.
                 If the specified line number is out of range then the message
                 will be scrolled on first line
 ***************************************************************************************************/
#if ( Enable_GLCD_ScrollMessage  == 1 )
void GLCD_ScrollMessage(uint8_t var_lineNumber_u8, char *ptr_msgPointer_u8)
{
    unsigned char i,j;


    if(var_lineNumber_u8 > STK_LCDConfig.mvar_MaxSupportedLines_U8)
        var_lineNumber_u8 = mENUM_LcdLineOne; // Select first line if the var_lineNumber_u8 is out of range

    glcd_CmdWrite(CMD_DISPLAY_ON_CURSOR_OFF);             //Disable the Cursor

    for(i=0;ptr_msgPointer_u8[i];i++)
    {      
        /* Loop to display the complete string,    each time 16 chars are displayed and
        pointer is incremented to point to next char */


        GLCD_GoToLine(var_lineNumber_u8);     //Move the Cursor to first line

        for(j=0;j<STK_LCDConfig.mvar_MaxSupportedChars_U8 && ptr_msgPointer_u8[i+j];j++)
        {
            //Display first 16 Chars or till Null char is reached
            GLCD_DisplayChar(ptr_msgPointer_u8[i+j]);
        }


        while( j<STK_LCDConfig.mvar_MaxSupportedChars_U8)
        {
            /*If the chars to be scrolled are less than MaxLcdChars,
              then display remaining chars with blank spaces*/
            GLCD_DisplayChar(' ');
            j++;
        }

        DELAY_ms(125);
    }
    glcd_CmdWrite(CMD_DISPLAY_ON_CURSOR_ON);              // Finally enable the Cursor
}
#endif






/***************************************************************************************************
            void  GLCD_DisplayNumber(uint32_t var_DecNumber_u32, uint8_t var_numOfDigitsToDisplay_u8 )
 ***************************************************************************************************
 * Function name:  GLCD_DisplayNumber()
 * I/P Arguments: uint32_t: Number to be displayed on the LCD.
                  uint8_t : Number of digits to be displayed
 * Return value    : none

 * description  :This function is used to display a max of 10digit decimal number.
                2nd parameter specifies the number of digits from the right side to be displayed
                 The output for the input combinations is as below
                1.(12345,4) then 4-digits ie. 2345 will be displayed
                2.(12345,6) then 6-digits ie. 012345 will be displayed
                3.(12345,C_DisplayDefaultDigits_U8) then 12345 will be displayed.
 ***************************************************************************************************/
#if ((Enable_GLCD_DisplayDecimalNumber == 1) || (Enable_GLCD_DisplayFloatNumber == 1))
void GLCD_DisplayDecimalNumber(uint32_t var_DecNumber_u32, uint8_t var_numOfDigitsToDisplay_u8)
{
    uint8_t i=0,a[10];

    if(var_DecNumber_u32==0)
    {
        /* If the number is zero then update the array with the same for displaying */
        for(i=0;((i<var_numOfDigitsToDisplay_u8) && (i<C_GlcdMaxDigitsToDisplay_U8));i++)
            a[i] = 0x00;
    }
    else
    {
        for(i=0;i<var_numOfDigitsToDisplay_u8;i++)
        {
            /* Continue extracting the digits from right side
               till the Specified var_numOfDigitsToDisplay_u8 */
            if(var_DecNumber_u32!=0)
            {
                /* Extract the digits from the number till it becomes zero.
                First get the remainder and divide the number by 10 each time.
                If var_num_u32 = 123 then extracted remainder will be 3 and number will be 12.
                The process continues till it becomes zero or max digits reached*/
                a[i]=util_GetMod32(var_DecNumber_u32,10);
                var_DecNumber_u32=var_DecNumber_u32/10;
            }
            else if( (var_numOfDigitsToDisplay_u8 == C_GlcdDisplayDefaultDigits_U8) ||
                     (var_numOfDigitsToDisplay_u8 > C_GlcdMaxDigitsToDisplay_U8))
            {
                /* Stop the iteration if the Max number of digits are reached or 
                 the user expects exact(Default) digits in the number to be displayed */ 
                break;
            }
            else
            {
                /* In case user expects more digits to be displayed than the actual digits in number,
                  then update the remaining digits with zero.
               Ex: var_num_u32 is 123 and user wants five digits then 00123 has to be displayed */
                a[i]=0;
            }
        }
    }


    while(i)
    { 
        /* Finally get the ascii values of the digits and display*/
        GLCD_DisplayChar(util_Dec2Ascii(a[i-1]));
        i--;
    }
}
#endif





/***************************************************************************************************
         void  GLCD_DisplayHexNumber(uint32_t var_hexNumber_u32, uint8_t var_numOfDigitsToDisplay_u8 )
 ***************************************************************************************************
 * Function name:  GLCD_DisplayHexNumber()
 * I/P Arguments: uint32_t: Hexadecimal Number to be displayed on the LCD.
                  uint8_t : Number of digits to be displayed
 * Return value    : none

 * description  :This function is used to display a max of 10digit hex number.
                 2nd parameter specifies the number of digits from the right side to be displayed
                 The output for the input combinations is as below
                1.(0x12AB,3) then 3-digits ie. 2AB will be displayed
                2.(0x12AB,6) then 6-digits ie. 0012AB will be displayed
                3.(0x12AB,C_DisplayDefaultDigits_U8) then 12AB will be displayed.
 ***************************************************************************************************/
#if ( Enable_GLCD_DisplayHexNumber == 1 ) 
void GLCD_DisplayHexNumber(uint32_t var_hexNumber_u32,uint8_t var_numOfDigitsToDisplay_u8)
{
    uint8_t i=0,a[10];

    if(var_hexNumber_u32==0)
    {
        /* If the number zero then update the array with the same for displaying */
        for(i=0;((i<var_numOfDigitsToDisplay_u8) && (i<C_GlcdMaxDigitsToDisplay_U8));i++)
            a[i] = 0x00;
    }
    else
    {
        for(i=0;i<var_numOfDigitsToDisplay_u8;i++)
        {
            /* Continue extracting the digits from right side
               till the Specified var_numOfDigitsToDisplay_u8 */
            if(var_hexNumber_u32!=0)
            {
                /* Extract the digits from the number till it becomes zero.
               First get the lower nibble and shift the number 4 times.
               if var_num_u32 = 0xABC then extracted digit will be 0x0C and number will become 0xAB.
               The process continues till it becomes zero or max digits reached*/
                a[i]=(uint8_t)(var_hexNumber_u32 & 0x0f);
                var_hexNumber_u32=var_hexNumber_u32 >> 4;
            }
            else if( (var_numOfDigitsToDisplay_u8 == C_GlcdDisplayDefaultDigits_U8) ||
                     (var_numOfDigitsToDisplay_u8 > C_GlcdMaxDigitsToDisplay_U8))
            {
                /* Stop the iteration if the Max number of digits are reached or 
                 the user expects exact(Default) digits in the number to be displayed */ 
                break;
            }
            else
            {
                /* In case user expects more digits to be displayed than the actual digits in number,
                  then update the remaining digits with zero.
                Ex: var_num_u32 is 0x123 and user wants five digits then 00123 has to be displayed */
                a[i]=0x00;
            }
        }
    }

    while(i!=0)
    {
        /* Finally get the ascii values of the digits and display*/
        GLCD_DisplayChar(util_Hex2Ascii(a[i-1]));
        i--;
    }
}
#endif






/*************************************************************************************************
      void  GLCD_DisplayBinaryNumber(uint32_t var_binNumber_u32, uint8_t var_numOfBitsToDisplay_u8)
 *************************************************************************************************
 * Function name:  GLCD_DisplayBinaryNumber()
 * I/P Arguments: uint32_t: Hexadecimal Number to be displayed on the LCD.
                  uint8_t : Number of bits to be displayed
 * Return value    : none

 * description  :This function is used to display the binary equivalent of the given number.
                 2nd parameter specifies the number of LSB to be displayed
                 The output for the input combinations is as below
                1.(10,4) then 4-LSB will be displayed ie. 1010
                2.(10,8) then 8-LSB will be displayed ie. 00001010
                3.(10,2) then 2-LSB will be displayed ie. 10
 *************************************************************************************************/
#if (Enable_GLCD_DisplayBinaryNumber == 1)
void GLCD_DisplayBinaryNumber(uint32_t var_binNumber_u32, uint8_t var_numOfBitsToDisplay_u8)
{
    uint8_t ch;
      
    while(var_numOfBitsToDisplay_u8!=0)
    {
        /* Start Extracting the bits from the specified bit positions.
         Get the Acsii values of the bits and display */
        ch = util_GetBitStatus(var_binNumber_u32,(var_numOfBitsToDisplay_u8-1));
        GLCD_DisplayChar(util_Dec2Ascii(ch));
        var_numOfBitsToDisplay_u8--;
    }
}
#endif






/*************************************************************************************************
            void  GLCD_DisplayFloatNumber(double var_floatNum_f32)
 *************************************************************************************************
 * Function name:  GLCD_DisplayFloatNumber()
 * I/P Arguments: float: float Number to be displayed on the LCD.

 * Return value    : none

 * description  :This function is used to display a floating point number
                 It supports 6digits of precision.

    Note: Float will be disabled by default as it takes huge controller resources
         It can be enabled by changing value of Enable_GLCD_DisplayFloatNumber to 1 in lcd.h
 **************************************************************************************************/
#if (Enable_GLCD_DisplayFloatNumber == 1)  
void GLCD_DisplayFloatNumber(double var_floatNum_f32)
{
    uint32_t var_temp_u32;
    /* Dirty hack to support the floating point by extracting the integer and fractional part.
      1.Type cast the number to int to get the integer part.
      2.Display the extracted integer part followed by a decimal point(.).
      3.Later the integer part is made zero by subtracting with the extracted integer value.
      4.Finally the fractional part is multiplied by 100000 to support 6-digit precision */

    var_temp_u32 = (uint32_t) var_floatNum_f32;
    GLCD_DisplayDecimalNumber(var_temp_u32,C_GlcdDisplayDefaultDigits_U8);

    GLCD_DisplayChar('.');

    var_floatNum_f32 = var_floatNum_f32 - var_temp_u32;
    var_temp_u32 = var_floatNum_f32 * 1000000;
    GLCD_DisplayDecimalNumber(var_temp_u32,C_GlcdDisplayDefaultDigits_U8);
}
#endif






/*************************************************************************************************
            void GLCD_Printf(const char *argList, ...)
 *************************************************************************************************
 * Function name:  GLCD_Printf()
 * I/P Arguments: variable length arguments similar to printf

 * Return value    : none

 * description  :This function is similar to printf function in C.
                 It takes the arguments with specified format and prints accordingly
                 The supported format specifiers are as below.
                 1. %c: character
                 2. %d: signed 16-bit number
                 3. %D: signed 32-bit number
                 4. %u: unsigned 16-bit number
                 5. %U: unsigned 32-bit number
                 6. %b: 16-bit binary number
                 7. %B: 32-bit binary number
                 8. %f: Float number
                 9. %x: 16-bit hexadecimal number
                 10. %X: 32-bit hexadecimal number
                 11. %s: String

  Note: By default all the functions will be disabled. The required functions can be enabled by 
        setting the respective compiler switch to 1 in lcd.h file.
        Ex:  setting Enable_GLCD_DisplayDecimalNumber to 1 will enable %d
             setting Enable_GLCD_DisplayHexNumber to 1 will enable %x

  Extra feature is available to specify the number of digits to be displayed using printf.
     ex: %4d: will display the lower four digits of the decimal number.
         %12b: will display the 12-LSB of the number
         %d: Will display the exact digits of the number
         
 #####: In case of printing the variables(8-bit) its recommended to type cast and promote them to uint16_t.
        uint8_t var_Num_u8;
        GLCD_Printf("num1:%u",(uint16_t)var_Num_u8);          
 *************************************************************************************************/
#if ( Enable_GLCD_Printf   == 1 ) 
void GLCD_Printf(const char *argList, ...)
{
    const char *ptr;
    double var_floatNum_f32;
    va_list argp;
    sint16_t var_num_s16;
    sint32_t var_num_s32;
    uint16_t var_num_u16;
    uint32_t var_num_u32;
    char *str;
    char  ch;
    uint8_t var_numOfDigitsToDisp_u8;

    va_start(argp, argList);

    /* Loop through the list to extract all the input arguments */
    for(ptr = argList; *ptr != '\0'; ptr++)
    {

        ch= *ptr;
        if(ch == '%')         /*Check for '%' as there will be format specifier after it */
        {
            ptr++;
            ch = *ptr;
           if((ch>=0x30) && (ch<=0x39))
            {
               var_numOfDigitsToDisp_u8 = 0;
               while((ch>=0x30) && (ch<=0x39))
                {
                   var_numOfDigitsToDisp_u8 = (var_numOfDigitsToDisp_u8 * 10) + (ch-0x30);
                   ptr++;
                   ch = *ptr;
                }
            }
            else
            {
              var_numOfDigitsToDisp_u8 = C_GlcdMaxDigitsToDisplayUsingPrintf_U8;
            }


            switch(ch)       /* Decode the type of the argument */
            {
            case 'C':
            case 'c':     /* Argument type is of char, hence read char data from the argp */
                ch = va_arg(argp, uint16_t);
                GLCD_DisplayChar(ch);
                break;

            case 'd':    /* Argument type is of signed integer, hence read 16bit data from the argp */
                var_num_s16 = va_arg(argp, sint16_t);
#if (Enable_GLCD_DisplayDecimalNumber == 1)
                if(var_num_s16<0)
                 { /* If the number is -ve then display the 2's complement along with '-' sign */ 
                   var_num_s16 = -var_num_s16;
                   GLCD_DisplayChar('-');
                 }
                GLCD_DisplayDecimalNumber(var_num_s16,var_numOfDigitsToDisp_u8);
#endif
                break;
                
            case 'D':    /* Argument type is of integer, hence read 16bit data from the argp */
                var_num_s32 = va_arg(argp, sint32_t);
#if (Enable_GLCD_DisplayDecimalNumber == 1)                
                if(var_num_s32<0)
                 { /* If the number is -ve then display the 2's complement along with '-' sign */
                   var_num_s32 = -var_num_s32;
                   GLCD_DisplayChar('-');
                 }
                GLCD_DisplayDecimalNumber(var_num_s32,var_numOfDigitsToDisp_u8);
#endif                
                break;    

            case 'u':    /* Argument type is of unsigned integer, hence read 16bit unsigned data */
                var_num_u16 = va_arg(argp, uint16_t);
#if (Enable_GLCD_DisplayDecimalNumber == 1)                
                GLCD_DisplayDecimalNumber(var_num_u16,var_numOfDigitsToDisp_u8);
#endif                
                break;
            
            case 'U':    /* Argument type is of integer, hence read 32bit unsigend data */
                var_num_u32 = va_arg(argp, uint32_t);
#if (Enable_GLCD_DisplayDecimalNumber == 1)                
                GLCD_DisplayDecimalNumber(var_num_u32,var_numOfDigitsToDisp_u8);
#endif                
                break;            

            case 'x':  /* Argument type is of hex, hence hexadecimal data from the argp */
                var_num_u16 = va_arg(argp, uint16_t);
#if (Enable_GLCD_DisplayHexNumber == 1)                
                GLCD_DisplayHexNumber(var_num_u16,var_numOfDigitsToDisp_u8);
#endif                
                break;

            case 'X':  /* Argument type is of hex, hence hexadecimal data from the argp */
                var_num_u32 = va_arg(argp, uint32_t);
#if (Enable_GLCD_DisplayHexNumber == 1)                        
                GLCD_DisplayHexNumber(var_num_u32,var_numOfDigitsToDisp_u8);
#endif                
                break;

            
            case 'b':  /* Argument type is of binary,Read int and convert to binary */
                var_num_u16 = va_arg(argp, uint16_t);
#if (Enable_GLCD_DisplayBinaryNumber == 1)                        
                if(var_numOfDigitsToDisp_u8 == C_GlcdMaxDigitsToDisplayUsingPrintf_U8)
                   var_numOfDigitsToDisp_u8 = 16;
                GLCD_DisplayBinaryNumber(var_num_u16,var_numOfDigitsToDisp_u8);
#endif                
                break;

            case 'B':  /* Argument type is of binary,Read int and convert to binary */
                var_num_u32 = va_arg(argp, uint32_t);
#if (Enable_GLCD_DisplayBinaryNumber == 1)                
                if(var_numOfDigitsToDisp_u8 == C_GlcdMaxDigitsToDisplayUsingPrintf_U8)
                   var_numOfDigitsToDisp_u8 = 16;                
                GLCD_DisplayBinaryNumber(var_num_u32,var_numOfDigitsToDisp_u8);    
#endif                
                break;


            case 'F':
            case 'f': /* Argument type is of float, hence read double data from the argp */
                var_floatNum_f32 = va_arg(argp, double);
#if (Enable_GLCD_DisplayFloatNumber == 1)                
                GLCD_DisplayFloatNumber(var_floatNum_f32);
#endif
                break;


            case 'S':
            case 's': /* Argument type is of string, hence get the pointer to sting passed */
                str = va_arg(argp, char *);
#if (Enable_GLCD_DisplayString == 1)
                GLCD_DisplayString(str);
#endif                
                break;

            case '%':
                GLCD_DisplayChar('%');
                break;
            }
        }
        else
        {
            /* As '%' is not detected display/transmit the char passed */
            GLCD_DisplayChar(ch);
        }
    }

    va_end(argp);
}
#endif





void GLCD_DisplayLogo()
{
    uint8_t line,cursor;

    for(line=0;line<8;line++)
    {
        GLCD_GoToLine(line);
        for(cursor=0;cursor<128;cursor++)
        {
            if(cursor==64)
            {
                glcd_SelectPage1();
            }
            glcd_DataWrite(0x00);
        }
    }

    GLCD_GoToLine(0);
}







void GLCD_DisplayVerticalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8)
{
    uint8_t var_lineNumberToStartDisplay_u8,i,j,var_barGraphPosition_u8;
    uint8_t lineNumber,var_valueToDisplay_u8,var_page_u8;

/* TODO: Finalize the graph numbers */
    if((var_barGraphNumber_u8 < C_MaxBarGraphs_U8) && (var_percentageValue_u8<=100))
    {    
        var_barGraphPosition_u8 = var_barGraphNumber_u8 * 32;
		
		if(var_barGraphPosition_u8<64)
		  {
		   var_page_u8 = 0;
		   }
		else
		  { 
            var_page_u8 = 1;
			var_barGraphPosition_u8 = var_barGraphPosition_u8 - 64;
		  }	
		
		
		GLCD_SetCursor(var_page_u8,0,var_barGraphPosition_u8+8);
		GLCD_DisplayDecimalNumber(var_percentageValue_u8,3);
				
		
		/* Divide the value by 8, as we have 8-pixels for each line */
		var_percentageValue_u8 = var_percentageValue_u8/2;
        var_lineNumberToStartDisplay_u8 = (var_percentageValue_u8>>3); 
        lineNumber = 7-var_lineNumberToStartDisplay_u8;
       

        for(i=1;i<8;i++) /* TODO: Finalize the line coding */
        {
            GLCD_SetCursor(var_page_u8,i,(var_barGraphPosition_u8+12));
            if(i<lineNumber)
            {
                var_valueToDisplay_u8 = 0x00;
            }  
            else if(i== lineNumber)
            {
                var_valueToDisplay_u8 = util_GetMod8(var_percentageValue_u8,8);
                var_valueToDisplay_u8 = (0xff<<(8-var_valueToDisplay_u8));
            }
            else
            {
                var_valueToDisplay_u8 = 0xff;
            }
			
            for(j=0;j<12;j++)
            {
			    
                glcd_DataWrite(var_valueToDisplay_u8);
            }			                    
        }
    }     
}


void GLCD_DisplayHorizontalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8)
{
    uint8_t var_lineNumber_u8,i;
	var_lineNumber_u8 = (var_barGraphNumber_u8 * 2)+1;
	
  if((var_barGraphNumber_u8 < C_MaxBarGraphs_U8) && (var_percentageValue_u8<=100))
    { 
       
      GLCD_SetCursor(0,var_lineNumber_u8,0);
      
      for(i=0;i<var_percentageValue_u8;i++)
        {
           if(i==64)
		     GLCD_GoToPage(1);
			
            glcd_DataWrite(0xff);
      
        }		
		
	  for(i=var_percentageValue_u8;i<100;i++)
        {
           if(i==64)
		     GLCD_GoToPage(1);
			
            glcd_DataWrite(0x00);
        }
       
        GLCD_SetCursor(1,var_lineNumber_u8,110);

        GLCD_DisplayDecimalNumber(var_percentageValue_u8,3);
    }
}






/***************************************************************************************************
                       static void glcd_CmdWrite( uint8_t var_lcdCmd_u8)
 ***************************************************************************************************
 * I/P Arguments: 8-bit command supported by LCD.
 * Return value    : none

 * description :This function sends a command to GLCD.
                Some of the commonly used commands are defined in lcd.h.
                For more commands refer the data sheet and send the supported command.                
                The behavior is undefined if unsupported commands are sent.    
 ***************************************************************************************************/
static void glcd_CmdWrite( uint8_t var_cmd_u8)
{
    glcd_BusyCheck();
    M_GlcdDataBus = var_cmd_u8;
    M_GlcdClearBit(GLCD_RS);           // Select the Command Register by pulling RS LOW
#ifdef GLCD_RW
    M_GlcdClearBit(GLCD_RW);           // Select the Write Operation  by pulling RW LOW
#endif
    M_GlcdSetBit(GLCD_EN);             // Send a High-to-Low Pulse at Enable Pin
    DELAY_us(2);
    M_GlcdClearBit(GLCD_EN);
}






/*************************************************************************************************
                       static void glcd_DataWrite( uint8_t dat)
 *************************************************************************************************
 * I/P Arguments: uint8_t: 8-bit value to be sent to LCD.
 * Return value    : none

 * description : This functions is used to send a byte of data to LCD.                 .    
 *************************************************************************************************/
static void glcd_DataWrite( uint8_t var_data_u8)
{
    glcd_BusyCheck();
    M_GlcdDataBus = var_data_u8 ^ GLCD.Invertdisplay;
    M_GlcdSetBit(GLCD_RS);           // Select the Data Register by pulling RS High
#ifdef GLCD_RW
    M_GlcdClearBit(GLCD_RW);           // Select the Write Operation  by pulling RW LOW
#endif
    M_GlcdSetBit(GLCD_EN);             // Send a High-to-Low Pulse at Enable Pin
    DELAY_us(2);
    M_GlcdClearBit(GLCD_EN);
}







/*************************************************************************************************
                       static void glcd_BusyCheck()
 *************************************************************************************************
 * I/P Arguments: none.
 * Return value    : none

 * description : This functions is used check whether LCD is busy.
                 It waits till the LCD is busy by polling the LCD busy flag.
                 After completing the previous operation, LCDs clears its internal busy flag.
 *************************************************************************************************/
static void glcd_BusyCheck()
{
    uint8_t busyflag;
    
#ifdef GLCD_RW                    //Perform Busy check if GLCD_RW pin is used

    util_UpdateBit(M_GlcdDataBusDirection,GLCD_D7,C_PinInput_U8); // Configure busy pin as input
    M_GlcdClearBit(GLCD_RS);           // Select the Command Register by pulling RS LOW
    M_GlcdSetBit(GLCD_RW);             // Select the Read Operation for busy flag by setting RW
    do
    {
        M_GlcdClearBit(GLCD_EN);             // Send a High-to-Low Pulse at Enable Pin
        DELAY_us(2);    
        M_GlcdSetBit(GLCD_EN);
        DELAY_us(2);
        busyflag = util_GetBitStatus(M_GlcdDataBusInput,GLCD_D7);
    }while(busyflag);

    util_UpdateBit(M_GlcdDataBusDirection,GLCD_D7,C_PinOutput_U8);
#else
    /* Busy flag cannot be read as GLCD_RW is not available hence Extra delay of 1ms is added 
      to ensure the LCD completes previous operation and ready to receive new commands/data */
    DELAY_ms(1);  
#endif
}


static void glcd_SelectPage0() 
 { 
   M_GlcdSetBit(GLCD_CS1); 
   M_GlcdClearBit(GLCD_CS2); 
 }

static void glcd_SelectPage1() 
 {
   M_GlcdSetBit(GLCD_CS2);  
   M_GlcdClearBit(GLCD_CS1); 
 }




