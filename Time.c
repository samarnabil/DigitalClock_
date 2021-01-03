#include "Time.h"
#include "ssd.h"
#include "Switch.h"

#define RETURN_HOURS (0)
#define RETURN_MINUTES (1)
#define RETURN_SECONDS (2)

/* tTIM_Time Init_Time;  bt3ml error lma a7awl a access Time[1] (cannot assign values to aggregates ) fa ha use int insted */
//static unsigned int hours = 0;
//static unsigned int mins = 0;

static unsigned char CountSec = 0;
static tTIM_Mode current_Mode = NORMAL;
static unsigned int SET_Counter=0;
static tTIM_Time time;

void TIM_Init(unsigned char Initial_Hours,unsigned char Initial_Minutes,unsigned char Initial_Seconds)
{
    time.hours = Initial_Hours;
    time.minutes = Initial_Minutes;
    time.seconds = Initial_Seconds;

    //time.hours = Counter/100;
    //time.minutes = Counter%100;
   // hours = Counter/100;
    //mins  = Counter%100;

}

void TIM_Update(void)
{
   //get Set button pressed Counts
    if(PB_GetState(PB_SET) == PB_PRE_PRESSED)
    {
        SET_Counter++;
    }

    //get current mode

    current_Mode = TIM_GetMode();


    // Behavior according to the Mode
    switch (current_Mode)
    {
    case NORMAL:
        if(CountSec < 31)
        {
            CountSec++;

        }
        else
        {
            CountSec = 0;
            if (time.seconds<59)
            {
                time.seconds++;
            }
            else
            {
                time.seconds=00;
                if (time.minutes < 59)
                {
                    time.minutes++;
                }
                else
                {
                    time.minutes = 00;
                    if (time.hours < 23)
                        {
                            time.hours++;
                        }
                    else
                    {
                        time.hours = 00;
                    }
                }
            }

        }
        break;

    case SET_HOURS:

        if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
        {
            if( TIM_GetTime(RETURN_HOURS) < 23)
            {
                time.hours += 1;
            }
            else
            {
                time.hours = 00;
            }
        }

        if (PB_GetState(PB_MINUS) == PB_PRE_PRESSED)
        {
            if( TIM_GetTime(RETURN_HOURS) > 0)
            {
                time.hours -= 1;
            }
            else
            {
                time.hours = 23;
            }
        }
        break;

    case SET_MINUTES:
        if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
        {
            if( TIM_GetTime(RETURN_MINUTES) < 59)
            {
                time.minutes+=1;
            }
            else
            {
                time.minutes = 0;
            }
        }

        if (PB_GetState(PB_MINUS) == PB_PRE_PRESSED)
        {
            if( TIM_GetTime(RETURN_MINUTES) > 0)
            {
                time.minutes-=1;
            }
            else
            {
                time.minutes = 59;
            }
        }
        break;

        default:
            /* Should not be here */
        break;
    }
}

// azon l ahsan n-return l struct?
/*unsigned char TIM_GetMin(void)
{
    return time.minutes;
}

unsigned char TIM_GetHour(void)
{
    return time.hours;
}*/

/* nfs el error lma b7awl a3ml x = TIM_GetTime() (cannot assign values to aggregates )
tTIM_Time TIM_GetTime()
{
    return Init_Time;
}
*/

unsigned char TIM_GetTime(unsigned char type)
{
    if (type == RETURN_HOURS)
    {
        return time.hours;
    }
    else if (type == RETURN_MINUTES)
    {
        return time.minutes;
    }
    else if (type == RETURN_SECONDS)
    {
        return time.seconds;
    }
}

tTIM_Mode TIM_GetMode()
{
   //Identifying the current mode
   if(SET_Counter % 3 == 0)
   {
       current_Mode = NORMAL;
   }
   else if(SET_Counter % 3 == 1)
   {
       current_Mode = SET_HOURS;
   }
   else if(SET_Counter % 3 == 2)
   {
       current_Mode = SET_MINUTES;
   }

   return current_Mode;
}
