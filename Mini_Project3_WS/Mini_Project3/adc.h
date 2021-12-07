/*
 * ADC.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Mustafa
 */

#ifndef ADC_H_
#define ADC_H_

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#include "common_macros.h"
#include "std_types.h"
#include <avr/io.h>

typedef unsigned char  ADC_ReferenceVolatge ;
typedef unsigned char ADC_Prescaler ;


typedef struct{
 ADC_ReferenceVolatge ref_volt ;
 ADC_Prescaler prescaler ;
}ADC_ConfigType;



void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);




#endif /* ADC_H_ */
