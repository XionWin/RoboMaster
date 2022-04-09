#include "pwm.h"
#include <math.h>

extern TIM_HandleTypeDef htim1;

pwm_t PWM;

void enable_timer1();
void pwm_set_reload(uint16_t value);
void pwm_enable_ch(uint8_t ch_number);
void pwm_disable_ch(uint8_t ch_number);
void pwm_set_ch(uint8_t ch_number, uint16_t value);

void pwm_init()
{
    PWM.set_reload = pwm_set_reload;
    PWM.enable_ch = pwm_enable_ch;
    PWM.disable_ch = pwm_disable_ch;
    PWM.set_ch = pwm_set_ch;

    enable_timer1();
}

void pwm_set_reload(uint16_t value)
{
    __HAL_TIM_SetAutoreload(&htim1, value);
}

void pwm_enable_ch(uint8_t ch_number)
{
    switch (ch_number)
    {
    case 1:
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
        break;
    case 2:
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
        break;
    case 3:
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
        break;
    case 4:
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
        break;
    default:
        break;
    }
}
void pwm_disable_ch(uint8_t ch_number)
{
    switch (ch_number)
    {
    case 1:
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
        break;
    case 2:
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
        break;
    case 3:
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
        break;
    case 4:
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
        break;
    default:
        break;
    }
}

void pwm_set_ch(uint8_t ch_number, uint16_t value)
{
    switch (ch_number)
    {
    case 1:
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, value);
        break;
    case 2:
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, value);
        break;
    case 3:
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, value);
        break;
    case 4:
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, value);
        break;
    default:
        break;
    }
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