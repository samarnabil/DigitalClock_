#include <pic16f877a.h>
#include "Switch.h"
#include "Time.h"
#include "ssd.h"
#include "timer0.h"
#include "DISP.h"

unsigned int  __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;


void main(void)
{
    /* Initialization */
    PB_Init(PB_PLUS, PB_RELEASED);
    PB_Init(PB_MINUS, PB_RELEASED);
    PB_Init(PB_SET, PB_RELEASED);

    TIM_Init(00,00,00);
    DISP_Init();

    TMR0_Init();
    TMR0_Start();

    while(1)
    {
        /* Do nothing */

    }
}

