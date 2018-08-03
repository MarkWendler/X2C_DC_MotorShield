/* ************************************************************************** */
/** X2CMain.c

  @Company
    Microchip Technology

  @Summary
 Implementation of X2C In and Outport connections

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CMain.h"
#warning "If the compiler failes here, that means you did not generate code by the X2C"
#include "X2C.h"
#include "mcc.h"
#include "../../qei.h"

int current = 0, poti = 0, commutation = 0, motorVoltage = 0; 

/* Motor speed calculation*/
#define PWMFREQ 10000 //Hz
#define VELOCITYSAMPLE 10 //Hz (100ms))
uint16 motorSpeed = 0, qeiCounter = 0, qeiSampleDivider = 0;

void UpdateInports(void) {

    /*
     * Pass the peripheral values to model Inports
     * if (PORTA & 1) { 
     *    Inports.Inport = INT16_MAX;
     * }else {
     *    Inports.Inport = 0;
     * }
     * 
     * The following inputs of the model can be used:
      Inports.I_Motor = 1*selectPeripheral
      Inports.POT = 1*selectPeripheral
      Inports.S1 = 1*selectPeripheral
      Inports.Commutation = 1*selectPeripheral
      Inports.Voltage = 1*selectPeripheral
      Inports.S2 = 1*selectPeripheral
      Inports.AngularVelocity = 1*selectPeripheral

     */

    if((qeiSampleDivider++) > (PWMFREQ/VELOCITYSAMPLE)){
        motorSpeed = qeiCounter;
        qeiCounter = 0;
    }
    
    Inports.AngularVelocity = motorSpeed;
    Inports.S2 = getSpeed();
    
    
    Inports.I_Motor = current << 3; /* 10bit to 15bit (Q15 format)*/
    Inports.POT = poti << 3;        /* 10bit to 15bit (Q15 format)*/
    Inports.Commutation = commutation << 3; /* 10bit to 15bit (Q15 format)*/
    Inports.V_Motor = POS1CNTL;
    
    
    
    if(IO_S1_GetValue()){
        Inports.S1 = 0; // Button not pressed
    }
    else{ // Button pressed
        Inports.S1 = INT16_MAX;
    }
}

void UpdateOutports(void) {
    
    /*
     * Pass model outports to peripherals e.g.:
     * 
     * if (*Outports.pOutport) {  // if model Outport differ than zero 
     *    LATB |= 1; // set LATB0 
     * } else {
     *    LATB &= ~1; // clear LATB0
     * }    
     * 
     * The following outputs of the model can be used:
      selectPeripheral = *Outports.V_MOTOR*1
      selectPeripheral = *Outports.LED0*1
      selectPeripheral = *Outports.LED1*1
     */
    int32 temp = *Outports.pV_MOTOR;
    temp = (temp *7000 ) / INT16_MAX;
    PWM_MasterDutyCycleSet((int16)temp);
    
    if(*Outports.pEnableMotor){
        if(*Outports.pDirection){
            //PWM1H active, PWM1L inactive
            __builtin_write_PWMSFR(&IOCON1, 0xE380, &PWMKEY);
            //PWM2H inactive, PWM2L no override
            __builtin_write_PWMSFR(&IOCON2, 0xE200, &PWMKEY);
        }

        else{
            //PWM2H active, PWM2L inactive
            __builtin_write_PWMSFR(&IOCON2, 0xE380, &PWMKEY); 
            //PWM1H inactive, PWM1L no override
            __builtin_write_PWMSFR(&IOCON1, 0xE200, &PWMKEY);
        
        }
    }
    else{
        //PWM2H active, PWM2L inactive
        __builtin_write_PWMSFR(&IOCON1, 0xE300, &PWMKEY);
        //PWM2H active, PWM2L inactive
        __builtin_write_PWMSFR(&IOCON2, 0xE300, &PWMKEY);
    }

}
/**
 * Calls the inports update function
 * Then run model calculation
 * Last read model outports and update the peripherals
 */
/*
 * No pwm callback function, manual modification needed.
 * TODO: delete _PWMInterrupt implementation from pwm.c
 */
void __attribute__ ( ( interrupt, no_auto_psv ) ) _PWM1Interrupt (  )
{
    IFS5bits.PWM1IF = false; 
 
    IO_LED3_SetHigh();
    
    //if(ADC1_IsConversionComplete()){
        //Start AD conversion
    //    ADC1_SamplingStart(); 
    //}
    
    UpdateInports();
    X2C_Update();
    UpdateOutports();
    
    IO_LED3_SetLow();

}


void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AD1Interrupt ( void )
{
    // clear the ADC interrupt flag
    IFS0bits.AD1IF = false;
    
    IO_LED4_Toggle();
    
    current = ADC1BUF0; // Read the AN0 conversion result
    poti = ADC1BUF1; // Read the AN1 conversion result
    commutation = ADC1BUF2; // Read the AN4 conversion result
    motorVoltage = ADC1BUF3; // Read the AN5 conversion result
}

/* Interrupt service routine for the CNI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNInterrupt ( void )
{
    if(IFS1bits.CNIF == 1)
    {
        // Clear the flag
        IFS1bits.CNIF = 0;
        
        qeiCounter ++;
    }
}

/* *****************************************************************************
 End of File
 */
