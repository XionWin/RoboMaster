#include "pwm.h"
#include <math.h>

extern TIM_HandleTypeDef htim1;

pwm_t PWM;

void enable_timer1();
void pwm_enable_ch1();
void pwm_disable_ch1();
void pwm_set_reload(uint16_t value);
void pwm_set_ch1(uint16_t value);

void pwm_init()
{
    PWM.set_reload = pwm_set_reload;
    PWM.enable_ch1 = pwm_enable_ch1;
    PWM.disable_ch1 = pwm_disable_ch1;
    PWM.set_ch1 = pwm_set_ch1;

    enable_timer1();
}

void pwm_set_reload(uint16_t value)
{
    __HAL_TIM_SetAutoreload(&htim1, value);
}

void pwm_enable_ch1()
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}
void pwm_disable_ch1()
{
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

void pwm_set_ch1(uint16_t value)
{
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, value);
}

void enable_timer1()
{
    // start tim
    HAL_TIM_Base_Start(&htim1);
    // start pwm channel
    // HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    // HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    // HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    // HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}