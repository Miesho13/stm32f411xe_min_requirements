/**
 * @file timers.c
 * @brief Timer driver for STM32F4xx
 * @date 2023-11-15
*/

#include "timers.h"

// HARD DEFINE TIMERS
htimer_t timres_handler[TIMER_COUNT] = {
    { TIM1, 0, 0, TIMER_ID_1, TIMER_OFF },
    { TIM2, 0, 0, TIMER_ID_2, TIMER_OFF },
    { TIM3, 0, 0, TIMER_ID_3, TIMER_OFF },
    { TIM4, 0, 0, TIMER_ID_4, TIMER_OFF },
    { TIM5, 0, 0, TIMER_ID_5, TIMER_OFF },
    { TIM9, 0, 0, TIMER_ID_9, TIMER_OFF },
    { TIM10, 0, 0, TIMER_ID_10, TIMER_OFF },
    { TIM11, 0, 0, TIMER_ID_11, TIMER_OFF },
};


#define TIM_HARD1  timres_handler[0]
#define TIM_HARD2  timres_handler[1]
#define TIM_HARD3  timres_handler[2]
#define TIM_HARD4  timres_handler[3]
#define TIM_HARD5  timres_handler[4]
#define TIM_HARD9  timres_handler[5]
#define TIM_HARD10 timres_handler[6]
#define TIM_HARD11 timres_handler[7]



void __attribute__((weak)) TIM1_UP_TIM10_IRQHandler(void) {
    if (TIM1->SR & TIM_SR_UIF) {
        TIM1->SR &= ~TIM_SR_UIF;

        // Your code here 
    }
}



void __attribute__((weak)) TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;

        // Your code here 
    }
}



void __attribute__((weak)) TIM3_IRQHandler(void) {
    if (TIM3->SR & TIM_SR_UIF) {
        TIM3->SR &= ~TIM_SR_UIF;

        // Your code here 
    }
}



void __attribute__((weak)) TIM4_IRQHandler(void) {
    if (TIM4->SR & TIM_SR_UIF) {
        TIM4->SR &= ~TIM_SR_UIF;

        // Your code here 
    }
}



void __attribute__((weak)) TIM5_IRQHandler(void) {
    if (TIM5->SR & TIM_SR_UIF) {
        TIM5->SR &= ~TIM_SR_UIF;

        // Your code here 
    }
}



/// @brief Initialize timer
/// @param tid Timer ID 
/// @param prescaler Prescaler value
/// @param period Period value 
void timers_TIMx_init(TIMERS_ID tid, 
                      uint32_t prescaler, 
                      uint32_t period) {
    switch (tid) {
        case TIMER_ID_1:
            TIM_HARD1.state = TIMER_ON;

            TIM_HARD1.prescaler = prescaler;
            TIM_HARD1.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

            TIM_HARD1.instance->PSC = TIM_HARD1.prescaler;
            TIM_HARD1.instance->ARR = TIM_HARD1.period;

            TIM_HARD1.instance->CR1 |= TIM_CR1_CEN;
            break;
        
        
        case TIMER_ID_2:
            TIM_HARD2.state = TIMER_ON;
            
            TIM_HARD2.prescaler = prescaler;
            TIM_HARD2.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

            TIM_HARD2.instance->PSC = TIM_HARD2.prescaler;
            TIM_HARD2.instance->ARR = TIM_HARD2.period;

            TIM_HARD2.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_3:
            TIM_HARD3.state = TIMER_ON;

            TIM_HARD3.prescaler = prescaler;
            TIM_HARD3.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

            TIM_HARD3.instance->PSC = TIM_HARD3.prescaler;
            TIM_HARD3.instance->ARR = TIM_HARD3.period;

            TIM_HARD3.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_4:
            TIM_HARD4.state = TIMER_ON;

            TIM_HARD4.prescaler = prescaler;
            TIM_HARD4.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

            TIM_HARD4.instance->PSC = TIM_HARD4.prescaler;
            TIM_HARD4.instance->ARR = TIM_HARD4.period;

            TIM_HARD4.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_5:
            TIM_HARD5.state = TIMER_ON;

            TIM_HARD5.prescaler = prescaler;
            TIM_HARD5.period = period;

            RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

            TIM_HARD5.instance->PSC = TIM_HARD5.prescaler;
            TIM_HARD5.instance->ARR = TIM_HARD5.period;

            TIM_HARD5.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_9:
            TIM_HARD9.state = TIMER_ON;

            TIM_HARD9.prescaler = prescaler;
            TIM_HARD9.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;

            TIM_HARD9.instance->PSC = TIM_HARD9.prescaler;
            TIM_HARD9.instance->ARR = TIM_HARD9.period;

            TIM_HARD9.instance->CR1 |= TIM_CR1_CEN;
            break;


        case TIMER_ID_10:
            TIM_HARD10.state = TIMER_ON;

            TIM_HARD10.prescaler = prescaler;
            TIM_HARD10.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;

            TIM_HARD10.instance->PSC = TIM_HARD10.prescaler;
            TIM_HARD10.instance->ARR = TIM_HARD10.period;

            TIM_HARD10.instance->CR1 |= TIM_CR1_CEN;
            break;
        

        case TIMER_ID_11:
            TIM_HARD11.state = TIMER_ON;

            TIM_HARD11.prescaler = prescaler;
            TIM_HARD11.period = period;

            RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;

            TIM_HARD11.instance->PSC = TIM_HARD11.prescaler;
            TIM_HARD11.instance->ARR = TIM_HARD11.period;

            TIM_HARD11.instance->CR1 |= TIM_CR1_CEN;
            break;
        case TIMER_COUNT:
            break;
    }
}

