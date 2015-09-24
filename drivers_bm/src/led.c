/*==================[inclusions]=============================================*/
#include "led.h"       /* <= own header */


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

void LedREDInit()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,1,1);
}

void LedREDOn()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,0);
}

void LedREDOff()
	{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0);
}

/////////////////////////////////////////////////////////////////////
void LedGREENInit()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,2,1);
}

void LedGREENOn()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,1);
}

void LedGREENOff()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1);
}

/////////////////////////////////////////////////////////////////////
void LedBLUEInit()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,4,1);
}

void LedBLUEOn()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,2);
}

void LedBLUEOff()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2);
}

/////////////////////////////////////////////////////////////////////
void Led1Init()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,1<<14,1);
}

void Led1On()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,0,14);
}

void Led1Off()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14);
}

/////////////////////////////////////////////////////////////////////
void Led2Init()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,1<<11,1);
}

void Led2On()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,11);
}

void Led2Off()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11);
}

/////////////////////////////////////////////////////////////////////
void Led3Init()
{
	Chip_GPIO_Init(LPC_GPIO_PORT);
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* remapea P2_0 en GPIO5[0], LED0R y habilita el pull up*/
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,1<<12,1);
}

void Led3On()
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,12);
}

void Led3Off()
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,12);
}
/////////////////////////////////////////////////////////////////////
void LEDsInit()
{
	LedREDInit();
	LedGREENInit();
	LedBLUEInit();
	Led1Init();
	Led2Init();
	Led3Init();
}
