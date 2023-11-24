/**
 * @brief GPIO driver
 * 
 * @author marcin.ryzewskii@gmail.com
 * @date 2023-11-22
*/

#include "gpio.h"


/// @brief Initializes the GPIOx peripheral according to the specified parameters 
///        in the GPIO_InitStruct.
/// @param GPIO_InitStruct pointer to a GPIO_InitTypeDef structure that contains 
///        the configuration information for the specified GPIO peripheral. 
void GPIO_Init(GPIO_InitTypeDef *GPIO_InitStruct) {
    uint32_t pinpos = 0x00;
    uint32_t pos = 0x00;
    uint32_t currentpin = 0x00;

    /* ------------------------- Configure the port pins ---------------- */
    /*-- GPIO Mode Configuration --*/
    for (pinpos = 0x00; pinpos < 0x10; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        /* Get the port pins position */
        currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

        if (currentpin == pos) {
            // Pin Mode configuration 
            // Configure Mode 
            GPIO_InitStruct->GPIOx->MODER &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
            GPIO_InitStruct->GPIOx->MODER |= ((GPIO_InitStruct->GPIO_Mode) << (pinpos * 2));

            // Pull-up Pull down resistor configuration 
            GPIO_InitStruct->GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
            GPIO_InitStruct->GPIOx->PUPDR |= ((GPIO_InitStruct->GPIO_PuPd) << (pinpos * 2));
           
            //  Speed config 
            GPIO_InitStruct->GPIOx->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
            GPIO_InitStruct->GPIOx->OSPEEDR |= ((GPIO_InitStruct->GPIO_Speed) << (pinpos * 2));
        }
    }

}


/// @brief 
/// @param GPIOx 
/// @param GPIO_Pin 
/// @return 
GPIO_PinState GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    GPIO_PinState bitstatus = GPIO_PIN_RESET;

    if ( (GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET ) {
        bitstatus = GPIO_PIN_SET;
    } else {
        bitstatus = GPIO_PIN_RESET;
    }

    return bitstatus;
}


/// @brief Toggles the specified GPIO pin. 
/// @param GPIOx  
/// @param GPIO_Pin 
/// @param PinState 
void GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
    if (PinState != GPIO_PIN_RESET) {
        GPIOx->BSRR = GPIO_Pin;
    } else {
        GPIOx->BSRR = (uint32_t)GPIO_Pin << 16;
    }
}


/// @brief 
/// @param GPIOx 
/// @param GPIO_Pin 
void GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    GPIOx->ODR ^= GPIO_Pin;
}
