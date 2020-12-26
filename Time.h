#ifndef __TIM_H__
#define __TIM_H__


typedef enum
{
   NORMAL,
   SET_HOURS,
   SET_MINUTES

}tTIM_Mode;

typedef struct
{
   unsigned int hours;
   unsigned int minutes;
   unsigned int seconds;
}tTIM_Time;


void TIM_Init(unsigned int initial_hours, unsigned int initial_minutes, unsigned int initial_seconds);
void TIM_Update(void);
tTIM_Time TIM_GetTime();            //not sure fe parameters gowa wla la
tTIM_Mode TIM_GetMode();            //not sure fe parameters gowa wla la

#endif // __TIM_H__
