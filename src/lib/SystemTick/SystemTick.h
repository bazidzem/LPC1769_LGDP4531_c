/**************************************************************************//**
 * @file    SystemTick.h
 * @brief   File contains declaration of SystemTick class.
 * @author  Dawid Bazan <dawidbazan@gmail.com>
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.1.0
 * @date    June 2011
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "inttypes.h"
#include "LPC17xx.h"


/**
* Initializes Systick counter at fixed 1ms.
* This method shall be called as soon as clocks are set.
* @return non-zero if failed to initialize
*/
extern void SysTick_Init( void );

/**
 * Waits for delay_ms amount of time
 * @param[in] delay_ms amount of miliseconds to wait
 */
extern void SysTick_Waitms( uint32_t delay_ms );

/**
 * ISR inline Handler increments counter necessary in wait()
 * Shall be called inside usual ISR handler
 */
extern void SysTick_Handler( void );

