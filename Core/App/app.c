#include "app.h"

#define CVT_FLOAT_TO_BYTE(float_v) ( \
    float_v * 0xFF)

color_t hsv = COLOR_HSV_INIT(0.f, 1.f, 1.f);
void console_receviced_callback(uint8_t *buffer, uint32_t len);
uint32_t color_convert_slv_to_argb(color_t hsv);

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
        ARGB_LED.set_color(color_convert_slv_to_argb(hsv));
        HAL_Delay(20);
    }
    return 0;
}

void console_receviced_callback(uint8_t *buffer, uint32_t len)
{
    CONSOLE.write(buffer, len);
    hsv.h += 0.01f;
    if (hsv.h >= 1)
    {
        hsv.h = 0.f;
    }
}

uint32_t color_convert_slv_to_argb(color_t hsv)
{
    color_t rgb = hsv;
    color_convert(&rgb, COLOR_TYPE_RGB);

    uint8_t r = CVT_FLOAT_TO_BYTE(rgb.r);
    uint8_t g = CVT_FLOAT_TO_BYTE(rgb.g);
    uint8_t b = CVT_FLOAT_TO_BYTE(rgb.b);

    return (0x33 << 24) + (r << 16) + (g << 8) + b;
}
