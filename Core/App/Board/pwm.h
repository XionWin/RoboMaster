#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"
    typedef void (*pwm_set_reload_func)(uint16_t value);
    typedef void (*pwm_enable_ch_func)(uint8_t ch_number);
    typedef void (*pwm_disable_ch_func)(uint8_t ch_number);
    typedef void (*pwm_set_ch_value_func)(uint8_t ch_number, uint16_t value);

    typedef struct
    {
        pwm_set_reload_func set_reload;
        pwm_enable_ch_func enable_ch;
        pwm_disable_ch_func disable_ch;
        pwm_set_ch_value_func set_ch;
    } pwm_t;

    void pwm_init();

#ifdef __cplusplus
}
#endif

#endif /* __PWM_H__ */
