#include <xc.h>
#include "LCD.h"
#include "mcc_generated_files/system/system.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


void lcdSend4bit(unsigned char data)
{
    D4 = data & 0x01;
    D5 = (data >> 1) & 0x01;
    D6 = (data >> 2) & 0x01;
    D7 = (data >> 3) & 0x01;
    
    EN = 1;
    __delay_us(1);
    EN = 0;
    __delay_us(40);
}

void lcdCmd(unsigned char data)
{
    RS = 0;
    lcdSend4bit(data >> 4);
    lcdSend4bit(data);
}

void lcdWrite(unsigned char data)
{
    RS = 1;
    lcdSend4bit(data >> 4);
    lcdSend4bit(data);
}

void lcdClear(void)
{
  lcdCmd(LCD_CLR_DISP);                                   // Clear display, set cursor position to zero
  __delay_ms(2);
}

void lcdHome (void)
{
  lcdCmd (LCD_RET_HOME);                                  // Set cursor position to zero
  __delay_ms (2);
}

void lcdSetCursor (unsigned char col, unsigned char row)  // Position the cursor. Col & Row starts from 0
{
  if (row >= 2)                                           // Max no. of rows = 2 (for 2-line display)
    row = 1;                                              // #row starts with zero
  unsigned char _rowOffset[2] = {0x00, 0x40};             // Row offset values corresponding to row #1, row #2 
  lcdCmd (LCD_SET_DDRAM_ADDR | (col + _rowOffset[row]));
}

void lcdDispOn(void)                                 // Turns on the display
{
  _dispCon |= LCD_DISP_ON;                           // D = 1 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd(LCD_DISP_CON | _dispCon);
}

void lcdDispOff(void)                                // Turns off the display. Display data remains in DDRAM, and can be displayed instantly by turning it on
{
  _dispCon &= ~LCD_DISP_ON;                          // D = 0 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd(LCD_DISP_CON | _dispCon);
}

void lcdCursor (void)
{
  _dispCon |= LCD_CUR_ON;                            // C = 1 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_DISP_CON | _dispCon);
}

void lcdNoCursor (void)
{
  _dispCon &= ~LCD_CUR_ON;                           // C = 0 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_DISP_CON | _dispCon);
}

void lcdBlink(void)                                  // Blinks the cursor
{
  _dispCon |= LCD_BLINK_ON;                          // B = 1 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (_dispCon);
}

void lcdNoBlink (void)                               // Stops blinking of cursor
{
  _dispCon &= ~LCD_BLINK_ON;                         // B = 0 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (_dispCon);
}

void lcdShiftDisplayLeft(void)                       // Shifts the entire display left
{
  lcdCmd (LCD_CUR_DISP_SHIFT | LCD_DISP_SHIFT_L);    // S/C = 1, R/L = 0 (See Hitachi HD44780U data sheet p. 29)
}

void lcdShiftDisplayRight(void)                      // Shifts the entire display right
{
  lcdCmd (LCD_CUR_DISP_SHIFT | LCD_DISP_SHIFT_R);    // S/C = 1, R/L = 1 (See Hitachi HD44780U data sheet p. 29)
}

void lcdShiftCursorLeft(void)                        // Shifts cursor position to the left without writing a character
{
    lcdCmd(LCD_CUR_DISP_SHIFT | LCD_CUR_SHIFT_L);    // S/C = 0, R/L = 0 (See Hitachi HD44780U data sheet p. 29)
}

void lcdShiftCursorRight(void)                       // Shifts cursor position to the right without writing a character
{
    lcdCmd(LCD_CUR_DISP_SHIFT | LCD_CUR_SHIFT_R);    // S/C = 0, R/L = 1 (See Hitachi HD44780U data sheet p. 29)
}

void lcdLeftToRight (void)                           // Characters appear from the left of the display (cursor shifts right)
{
  _dispMode |= LCD_ENTRY_LEFT;                       // I/D = 1 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_ENTRY_MODE_SET | _dispMode);
}

void lcdRightToLeft (void)                           // Characters appear from the right of the display (cursor shifts left)
{
  _dispMode &= ~LCD_ENTRY_LEFT;                      // I/D = 0 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_ENTRY_MODE_SET | _dispMode);
}

void lcdAutoScroll (void)                            // Shifts the entire display either to the right (I/D = 0) or to the left (I/D = 1). Cursor does not move
{
  _dispMode |= LCD_ENTRY_DISP_SHIFT;                 // S = 1 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_ENTRY_MODE_SET | _dispMode);
}

void lcdNoAutoScroll (void)                          // Shifts the cursor, NOT the display
{
  _dispMode &= ~LCD_ENTRY_DISP_SHIFT;                // S = 0 (See Hitachi HD44780U data sheet p. 26)
  lcdCmd (LCD_ENTRY_MODE_SET | _dispMode);
}

void lcdCreateChar(unsigned char location, unsigned char *charmap)  // Create your own character and store in the CGRAM (See Hitachi HD44780U data sheet p. 19)
{
  location &= 0x07;                                    // Mask bit-3 to bit-7
  lcdCmd (LCD_SET_CGRAM_ADDR | (location << 3));       // Write data to CGRAM. CGRAM address is 6-bit long. (DB5:DB3 = Char Location, DB2:DB0 = Dot_Matrix_Row#)
  for (int i = 0; i < 8; i++)
    lcdWrite (charmap[i]);                             // Write Dot pattern to the CGRAM
  lcdCmd(LCD_SET_DDRAM_ADDR);                          // Write data to DDRAM (Display Data RAM)
}


void lcdInit(void)                 // Initializes the LCD Module ( See Hitachi HD44780 data sheet, fig. 24, p. 46)
{
    ANSELA = 0;
    ANSELE = 0;
    TRISE = 0;
    TRISA = 0;
    
    
    __delay_ms(50);                // Wait at least 40 ms after power rises above 2.7V
    
    RS = 0;
    EN = 0;
    
    lcdSend4bit(0x03);
    __delay_ms(5);
    lcdSend4bit(0x03);
    __delay_us(150);
    lcdSend4bit(0x03);
    lcdSend4bit(0x02);
    
    _dispFunc = LCD_4BIT_MODE | LCD_2LINE_DISP | LCD_5x8DOTS;          // Display Function set: DL = 0 (4-bit), N = 1 (2-line disp), F = X (5x8 dot font)
    lcdCmd(LCD_FUNC_SET | _dispFunc);
    
    _dispCon = LCD_DISP_ON | LCD_CUR_OFF | LCD_BLINK_OFF;              // Display on/off ctrl.: D = 0 (disp off), C = 0 (cursor off), B = 0 (blink off)
    lcdCmd(LCD_DISP_CON | _dispCon);
    
    lcdClear();
    
    _dispMode = LCD_ENTRY_LEFT | LCD_ENTRY_CUR_SHIFT;                  // Entry mode set: I/D = 1 (Cursor shifts right), No display Shift (Cursor moves)
    lcdCmd(LCD_ENTRY_MODE_SET | _dispMode);
}

void lcdPrint(char *data)
{
    for(int i = 0; data[i] != '\0'; i++) {
        lcdWrite(data[i]);
    }
}

void lcdPrintF(const char *format, ...) {
    char buffer[128]; // Define a buffer to hold the formatted string
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    // Now call the original lcdPrint function with the formatted string
    for (int i = 0; buffer[i] != '\0'; i++) {
        lcdWrite(buffer[i]);
    }
}

