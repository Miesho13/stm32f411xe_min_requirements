/**
 * @file timers.c
 * @brief Timer driver for STM32F4xx
 * @date 2023-11-15
*/

#include "timers.h"

// HARD DEFINE TIMERS
htimer_t timres_handler[TIMER_COUNT]; 

#define TIM_HARD1  timres_handler[0]
#define TIM_HARD2  timres_handler[1]
#define TIM_HARD3  timres_handler[2]
#define TIM_HARD4  timres_handler[3]
#define TIM_HARD5  timres_handler[4]
#define TIM_HARD9  timres_handler[5]
#define TIM_HARD10 timres_handler[6]
#define TIM_HARD11 timres_handler[7]


/// @brief Initialize timer
/// @param tid Timer ID 
/// @param prescaler Prescaler value
/// @param period Period value 
void timers_TIMx_init(TIMER_ID tid, 
                      uint32_t prescaler, 
                      uint32_t period) {
    switch (tid) {
        case TIMER_ID_1:
            TIM_HARD1.instance = TIM1;
            TIM_HARD1.timer_id = TIMER_ID_1;

            TIM_HARD1.prescaler = prescaler;
            TIM_HARD1.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

            TIM_HARD1.instance->PSC = TIM_HARD1.prescaler;
            TIM_HARD1.instance->ARR = TIM_HARD1.period;

            TIM_HARD1.instance->CR1 |= TIM_CR1_CEN;
            break;
        
        
        case TIMER_ID_2:
            TIM_HARD2.instance = TIM2;
            TIM_HARD2.timer_id = TIMER_ID_2;

            TIM_HARD2.prescaler = prescaler;
            TIM_HARD2.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

            TIM_HARD2.instance->PSC = TIM_HARD2.prescaler;
            TIM_HARD2.instance->ARR = TIM_HARD2.period;

            TIM_HARD2.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_3:
            TIM_HARD3.instance = TIM3;
            TIM_HARD3.timer_id = TIMER_ID_3;

            TIM_HARD3.prescaler = prescaler;
            TIM_HARD3.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

            TIM_HARD3.instance->PSC = TIM_HARD3.prescaler;
            TIM_HARD3.instance->ARR = TIM_HARD3.period;

            TIM_HARD3.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_4:
            TIM_HARD4.instance = TIM4;
            TIM_HARD4.timer_id = TIMER_ID_4;

            TIM_HARD4.prescaler = prescaler;
            TIM_HARD4.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

            TIM_HARD4.instance->PSC = TIM_HARD4.prescaler;
            TIM_HARD4.instance->ARR = TIM_HARD4.period;

            TIM_HARD4.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_5:
            TIM_HARD5.instance = TIM5;
            TIM_HARD5.timer_id = TIMER_ID_5;

            TIM_HARD5.prescaler = prescaler;
            TIM_HARD5.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

            TIM_HARD5.instance->PSC = TIM_HARD5.prescaler;
            TIM_HARD5.instance->ARR = TIM_HARD5.period;

            TIM_HARD5.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_9:
            TIM_HARD9.instance = TIM9;
            TIM_HARD9.timer_id = TIMER_ID_9;

            TIM_HARD9.prescaler = prescaler;
            TIM_HARD9.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;

            TIM_HARD9.instance->PSC = TIM_HARD9.prescaler;
            TIM_HARD9.instance->ARR = TIM_HARD9.period;

            TIM_HARD9.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_10:
            TIM_HARD10.instance = TIM10;
            TIM_HARD10.timer_id = TIMER_ID_10;

            TIM_HARD10.prescaler = prescaler;
            TIM_HARD10.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;

            TIM_HARD10.instance->PSC = TIM_HARD10.prescaler;
            TIM_HARD10.instance->ARR = TIM_HARD10.period;

            TIM_HARD10.instance->CR1 |= TIM_CR1_CEN;
            break;
        

        case TIMER_ID_11:
            TIM_HARD11.instance = TIM11;
            TIM_HARD11.timer_id = TIMER_ID_11;

            TIM_HARD11.prescaler = prescaler;
            TIM_HARD11.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;

            TIM_HARD11.instance->PSC = TIM_HARD11.prescaler;
            TIM_HARD11.instance->ARR = TIM_HARD11.period;

            TIM_HARD11.instance->CR1 |= TIM_CR1_CEN;
            break;
    }
}
