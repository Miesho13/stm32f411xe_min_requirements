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

}

void system_loop() { 

}


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    
    (void)system_init();
    while (true) {
        (void)system_loop();
    }
}