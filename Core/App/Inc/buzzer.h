#ifndef __BUZZER_H__
#define __BUZZER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "stm32f4xx_hal.h"

    typedef void (*buzzer_set_tone_func)(uint16_t tone);

    typedef struct
    {
        buzzer_set_tone_func set_tone;
    } buzzer_t;

    void buzzer_init();

#ifdef __cplusplus
}
#endif

#endif /* __BUZZER_H__ */
