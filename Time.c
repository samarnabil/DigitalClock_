#include "Time.h"
#include "ssd.h"
#include "Switch.h"

tTIM_Time Init_Time;

void TIM_Init(unsigned int initial_hours, unsigned int initial_minutes, unsigned int initial_seconds)
{
    //change it lw habeen ana bs gat f bali f ktbtaha
    Init_Time.hours = initial_hours;
    Init_Time.minutes= initial_minutes;
    Init_Time.seconds = initial_seconds;
}

void TIM_Update(void)
{

}


tTIM_Time TIM_GetTime()
{

}

tTIM_Mode TIM_GetMode()
{

}
