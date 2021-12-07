/*
 * pwm.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Mustafa
 */

#ifndef PWM_H_
#define PWM_H_


#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for setting the duty cycle of the 0 Timer.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
