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
    buzzer_init();
    pwm_init();

    CONSOLE.read_callback = console_receviced_callback;
}

int app_run()
{
    // uint16_t psc = 0;
    // const uint16_t max_psc = 0xFFFF;
    // BUZZER.set_volume(0x00AA);

    uint16_t pwm_base = 1130;
    uint16_t pwm_max = 1400;
    uint16_t pwm = pwm_base;
    PWM.set_ch1(pwm);
    PWM.set_ch2(pwm);
    PWM.set_ch3(pwm);
    PWM.set_ch4(pwm);

    HAL_Delay(3000);






    while (1)
    {
        ARGB_LED.set_color(color_convert_slv_to_argb(hsv));


        PWM.set_ch1(pwm);
        PWM.set_ch2(pwm);
        PWM.set_ch3(pwm);
        PWM.set_ch4(pwm);

        pwm += 1;
        if(pwm > pwm_max)
        {
            pwm = pwm_base;
        }

        // BUZZER.set_frequency(psc);
        // psc += 5;
        // if(psc >= max_psc)
        // {
        //     psc = 0;
        // }

        HAL_Delay(100);
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
