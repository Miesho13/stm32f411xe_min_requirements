#ifndef __GPIO_H__
#define __GPIO_H__

#include "../cmsis/stm32f4xx.h"
#include "../cmsis/system_stm32f4xx.h"



typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALT,
    GPIO_MODE_ANALOG,

} GPIO_MODE;

typedef enum {
    GPIO_TYPE_PUSH_PULL = 0,
    GPIO_TYPE_OPEN_DRAIN,

} GPIO_TYPE;

typedef enum {
    GPIO_PUPD_NO = 0,
    GPIO_PUPD_UP,
    GPIO_PUPD_DOWN,

} GPIO_PUPD;

typedef enum {
    GPIO_SPEED_LOW = 0,
    GPIO_SPEED_MID,
    GPIO_SPEED_FAST,
    GPIO_SPEED_HIGH,

} GPIO_SPEED;


typedef struct {
    GPIO_TypeDef *GPIOx;
    GPIO_MODE mode;
    GPIO_SPEED speed;
    GPIO_PUPD pupd;
    uint16_t pins;
    GPIO_TYPE type;

} gpio_init_t;

void gpio_init(gpio_init_t hgpio);

#endif // __GPIO_H__
