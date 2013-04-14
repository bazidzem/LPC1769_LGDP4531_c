/**************************************************************************//**
 * @file    Lamp.h
 * @brief   File contains class declaration of Lamp class.
 * @author  Dawid Bazan <dawidbazan@gmail.com>
 * @author  Dariusz Synowiec <devemouse@gmail.com>
 * @version 0.1.0
 * @date    May 2011
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "inttypes.h"
#include "LPC17xx.h"



typedef struct
{
   volatile LPC_GPIO_TypeDef *port;
   uint8_t                    pin; // which pin
}Lamp;

/**
 * Function used for verifying if a lamp is on or not.
 * @return true if lamp is on, false otherwise.
 */
uint8_t Lamp_IsON( Lamp *lamp );

/**
 * Turns the lamp on
 */
void Lamp_ON( Lamp *lamp );

/**
 * Turns the lamp off
 */
void Lamp_OFF( Lamp *lamp );

/**
 * Toggles the lamp
 */
void Lamp_Toggle( Lamp *lamp );

