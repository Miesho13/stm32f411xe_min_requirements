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
} TIMER_ID;

typedef struct {
    TIM_TypeDef *instance;
    TIMER_ID timer_id;
    uint32_t prescaler;
    uint32_t period;
    
} htimer_t;



void timers_TIMx_init(TIMER_ID tid, 
                      uint32_t prescaler, 
                      uint32_t period);

htimer_t timers_TIMx_facotry(TIMER_ID tid);



#endif