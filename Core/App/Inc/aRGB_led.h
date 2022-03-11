
#ifndef __RGB_LED_H__
#define __RGB_LED_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

    typedef struct aRGB_led_s_t aRGB_led_s_t;

    typedef void (*aRGB_led_set_init_func)();
    typedef void (*aRGB_led_set_color_func)(uint32_t color);
    typedef void (*argb_led_set_channels_func)(uint8_t a, uint8_t r, uint8_t g, uint8_t b);

    typedef struct
    {
        aRGB_led_s_t *super;
        aRGB_led_set_init_func init;
        aRGB_led_set_color_func set_color;
        argb_led_set_channels_func set_channels;
    } aRGB_led_t;

    void aRGB_led_init();

#ifdef __cplusplus
}
#endif

#endif /* __RGB_LED_H__ */
