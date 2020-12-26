#include "DISP.h"
#include "Time.h"
#include "ssd.h"
#include "Switch.h"

// tTIM_Time Time;
static unsigned int hours;
static unsigned int mins;
void DISP_Init()
{
    SSD_Init(SSD_HOURS_TENS, SSD_OFF, SSD_NULL);
    SSD_Init(SSD_HOURS_UNITS, SSD_OFF, SSD_NULL);
    SSD_Init(SSD_MINUTES_TENS, SSD_OFF, SSD_NULL);
    SSD_Init(SSD_MINUTES_UNITS, SSD_OFF, SSD_NULL);
}


void DISP_Update()
{
    /*
    Time = TIM_GetTime();
    SSD_SetSymbol(SSD_HOURS_TENS, Time.hours/10);
    SSD_SetSymbol(SSD_HOURS_UNITS, Time.hours%10);
    SSD_SetSymbol(SSD_MINUTES_TENS, Time.minutes/10);
    SSD_SetSymbol(SSD_MINUTES_UNITS, Time.minutes%10);
    */
    hours = TIM_GetHour();
    mins  = TIM_GetMin();
    SSD_SetSymbol(SSD_HOURS_TENS, hours/10);
    SSD_SetSymbol(SSD_HOURS_UNITS, hours%10);
    SSD_SetSymbol(SSD_MINUTES_TENS, mins/10);
    SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10);
}
