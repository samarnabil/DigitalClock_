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
   unsigned char hours;
   unsigned char minutes;
   unsigned char seconds;

}tTIM_Time;


void TIM_Init(unsigned char Initial_Hours,unsigned char Initial_Minutes,unsigned char Initial_Seconds);
void TIM_Update(void);
unsigned char TIM_GetTime(unsigned char type);
tTIM_Mode TIM_GetMode();

//unsigned char TIM_GetMin(void);
//unsigned char TIM_GetHour(void);

#endif // __TIM_H__
