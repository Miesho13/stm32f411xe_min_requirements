/**
 * @brief GPIO driver
 * 
 * @author marcin.ryzewskii@gmail.com
 * @date 2023-11-22
*/

#include "gpio.h"

void gpio_init(gpio_init_t hgpio) {
    // pins =  (1 << 1) | (1 << 3) | (1 << 14)
    for (uint16_t pin_ofs = 0; pin_ofs < 16; pin_ofs++) {
        if ((1 << pin_ofs) == (hgpio.pins & (1 << pin_ofs))) {
            hgpio.GPIOx->MODER |= (hgpio.mode << pin_ofs*2);
            hgpio.GPIOx->OTYPER |= (hgpio.type << pin_ofs);
            hgpio.GPIOx->OSPEEDR |= (hgpio.speed << pin_ofs*2);
            hgpio.GPIOx->PUPDR |= (hgpio.pupd << pin_ofs*2);
        }
    }
}
