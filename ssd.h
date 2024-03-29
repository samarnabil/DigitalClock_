#ifndef __SSD_H__
#define __SSD_H__

typedef enum
{
    SSD_HOURS_TENS,
    SSD_HOURS_UNITS,
    SSD_MINUTES_TENS,
    SSD_MINUTES_UNITS,

}tSSD;

typedef enum
{
    SSD_OFF = 0,
    SSD_ON
}tSSD_State;

typedef enum
{
   SSD_0,
   SSD_1,
   SSD_2,
   SSD_3,
   SSD_4,
   SSD_5,
   SSD_6,
   SSD_7,
   SSD_8,
   SSD_9,
   SSD_NULL
}tSSD_Symbol;

void SSD_Init(tSSD ssd, tSSD_State initial_state, tSSD_Symbol initial_symbol);
void SSD_Update(void);
void SSD_SetSymbol(tSSD ssd, tSSD_Symbol symbol, unsigned char condition);
void SSD_SetState(tSSD ssd, tSSD_State state);
tSSD_Symbol SSD_GetSymbol(tSSD ssd);
tSSD_State SSD_GetState(tSSD ssd);

#endif // __SSD_H__
