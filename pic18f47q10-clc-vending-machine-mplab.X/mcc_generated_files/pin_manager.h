/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LCDMini_nCS2 aliases
#define LCDMini_nCS2_TRIS                 TRISAbits.TRISA1
#define LCDMini_nCS2_LAT                  LATAbits.LATA1
#define LCDMini_nCS2_PORT                 PORTAbits.RA1
#define LCDMini_nCS2_WPU                  WPUAbits.WPUA1
#define LCDMini_nCS2_OD                   ODCONAbits.ODCA1
#define LCDMini_nCS2_ANS                  ANSELAbits.ANSELA1
#define LCDMini_nCS2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LCDMini_nCS2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LCDMini_nCS2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LCDMini_nCS2_GetValue()           PORTAbits.RA1
#define LCDMini_nCS2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LCDMini_nCS2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LCDMini_nCS2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LCDMini_nCS2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LCDMini_nCS2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LCDMini_nCS2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LCDMini_nCS aliases
#define LCDMini_nCS_TRIS                 TRISAbits.TRISA3
#define LCDMini_nCS_LAT                  LATAbits.LATA3
#define LCDMini_nCS_PORT                 PORTAbits.RA3
#define LCDMini_nCS_WPU                  WPUAbits.WPUA3
#define LCDMini_nCS_OD                   ODCONAbits.ODCA3
#define LCDMini_nCS_ANS                  ANSELAbits.ANSELA3
#define LCDMini_nCS_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LCDMini_nCS_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LCDMini_nCS_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LCDMini_nCS_GetValue()           PORTAbits.RA3
#define LCDMini_nCS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LCDMini_nCS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LCDMini_nCS_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LCDMini_nCS_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LCDMini_nCS_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LCDMini_nCS_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LCDMini_nCS_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LCDMini_nCS_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set CHANGE1 aliases
#define CHANGE1_TRIS                 TRISAbits.TRISA4
#define CHANGE1_LAT                  LATAbits.LATA4
#define CHANGE1_PORT                 PORTAbits.RA4
#define CHANGE1_WPU                  WPUAbits.WPUA4
#define CHANGE1_OD                   ODCONAbits.ODCA4
#define CHANGE1_ANS                  ANSELAbits.ANSELA4
#define CHANGE1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define CHANGE1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define CHANGE1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define CHANGE1_GetValue()           PORTAbits.RA4
#define CHANGE1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define CHANGE1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define CHANGE1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define CHANGE1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define CHANGE1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define CHANGE1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define CHANGE1_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define CHANGE1_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set CHANGE2 aliases
#define CHANGE2_TRIS                 TRISAbits.TRISA5
#define CHANGE2_LAT                  LATAbits.LATA5
#define CHANGE2_PORT                 PORTAbits.RA5
#define CHANGE2_WPU                  WPUAbits.WPUA5
#define CHANGE2_OD                   ODCONAbits.ODCA5
#define CHANGE2_ANS                  ANSELAbits.ANSELA5
#define CHANGE2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define CHANGE2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define CHANGE2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define CHANGE2_GetValue()           PORTAbits.RA5
#define CHANGE2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define CHANGE2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define CHANGE2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define CHANGE2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define CHANGE2_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define CHANGE2_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define CHANGE2_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define CHANGE2_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set CHANGE3 aliases
#define CHANGE3_TRIS                 TRISAbits.TRISA6
#define CHANGE3_LAT                  LATAbits.LATA6
#define CHANGE3_PORT                 PORTAbits.RA6
#define CHANGE3_WPU                  WPUAbits.WPUA6
#define CHANGE3_OD                   ODCONAbits.ODCA6
#define CHANGE3_ANS                  ANSELAbits.ANSELA6
#define CHANGE3_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define CHANGE3_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define CHANGE3_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define CHANGE3_GetValue()           PORTAbits.RA6
#define CHANGE3_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define CHANGE3_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define CHANGE3_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define CHANGE3_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define CHANGE3_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define CHANGE3_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define CHANGE3_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define CHANGE3_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set BOTTLE aliases
#define BOTTLE_TRIS                 TRISAbits.TRISA7
#define BOTTLE_LAT                  LATAbits.LATA7
#define BOTTLE_PORT                 PORTAbits.RA7
#define BOTTLE_WPU                  WPUAbits.WPUA7
#define BOTTLE_OD                   ODCONAbits.ODCA7
#define BOTTLE_ANS                  ANSELAbits.ANSELA7
#define BOTTLE_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BOTTLE_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BOTTLE_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BOTTLE_GetValue()           PORTAbits.RA7
#define BOTTLE_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BOTTLE_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BOTTLE_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BOTTLE_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BOTTLE_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define BOTTLE_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define BOTTLE_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define BOTTLE_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISBbits.TRISB1
#define SCK1_LAT                  LATBbits.LATB1
#define SCK1_PORT                 PORTBbits.RB1
#define SCK1_WPU                  WPUBbits.WPUB1
#define SCK1_OD                   ODCONBbits.ODCB1
#define SCK1_ANS                  ANSELBbits.ANSELB1
#define SCK1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK1_GetValue()           PORTBbits.RB1
#define SCK1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISBbits.TRISB2
#define SDI1_LAT                  LATBbits.LATB2
#define SDI1_PORT                 PORTBbits.RB2
#define SDI1_WPU                  WPUBbits.WPUB2
#define SDI1_OD                   ODCONBbits.ODCB2
#define SDI1_ANS                  ANSELBbits.ANSELB2
#define SDI1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SDI1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SDI1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SDI1_GetValue()           PORTBbits.RB2
#define SDI1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISBbits.TRISB3
#define SDO1_LAT                  LATBbits.LATB3
#define SDO1_PORT                 PORTBbits.RB3
#define SDO1_WPU                  WPUBbits.WPUB3
#define SDO1_OD                   ODCONBbits.ODCB3
#define SDO1_ANS                  ANSELBbits.ANSELB3
#define SDO1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SDO1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SDO1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SDO1_GetValue()           PORTBbits.RB3
#define SDO1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set LCD_BL aliases
#define LCD_BL_TRIS                 TRISCbits.TRISC2
#define LCD_BL_LAT                  LATCbits.LATC2
#define LCD_BL_PORT                 PORTCbits.RC2
#define LCD_BL_WPU                  WPUCbits.WPUC2
#define LCD_BL_OD                   ODCONCbits.ODCC2
#define LCD_BL_ANS                  ANSELCbits.ANSELC2
#define LCD_BL_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_BL_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_BL_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_BL_GetValue()           PORTCbits.RC2
#define LCD_BL_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_BL_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_BL_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_BL_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_BL_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_BL_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_BL_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCD_BL_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCDMini_nRESET aliases
#define LCDMini_nRESET_TRIS                 TRISDbits.TRISD0
#define LCDMini_nRESET_LAT                  LATDbits.LATD0
#define LCDMini_nRESET_PORT                 PORTDbits.RD0
#define LCDMini_nRESET_WPU                  WPUDbits.WPUD0
#define LCDMini_nRESET_OD                   ODCONDbits.ODCD0
#define LCDMini_nRESET_ANS                  ANSELDbits.ANSELD0
#define LCDMini_nRESET_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCDMini_nRESET_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCDMini_nRESET_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCDMini_nRESET_GetValue()           PORTDbits.RD0
#define LCDMini_nRESET_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCDMini_nRESET_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCDMini_nRESET_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LCDMini_nRESET_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LCDMini_nRESET_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LCDMini_nRESET_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LCDMini_nRESET_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define LCDMini_nRESET_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/