#include "DISP.h"
#include "Time.h"
#include "ssd.h"
#include "Switch.h"

#define RETURN_HOURS (0)
#define RETURN_MINUTES (1)
#define RETURN_SECONDS (2)


static unsigned char hours;
static unsigned char mins;
static unsigned char BLINKING_INTERVAL = 0;
void DISP_Init()
{
    SSD_Init(SSD_HOURS_TENS, SSD_OFF, SSD_0);
    SSD_Init(SSD_HOURS_UNITS, SSD_OFF, SSD_0);
    SSD_Init(SSD_MINUTES_TENS, SSD_OFF, SSD_0);
    SSD_Init(SSD_MINUTES_UNITS, SSD_OFF, SSD_0);
}


void DISP_Update()
{

    tTIM_Mode current_Mode = TIM_GetMode();
    hours = TIM_GetTime(RETURN_HOURS);
    mins  = TIM_GetTime(RETURN_MINUTES);

    //Display behavior for each mode
     switch(current_Mode)
    {
    case NORMAL:
        if (BLINKING_INTERVAL > 50)
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,1);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,1);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,1);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,1);
        }
        else
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,1);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,2);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,1);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,1);
        }

        break;
    case SET_HOURS:
        if (BLINKING_INTERVAL > 60)
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,1);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,1);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,1);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,1);
        }
        else
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,0);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,0);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,1);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,1);
        }
        break;
    case SET_MINUTES:
        if ( BLINKING_INTERVAL > 60)
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,1);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,1);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,1);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,1);
        }
        else
        {
            SSD_SetSymbol(SSD_HOURS_TENS, hours/10,1);
            SSD_SetSymbol(SSD_HOURS_UNITS, hours%10,1);
            SSD_SetSymbol(SSD_MINUTES_TENS, mins/10,0);
            SSD_SetSymbol(SSD_MINUTES_UNITS, mins%10,0);
        }
        break;

        break;
    default:
        break;
    }

    BLINKING_INTERVAL++;
    if (BLINKING_INTERVAL >= 200)
    {
        BLINKING_INTERVAL = 0;
    }



}
