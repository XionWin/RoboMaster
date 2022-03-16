#include "pwm.h"

extern TIM_HandleTypeDef htim1;

pwm_t PWM;

void pwm_set_psc(uint16_t value);
void pwm_set_tone(uint16_t value);
void pwm_set_ch1(uint16_t value);
void pwm_set_ch2(uint16_t value);
void pwm_set_ch3(uint16_t value);
void pwm_set_ch4(uint16_t value);
void enable_timer1();

void pwm_init()
{
    PWM.set_psc = pwm_set_psc;
    PWM.set_tone = pwm_set_tone;
    PWM.set_ch1 = pwm_set_ch1;
    PWM.set_ch2 = pwm_set_ch2;
    PWM.set_ch3 = pwm_set_ch3;
    PWM.set_ch4 = pwm_set_ch4;

    enable_timer1();
}

void pwm_set_psc(uint16_t value)
{
    __HAL_TIM_PRESCALER(&htim1, value);
}

void pwm_set_tone(uint16_t tone)
{
    __HAL_TIM_SetAutoreload(&htim1, 3);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 2);
}

void pwm_set_ch1(uint16_t value)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, value);
}
void pwm_set_ch2(uint16_t value)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, value);
}
void pwm_set_ch3(uint16_t value)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, value);
}
void pwm_set_ch4(uint16_t value)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, value);
}

void enable_timer1()
{
    // start tim
    HAL_TIM_Base_Start(&htim1);
    // start pwm channel
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}