/*
 * main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Mustafa
 */


#include "lcd.h"
#include "lm35_sensor.h"
#include "dcmotor.h"
#include "adc.h"

void main(void)
{
	/*Structure that contains the configuration type of ADC */
	ADC_ConfigType  Config_Struct;
	Config_Struct.ref_volt = 0x03; /*Internal 2.56 voltage Reference with external cap at AREF pin*/
	Config_Struct.prescaler =  0x03;  /*Division by 8*/
	/*Defining a pointer to constant structure to pass it for the init function */
	const ADC_ConfigType * Config_Ptr = &Config_Struct;

	/*Initializing the drivers */
	LCD_init();
	DcMotor_Init();
	ADC_init(Config_Ptr);
	uint8 temperature;/*Variable to store the reading of temperature*/
	/*Storing strings in arrays that will be displayed */
	const char * str_off_Ptr = "FAN is OFF";
	const char * str_on_Ptr = "FAN is ON ";
	const char * str_temp_Ptr = "Temp =     C";
	LCD_clearScreen();/*First clearing the lcd*/
	/*Printing temp = because it will always be displayed*/
	LCD_displayStringRowColumn(1, 3, str_temp_Ptr);


	while(1)
	{
		temperature = LM35_getTemperature();/*GETTING TEMP READ*/

		if(temperature < 30 )
		{
			/*FAN is OFF*/
			LCD_displayStringRowColumn( 0 , 3 , str_off_Ptr);
			LCD_moveCursor(1 , 10);/*moving cursor to write the temp value*/
			LCD_intgerToString(temperature); /*displaying the temp after moving the cursor*/
			DcMotor_Rotate(STOP, 0 ); /*STOPPING THE MOTOR*/
		}

		else if(temperature < 60 )
		{
			/*FAN is ON*/
			LCD_displayStringRowColumn( 0 , 3 , str_on_Ptr);
			LCD_moveCursor(1 , 10);/*moving cursor to write the temp value*/
			LCD_intgerToString(temperature); /*displaying the temp after moving the cursor*/
			DcMotor_Rotate(CW, 25 ); /*THE MOTOR WORKS WITH 25% SPEED*/
		}

		else if(temperature < 90 )
		{
			/*FAN is ON*/
			LCD_displayStringRowColumn( 0 , 3 , str_on_Ptr);
			LCD_moveCursor(1 , 10);/*moving cursor to write the temp value*/
			LCD_intgerToString(temperature); /*displaying the temp after moving the cursor*/
			DcMotor_Rotate(CW, 50 ); /*THE MOTOR WORKS WITH 50% SPEED*/
		}
		else if(temperature < 120 )
		{
			/*FAN is ON*/
			LCD_displayStringRowColumn( 0 , 3 , str_on_Ptr);
			LCD_moveCursor(1 , 10);/*moving cursor to write the temp value*/
			LCD_intgerToString(temperature); /*displaying the temp after moving the cursor*/
			DcMotor_Rotate(CW, 75 ); /*THE MOTOR WORKS WITH 75% SPEED*/
		}
		else if(temperature >= 120 )
		{
			/*FAN is ON*/
			LCD_displayStringRowColumn( 0 , 3 , str_on_Ptr);
			LCD_moveCursor(1 , 10);/*moving cursor to write the temp value*/
			LCD_intgerToString(temperature); /*displaying the temp after moving the cursor*/
			DcMotor_Rotate(CW, 100 ); /*THE MOTOR WORKS WITH 100% SPEED*/
		}
		/*Condition to clear number from lcd when decrementing temp*/
		if(temperature < 10)
		{
			LCD_displayStringRowColumn( 1 , 11 , "  ");/*clearing 2nd & 3rd numbers*/
		}
		else if(temperature < 100)
		{
			LCD_displayStringRowColumn( 1 , 12 , " ");/*clear 3rd number from lcd when decrementing temp*/
		}
	}

}




