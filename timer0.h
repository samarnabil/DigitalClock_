#ifndef __TMR_H__
#define __TMR_H__


void TMR0_Init(void);
void TMR0_Update(void) __interrupt 0;
void TMR0_Start(void);
//unsigned int delay_sec(unsigned int F_clk, unsigned int desired_delay);


#endif // __TMR_H__
