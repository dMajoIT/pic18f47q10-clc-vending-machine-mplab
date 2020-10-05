#include "mcc_generated_files/mcc.h"
#include "application.h"
#include "mcc_generated_files/lcd_example.h"

#define USER_INACTIVITY_CYCLES   300  //300 //equivalent to 60s
#define LCD_STRING_SIZE         17

bool bottleFlag;
uint8_t changeFlag = 0xff; //keeping in to unknown case to push the switch control to default case 
bool invalidFlag;
bool timerLedFlag;

volatile uint16_t timer5ReloadVal;
extern uint16_t sleepCounter;

char stringRow1[LCD_STRING_SIZE];
char stringRow2[LCD_STRING_SIZE];
uint16_t sleepCounter = 0;

void CLC_DefaultState(void) {
    CLC1POLbits.G3POL = 1;
    CLC1POLbits.G3POL = 0;
    CLC2POLbits.G3POL = 1;
    CLC2POLbits.G3POL = 0;

    CLC3POLbits.G3POL = 1;
    CLC3POLbits.G4POL = 1;
    CLC4POLbits.G3POL = 1;
    CLC4POLbits.G4POL = 1;
}

/**
   @Param
    none
   @Returns
    none
   @Description
   @application display initialization message on screen 
   @Example
    lcd_put_init_message();
 */
void lcd_put_init_message(void)
{
    char stringTemp1[16] = " MICROCHIP DEMO ";
    char stringTemp2[16] = "CLC Example: FSM";
    
    //set LCD contrast
    lcd_setContrast(0x35);
    
    //turn on LCD Back light
    LCD_BL_SetHigh();
    
    //Display LCD Data
    lcd_writeString(stringTemp1, 0);
    lcd_writeString(stringTemp2, 1);
}

/**
   @Param
    none
   @Returns
    none
   @Description
   @application initialization  
   @Example
    ApplicationInit();
 */
void ApplicationInit(void) //debug
{
    // reset D flip flop CLC1 and CLC2 to 0 by toggling R pin

    CLC1POLbits.G3POL = 1;
    CLC1POLbits.G3POL = 0;
    CLC2POLbits.G3POL = 1;
    CLC2POLbits.G3POL = 0;
     
    invalidFlag = false; //explicitly making zero to avoid initial error message 

}

/**
   @Param
    none
   @Returns
    none
   @Description
    main application task
   @Example
    applicationTask();
 */
void ApplicationTask(void) {
    /*
     * if the system is waiting for the coins, display system state
     * and balance to be entered. Else, display dispense messages.
     * timer_led_flag is used for checking it
     */
    if (!timerLedFlag) {
        //Get System State and LCD strings
        FillFSMstate();
    } else {
        //Get Dispense State
        FillDispenseData();
    }
    //Display LCD Data
    lcd_writeString(stringRow1, 0);
    lcd_writeString(stringRow2, 1);

    //check for user inactivity and go to sleep
    CheckSleepMode();
}

/**
  @Param
   none
  @Returns
   none
  @Description
   Count the delay for user inactivity and go to sleep
  @Example
   CheckSleepMode();
 */
void CheckSleepMode(void) {
    uint16_t stateBit0;
    uint16_t stateBit1;
    uint16_t state;

    //increment user inactivity counter
    sleepCounter++;
    //if it is more than defined cycles
    //turn off the LCD back-light and go to sleep
    if (sleepCounter >= USER_INACTIVITY_CYCLES) {
        //Get current FSM State from CLC outputs to display on the LCD
        sleepCounter = 0;
        stateBit0 = CLC4_OutputStatusGet();
        stateBit1 = CLC3_OutputStatusGet();
        state = (stateBit1 << 1) + stateBit0;
        if (state) {
            //Display LCD message to error
            sprintf(stringRow1, "FSM State: Error");
            sprintf(stringRow2, "Going  to  Sleep");

            lcd_writeString(stringRow1, 0);
            lcd_writeString(stringRow2, 1);

            // reset D flip flop CLC1 and CLC2 to 0 by toggling R pin
            CLC1POLbits.G3POL = 1;
            CLC1POLbits.G3POL = 0;
            CLC2POLbits.G3POL = 1;
            CLC2POLbits.G3POL = 0;
            __delay_ms(2000);
        }

        //Display LCD message to error
        sprintf(stringRow1, "Sleep Mode      ");
        sprintf(stringRow2, "Add Coin to Wake");

        lcd_writeString(stringRow1, 0);
        lcd_writeString(stringRow2, 1);

        //turn off lcd backlight
        LCD_BL_SetLow();
        //go to sleep
        SLEEP();
        __delay_ms(10);
        //turn on lcd backlight
        LCD_BL_SetHigh();
    }
}

