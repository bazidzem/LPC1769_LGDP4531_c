/**************************************************************************//**
 * @file main.cpp
 * @brief This file contains main loop
 * @author Dawid Bazan <dawidbazan@gmail.com>
 * @author Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.1.0
 * @date    May 2011
 * @bug There is no bug. left this to have a reference.
 *****************************************************************************/

/**
 * \mainpage LPC176x Startup project
 *
 * \section intro_sec Introduction
 *
 * The project main goal is to provide a template startup project for LPC176x micro.
 * See README for more details.
 *
 */

#define VERSION_STRING "v0.1.0"

#include "lamp.h"
#include "SystemTick.h"

#include "LPC17xx.h"


/**************************************************************************//**
 * This function is run from RAM not from ROM
 *****************************************************************************/
__attribute__((section(".fastcode")))
void fastCodeFunct(void);


/**************************************************************************//**
 * enableCLKOUT
 * After calling this function you will have cpu clock divided by 10 on pin 1.27
 *****************************************************************************/
void enableCLKOUT(void)
{
   LPC_GPIO1->FIODIR_b27 = 1;          // 1 - output
   LPC_SC->CLKOUTCFG     = 0x00000190; // 0x0100 - enable, 0x00A0 - divide by 10
   LPC_PINCON->PINSEL3   = 0x00400000; // set pin as CLKOUT
}

/**************************************************************************//**
 * main
 * Function from which everything starts...
 *
 * @return on embedded targets this function shall never return
 *****************************************************************************/
int main(void)
{
   enableCLKOUT();

   Lamp the_blinker;
   Lamp the_inverted_blinker;

   the_blinker.port = LPC_GPIO1;
   the_blinker.pin = 25;
   the_inverted_blinker.port = LPC_GPIO1;
   the_inverted_blinker.pin = 26;
   LPC_SC->PCONP      |= (1 << 15); // power up GPIO

   SysTick_Init();


   Lamp_ON( &the_blinker );
   while (1)
   {
      Lamp_Toggle( &the_blinker );
      Lamp_Toggle( &the_inverted_blinker );
      SysTick_Waitms(100);
      Lamp_Toggle( &the_blinker );
      Lamp_Toggle( &the_inverted_blinker );
      SysTick_Waitms(100);
   }
   return(0);
} /* main */
