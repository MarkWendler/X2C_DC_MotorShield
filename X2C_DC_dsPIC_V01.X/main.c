/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  Description:
*/

#include "mcc_generated_files/mcc.h"
#include "qei.h"
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalEnable();
    
    //Enable QEI     
    qei_Initialize();
    
    while (1)
    {
        
        X2C_Communicate();
    }
}

/**
 End of File
*/