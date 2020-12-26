#ifndef __PORT_H__
#define __PORT_H__

#include "gpio.h"

/* Fill missing code below */
/* Leds' pins */
#define LED_1_PORT_DR   (GPIO_PORTB_DATA)
#define LED_1_PORT_CR   (GPIO_PORTB_DIRECTION)
#define LED_1_PIN       (GPIO_PIN_0)

#define LED_2_PORT_DR   (GPIO_PORTB_DATA)
#define LED_2_PORT_CR   (GPIO_PORTB_DIRECTION)
#define LED_2_PIN       (GPIO_PIN_1)

#define LED_3_PORT_DR   (GPIO_PORTB_DATA)
#define LED_3_PORT_CR   (GPIO_PORTB_DIRECTION)
#define LED_3_PIN       (GPIO_PIN_2)

#define LED_4_PORT_DR   (GPIO_PORTB_DATA)
#define LED_4_PORT_CR   (GPIO_PORTB_DIRECTION)
#define LED_4_PIN       (GPIO_PIN_3)
/* End of code filling */
#endif // __PORT_H__
