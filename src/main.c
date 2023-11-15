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

void system_init() {
    SystemInit();
    RCC_Init();

}

void system_loop() {

}


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    
    system_init();
    while (true) {
        SystemCoreClock;
        system_loop();
    }
}