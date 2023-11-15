#ifndef __TIMERS_H__
#define __TIMERS_H__ 

#include <stdint.h>
#include <stdlib.h>

#include "../cmsis/system_stm32f4xx.h"
#include "../cmsis/stm32f4xx.h"

typedef enum {
    TIM_ID_1,
    TIM_ID_2,
    TIM_ID_3,
    TIM_ID_4,
    TIM_ID_5,
    TIM_ID_9,
    TIM_ID_10,
    TIM_ID_11,

    TIM_COUNT,
} TIMER_ID;

typedef struct {
    TIM_TypeDef *instance;
    TIMER_ID timer_id;
    uint32_t prescaler;
    uint32_t period;
} htimer_t;

typedef struct {

} htimer_soft_t;

void tmier_init(
    TIMER_ID id, 
    htimer_t *htimer, 
    uint32_t prescaler, 
    uint32_t period
);


void timier_TIM1_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);

void timier_TIM2_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);
void timier_TIM3_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);
void timier_TIM4_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);
void timier_TIM5_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);

void timier_TIM9_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);
void timier_TIM10_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);
void timier_TIM11_init(htimer_t *htimer, uint32_t prescaler, uint32_t period);

void tmier_init();


void timer_factory(TIMER_ID);

#endif