
#include "../cmsis/stm32f4xx.h"
#include "../cmsis/system_stm32f4xx.h"

#include "rcc.h"

// set main clock to 100MHz
void RCC_Init(void) {
    // hesi enamble
    RCC->CR |= RCC_CR_HSEON; 
    while ((RCC->CR & RCC_CR_HSERDY) == 0) { } 

    // pll configuration 
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE; 
    RCC->PLLCFGR |= (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | 16;
    RCC->PLLCFGR = 
        (RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) |
        (200 << 6); 

    // pll enable
    RCC->CR |= RCC_CR_PLLON;
    while ((RCC->CR & RCC_CR_PLLRDY) == 0) { }

    // set pll as system clock
    RCC->CFGR |= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) { }

    SystemCoreClockUpdate();
}
