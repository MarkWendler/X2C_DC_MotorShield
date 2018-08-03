/*
 * @file: qei.h
 * @author: Mark Wendler
 * @date 30 Apr 2018
 * @brief: Quadrature Encoder Interface (QEI)
 * 
 * QEI configuration for X2C+ development board and DC motor shield 
 * @see http://x2c.microstickplus.com/
 * @note hardware specific configuration: X2C+ with DC motor shield
 */

#include "qei.h"
#include "mcc_generated_files/X2CCode/X2C.h"

void qei_Initialize(void){
    
      /* QEI Config*/
    
    // Data Direction for QEI
    // Setup by MCC PIN module
    
    // PPS for QEI X2C DC motor shield
    RPINR14bits.QEA1R = 42;
    RPINR14bits.QEB1R = 43;    
    
    QEI1CON = 0x0;
    
    QEI1CONbits.PIMOD = 5; // RESET POS if equals QEI1GEC

    // Limit count range between 0 and PULSES_PER_REV 
    QEI1LECL = 0;
    QEI1LECH = 0;
    QEI1GECL = 50 - 1;
    QEI1GECH = 0;
    
    // Enable digital filtering, this is a must!
    QEI1IOCbits.FLTREN = 0; 
    
    // QEI enable
    QEI1CONbits.QEIEN = 1;
    /* END: QEI Config*/
}


#define PWMFREQUENCY 10000 //Hz
#define SPEED_SAMPLE_FREQ 10 //Hz (100ms))

int getSpeed(void){
  static uint16 sampleTimeDivider = 0;
  static int speed = 0;
  
  sampleTimeDivider++;  /* Sample time 10ms SAMPLE_FREQ */
    
  if(sampleTimeDivider >= (PWMFREQUENCY/SPEED_SAMPLE_FREQ)){
      sampleTimeDivider = 0;
      speed = VEL1CNT; /* Get the counted qei pulses */
//      VEL1CNT = 0;
//      if(VELTEMP > 0xF000) Speed = 0 - (UINT16_MAX-VELTEMP); /*Get direction*/
//      else Speed = VELTEMP;

    
    /* Calculate in RPM pulses*((1/sampletime)/Pulses_PER_REV)*60sec*/
    /* Scale speed -> 3000rpm -> 1*/
    /*INT32_MAX*SPEED_SAMPLE_FREQ*60)/(PULSE_PER_REV*3000)*/
//    Speed =  (Speed*(INT16_MAX/500)); //((int32_t)INT16_MAX*SPEED_SAMPLE_FREQ*60)/(PULSE_PER_REV*MAX_SPEED))
    /* Check overflow*/
//    if ( (VELTEMP > 0xF000) && ( Speed > 0 ) ) Speed = -INT16_MAX;
//    else if ( (VELTEMP < 0xF000) && (Speed < 0)  ) Speed = INT16_MAX;
  }
  return speed;
}
