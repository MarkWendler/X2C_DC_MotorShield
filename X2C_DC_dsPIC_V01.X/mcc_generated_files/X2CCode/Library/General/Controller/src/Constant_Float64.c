/*
 * Copyright (c) 2013, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://www.mechatronic-simulation.org/
 * $LastChangedRevision: 1000 $
 */
/* USERCODE-BEGIN:Description                                                                                         */
/**     Description:	Constant value.                                      **/
/**																			 **/
/* USERCODE-END:Description                                                                                           */
#include "Constant_Float64.h"

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* Outputs */
#define OUT				(pTConstant_Float64->Out)

/* Parameter */
#define VALUE 			(pTConstant_Float64->K)

/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** No Update function                                                                                               **/
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void Constant_Float64_Init(CONSTANT_FLOAT64 *pTConstant_Float64)
{
     pTConstant_Float64->ID = CONSTANT_FLOAT64_ID;
     pTConstant_Float64->Out = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
     OUT = VALUE;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 Constant_Float64_Load(const CONSTANT_FLOAT64 *pTConstant_Float64, uint8 data[])
{
     uint8 loadSize;

     data[0] = (uint8)((*(uint64*)&(pTConstant_Float64->K)) & 0x00000000000000FF);
     data[1] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 8) & 0x00000000000000FF);
     data[2] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 16) & 0x00000000000000FF);
     data[3] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 24) & 0x00000000000000FF);
     data[4] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 32) & 0x00000000000000FF);
     data[5] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 40) & 0x00000000000000FF);
     data[6] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 48) & 0x00000000000000FF);
     data[7] = (uint8)((*(uint64*)&(pTConstant_Float64->K) >> 56) & 0x00000000000000FF);
     loadSize = (uint8)8;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
     return (loadSize);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 Constant_Float64_Save(CONSTANT_FLOAT64 *pTConstant_Float64, const uint8 data[], 
          uint8 frameLength)
{
     uint8 error;
     uint64 tmp64;

     if (frameLength != (uint8)8)
     {
          error = (uint8)1;
     }
     else
     {
          tmp64 = (uint64)data[0] + \
               ((uint64)data[1] << 8) + ((uint64)data[2] << 16) + \
               ((uint64)data[3] << 24) + ((uint64)data[4] << 32) + \
               ((uint64)data[5] << 40) + ((uint64)data[6] << 48) + \
               ((uint64)data[7] << 56);
          pTConstant_Float64->K = (float64)(*(float64*)&tmp64);
          error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
          OUT = VALUE;
/* USERCODE-END:SaveFnc                                                                                               */
     }
     return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(CONSTANT_FLOAT64_ISLINKED)
void* Constant_Float64_GetAddress(const CONSTANT_FLOAT64* block, uint16 elementId)
{
    void* addr;
    switch (elementId)
    {
        case 1:
            addr = (void*)&block->Out;
            break;
        default:
            addr = (void*)0;
            break;
    }
    return (addr);
}
#endif
