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
}tTIM_Time;


void TIM_Init(unsigned int Counter);
void TIM_Update(void);
//tTIM_Time TIM_GetTime();
tTIM_Mode TIM_GetMode();

unsigned int TIM_GetMin(void);
unsigned int TIM_GetHour(void);

#endif // __TIM_H__
