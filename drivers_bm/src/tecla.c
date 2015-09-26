/*==================[inclusions]=============================================*/
#include "tecla.h"       /* <= own header */
#include "delay.h"

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
////////////////////////////////////////////////////////////////
void Tec1Init()
	{
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,4,0);
	}

char LeerTec1()
	{
	char t1, t2, t;
	t1 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4);
	demora();
	t2 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,4);
	if((t1==0) & (t2==0))
	{
		t=0;
	}
	else
	{
		t=1;
	}
	return (t);
	}

////////////////////////////////////////////////////////////////
void Tec2Init()
	{
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,8,0);
	}

char LeerTec2()
	{
	char t1, t2, t;
	t1 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8);
	demora();
	t2 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,8);
	if((t1==0) & (t2==0))
	{
		t=0;
	}
	else
	{
		t=1;
	}
	return (t);
	}
////////////////////////////////////////////////////////////////
void Tec3Init()
	{
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,9,0);
	}

char LeerTec3()
	{
	char t1, t2, t;
	t1 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9);
	demora();
	t2 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,0,9);
	if((t1==0) & (t2==0))
	{
		t=0;
	}
	else
	{
		t=1;
	}
	return (t);
	}
////////////////////////////////////////////////////////////////
void Tec4Init()
	{
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,9,0);
	}

char LeerTec4()
	{
	char t1, t2, t;
	t1 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9);
	demora();
	t2 = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,1,9);
	if((t1==0) & (t2==0))
	{
		t=0;
	}
	else
	{
		t=1;
	}
	return (t);
	}
