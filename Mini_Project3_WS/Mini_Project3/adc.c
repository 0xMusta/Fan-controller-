/*
 * adc.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Mustafa
 */


#include "adc.h"


void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX = 0;
	/*configure to operate using the reference voltage*/
	ADMUX |= (Config_Ptr->ref_volt << REFS0);
	/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 1 Enable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
		 */
	/*ADC ENABLE*/
	SET_BIT(ADCSRA  , ADEN);
	/*configure to operate using the prescaler*/
	ADCSRA = (ADCSRA & 0xF8)|(Config_Ptr->prescaler & 0x07);


}
uint16 ADC_readChannel(uint8 ch_num)
{

	/* Input channel number must be from 0 --> 7 */
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA , ADSC);
	while(BIT_IS_CLEAR(ADCSRA , ADIF))
	{
		/*waiting for the adc to convert and set the flag*/
	}
	SET_BIT(ADCSRA , ADIF);/*clearing interrupt flag for next read*/
	return ADC;
}
