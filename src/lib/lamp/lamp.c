#include "LPC17xx.h"
#include "lamp.h"

/**
 * Function used for verifying if a lamp is on or not.
 * @return true if lamp is on, false otherwise.
 */
uint8_t Lamp_IsON( Lamp *lamp )
{
	return lamp->port->FIOSET;
}

/**
 * Turns the lamp on
 */
void Lamp_ON( Lamp *lamp )
{
	lamp->port->FIOSET = (1 << lamp->pin);
}

/**
 * Turns the lamp off
 */
void Lamp_OFF( Lamp *lamp )
{
	lamp->port->FIOCLR = (1 << lamp->pin);
}

/**
 * Toggles the lamp
 */
void Lamp_Toggle( Lamp *lamp )
{
	lamp->port->FIOPIN ^= (1 << lamp->pin);
}