void timers_TIMx_IRQinit(TIMERS_ID tid,
                         uint32_t prescaler,
                         uint32_t period,
                         uint32_t priority) {

    (void)timers_TIMx_init(tid, prescaler, period);

    switch (tid) {
        case TIMER_ID_1:
            NVIC_SetPriority(TIM1_UP_TIM10_IRQn, priority);
            NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
            break;


        case TIMER_ID_2:
            NVIC_SetPriority(TIM2_IRQn, priority);
            NVIC_EnableIRQ(TIM2_IRQn);
            break;
        

        case TIMER_ID_3:
            NVIC_SetPriority(TIM3_IRQn, priority);
            NVIC_EnableIRQ(TIM3_IRQn);
            break;


        case TIMER_ID_4:
            NVIC_SetPriority(TIM4_IRQn, priority);
            NVIC_EnableIRQ(TIM4_IRQn);
            break;


        case TIMER_ID_5:
            NVIC_SetPriority(TIM5_IRQn, priority);
            NVIC_EnableIRQ(TIM5_IRQn);
            break;


        case TIMER_ID_9:
            NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, priority);
            NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
            break;


        case TIMER_ID_10:
            NVIC_SetPriority(TIM1_UP_TIM10_IRQn, priority);
            NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
            break; 
        

        case TIMER_ID_11:
            NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, priority);
            NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
            break;

        case TIMER_COUNT:
            break;
    }
}



htimer_t* timers_TIMx_facotry(TIMERS_ID tid) {
    switch (tid) {
        case TIMER_ID_1:
            return &TIM_HARD1;
            break;

        
        case TIMER_ID_2:
            return &TIM_HARD2;
            break;

        
        case TIMER_ID_3:
            return &TIM_HARD3;
            break;


        case TIMER_ID_4:
            return &TIM_HARD4;
            break;

        
        case TIMER_ID_5:
            return &TIM_HARD5;
            break;
        
        
        case TIMER_ID_9:
            return &TIM_HARD9;
            break;

        
        case TIMER_ID_10:
            return &TIM_HARD10;
            break;

        
        case TIMER_ID_11:
            return &TIM_HARD11;
            break;  

        case TIMER_COUNT:
            break;
    }

    return NULL;
}



/// @brief Start timer 
/// @param timer is a pointer to a ctx strcut for hardware timer  
void timers_TIMx_start(htimer_t *timer) {
    timer->instance->CR1 |= TIM_CR1_CEN;
}



/// @brief Stop timer 
/// @param timer is a pointer to a ctx strcut for hardware timer  
void timers_TIMx_stop(htimer_t *timer) {
    timer->instance->CR1 &= ~TIM_CR1_CEN;
}



/// @brief Reset timer 
/// @param timer is a pointer to a ctx strcut for hardware timer  
void timers_TIMx_reset(htimer_t *timer) {
    timer->instance->CNT = 0;
}


/// @brief Get elapsed time from timer
/// @param timer 
/// @return Elapsed time
uint32_t timers_TIMx_elapsed(htimer_t *timer) {
    return timer->instance->CNT;
}




