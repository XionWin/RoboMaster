#include "buzzer.h"

extern TIM_HandleTypeDef htim4;

buzzer_t BUZZER;

void buzzer_set_tone(uint16_t tone);
void enable_timer4();

void buzzer_init()
{
    BUZZER.set_tone = buzzer_set_tone;

    enable_timer4();
}

void buzzer_set_tone(uint16_t tone)
{
    __HAL_TIM_SetAutoreload(&htim4, tone);
    __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_3, tone / 2);
}


void enable_timer4()
{
    // start tim
    HAL_TIM_Base_Start(&htim4);
    // start pwm channel
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
}