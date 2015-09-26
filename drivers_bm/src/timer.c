/*==================[inclusions]=============================================*/
#include "timer.h"       /* <= own header */

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

void TimerInit(int a)
{
	NVIC_EnableIRQ(11);       // 11 = RITIMER_IRQn
	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_SetTimerInterval(LPC_RITIMER, a);
}

void TimerClearFlag(void)
{
	Chip_RIT_ClearInt(LPC_RITIMER);
}


