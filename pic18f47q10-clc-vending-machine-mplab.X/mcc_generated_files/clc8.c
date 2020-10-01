/**
  CLC8 Generated Driver File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    clc8.c
 
  @Summary
    This is the generated driver implementation file for the CLC8 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
  @Description
    This source file provides implementations for driver APIs for CLC8.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00 or later
        MPLAB             :  MPLAB X 5.10
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

/**
  Section: Included Files
 */

#include <xc.h>
#include "mcc.h"
#include "clc8.h"
#include "tmr5.h"
#include "pin_manager.h"
#include "../application.h"

extern bool invalidFlag;
extern bool timerLedFlag;

/**
  Section: CLC8 APIs
 */

void CLC8_Initialize(void) {
    // Set the CLC8 to the options selected in the User Interface

    // LC8G1POL not_inverted; LC8G2POL not_inverted; LC8G3POL inverted; LC8G4POL inverted; LC8POL not_inverted; 
    CLC8POL = 0x0C;
    // LC8D1S CLC1_OUT; 
    CLC8SEL0 = 0x21;
    // LC8D2S CLC2_OUT; 
    CLC8SEL1 = 0x22;
    // LC8D3S TMR2_OUT; 
    CLC8SEL2 = 0x13;
    // LC8D4S TMR4_OUT; 
    CLC8SEL3 = 0x15;
    // LC8G1D3N enabled; LC8G1D2N disabled; LC8G1D4N disabled; LC8G1D1T disabled; LC8G1D3T disabled; LC8G1D2T disabled; LC8G1D4T disabled; LC8G1D1N disabled; 
    CLC8GLS0 = 0x10;
    // LC8G2D2N disabled; LC8G2D1N disabled; LC8G2D4N enabled; LC8G2D3N disabled; LC8G2D2T disabled; LC8G2D1T disabled; LC8G2D4T disabled; LC8G2D3T disabled; 
    CLC8GLS1 = 0x40;
    // LC8G3D1N disabled; LC8G3D2N disabled; LC8G3D3N disabled; LC8G3D4N disabled; LC8G3D1T disabled; LC8G3D2T disabled; LC8G3D3T disabled; LC8G3D4T disabled; 
    CLC8GLS2 = 0x00;
    // LC8G4D1N disabled; LC8G4D2N disabled; LC8G4D3N disabled; LC8G4D4N disabled; LC8G4D1T disabled; LC8G4D2T disabled; LC8G4D3T disabled; LC8G4D4T disabled; 
    CLC8GLS3 = 0x00;
    // LC8EN enabled; INTN disabled; INTP enabled; MODE 4-input AND; 
    CLC8CON = 0x92;

    // Clear the CLC interrupt flag
    PIR6bits.CLC8IF = 0;
    // Enabling CLC8 interrupt.
    PIE6bits.CLC8IE = 1;
}

void CLC8_ISR(void) {
    // Clear the CLC interrupt flag
    PIR6bits.CLC8IF = 0;
    // make the Invalid Flag high to indicate wrong coin entry
    invalidFlag = true;
    // and check if the timer 5 is already started by Bottle/Change interrupt
    // If already started , don't start the timer again

    BOTTLE_SetLow();
    CHANGE1_SetLow();
    CHANGE2_SetLow();
    CHANGE3_SetLow();
    if (!timerLedFlag) {
        TMR5_StartTimer();
        timerLedFlag = true;
    }
}

bool CLC8_OutputStatusGet(void) {
    return (CLC8CONbits.LC8OUT);
}
/**
 End of File
 */

