#include "DISP.h"
#include "Time.h"
#include "ssd.h"
#include "Switch.h"

// tTIM_Time Time;
static unsigned int hours;
static unsigned int mins;
void DISP_Init()
{
    SSD_Init(SSD_HOURS_TENS, SSD_OFF, SSD_0);
    SSD_Init(SSD_HOURS_UNITS, SSD_OFF, SSD_0);
    SSD_Init(SSD_MINUTES_TENS, SSD_OFF, SSD_0);
    SSD_Init(SSD_MINUTES_UNITS, SSD_OFF, SSD_0);
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
    tTIM_Mode current_Mode = TIM_GetMode();
    hours = TIM_GetHour();
    mins  = TIM_GetMin();

    //Display behavior for each mode
    switch(current_Mode)
    {
    case NORMAL:
        //seconds blinking dot
        SSD_SetSymbol(SSD_HOURS_TENS, hours/10);
        SSD_SetSymbol(SSD_HOURS_UNITS, hours%10);
        SSD_SetSymbol(SSD_MINUTES_TENS, mins/10);
        SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10);
        break;
    case SET_HOURS:
        //SSD_HOURS_TENS & SSD_HOURS_UNITS blinking
        SSD_SetSymbol(SSD_HOURS_TENS, hours/10);
        SSD_SetSymbol(SSD_HOURS_UNITS, hours%10);
        break;
    case SET_MINUTES:
        //SSD_MINUTES_TENS & SSD_MINUTES_UNITS blinking
        //lw fe hours already set yfdalo zahreen w sabteen
        SSD_SetSymbol(SSD_MINUTES_TENS, mins/10);
        SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10);

        break;
    default:
        break;


    }

}
