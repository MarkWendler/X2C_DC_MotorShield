/**
 * @file
 * @brief Generated model file.

 * Date:  2018-05-01 20:11
 * X2C-Version: 1116
 */
/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: X2C_LowEndMotorShield_V01                                                                                   */
/* Date:  2018-05-01 20:11                                                                                            */

/* X2C-Version: 1116                                                                                                  */

#ifndef __X2C_H__
#define __X2C_H__

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
#include "PI_FiP16.h"
#include "Constant_FiP16.h"
#include "Sub_FiP16.h"
#include "Constant_FiP8.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS PI_FIP16_FUNCTIONS , \
                  CONSTANT_FIP16_FUNCTIONS , \
                  SUB_FIP16_FUNCTIONS , \
                  CONSTANT_FIP8_FUNCTIONS , \
                  SCOPE_MAIN_FUNCTIONS 

#define PARAMETER_TABLE { (uint16)1, &TConstant } , \
                        { (uint16)2, &TConstant1 } , \
                        { (uint16)3, &TConstant3 } , \
                        { (uint16)4, &TPI } , \
                        { (uint16)5, &TPI1 } , \
                        { (uint16)6, &TSub } , \
                        { (uint16)7, &TSub1 } , \
                        { (uint16)8, &TScope } , \
                        { (uint16)9, &Inports.AngularVelocity } , \
                        { (uint16)10, &Inports.Commutation } , \
                        { (uint16)11, &Inports.I_Motor } , \
                        { (uint16)12, &Inports.POT } , \
                        { (uint16)13, &Inports.S1 } , \
                        { (uint16)14, &Inports.S2 } , \
                        { (uint16)15, &Inports.V_Motor } , \
                        { (uint16)16, &Outports.pV_MOTOR } , \
                        { (uint16)17, &Outports.pLED0 } , \
                        { (uint16)18, &Outports.pEnableMotor } , \
                        { (uint16)19, &Outports.pLED1 } , \
                        { (uint16)20, &Outports.pDirection } 

/**********************************************************************************************************************/
/**     Typdefs                                                                                                      **/
/**********************************************************************************************************************/

/* Inport structure                                                                                                   */
typedef struct 
{
    int16 I_Motor;
    int16 V_Motor;
    int16 POT;
    int16 S1;
    int16 S2;
    int16 AngularVelocity;
    int16 Commutation;
} TInports;

/* Outport structure                                                                                                  */
typedef struct 
{
    int16* pV_MOTOR;
    int16* pLED0;
    int16* pEnableMotor;
    int16* pLED1;
    int16* pDirection;
} TOutports;

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern TInports Inports;
extern TOutports Outports;
extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];


/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);


#endif
