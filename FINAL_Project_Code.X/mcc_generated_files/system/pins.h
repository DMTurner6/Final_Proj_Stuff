/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA4 aliases
#define DATA4_TRIS                 TRISAbits.TRISA4
#define DATA4_LAT                  LATAbits.LATA4
#define DATA4_PORT                 PORTAbits.RA4
#define DATA4_WPU                  WPUAbits.WPUA4
#define DATA4_OD                   ODCONAbits.ODCA4
#define DATA4_ANS                  ANSELAbits.ANSELA4
#define DATA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DATA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DATA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DATA4_GetValue()           PORTAbits.RA4
#define DATA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DATA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DATA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define DATA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define DATA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define DATA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define DATA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define DATA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define DATA5_TRIS                 TRISAbits.TRISA5
#define DATA5_LAT                  LATAbits.LATA5
#define DATA5_PORT                 PORTAbits.RA5
#define DATA5_WPU                  WPUAbits.WPUA5
#define DATA5_OD                   ODCONAbits.ODCA5
#define DATA5_ANS                  ANSELAbits.ANSELA5
#define DATA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DATA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DATA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DATA5_GetValue()           PORTAbits.RA5
#define DATA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DATA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DATA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define DATA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define DATA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define DATA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define DATA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define DATA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 aliases
#define DATA6_TRIS                 TRISAbits.TRISA6
#define DATA6_LAT                  LATAbits.LATA6
#define DATA6_PORT                 PORTAbits.RA6
#define DATA6_WPU                  WPUAbits.WPUA6
#define DATA6_OD                   ODCONAbits.ODCA6
#define DATA6_ANS                  ANSELAbits.ANSELA6
#define DATA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DATA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DATA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DATA6_GetValue()           PORTAbits.RA6
#define DATA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DATA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define DATA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define DATA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define DATA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define DATA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define DATA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define DATA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RA7 aliases
#define DATA7_TRIS                 TRISAbits.TRISA7
#define DATA7_LAT                  LATAbits.LATA7
#define DATA7_PORT                 PORTAbits.RA7
#define DATA7_WPU                  WPUAbits.WPUA7
#define DATA7_OD                   ODCONAbits.ODCA7
#define DATA7_ANS                  ANSELAbits.ANSELA7
#define DATA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define DATA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define DATA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define DATA7_GetValue()           PORTAbits.RA7
#define DATA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define DATA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define DATA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define DATA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define DATA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define DATA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define DATA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define DATA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 aliases
#define RED_TRIS                 TRISBbits.TRISB0
#define RED_LAT                  LATBbits.LATB0
#define RED_PORT                 PORTBbits.RB0
#define RED_WPU                  WPUBbits.WPUB0
#define RED_OD                   ODCONBbits.ODCB0
#define RED_ANS                  ANSELBbits.ANSELB0
#define RED_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RED_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RED_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RED_GetValue()           PORTBbits.RB0
#define RED_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RED_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RED_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define RED_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define RED_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define RED_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define RED_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RED_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define YELLOW_TRIS                 TRISBbits.TRISB1
#define YELLOW_LAT                  LATBbits.LATB1
#define YELLOW_PORT                 PORTBbits.RB1
#define YELLOW_WPU                  WPUBbits.WPUB1
#define YELLOW_OD                   ODCONBbits.ODCB1
#define YELLOW_ANS                  ANSELBbits.ANSELB1
#define YELLOW_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define YELLOW_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define YELLOW_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define YELLOW_GetValue()           PORTBbits.RB1
#define YELLOW_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define YELLOW_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define YELLOW_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define YELLOW_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define YELLOW_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define YELLOW_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define YELLOW_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define YELLOW_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define GREEN_TRIS                 TRISBbits.TRISB2
#define GREEN_LAT                  LATBbits.LATB2
#define GREEN_PORT                 PORTBbits.RB2
#define GREEN_WPU                  WPUBbits.WPUB2
#define GREEN_OD                   ODCONBbits.ODCB2
#define GREEN_ANS                  ANSELBbits.ANSELB2
#define GREEN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define GREEN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define GREEN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define GREEN_GetValue()           PORTBbits.RB2
#define GREEN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define GREEN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define GREEN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define GREEN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define GREEN_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define GREEN_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define GREEN_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define GREEN_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define ORANGE_TRIS                 TRISBbits.TRISB3
#define ORANGE_LAT                  LATBbits.LATB3
#define ORANGE_PORT                 PORTBbits.RB3
#define ORANGE_WPU                  WPUBbits.WPUB3
#define ORANGE_OD                   ODCONBbits.ODCB3
#define ORANGE_ANS                  ANSELBbits.ANSELB3
#define ORANGE_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define ORANGE_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define ORANGE_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define ORANGE_GetValue()           PORTBbits.RB3
#define ORANGE_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define ORANGE_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define ORANGE_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define ORANGE_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define ORANGE_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define ORANGE_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define ORANGE_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define ORANGE_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC3 aliases
#define SCL_TRIS                 TRISCbits.TRISC3
#define SCL_LAT                  LATCbits.LATC3
#define SCL_PORT                 PORTCbits.RC3
#define SCL_WPU                  WPUCbits.WPUC3
#define SCL_OD                   ODCONCbits.ODCC3
#define SCL_ANS                  ANSELCbits.
#define SCL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL_GetValue()           PORTCbits.RC3
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC4 aliases
#define SDA_TRIS                 TRISCbits.TRISC4
#define SDA_LAT                  LATCbits.LATC4
#define SDA_PORT                 PORTCbits.RC4
#define SDA_WPU                  WPUCbits.WPUC4
#define SDA_OD                   ODCONCbits.ODCC4
#define SDA_ANS                  ANSELCbits.
#define SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA_GetValue()           PORTCbits.RC4
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RD0 aliases
#define RESET_TRIS                 TRISDbits.TRISD0
#define RESET_LAT                  LATDbits.LATD0
#define RESET_PORT                 PORTDbits.RD0
#define RESET_WPU                  WPUDbits.WPUD0
#define RESET_OD                   ODCONDbits.ODCD0
#define RESET_ANS                  ANSELDbits.
#define RESET_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RESET_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RESET_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RESET_GetValue()           PORTDbits.RD0
#define RESET_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RESET_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RESET_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define RESET_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define RESET_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define RESET_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define RESET_SetAnalogMode()      do { ANSELDbits. = 1; } while(0)
#define RESET_SetDigitalMode()     do { ANSELDbits. = 0; } while(0)

