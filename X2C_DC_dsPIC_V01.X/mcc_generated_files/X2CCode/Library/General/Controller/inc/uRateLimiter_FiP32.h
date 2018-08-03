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
 * $LastChangedRevision: 457 $
 */
/* USERCODE-BEGIN:Description                                                                                         */
/*      Description:	Output change rate limitation of angle signals        */
/* 						Calculation:										  */
/* 							u > y:											  */
/* 								y(k)     = y(k-1) + RateUp					  */
/* 								RateUp   = 1/Tr * Ts						  */
/* 							u < y:											  */
/* 								y(k)     = y(k-1) - RateDown				  */
/* 								RateDown = 1/Tf * Ts						  */
/*                                                                            */
/* USERCODE-END:Description                                                                                           */
#ifndef __URATELIMITER_FIP32__
#define __URATELIMITER_FIP32__

#include "CommonFcts.h"

#if !defined(URATELIMITER_FIP32_ISLINKED)
#define URATELIMITER_FIP32_ID ((uint16)290)

typedef struct {
        uint16       ID;
        int32        *In;
        int32        *Init;
        int8         *Enable;
        int32        Out;
        int32        RateUp;
        int32        RateDown;
        int8         enable_old;
} URATELIMITER_FIP32;

#define URATELIMITER_FIP32_FUNCTIONS {URATELIMITER_FIP32_ID, \
                              (void (*)(void*))uRateLimiter_FiP32_Update, \
                              (void (*)(void*))uRateLimiter_FiP32_Init, \
                              (uint8 (*)(void*, uint8[]))uRateLimiter_FiP32_Load, \
                              (uint8 (*)(void*, uint8[], uint8))uRateLimiter_FiP32_Save, \
                              (void* (*)(void*, uint16))uRateLimiter_FiP32_GetAddress}

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void uRateLimiter_FiP32_Update(URATELIMITER_FIP32 *pTuRateLimiter_FiP32);
void uRateLimiter_FiP32_Init(URATELIMITER_FIP32 *pTuRateLimiter_FiP32);
uint8 uRateLimiter_FiP32_Load(const URATELIMITER_FIP32 *pTuRateLimiter_FiP32, uint8 data[]);
uint8 uRateLimiter_FiP32_Save(URATELIMITER_FIP32 *pTuRateLimiter_FiP32, const uint8 data[], uint8 frameLength);
void* uRateLimiter_FiP32_GetAddress(const URATELIMITER_FIP32* block, uint16 elementId);

#endif

#endif
