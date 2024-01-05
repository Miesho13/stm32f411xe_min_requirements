#include "system.h"
#include "../driver/timers.h"
#include "../cmsis/stm32f4xx.h"



void system_function_init(void) {
    // reserv tim3 for system_delay_ms
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 8000U - 1; 
    TIM3->ARR = 0xffffffff - 1;
    TIM3->CR1 |= TIM_CR1_CEN;
}

// DELAY BASE ON TIM3 COUNTER
void  system_delay_ms(uint32_t ms) {
    TIM3->CNT = 0;
    while ((TIM3->CNT) <= ms) { }
}