// get/set RE0 aliases
#define EN_TRIS                 TRISEbits.TRISE0
#define EN_LAT                  LATEbits.LATE0
#define EN_PORT                 PORTEbits.RE0
#define EN_WPU                  WPUEbits.WPUE0
#define EN_OD                   ODCONEbits.ODCE0
#define EN_ANS                  ANSELEbits.ANSELE0
#define EN_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define EN_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define EN_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define EN_GetValue()           PORTEbits.RE0
#define EN_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define EN_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define EN_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RE1 aliases
#define RW_TRIS                 TRISEbits.TRISE1
#define RW_LAT                  LATEbits.LATE1
#define RW_PORT                 PORTEbits.RE1
#define RW_WPU                  WPUEbits.WPUE1
#define RW_OD                   ODCONEbits.ODCE1
#define RW_ANS                  ANSELEbits.ANSELE1
#define RW_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define RW_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define RW_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define RW_GetValue()           PORTEbits.RE1
#define RW_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define RW_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define RW_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define RW_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define RW_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define RW_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define RW_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set RE2 aliases
#define RS_TRIS                 TRISEbits.TRISE2
#define RS_LAT                  LATEbits.LATE2
#define RS_PORT                 PORTEbits.RE2
#define RS_WPU                  WPUEbits.WPUE2
#define RS_OD                   ODCONEbits.ODCE2
#define RS_ANS                  ANSELEbits.ANSELE2
#define RS_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RS_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RS_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RS_GetValue()           PORTEbits.RE2
#define RS_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define RS_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define RS_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set RF0 aliases
#define OUTA_TRIS                 TRISFbits.TRISF0
#define OUTA_LAT                  LATFbits.LATF0
#define OUTA_PORT                 PORTFbits.RF0
#define OUTA_WPU                  WPUFbits.WPUF0
#define OUTA_OD                   ODCONFbits.ODCF0
#define OUTA_ANS                  ANSELFbits.ANSELF0
#define OUTA_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define OUTA_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define OUTA_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define OUTA_GetValue()           PORTFbits.RF0
#define OUTA_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define OUTA_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define OUTA_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define OUTA_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define OUTA_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define OUTA_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define OUTA_SetAnalogMode()      do { ANSELFbits.ANSELF0 = 1; } while(0)
#define OUTA_SetDigitalMode()     do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 aliases
#define OUTB_TRIS                 TRISFbits.TRISF1
#define OUTB_LAT                  LATFbits.LATF1
#define OUTB_PORT                 PORTFbits.RF1
#define OUTB_WPU                  WPUFbits.WPUF1
#define OUTB_OD                   ODCONFbits.ODCF1
#define OUTB_ANS                  ANSELFbits.ANSELF1
#define OUTB_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define OUTB_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define OUTB_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define OUTB_GetValue()           PORTFbits.RF1
#define OUTB_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define OUTB_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define OUTB_SetPullup()          do { WPUFbits.WPUF1 = 1; } while(0)
#define OUTB_ResetPullup()        do { WPUFbits.WPUF1 = 0; } while(0)
#define OUTB_SetPushPull()        do { ODCONFbits.ODCF1 = 0; } while(0)
#define OUTB_SetOpenDrain()       do { ODCONFbits.ODCF1 = 1; } while(0)
#define OUTB_SetAnalogMode()      do { ANSELFbits.ANSELF1 = 1; } while(0)
#define OUTB_SetDigitalMode()     do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set RF5 aliases
#define SW1_TRIS                 TRISFbits.TRISF5
#define SW1_LAT                  LATFbits.LATF5
#define SW1_PORT                 PORTFbits.RF5
#define SW1_WPU                  WPUFbits.WPUF5
#define SW1_OD                   ODCONFbits.ODCF5
#define SW1_ANS                  ANSELFbits.ANSELF5
#define SW1_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define SW1_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define SW1_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define SW1_GetValue()           PORTFbits.RF5
#define SW1_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define SW1_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set RF6 aliases
#define SW2_TRIS                 TRISFbits.TRISF6
#define SW2_LAT                  LATFbits.LATF6
#define SW2_PORT                 PORTFbits.RF6
#define SW2_WPU                  WPUFbits.WPUF6
#define SW2_OD                   ODCONFbits.ODCF6
#define SW2_ANS                  ANSELFbits.ANSELF6
#define SW2_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define SW2_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define SW2_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define SW2_GetValue()           PORTFbits.RF6
#define SW2_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define SW2_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)

// get/set RF7 aliases
#define SW3_TRIS                 TRISFbits.TRISF7
#define SW3_LAT                  LATFbits.LATF7
#define SW3_PORT                 PORTFbits.RF7
#define SW3_WPU                  WPUFbits.WPUF7
#define SW3_OD                   ODCONFbits.ODCF7
#define SW3_ANS                  ANSELFbits.ANSELF7
#define SW3_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define SW3_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define SW3_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define SW3_GetValue()           PORTFbits.RF7
#define SW3_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define SW3_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define SW3_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define SW3_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define SW3_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/