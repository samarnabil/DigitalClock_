#include "Time.h"
#include "ssd.h"
#include "Switch.h"

/* tTIM_Time Init_Time;  bt3ml error lma a7awl a access Time[1] (cannot assign values to aggregates ) fa ha use int insted */


static unsigned int hours = 0;
static unsigned int mins = 0;
static tTIM_Mode current_Mode = NORMAL;

void TIM_Init(unsigned int Counter)
{
    //Init_Time.hours = Counter/100;
    //Init_Time.minutes = Counter%100;
    hours = Counter/100;
    mins  = Counter%100;
}

void TIM_Update(void)
{
    switch (current_Mode)
    {
        case NORMAL:
            if (PB_GetState(PB_SET) == PB_PRE_RELEASED)
            {
                current_Mode = SET_HOURS;
            }
            if(TIM_GetMin()<59)
            {
                mins = TIM_GetMin()+1;
            }
            else if(TIM_GetHour()<23)
            {
                mins  = 0;
                hours = TIM_GetHour()+1;
            }
            else
            {
                mins  = 0;
                hours = 0;
            }
        break;
        case SET_HOURS:
            if (PB_GetState(PB_SET) == PB_PRE_RELEASED)
            {
                current_Mode = SET_MINUTES;
            }
            if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
            {
                if(TIM_GetHour() < 23)
                {
                    hours = TIM_GetHour()+1;
                }
                else
                {
                    hours = 0;
                }
            }
            if (PB_GetState(PB_MINUS) == PB_PRE_PRESSED)
            {
                if(TIM_GetHour() > 0)
                {
                    hours = TIM_GetHour()-1;
                }
                else
                {
                    hours = 23;
                }
            }
        break;
        case SET_MINUTES:
            if (PB_GetState(PB_SET) == PB_PRE_RELEASED)
            {
                current_Mode = NORMAL;
            }
            if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
            {
                if(TIM_GetHour() < 59)
                {
                    mins = TIM_GetMin()+1;
                }
                else
                {
                    mins = 0;
                }
            }
            if (PB_GetState(PB_MINUS) == PB_PRE_PRESSED)
            {
                if(TIM_GetHour() > 0)
                {
                    mins = TIM_GetMin()-1;
                }
                else
                {
                    mins = 59;
                }
            }
        break;
        default:
            /* Should not be here */
        break;
    }
}


unsigned int TIM_GetMin(void)
{
    return mins;
}

unsigned int TIM_GetHour(void)
{
    return hours;
}

/* nfs el error lma b7awl a3ml x = TIM_GetTime() (cannot assign values to aggregates )
tTIM_Time TIM_GetTime()
{
    return Init_Time;
}
*/

tTIM_Mode TIM_GetMode()
{
   // do nothing for now
}
