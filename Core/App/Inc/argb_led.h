
#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

typedef struct {
    
} aRGB_led;


void argb_led_show(uint32_t aRGB);
void argb_led_channel_show(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);

#ifdef __cplusplus
}
#endif

#endif /* __RGB_LED_H__ */

