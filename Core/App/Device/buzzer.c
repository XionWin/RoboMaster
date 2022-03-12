#include "buzzer.h"

extern TIM_HandleTypeDef htim4;

buzzer_t BUZZER;

void buzzer_set_frequency(uint16_t freq);
void buzzer_set_volume(uint16_t volume);
void enable_timer4();

void buzzer_init()
{
    BUZZER.set_frequency = buzzer_set_frequency;
    BUZZER.set_volume = buzzer_set_volume;

    enable_timer4();
}

void buzzer_set_frequency(uint16_t freq)
{
    __HAL_TIM_PRESCALER(&htim4, freq);
}

void buzzer_set_volume(uint16_t volume)
{
    __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_3, volume);
}


void enable_timer4()
{
    // start tim
    HAL_TIM_Base_Start(&htim4);
    // start pwm channel
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
}