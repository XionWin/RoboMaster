#include "app.h"
#include "color.h"

extern TIM_HandleTypeDef htim5;
extern UART_HandleTypeDef huart1;
void enable_timer5();

#define CVT_FLOAT_TO_BYTE(float_v)          (                       \
                                                float_v * 0xFF      \
                                            )
int app_run()
{
    enable_timer5();

    color_t hsv = COLOR_HSV_INIT(0.f, 1.f, 1.f);

    while (1)
    {
        hsv.h += 0.01f;
        if(hsv.h >= 1)
        {
            hsv.h = 0.f;
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"hello world 2022", 16);
        }

        color_t rgb = hsv;
        color_convert(&rgb, COLOR_TYPE_RGB);

        uint8_t r = CVT_FLOAT_TO_BYTE(rgb.r);
        uint8_t g = CVT_FLOAT_TO_BYTE(rgb.g);
        uint8_t b = CVT_FLOAT_TO_BYTE(rgb.b);
        argb_led_channel_show(0xFF, r, g, b);

        HAL_Delay(20);
    }
    


    return 0;
}


void enable_timer5()
{
    //start tim
    HAL_TIM_Base_Start(&htim5);
    //start pwm channel
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
}