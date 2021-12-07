/*
 * dcmotor.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Mustafa
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"
#include "pwm.h"

typedef enum DcMotor_State {STOP , CW , A_CW} DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);





#endif /* DCMOTOR_H_ */
