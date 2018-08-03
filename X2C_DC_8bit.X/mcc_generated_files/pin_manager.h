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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18857
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ch_POT aliases
#define ch_POT_TRIS                 TRISAbits.TRISA1
#define ch_POT_LAT                  LATAbits.LATA1
#define ch_POT_PORT                 PORTAbits.RA1
#define ch_POT_WPU                  WPUAbits.WPUA1
#define ch_POT_OD                   ODCONAbits.ODCA1
#define ch_POT_ANS                  ANSELAbits.ANSA1
#define ch_POT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ch_POT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ch_POT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ch_POT_GetValue()           PORTAbits.RA1
#define ch_POT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ch_POT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ch_POT_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ch_POT_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ch_POT_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define ch_POT_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define ch_POT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define ch_POT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IO_S2 aliases
#define IO_S2_TRIS                 TRISAbits.TRISA6
#define IO_S2_LAT                  LATAbits.LATA6
#define IO_S2_PORT                 PORTAbits.RA6
#define IO_S2_WPU                  WPUAbits.WPUA6
#define IO_S2_OD                   ODCONAbits.ODCA6
#define IO_S2_ANS                  ANSELAbits.ANSA6
#define IO_S2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_S2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_S2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_S2_GetValue()           PORTAbits.RA6
#define IO_S2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_S2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_S2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_S2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_S2_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_S2_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_S2_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define IO_S2_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_S1 aliases
#define IO_S1_TRIS                 TRISAbits.TRISA7
#define IO_S1_LAT                  LATAbits.LATA7
#define IO_S1_PORT                 PORTAbits.RA7
#define IO_S1_WPU                  WPUAbits.WPUA7
#define IO_S1_OD                   ODCONAbits.ODCA7
#define IO_S1_ANS                  ANSELAbits.ANSA7
#define IO_S1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_S1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_S1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_S1_GetValue()           PORTAbits.RA7
#define IO_S1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_S1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_S1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_S1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_S1_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_S1_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_S1_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define IO_S1_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set IO_QEB aliases
#define IO_QEB_TRIS                 TRISBbits.TRISB0
#define IO_QEB_LAT                  LATBbits.LATB0
#define IO_QEB_PORT                 PORTBbits.RB0
#define IO_QEB_WPU                  WPUBbits.WPUB0
#define IO_QEB_OD                   ODCONBbits.ODCB0
#define IO_QEB_ANS                  ANSELBbits.ANSB0
#define IO_QEB_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_QEB_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_QEB_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_QEB_GetValue()           PORTBbits.RB0
#define IO_QEB_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_QEB_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_QEB_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_QEB_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_QEB_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_QEB_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_QEB_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_QEB_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_QEA aliases
#define IO_QEA_TRIS                 TRISBbits.TRISB1
#define IO_QEA_LAT                  LATBbits.LATB1
#define IO_QEA_PORT                 PORTBbits.RB1
#define IO_QEA_WPU                  WPUBbits.WPUB1
#define IO_QEA_OD                   ODCONBbits.ODCB1
#define IO_QEA_ANS                  ANSELBbits.ANSB1
#define IO_QEA_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_QEA_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_QEA_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_QEA_GetValue()           PORTBbits.RB1
#define IO_QEA_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_QEA_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_QEA_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_QEA_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_QEA_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_QEA_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_QEA_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_QEA_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()               do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()                do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()                do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()       do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()      do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()               do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()                do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()                do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()       do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()      do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()               do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()                do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()                do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()       do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()      do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()               do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()                do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()                do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()       do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()      do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_LED1 aliases
#define IO_LED1_TRIS                 TRISCbits.TRISC4
#define IO_LED1_LAT                  LATCbits.LATC4
#define IO_LED1_PORT                 PORTCbits.RC4
#define IO_LED1_WPU                  WPUCbits.WPUC4
#define IO_LED1_OD                   ODCONCbits.ODCC4
#define IO_LED1_ANS                  ANSELCbits.ANSC4
#define IO_LED1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_LED1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_LED1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_LED1_GetValue()           PORTCbits.RC4
#define IO_LED1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_LED1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_LED1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_LED1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_LED1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_LED1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_LED1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_LED1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_LED2 aliases
#define IO_LED2_TRIS                 TRISCbits.TRISC5
#define IO_LED2_LAT                  LATCbits.LATC5
#define IO_LED2_PORT                 PORTCbits.RC5
#define IO_LED2_WPU                  WPUCbits.WPUC5
#define IO_LED2_OD                   ODCONCbits.ODCC5
#define IO_LED2_ANS                  ANSELCbits.ANSC5
#define IO_LED2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_LED2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_LED2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_LED2_GetValue()           PORTCbits.RC5
#define IO_LED2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_LED2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_LED2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_LED2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_LED2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_LED2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_LED2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_LED2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_LED4 aliases
#define IO_LED4_TRIS                 TRISCbits.TRISC7
#define IO_LED4_LAT                  LATCbits.LATC7
#define IO_LED4_PORT                 PORTCbits.RC7
#define IO_LED4_WPU                  WPUCbits.WPUC7
#define IO_LED4_OD                   ODCONCbits.ODCC7
#define IO_LED4_ANS                  ANSELCbits.ANSC7
#define IO_LED4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_LED4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_LED4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_LED4_GetValue()           PORTCbits.RC7
#define IO_LED4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_LED4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_LED4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_LED4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_LED4_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_LED4_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_LED4_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_LED4_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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