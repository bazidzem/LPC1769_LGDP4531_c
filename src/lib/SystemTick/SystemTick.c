
#include "SystemTick.h"
#include "system_LPC17xx.h"


static volatile uint32_t msTicks = 0;
static uint8_t initialized = 0;


void SysTick_Init( void )
{
   if (!initialized)
   {
	  uint32_t ticks = GetSystemCoreClock() / 1000;                /* Hard coded at 1000Hz (1ms) */
	  if (ticks <= SysTick_LOAD_RELOAD_Msk)                        /* Reload value possible? */
	  {
		  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
		  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
		  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
		  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
			 SysTick_CTRL_TICKINT_Msk   |
			 SysTick_CTRL_ENABLE_Msk;                    			   /* Enable SysTick IRQ and SysTick Timer */

		  msTicks = 0;
		  initialized = 1;
	  }
   }
}

void SysTick_Waitms( uint32_t delay_ms )
{
    if (initialized)
    {
       uint32_t curTicks;
       curTicks = msTicks;
       while ((msTicks - curTicks) < delay_ms) {}
    }
}


void SysTick_Handler(void)
{
	msTicks++;
}
