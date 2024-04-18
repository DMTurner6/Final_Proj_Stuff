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
#define ADCs 100

uint24_t ADC_MEAS = 0;
uint24_t Offset = 0;
uint32_t Gain = 0;

uint32_t ADC_Final = 0;


uint24_t read;
uint24_t AMP_read[ADCs];
uint8_t AMP_Flag = 0;
static uint8_t i = 0;

void AMP_INIT(uint8_t channel);
void MUX_ADRESS(uint8_t reg);
void AMP_ADRESS(uint8_t reg, uint8_t data);
void AMP_CAL(uint8_t channel);
uint24_t AMPMEASURE(uint8_t channel);
uint8_t AMP_Read(uint8_t reg);
uint24_t AMP_24Read(uint8_t reg);
uint32_t AMP_32Read(uint8_t reg);
void TEST_measurement(void);
bool Confirm_Bit(uint8_t data, int place, uint8_t bit); 

int main(void) {
    SYSTEM_Initialize();
    lcdInit();
    RESET_SetHigh();


    AMP_INIT(Channel_0);
    //AMP_INIT(Channel_1);
    //AMP_INIT(Channel_2);
    //AMP_INIT(Channel_3);
 
    AMP_CAL(Channel_0);
    //AMP_CAL(Channel_1);
    //AMP_CAL(Channel_2);
    //AMP_CAL(Channel_3);

   
    GREEN_SetHigh();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 


    lcdClear();
    lcdPrint("READY");





    while (1) {


       
        TEST_measurement();





    }
}

void AMP_INIT(uint8_t channel) {
    MUX_ADRESS(channel); //Opens MUX to desired channel
    
    AMP_ADRESS(0x00, 0x01);  // sends reset bit
    
    AMP_ADRESS(0x00, 0x02);  //Power to digital registers
    __delay_ms(220);
    AMP_ADRESS(0x00, 0x86);  //Internal LDO, Analog, and Digital Power-up
   
    AMP_ADRESS(0x01, 0x27);  //Internal LDO -- Set to 3.3V and gain select as 128x 
   
    AMP_ADRESS(0x02, 0x00);  //Samples collected at rate of 320SPS
   
    AMP_ADRESS(0x1B, 0x31);  //Disables Chopper??
   

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

    MUX_ADRESS(Channel_0); //Opens MUX to desired channel
    
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

uint24_t AMPMEASURE(uint8_t channel) {
    uint24_t ADC_MEAS = 0;
    uint24_t Offset = 0;
    uint32_t Gain = 1;

    uint8_t ADC_out = 0;

    MUX_ADRESS(channel); //Opens MUX to desired channel
    __delay_ms(50);
    AMP_ADRESS(0x00, 0x96);
    __delay_ms(500);
    ADC_MEAS = AMP_24Read(0x12);
    __delay_ms(50);
    Offset = AMP_24Read(0x03);
    __delay_ms(50);
    Gain = AMP_32Read(0x06);
    __delay_ms(50);

    ADC_out = Gain * (ADC_MEAS - Offset);

    return ADC_out;
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

    data = dataLow << 16;
    data = dataHigh << 8;
    data = data | dataU;
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

    data = dataLow << 24;
    data = dataHigh << 16;
    data = dataU << 8;
    data = data | dataT;
    return data;
}

void TEST_measurement(void) 
{
    if(AMP_Flag == 0){
    
     AMP_ADRESS(0x00,0x96);
  
     AMP_Flag = 1;
     lcdClear();
//     lcdPrint("SENT");

    }
    
//    lcdClear();
//    lcdPrint("TAKING SAMPLE");


    read = AMP_24Read(0x00);
    
    if ((read >> 5 & 0x01) == 1) 
    {                
       
       AMP_read[i] = AMP_24Read(0x12);
       ADC_Final = AMP_read[i] + AMP_read[i-1];
       AMP_Flag = 0;
       i++;
       
//    lcdClear();
//    lcdPrint("SAMPLE TAKEN"); 
       
    if(i >= ADCs) 
    {  
        ADC_Final = ADC_Final/ADCs;
     
        lcdClear();
        lcdSetCursor(0,1);
        lcdPrintF("AVG:%d", ADC_Final);
        lcdSetCursor(0,0);
        lcdPrintF("LAST %d", AMP_read[i]);
        i == 0;
        __delay_ms(500);
        
        
    }
    }

}

uint32_t TEST_Sample(uint8_t channel) 
{
    if(AMP_Flag == 0)
    {
     AMP_ADRESS(0x00,0x96);
     __delay_ms(1);
     AMP_Flag = 1;
     lcdClear();
    }
    
    read = AMP_24Read(0x00);
    __delay_ms(1);

    
    if ((read >> 5 & 0x01) == 1) 
    {                
       
       AMP_read[i] = AMP_24Read(0x12);
       __delay_ms(1);
       ADC_Final = AMP_read[i] + AMP_read[i-1];
       AMP_Flag = 0;
       i++;
       
//    lcdClear();
//    lcdPrint("SAMPLE TAKEN"); 
       
    if(i >= ADCs) 
    {  
        ADC_Final = ADC_Final/ADCs;
     
        lcdClear();
        lcdSetCursor(0,1);
        lcdPrintF("AVG:%d", ADC_Final);
        lcdSetCursor(0,0);
        lcdPrintF("LAST %d", AMP_read[i]);
        i == 0;
        __delay_ms(500);
        
        
    }
    }

}

bool Confirm_Bit(uint8_t data, int place, uint8_t bit) 
{
    if ((data >> place & bit) == bit) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}