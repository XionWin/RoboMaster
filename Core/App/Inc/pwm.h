#ifndef __PWM_H__
#define __PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"
    typedef void (*pwm_set_psc_func)(uint16_t value);
    typedef void (*pwm_set_value_func)(uint16_t value);

    typedef struct
    {
        pwm_set_psc_func   set_psc;
        pwm_set_value_func set_ch1;
        pwm_set_value_func set_ch2;
        pwm_set_value_func set_ch3;
        pwm_set_value_func set_ch4;
    } pwm_t;

    void pwm_init();

#ifdef __cplusplus
}
#endif

#endif /* __PWM_H__ */
