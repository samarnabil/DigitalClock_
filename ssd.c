#include "ssd.h"
#include "gpio.h"
#include "utilities.h"

#define NUMBER_OF_SSD   (4)

tSSD_Symbol ssd_symbols[NUMBER_OF_SSD] = {SSD_NULL};

static unsigned char ssd_data[] =
{
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
};


void SSD_Init(tSSD ssd, tSSD_State initial_state, tSSD_Symbol initial_symbol)
{
    /* Initialize SSD data pins  */
    GPIO_InitPort(PORT_D, GPIO_OUT);
    GPIO_SetPortState(PORT_D, ssd_data[SSD_NULL]);

    /* Initialize SSD state pin */
    switch(ssd)
    {
    case SSD_HOURS_TENS:
        GPIO_InitPortPin(PORT_B, 7, GPIO_OUT);
        break;
    case SSD_HOURS_UNITS:
        GPIO_InitPortPin(PORT_B, 6, GPIO_OUT);
        break;
    case SSD_MINUTES_TENS:
        GPIO_InitPortPin(PORT_B, 5, GPIO_OUT);
        break;
    case SSD_MINUTES_UNITS:
        GPIO_InitPortPin(PORT_B, 4, GPIO_OUT);
        break;
    default:
        /* Should not be here */
        break;
    }

    /* Set initial state */
    SSD_SetState(ssd, initial_state);

    /* Set initial symbol */
    SSD_SetSymbol(ssd, initial_symbol);

}

void SSD_Update(void)
{
    static tSSD current_ssd = SSD_HOURS_TENS;

    /* Turn off all ssd */
    SSD_SetState(SSD_HOURS_TENS, SSD_OFF);
    SSD_SetState(SSD_HOURS_UNITS, SSD_OFF);
    SSD_SetState(SSD_MINUTES_TENS, SSD_OFF);
    SSD_SetState(SSD_MINUTES_UNITS, SSD_OFF);

    /* Set current ssd output */
    GPIO_SetPortState(PORT_D, ssd_data[ssd_symbols[current_ssd]]);
    /* Turn on current ssd */
    SSD_SetState(current_ssd, SSD_ON);

    if(current_ssd == SSD_MINUTES_UNITS)
    {
        current_ssd  = SSD_HOURS_TENS;

    } else
    {
        current_ssd++;
    }


}

void SSD_SetSymbol(tSSD ssd, tSSD_Symbol symbol)
{
    ssd_symbols[ssd] = symbol;
}

void SSD_SetState(tSSD ssd, tSSD_State state)
{
    switch(ssd)
    {
    case SSD_HOURS_TENS:
        GPIO_SetPortPinState(PORT_B, 7, state);
        break;
    case SSD_HOURS_UNITS:
        GPIO_SetPortPinState(PORT_B, 6, state);
        break;
    case SSD_MINUTES_TENS:
        GPIO_SetPortPinState(PORT_B, 5, state);
        break;
    case SSD_MINUTES_UNITS:
        GPIO_SetPortPinState(PORT_B, 4, state);
        break;
    default:
        /* Should not be here */
        break;
    }
}

tSSD_Symbol SSD_GetSymbol(tSSD ssd)
{
    tSSD_Symbol ret = SSD_NULL;

    ret = ssd_symbols[ssd];

    return ret;
}

tSSD_State SSD_GetState(tSSD ssd)
{
    tSSD_State ret = SSD_OFF;

    switch(ssd)
    {
    case SSD_HOURS_TENS:
        ret = GPIO_GetPortPinState(PORT_B, 7);
        break;
    case SSD_HOURS_UNITS:
        ret = GPIO_GetPortPinState(PORT_B, 6);
        break;
    case SSD_MINUTES_TENS:
        ret = GPIO_GetPortPinState(PORT_B, 5);
        break;
    case SSD_MINUTES_UNITS:
        ret = GPIO_GetPortPinState(PORT_B, 4);
        break;
    default:
        /* Should not be here */
        break;
    }

    return ret;
}
