#include "system.h"
#include "../driver/timers.h"
#include "../cmsis/stm32f4xx.h"



void __delay(uint32_t count) {

    for (uint32_t i = 0; i < count; i++) {
        __asm__("nop");
    }
}





// DELAY BASE ON TIM3 COUNTER
void __delay_ms(uint32_t ms) {


    uint32_t prescaler;
    uint32_t period;


    // // ENABLE TIM3
    // TIM3->CR1 |= TIM_CR1_CEN;

    // // RESET COUNTER
    // TIM3->CNT = 0;

    // // WAIT FOR COUNTER TO REACH ms
    // while (TIM3->CNT < ms);

    // // DISABLE TIM3
    // TIM3->CR1 &= ~TIM_CR1_CEN;    


}