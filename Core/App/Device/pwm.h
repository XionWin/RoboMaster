#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"
    typedef void (*pwm_set_reload_func)(uint16_t value);
    typedef void (*pwm_enable_func)();
    typedef void (*pwm_disable_func)();
    typedef void (*pwm_set_ch_value_func)(uint16_t value);

    typedef struct
    {
        pwm_set_reload_func set_reload;
        pwm_enable_func enable_ch1;
        pwm_disable_func disable_ch1;
        pwm_set_ch_value_func set_ch1;
    } pwm_t;

    void pwm_init();

#ifdef __cplusplus
}
#endif

#endif /* __PWM_H__ */
