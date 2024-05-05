/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"
#include "LCD.h"

#define Channel_0 0x01
#define Channel_1 0x02
#define Channel_2 0x04
#define Channel_3 0x08

#define AMP 0x2A
#define CAL_READY 0x04
#define MUX 0x70
#define PROX 0x13 
#define ADCs 32


#define PRESSED             1
#define NOT_PRESSED         0
#define RUNNING             1
#define NOT_RUNNING         0
#define LAST                16


static uint8_t i = 0;
volatile int ii = 0;
static uint16_t state = 0, counter = 0;
uint8_t DEV1 = 0;
uint8_t DEV2 = 0;
uint8_t DEV3 = 0;
uint8_t DEV4 = 0;
uint8_t Rand = 0;
uint8_t AMP_Flag = 0;
uint8_t Stage_Flag = 0;
uint8_t read;
uint24_t ADC_MEAS = 0;
uint24_t Offset = 0;
uint32_t Gain = 0;
uint32_t ADC_Final = 0;
uint24_t AMP_read[ADCs];
uint8_t labNumber = 0;
uint8_t switchEvent = 0;
uint8_t labState = NOT_RUNNING;
uint8_t btnState = NOT_PRESSED;


void checkButtonS1(void);
void nextLab(void);
void Rotary_TEST(void);
void Rotary_GO(void);
void ROT_INIT(void);
void AMP_START(void);
void AMP_INIT(uint8_t channel);
void MUX_ADRESS(uint8_t reg);
void AMP_ADRESS(uint8_t reg, uint8_t data);
void AMP_CAL(uint8_t channel);
uint24_t AMPMEASURE(uint8_t channel);
uint8_t AMP_Read(uint8_t reg);
uint16_t AMP_16Read(uint8_t reg);
uint24_t AMP_24Read(uint8_t reg);
uint32_t AMP_32Read(uint8_t reg);
void PROX_ADRESS(uint8_t reg, uint8_t data);
uint8_t PROX_Read(uint8_t reg);
uint16_t PROX_16Read(uint8_t reg);
void TEST_measurement(void);
bool Confirm_Bit(uint8_t data, int place, uint8_t bit);
void INTRO_run(void);
void DEVID(void);

int main(void) {
    SYSTEM_Initialize();
    ORANGE_SetHigh();
    lcdInit();
    GREEN_SetHigh();
    ROT_INIT();
    RESET_SetHigh();
    YELLOW_SetHigh();
    AMP_START();
    RED_SetHigh();



    


    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable();


    lcdClear();
    lcdSetCursor(4, 0);
    lcdPrint("READY FOR");
    lcdSetCursor(4, 1);
    lcdPrint("LIVE DEMO");
    __delay_ms(500);
    lcdClear();

    while (1) {

        checkButtonS1();
        switch (labNumber) {
            case 1:INTRO_run();
                break;
            case 2:Rotary_GO();
                break;
            case 3:Rotary_TEST();
                break;
            case 4:TEST_measurement();
                break;
            case 5:DEVID();
                break;

        }

        if (switchEvent) {
            nextLab();
        }
    }
}

void checkButtonS1(void) {
    if (btnState == NOT_PRESSED) {
        if (SW1_PORT == LOW) {
            __delay_ms(100);
            if (SW1_PORT == LOW) {
                btnState = PRESSED;
            }
        }
    } else if (SW1_PORT == HIGH) {
        btnState = NOT_PRESSED;
        switchEvent = 1;
    }
}

void nextLab(void) {
    switchEvent = 0;
    labNumber++;

    if (labNumber > 5) {
        labNumber = 1;
    }
}

bool SwitchDebounce(bool buttonState) {
    static uint16_t debouncer = 0;

    debouncer = (debouncer << 1) | !buttonState | 0xE000;
    if (debouncer == 0xF000)return 1;
    else return 0;

}

