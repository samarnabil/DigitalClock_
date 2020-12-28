#include "DISP.h"
#include "Time.h"
#include "ssd.h"
#include "Switch.h"

#define RETURN_HOURS (0)
#define RETURN_MINUTES (1)
#define RETURN_SECONDS (2)

// tTIM_Time Time;
static unsigned char hours;
static unsigned char mins;
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
    hours = TIM_GetTime(RETURN_HOURS);
    mins  = TIM_GetTime(RETURN_MINUTES);

    //Display behavior for each mode
    switch(current_Mode)
    {
    case NORMAL:
        SSD_SetSymbol(SSD_HOURS_TENS, hours/10);
        SSD_SetSymbol(SSD_HOURS_UNITS, hours%10);
        SSD_SetSymbol(SSD_MINUTES_TENS, mins/10);
        SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10);
        //seconds blinking dot
        break;
    case SET_HOURS:
        SSD_SetSymbol(SSD_HOURS_TENS, hours/10);
        SSD_SetSymbol(SSD_HOURS_UNITS, hours%10);
        //SSD_HOURS_TENS & SSD_HOURS_UNITS blinking
        break;
    case SET_MINUTES:
        SSD_SetSymbol(SSD_MINUTES_TENS, mins/10);
        SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10);
        //SSD_MINUTES_TENS & SSD_MINUTES_UNITS blinking
        //lw fe hours already set yfdalo zahreen w sabteen

        break;
    default:
        break;


    }

}
