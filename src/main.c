/*
  This is the main file for the project.

  @author Marcin Ryzewski
  @date 11/2023
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "cmsis/stm32f4xx.h"
#include "cmsis/system_stm32f4xx.h"

#include "driver/rcc.h"
#include "driver/timers.h"
void system_init() {
    // Cortex-M4F core configuration
    (void)SystemInit();

    // set main clock to 100MHz
    (void)RCC_Init();

    // initialize timers 
    (void)timers_TIMx_init(TIMER_ID_2, 10000, 10000);
}

void system_loop() {
    uint32_t elapsed = timers_TIMx_elapsed(timers_TIMx_facotry(TIMER_ID_2)); 
}


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    
    (void)system_init();
    while (true) {
        (void)system_loop();
    }
}