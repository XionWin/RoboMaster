#include "argb_led.h"

extern TIM_HandleTypeDef htim5;


struct aRGB_led {
    uint8_t alpha;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

void argb_led_show(uint32_t aRGB)
{
    static uint8_t alpha;
    static uint8_t red,green,blue;

    alpha = (aRGB & 0xFF000000) >> 24;
    red = (aRGB & 0x00FF0000) >> 16;
    green = (aRGB & 0x0000FF00) >> 8;
    blue = (aRGB & 0x000000FF) >> 0;

    argb_led_channel_show(alpha, red, green, blue);
}

void argb_led_channel_show(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
    uint16_t r = (uint16_t)red * alpha;
    uint16_t g = (uint16_t)green * alpha;
    uint16_t b = (uint16_t)blue * alpha;

    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_1, b);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, g);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_3, r);
}
