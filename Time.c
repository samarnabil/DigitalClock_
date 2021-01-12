#include "Time.h"
#include "ssd.h"
#include "Switch.h"
#include "timer0.h"


#define RETURN_HOURS   (0)
#define RETURN_MINUTES (1)
#define RETURN_SECONDS (2)

#define Normal_Count      (0)
#define Set_Hours_Count   (1)
#define Set_Minutes_Count (2)
#define Change_Mode_Count (3)


static unsigned char CountSec = 0;
static tTIM_Mode current_Mode = NORMAL;
static unsigned int SET_Counter=0;
static tTIM_Time time;

void TIM_Init(unsigned char Initial_Hours,unsigned char Initial_Minutes,unsigned char Initial_Seconds)
{
    time.hours = Initial_Hours;
    time.minutes = Initial_Minutes;
    time.seconds = Initial_Seconds;

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
        if(CountSec < 72)
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
   //Identifying the current mode from the number of button presses
   if(SET_Counter % Change_Mode_Count == Normal_Count)
   {
       current_Mode = NORMAL;
   }
   else if(SET_Counter % Change_Mode_Count == Set_Hours_Count)
   {
       current_Mode = SET_HOURS;
   }
   else if(SET_Counter % Change_Mode_Count == Set_Minutes_Count)
   {
       current_Mode = SET_MINUTES;
   }

   return current_Mode;
}

//N: normal mode,
//SH: set hours mode
//SM: set minutes mode

//N     SH      SM      N       SH       SM
//0      1       2      3       4        5
//(0,3,6,9,....) % 3 = 0
//(1,4,7,10,...) % 3 = 1
//(2,5,8,11,...) % 3 = 2
