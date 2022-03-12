#include "aRGB_led.h"

extern TIM_HandleTypeDef htim5;

struct aRGB_led_s_t
{
    uint8_t alpha;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

aRGB_led_t ARGB_LED;

void argb_led_set_color(uint32_t aRGB);
void argb_led_set_channels(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
uint16_t mix_channel_with_alpha(uint8_t value, uint8_t alpha);
void enable_timer5();

void aRGB_led_init()
{
    ARGB_LED.super->alpha = 0xFF;
    ARGB_LED.super->red = 0x00;
    ARGB_LED.super->green = 0x00;
    ARGB_LED.super->blue = 0x00;
    ARGB_LED.set_color = argb_led_set_color;
    ARGB_LED.set_channels = argb_led_set_channels;

    enable_timer5();
}

void argb_led_set_color(uint32_t aRGB)
{
    static uint8_t alpha;
    static uint8_t red, green, blue;

    alpha = (aRGB & 0xFF000000) >> 24;
    red = (aRGB & 0x00FF0000) >> 16;
    green = (aRGB & 0x0000FF00) >> 8;
    blue = (aRGB & 0x000000FF) >> 0;

    argb_led_set_channels(alpha, red, green, blue);
}

void argb_led_set_channels(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
    uint16_t r = mix_channel_with_alpha(red, alpha);
    uint16_t g = mix_channel_with_alpha(green, alpha);
    uint16_t b = mix_channel_with_alpha(blue, alpha);

    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_1, b);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, g);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_3, r);
}

uint16_t mix_channel_with_alpha(uint8_t value, uint8_t alpha)
{
    float color_rate = (float)value / 0xFF;
    float alpha_rate = (float)alpha / 0xFF;
    float rate = color_rate * alpha_rate;
    return (uint16_t)(0xFFFF * rate);
}

void enable_timer5()
{
    // start tim
    HAL_TIM_Base_Start(&htim5);
    // start pwm channel
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
}
