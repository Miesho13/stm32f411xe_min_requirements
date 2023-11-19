#ifndef __TIMERS_H__
#define __TIMERS_H__ 

#include <stdint.h>
#include <stdlib.h>

#include "../cmsis/system_stm32f4xx.h"
#include "../cmsis/stm32f4xx.h"

typedef enum {
    TIMER_ID_1,
    TIMER_ID_2,
    TIMER_ID_3,
    TIMER_ID_4,
    TIMER_ID_5,
    TIMER_ID_9,
    TIMER_ID_10,
    TIMER_ID_11,

    TIMER_COUNT,
} TIMERS_ID;



typedef enum {
    TIMER_ON = 0,
    TIMER_OFF,

} TIMER_STATE;



typedef struct {
    TIM_TypeDef *instance;
    uint32_t prescaler;
    uint32_t period;
    TIMERS_ID timer_id;
    TIMER_STATE state;
} htimer_t;



void timers_TIMx_init(TIMERS_ID tid, 
                      uint32_t prescaler, 
                      uint32_t period);
                      
void timers_TIMx_IRQinit(TIMERS_ID tid,
                         uint32_t prescaler,
                         uint32_t period,
                         uint32_t priority);

htimer_t* timers_TIMx_facotry(TIMERS_ID tid);
void timers_TIMx_start(htimer_t *timer);
void timers_TIMx_stop(htimer_t *timer);
void timers_TIMx_reset(htimer_t *timer);
uint32_t timers_TIMx_elapsed(htimer_t *timer);

#endif