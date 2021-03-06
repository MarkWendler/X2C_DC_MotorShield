/* This file is part of X2C. http://www.mechatronic-simulation.org/                                                   */

/* Model: X2C_LowEndMotorShield_V01                                                                                   */
/* Date:  2018-05-01 20:11                                                                                            */

/* X2C-Version: 1116                                                                                                  */

#include "FlashTable.h"
#include "RamTable.h"
#include "X2C.h"

/*                                                       Inports                                                      */
/*--------------------------------------------------------------------------------------------------------------------*/
TInports Inports;

/*                                                      Outports                                                      */
/*--------------------------------------------------------------------------------------------------------------------*/
TOutports Outports;

/**********************************************************************************************************************/
/**                                              Global Variables Block                                              **/
/**********************************************************************************************************************/
PI_FIP16                      TPI;
CONSTANT_FIP16                TConstant3;
SUB_FIP16                     TSub;
CONSTANT_FIP16                TConstant;
CONSTANT_FIP8                 TConstant1;
SUB_FIP16                     TSub1;
PI_FIP16                      TPI1;
SCOPE_MAIN                    TScope;

/* Block function table                                                                                               */
#define END_BLOCKFUNCTIONS { (uint16)0, (void (*)(void*))0, (void (*)(void*))0, \
    (uint8 (*)(void*, uint8[]))0, (uint8 (*)(void*, uint8[], uint8))0, (void* (*)(void*, uint16))0 }

const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    END_BLOCKFUNCTIONS
};

/* Parameter identifier table                                                                                         */
#define END_PARAMETERTABLE { (uint16)0, (void*)0 }

const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    END_PARAMETERTABLE
};

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init()
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block PI                                                                                                       */
    /* Kp = 0.0                                                                                                       */
    /* Ki = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    TPI.b0 = 0;
    TPI.b1 = 0;
    TPI.sfrb0 = 15;
    TPI.sfrb1 = 15;
    TPI.i_old = 0;
    TPI.enable_old = 0;

    /* Block Constant3                                                                                                */
    /* Value = 1.0                                                                                                    */
    TConstant3.K = 32767;

    /* Block Sub                                                                                                      */

    /* Block Constant                                                                                                 */
    /* Value = 0.0                                                                                                    */
    TConstant.K = 0;

    /* Block Constant1                                                                                                */
    /* Value = 1.0                                                                                                    */
    TConstant1.K = 127;

    /* Block Sub1                                                                                                     */

    /* Block PI1                                                                                                      */
    /* Kp = 0.0                                                                                                       */
    /* Ki = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    TPI1.b0 = 0;
    TPI1.b1 = 0;
    TPI1.sfrb0 = 15;
    TPI1.sfrb1 = 15;
    TPI1.i_old = 0;
    TPI1.enable_old = 0;


    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block PI                                                                                                       */
    TPI.In                           = &TSub.Out;
    TPI.Init                         = &TConstant.Out;
    TPI.Enable                       = &TConstant1.Out;

    /* Block Constant3                                                                                                */

    /* Block Sub                                                                                                      */
    TSub.Plus                        = &(Inports.POT);
    TSub.Minus                       = &(Inports.AngularVelocity);

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Sub1                                                                                                     */
    TSub1.Plus                       = &TPI.Out;
    TSub1.Minus                      = &(Inports.I_Motor);

    /* Block PI1                                                                                                      */
    TPI1.In                          = &TSub1.Out;
    TPI1.Init                        = &TConstant.Out;
    TPI1.Enable                      = &TConstant1.Out;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    Outports.pV_MOTOR                 = &Inports.POT;
    Outports.pLED0                    = &Inports.S1;
    Outports.pEnableMotor             = &TConstant3.Out;
    Outports.pLED1                    = &Inports.S2;
    Outports.pDirection               = &Inports.S1;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    PI_FiP16_Init(&TPI);
    Constant_FiP16_Init(&TConstant3);
    Sub_FiP16_Init(&TSub);
    Constant_FiP16_Init(&TConstant);
    Constant_FiP8_Init(&TConstant1);
    Sub_FiP16_Init(&TSub1);
    PI_FiP16_Init(&TPI1);
    Scope_Main_Init(&TScope);
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
void X2C_Update(void)
{
    X2C_Update_1();

}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    Sub_FiP16_Update(&TSub);
    PI_FiP16_Update(&TPI);
    Sub_FiP16_Update(&TSub1);
    PI_FiP16_Update(&TPI1);
    Scope_Main_Update(&TScope);
}

