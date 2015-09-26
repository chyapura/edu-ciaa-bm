/* Copyright 2015, Eduardo Filomena, Juan Manuel Reta
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "examen.h"       /* <= own header */
#include "adc.h"
#include "dac.h"
#include "timer.h"
#include "tecla.h"
#include "led.h"
#include "uart.h"


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
float A = 1.0;

char msj1[] = "Aumento Ganancia\n\r";
char msj2[] = "Disminuyo Ganancia\n\r";
char msj3[] = "MUTE\n\r";
char msj4[] = "\n\r\n\r Tec1 - Aumento Ganancia\n\r Tec2 - Disminuyo Ganancia\n\r Tec3 - MUTE\n\r Tec4 - Menu... \n\r";

int main(void)
{

	/* perform the needed initialization here */
	LEDsInit();
	Tec1Init();
	Tec2Init();
	Tec3Init();
	Tec4Init();
	ADCInit();
	DACInit();
	UARTInit();
	TimerInit(100);

	for(;;)
	{
		if(LeerTec1()==0)
		{
			A += 0.1;
			UARTSendString(msj1);

		}

		if(LeerTec2()==0)
		{
			A -= 0.1;
			UARTSendString(msj2);
		}

		if(LeerTec3()==0)
		{
			A = 0;
			UARTSendString(msj3);
		}

		if(LeerTec4()==0)
		{
			UARTSendString(msj4);
		}

	}

         return 0;
}

void ISR_TIMER(void)
{
	uint16_t LecturaADC;
	LecturaADC = A * ADCRead();
	Led1Toggle();

	if(LecturaADC > 1023)
		LecturaADC = 1023;

	if(LecturaADC < 10)
		LecturaADC = 0;

	DACUpdate(LecturaADC);

	TimerClearFlag();
}

void UARTSendString(char *cadena_p)
{
	int i=0;

	while(cadena_p[i] != 0)
	{
		UARTSend(cadena_p[i]);
		i++;
	}
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

