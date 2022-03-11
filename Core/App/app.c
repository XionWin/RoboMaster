#include "app.h"

extern TIM_HandleTypeDef htim5;


void enable_timer5();

#define CVT_FLOAT_TO_BYTE(float_v)          (                       \
                                                float_v * 0xFF      \
                                            )

color_t hsv = COLOR_HSV_INIT(0.f, 1.f, 1.f);
void console_receviced_callback(uint8_t * buffer, uint32_t len)
{
    CONSOLE.write(buffer, len);
    hsv.h += 0.05f;
    if(hsv.h >= 1)
    {
        hsv.h = 0.f;
    }
}

void app_init()
{
    aRGB_led_init();
    console_init();
    
    CONSOLE.read_callback = console_receviced_callback;
}

int app_run()
{

    while (1)
    {
        color_t rgb = hsv;
        color_convert(&rgb, COLOR_TYPE_RGB);

        uint8_t r = CVT_FLOAT_TO_BYTE(rgb.r);
        uint8_t g = CVT_FLOAT_TO_BYTE(rgb.g);
        uint8_t b = CVT_FLOAT_TO_BYTE(rgb.b);
        
        ARGB_LED.set_channels(0x33, r, g, b);

        HAL_Delay(20);
    }
    


    return 0;
}

