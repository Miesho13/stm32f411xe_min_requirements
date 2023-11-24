#ifndef __SYTSTEM__H__
#define __SYTSTEM__H__



#include <stdint.h>
#include "../driver/timers.h"



void __deley(uint32_t count);
void __delay_ms(uint32_t ms);

#endif // __SYTSTEM__H__