/*
 * @file: qei.h
 * @author: Mark Wendler
 * @brief: Quadrature Encoder Interface (QEI)
 * @date 30 Apr 2018
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_QEI_H
#define	XC_QEI_H

#include <xc.h> // include processor files - each processor file is guarded.  

void qei_Initialize(void);

int getSpeed(void);


#endif	/* XC_HEADER_TEMPLATE_H */

