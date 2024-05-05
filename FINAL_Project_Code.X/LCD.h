/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/system/system.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define D4 LATAbits.LATA4
#define D5 LATAbits.LATA5
#define D6 LATAbits.LATA6
#define D7 LATAbits.LATA7

#define EN LATEbits.LATE0
#define RS LATEbits.LATE2
#define RW LATEbits.LATE1

// Commands templates (See Hitachi HD44780U data sheet p. 28)
#define LCD_CLR_DISP 0x01              
#define LCD_RET_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISP_CON 0x08
#define LCD_CUR_DISP_SHIFT 0x10
#define LCD_FUNC_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

// Entry mode set command-bits
#define LCD_ENTRY_RIGHT 0x00          
#define LCD_ENTRY_LEFT 0x02
#define LCD_ENTRY_DISP_SHIFT 0x01
#define LCD_ENTRY_CUR_SHIFT 0x00

// Display on/off control command-bits
#define LCD_DISP_ON 0x04              
#define LCD_DISP_OFF 0x00
#define LCD_CUR_ON 0x02
#define LCD_CUR_OFF 0x00
#define LCD_BLINK_ON 0x01
#define LCD_BLINK_OFF 0x00

// Display cursor control command-bits (Hitachi HD44780 p. 27, 29)
#define LCD_DISP_SHIFT_L 0x08                       // Shifts the entire display to the left
#define LCD_DISP_SHIFT_R 0x0C                       // Shifts the entire display to the right
#define LCD_CUR_SHIFT_L 0x00                        // Shifts the cursor position to the left
#define LCD_CUR_SHIFT_R 0x04                        // Shifts the cursor position to the right

// Display function set command-bits
#define LCD_8BIT_MODE 0x10            
#define LCD_4BIT_MODE 0x00
#define LCD_2LINE_DISP 0x08
#define LCD_1LINE_DISP 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

unsigned char _dispFunc;
unsigned char _dispCon;
unsigned char _dispMode;


void lcdSend4bit(unsigned char data);                                 // Sends 4 bit data to LCD and provide a 37 us delay afterwaards           
void lcdCmd(unsigned char data);                                      // Sends a command word to LCD
void lcdWrite(unsigned char data);                                    // Sends a character to LCD
void lcdClear(void);                                                  // Clears the LCD and set the cursor in (0,0) pos
void lcdHome (void);                                                  // Sets the cursor position to (0,0)
void lcdSetCursor (unsigned char col, unsigned char row);             // Set cursor position (column#, row#)
void lcdDispOn(void);                                                 // Turns on the display
void lcdDispOff(void);                                                // Turns off the display. Display data remains in DDRAM, and can be displayed instantly by turning it on
void lcdCursor (void);                                                // Makes the cursor visible
void lcdNoCursor (void);                                              // Hides the cursor
void lcdBlink(void);                                                  // Blinks the cursor
void lcdNoBlink (void);                                               // Turns of blinking of the cursor
void lcdShiftDisplayLeft(void);                                       // Shifts the entire display left
void lcdShiftDisplayRight(void);                                      // Shifts the entire display Right
void lcdShiftCursorLeft(void);                                        // Shifts cursor position to the left without writing a character
void lcdShiftCursorRight(void);                                       // Shifts cursor position to the right without writing a character
void lcdLeftToRight (void);                                           // Characters appear from the left of the display (cursor shifts right)
void lcdRightToLeft (void);                                           // Characters appear from the right of the display (cursor shifts left)
void lcdAutoScroll (void);                                            // Shifts the entire display either to the right (I/D = 0) or to the left 
void lcdNoAutoScroll (void);                                          // Shifts the cursor, NOT the display
void lcdCreateChar(unsigned char location, unsigned char charmap[]);  // Create your own character and store in the CGRAM
void lcdInit(void);                                                   // Initializes the LCD Module
void lcdPrint(char *data);
void lcdPrintF(const char *format, ...);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

