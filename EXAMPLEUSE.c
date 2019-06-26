/* ###################################################################
**     Filename    : main.c
**     Project     : NunchukTest
**     Processor   : MC9S08QD4CPC
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2019-06-24, 14:28, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */
/*----------------------------------------------------------------------------


  THIS CODE IS NOT PART OF THE LIBRARY. IT IS JUST HERE TO SHOW HOW TO USE THE 
  FUNCTIONS. UNLESS YOU WANT TO RUN IT OR HAVE IT IN YOUR IDE AS AN EXAMPLE,
  PLEASE DO NOT COPY THIS INTO YOUR PROJECT.


-----------------------------------------------------------------------------*/

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "EI2C1.h"
#include "DataPin1.h"
#include "ClockPin1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "NunchukLib.h"

byte I2C_data[6];

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your local variable definition here */
  
  init();
  
  for(;;) { 
	  getNewData(I2C_data);    //you have access to all the variables specified in NunchukLib.h. You could say AccelX + 1 and it would give you the Accelerometer's X value plus 1
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
