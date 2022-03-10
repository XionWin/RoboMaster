
#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

void argb_led_show(uint32_t aRGB);
void argb_led_channel_show(uint8_t alpha, uint16_t red, uint16_t green, uint16_t blue);

#ifdef __cplusplus
}
#endif

#endif /* __RGB_LED_H__ */