void Rotary_TEST(void) {
    if (labState == NOT_RUNNING) {
        lcdClear();
        lcdPrintF("LAB 3");
        __delay_ms(1000);
        lcdClear();
        labState = RUNNING;
    }
    if (labState == RUNNING) {
        state = (state << 1) | OUTA_GetValue() | 0xe000;
        if (state == 0xf000) {
            state = 0x0000;
            if (OUTB_GetValue())
                counter++;
            else
                counter--;

            lcdPrintF("COUNT: is %d", counter);
            __delay_ms(2000);
            lcdClear();
        }
    }
    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

void Rotary_GO(void) {

    if (labState == NOT_RUNNING) {
        lcdClear();
        lcdPrintF("LAB 2");
        __delay_ms(1000);
        lcdClear();
        labState = RUNNING;
    }

    if (labState == RUNNING) {

        state = (state << 1) | OUTA_GetValue() | 0xe000;
        if (state == 0xf000) {
            state = 0x0000;
            if (OUTB_GetValue())
                counter++;
            else
                counter--;

            lcdPrintF("COUNT: is %d", counter);
            lcdClear();
        }
    }
    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

void ROT_INIT(void) {

    TRISFbits.TRISF1 = 1;
    TRISFbits.TRISF0 = 1;


    WPUFbits.WPUF0 = 1;
    WPUFbits.WPUF1 = 1;

    ANSELFbits.ANSELF0 = 0;
    ANSELFbits.ANSELF1 = 0;

}

void AMP_START(void) {

    AMP_INIT(Channel_0);
    lcdSetCursor(0, 0);
    lcdPrintF("Channel 0 ACKED");
    AMP_CAL(Channel_0);
    lcdSetCursor(0, 1);
    lcdPrintF("Channel 0 Cal'd");
    __delay_ms(500);
    lcdClear();


    AMP_INIT(Channel_1);
    lcdSetCursor(0, 0);
    lcdPrintF("Channel 1 ACKED");
    AMP_CAL(Channel_1);
    lcdSetCursor(0, 1);
    lcdPrintF("Channel 1 Cal'd");
    __delay_ms(500);
    lcdClear();

    AMP_INIT(Channel_2);
    lcdSetCursor(0, 0);
    lcdPrintF("Channel 2 ACKED");
    AMP_CAL(Channel_2);
    lcdSetCursor(0, 1);
    lcdPrintF("Channel 2 Cal'd");
    __delay_ms(500);
    lcdClear();

    AMP_INIT(Channel_3);
    lcdSetCursor(0, 0);
    lcdPrintF("Channel 3 ACKED");
    AMP_CAL(Channel_3);
    lcdSetCursor(0, 1);
    lcdPrintF("Channel 3 Cal'd");
    __delay_ms(500);
    lcdClear();

}

void AMP_INIT(uint8_t channel) {
    MUX_ADRESS(channel); //Opens MUX to desired channel

    AMP_ADRESS(0x00, 0x01); // sends reset bit

    AMP_ADRESS(0x00, 0x02); //Power to digital registers
    __delay_ms(220);
    AMP_ADRESS(0x00, 0x86); //Internal LDO, Analog, and Digital Power-up

    AMP_ADRESS(0x01, 0xA3); //Internal LDO -- Set to 3.3V and gain select as 128x 

    AMP_ADRESS(0x02, 0x70); //Samples collected at rate of 320SPS

    //AMP_ADRESS(0x1B, 0x31);  //Disables Chopper??


}

void MUX_ADRESS(uint8_t reg) {

    I2C1ADB1 = (uint8_t) (MUX << 1);
    I2C1CNTL = 1;
    I2C1TXB = reg;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    __delay_ms(1);
}

void AMP_ADRESS(uint8_t reg, uint8_t data) {

    I2C1ADB1 = (uint8_t) (AMP << 1);
    I2C1CNTL = 2;
    I2C1TXB = reg;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1TXB = data;
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    __delay_ms(1);
}

void AMP_CAL(uint8_t channel) {

    MUX_ADRESS(channel); //Opens MUX to desired channel

    AMP_ADRESS(0x02, 0x33); //Calibrates the Gain  

    AMP_ADRESS(0x02, 0x3E); //begins the calibration 
    __delay_ms(400);

    AMP_Read(0x02);


    AMP_ADRESS(0x02, 0x32); //Calibrates the offset  

    AMP_ADRESS(0x02, 0x36); //Begins the calibration
    __delay_ms(400);

    AMP_Read(0x02);


    AMP_ADRESS(0x02, 0x30); //Calibrates the offset  

    AMP_ADRESS(0x02, 0x38); //Begins the calibration
    __delay_ms(400);

    AMP_Read(0x02);


}

uint8_t AMP_Read(uint8_t reg) {
    uint8_t address;
    uint8_t data;

    I2C1ADB1 = (uint8_t) (AMP << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (AMP << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    data = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    __delay_ms(1);


    return data;
}

uint16_t AMP_16Read(uint8_t reg) {
    uint8_t address;
    uint8_t dataLow;
    uint8_t dataHigh;
    uint16_t data;

    I2C1ADB1 = (uint8_t) (AMP << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (AMP << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 3;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    dataLow = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataHigh = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);

    __delay_ms(1);


    data = dataLow << 8;
    data = data | dataHigh;
    return data;
}

uint24_t AMP_24Read(uint8_t reg) {
    uint8_t address;
    uint8_t dataLow;
    uint8_t dataHigh;
    uint8_t dataU;
    uint24_t data;

    I2C1ADB1 = (uint8_t) (AMP << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (AMP << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 3;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    dataLow = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataHigh = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataU = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  

    __delay_ms(1);

    data = dataU << 16;
    data = dataHigh << 8;
    data = data | dataLow;
    return data;
}

uint32_t AMP_32Read(uint8_t reg) {
    uint8_t address;
    uint8_t dataLow;
    uint8_t dataHigh;
    uint8_t dataU;
    uint8_t dataT;
    uint32_t data;

    I2C1ADB1 = (uint8_t) (AMP << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (AMP << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 4;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    dataLow = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataHigh = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataU = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataT = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  

    __delay_ms(1);

    data = dataT << 24;
    data = dataU << 16;
    data = dataHigh << 8;
    data = data | dataLow;
    return data;
}

uint8_t PROX_Read(uint8_t reg) {
    uint8_t address;
    uint8_t data;

    I2C1ADB1 = (uint8_t) (PROX << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (PROX << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    data = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    __delay_ms(1);


    return data;
}

uint16_t PROX_16Read(uint8_t reg) {
    uint8_t address;
    uint8_t dataLow;
    uint8_t dataHigh;
    uint16_t data;

    I2C1ADB1 = (uint8_t) (PROX << 1);
    I2C1TXB = reg;
    I2C1CNTL = 1;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode   
    while (!I2C1STAT1bits.TXBE); // Write address is sent into the TX buffer
    I2C1CON0bits.RSEN = 1;

    while (!I2C1CON0bits.MDR); //    

    address = (uint8_t) (PROX << 1);
    I2C1ADB1 = (uint8_t) (address | 1);
    I2C1CNTL = 3;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    I2C1CON0bits.RSEN = 0;
    while (!I2C1STAT1bits.RXBF);
    dataLow = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);
    dataHigh = I2C1RXB;
    I2C1CON0bits.S = 1; // Sets I2C host Start Mode  
    while (!I2C1STAT1bits.RXBF);

    __delay_ms(1);


    data = dataLow << 8;
    data = data | dataHigh;
    return data;
}

void TEST_measurement(void) {

    if (labState == NOT_RUNNING) {

        lcdClear();
        lcdPrintF("LAB 4");
        __delay_ms(1000);
        lcdClear();
        labState = RUNNING;
    }
    if (labState == RUNNING) {
        
        
        MUX_ADRESS(Channel_0);
        read = AMP_Read(0x00);
       
        
        
        if (AMP_Flag == 0 & (read >> 3 & 0x05) == 0x5) {

            AMP_ADRESS(0x00, 0x96);

            AMP_Flag = 1;
            lcdClear();

        }
        if (AMP_Flag == 1 & (read >> 3 & 0x05) == 0x5) {

            AMP_read[i] = AMP_24Read(0x12);
            printf("ADC SAMPLE [%d] : [%ld]\r\n", i, AMP_read[i]);
            ADC_Final = AMP_read[i] + ADC_Final;
            AMP_Flag = 0;
            i++;

            if (i > ADCs) {
                ADC_Final >> 5; //ADC_Final/ADCs;
                printf("final ADC: %ld\r\n", ADC_Final);

                lcdClear();
                lcdSetCursor(0, 1);
                lcdPrintF("AVG:%ld", ADC_Final);
                lcdSetCursor(0, 0);
                lcdPrintF("LAST%ld", AMP_read[31]);
                ADC_Final = 0;
                i = 0;
                __delay_ms(500);
            }
        }
    }
    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

bool Confirm_Bit(uint8_t data, int place, uint8_t bit) {
    if ((data >> place & bit) == bit) {
        return true;
    } else {
        return false;
    }
}

void INTRO_run(void) {

    if (labState == NOT_RUNNING) {
        lcdClear();
        lcdPrintF("LAB 1");
        __delay_ms(1000);
        lcdClear();
        labState = RUNNING;
    }

    if (labState == RUNNING) {
        lcdClear();
        __delay_ms(500);
        lcdPrintF("HELLO");
        __delay_ms(500);
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }




}

void DEVID(void) {

    if (labState == NOT_RUNNING) {
        lcdClear();
        lcdPrintF("LAB 5");
        __delay_ms(1000);
        lcdClear();
        labState = RUNNING;
    }

    if (labState == RUNNING) {
        MUX_ADRESS(Channel_0);
        DEV1 = AMP_Read(0x1F);
        lcdSetCursor(0,0);
        lcdPrint("AMP DEVID 1");
        lcdSetCursor(0,1);
        lcdPrintF("%x",DEV1);    
        __delay_ms(500);
                
        MUX_ADRESS(Channel_1);
        DEV2 = AMP_Read(0x1F);
        DEV1 = AMP_Read(0x1F);
        lcdSetCursor(0,0);
        lcdPrint("AMP DEVID 2");
        lcdSetCursor(0,1);
        lcdPrintF("%x",DEV2); 
        __delay_ms(500);
        
        MUX_ADRESS(Channel_2);
        DEV3 = AMP_Read(0x1F);
        lcdSetCursor(0,0);
        lcdPrint("AMP DEVID 3");
        lcdSetCursor(0,1);
        lcdPrintF("%x",DEV3); 
        __delay_ms(500);
        
        MUX_ADRESS(Channel_3);
        DEV4 = AMP_Read(0x1F);
        lcdSetCursor(0,0);
        lcdPrint("AMP DEVID 4");
        lcdSetCursor(0,1);
        lcdPrintF("%x",DEV1);
        __delay_ms(500);
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }




}
