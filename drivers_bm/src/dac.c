/*==================[inclusions]=============================================*/
#include "dac.h"       /* <= own header */


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

void DACInit()
{
	Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);

	Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_DMA_ENA);
}

void DACUpdate (valorDAC)
{
	Chip_DAC_UpdateValue (LPC_DAC, valorDAC);
}
