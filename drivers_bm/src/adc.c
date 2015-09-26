/*==================[inclusions]=============================================*/
#include "adc.h"       /* <= own header */


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

void ADCInit(void)
{
	Chip_SCU_ADC_Channel_Config(0,ADC_CH1);
}

uint16_t ADCRead(void)
{
uint16_t datoADC=0;

 ADC_CLOCK_SETUP_T ADC_Config;

	/*ADC_Config.adcRate=1000;
	ADC_Config.bitsAccuracy = ADC_10BITS;
	ADC_Config.burstMode = DISABLE;*/

	Chip_ADC_Init(LPC_ADC0, &ADC_Config);

	Chip_ADC_EnableChannel(LPC_ADC0,1,ENABLE);

	Chip_ADC_SetStartMode(LPC_ADC0,ADC_START_NOW,ADC_TRIGGERMODE_RISING);

	while(Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1,ADC_DR_DONE_STAT)==!SET)
	{
		asm("NOP");
	}
		Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &datoADC);
	//Chip_ADC_EnableChannel(LPC_ADC0,1,DISABLE);

	return(datoADC);
}
