
#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

void rgb_led_show(uint32_t aRGB);

#ifdef __cplusplus
}
#endif

#endif /* __RGB_LED_H__ */
