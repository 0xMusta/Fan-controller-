/*
 * dcmotor.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Mustafa
 */

#include "dcmotor.h"


void DcMotor_Init(void)
{
	/*Setting two pins for the motor*/
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	/*stopping the motor by writing zero */
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

}
/* Description:
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC. connect the
  * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor.
  * duty cycle 100% --> Maximum Speed
  * duty cycle 50%  --> Half Maximum Speed
  * duty cycle 0%   --> Motor Stop
  */
void DcMotor_Rotate(DcMotor_State state , uint8 speed)
{
	if(state == STOP)
	{
		/*stopping the motor by writing zero */
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

	}
	else if( state == A_CW)
	{
		// Rotate the motor --> anti-clock wise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);

	}
	else if(state == CW)
	{
		// Rotate the motor --> clock wise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

	}
	/*setting the pwm to set the speed of the motor*/
	PWM_Timer0_Start(speed);

}

