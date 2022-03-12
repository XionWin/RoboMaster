#ifndef __BUZZER_H__
#define __BUZZER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"

    typedef void (*buzzer_set_frequency_func)(uint16_t freq);
    typedef void (*buzzer_set_volume_func)(uint16_t volume);

    typedef struct
    {
        buzzer_set_frequency_func set_frequency;
        buzzer_set_volume_func set_volume;
    } buzzer_t;

    void buzzer_init();

#ifdef __cplusplus
}
#endif

#endif /* __BUZZER_H__ */