/**
@Param
 none
@Returns
 none
@Description
  Get Current FSM state from CLC and Fill LCD strings
@Example
 FillFSMstate();
 */
void FillFSMstate(void) {
    uint16_t stateBit0;
    uint16_t stateBit1;
    uint16_t state;

    //Get current FSM State from CLC outputs to display on the LCD
    stateBit0 = CLC4_OutputStatusGet();
    stateBit1 = CLC3_OutputStatusGet();
    state = (stateBit1 << 1) + stateBit0;

    if (true == invalidFlag) {
        state = 0;
        invalidFlag = false;
        CLC_DefaultState();
    }

    //Depending on FSM state fill strings to be displayed
    switch (state) {
            //state 00
        case 0:
            //Copy strings into array
            sprintf(stringRow1, "FSM: Wait 0 Cent");
            sprintf(stringRow2, "Bottle Price 75C");
            break;
            //state 01
        case 1:
            //Copy strings into array
            sprintf(stringRow1, "FSM: 25 CentPaid");
            sprintf(stringRow2, "Insert 50 C more");
            break;
            //state 10
        case 2:
            //Copy strings into array
            sprintf(stringRow1, "FSM: 50 CentPaid");
            sprintf(stringRow2, "Insert 25 C more");
            break;

        default:
            break;
    }

}

/**
@Param
 none
@Returns
 none
@Description
 Get Get dispense information from CLC and fill LCD strings
@Example
 FillDispenseData();
 */
void FillDispenseData(void) {
    //Read the output flags from the CLC to print the corresponding dispenses.
    //if the invalid state output is generated
    if (invalidFlag) {
        //Copy strings into array
        sprintf(stringRow1, "FSM State: Error");
        sprintf(stringRow2, "Coins   Returned");
    } else if (bottleFlag) {
        switch (changeFlag) {
            case 0:
                //Copy strings into array
                sprintf(stringRow1, "FSM State:  Done");
                sprintf(stringRow2, "Bottle Dispensed");
                break;
            case 1:
                //Copy strings into array
                sprintf(stringRow1, "FSM State:  Done");
                sprintf(stringRow2, "Bott & 25 C Disp");
                break;
            case 2:
                //Copy strings into array
                sprintf(stringRow1, "FSM State:  Done");
                sprintf(stringRow2, "Bott & 50 C Disp");
                break;
            case 3:
                //Copy strings into array
                sprintf(stringRow1, "FSM State:  Done");
                sprintf(stringRow2, "Bott & 75 C Disp");
                break;
            default:
                break;
        }
    }
}

/**
  @Param
   none
  @Returns
   none
  @Description
   Reset user inactivity counter as switch is pressed
  @Example
   TMR2UserInterrupt();
 */
void TMR2UserInterrupt(void)
{
    sleepCounter = 0;
}

/**
  @Param
   none
  @Returns
   none
  @Description
   Reset user inactivity counter as switch is pressed
  @Example
   TMR4UserInterrupt();
 */
void TMR4UserInterrupt(void)
{
    sleepCounter = 0;
}

/**
  @Param
   none
  @Returns
   none
  @Description
   Flag reset, Dispense and bottle/change information
  @Example
   TMR5UserInterrupt();
 */
void TMR5UserInterrupt(void)
{
    //Dispense flag reset
    bottleFlag = false;
    changeFlag = 0;
    //invalidFlag = false;
    timerLedFlag = false;
    // make both the LEDs low to indicate the BOTTLE/CHANGE is dispensed
    CHANGE1_SetLow();
    CHANGE2_SetLow();
    CHANGE3_SetLow();
    BOTTLE_SetLow();
    // stop the timer and reload it
    TMR5_StopTimer();
    TMR5_WriteTimer(timer5ReloadVal);
}
