#ifndef __GPIO_H__
#define __GPIO_H__

#include "../cmsis/stm32f4xx.h"
#include "../cmsis/system_stm32f4xx.h"


// MARCRO DEFINE START
// Define GPIO Port/Pin A 
#define GPIO_PORT_A GPIOA

// Define GPIO Port/Pin B
#define GPIO_PORT_B GPIOB

// Define GPIO Port/Pin C
#define GPIO_PORT_C GPIOC

// Define GPIO Port/Pin D
#define GPIO_PORT_D GPIOD 

// Define GPIO Port/Pin E
#define GPIO_PORT_E GPIOE

// Define GPIO Port/Pin F
#define GPIO_PORT_H GPIOH

// MACRO GPIO END
typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET

} GPIO_PinState;


typedef struct {
    GPIO_TypeDef* GPIOx;  // GPIO Port
    uint32_t GPIO_Mode;   // GPIO Mode
    uint32_t GPIO_Pull;   // GPIO Pull-Up/Pull-Down
    uint32_t GPIO_Speed;  // GPIO Speed
    uint32_t GPIO_PuPd;   // GPIO Pull-Up/Pull-Down
    uint16_t GPIO_Pin;    // GPIO Pin

} GPIO_InitTypeDef;



#define GPIO_MODE_INPUT        0x00000000U   /* Input Floating Mode                   */
#define GPIO_MODE_OUTPUT_PP    0x00000001U   /* Output Push Pull Mode                 */
#define GPIO_MODE_OUTPUT_OD    0x00000011U   /* Output Open Drain Mode                */
#define GPIO_MODE_AF_PP        0x00000002U   /* Alternate Function Push Pull Mode     */
#define GPIO_MODE_AF_OD        0x00000012U   /* Alternate Function Open Drain Mode    */
#define GPIO_MODE_ANALOG       0x00000003U   /* Analog Mode                           */


void GPIO_Init(GPIO_InitTypeDef *GPIO_InitStruct);
GPIO_PinState GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif // __GPIO_H__