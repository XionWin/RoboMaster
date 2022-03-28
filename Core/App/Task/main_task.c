#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "main_task.h"

#include "aRGB_led.h"
#include "console.h"
#include "buzzer.h"
#include "pwm.h"

extern aRGB_led_t ARGB_LED;
extern console_t CONSOLE;
extern buzzer_t BUZZER;
extern pwm_t PWM;

// Stm32f4 functions
/* Register in USART1_IRQHandler */
void USART1_Rx_Idle_Callback(UART_HandleTypeDef *huart);

int main_task_run();

main_task_t MAIN_TASK;

#define CVT_FLOAT_TO_BYTE(float_v) (float_v * 0xFF)

color_t hsv = COLOR_HSV_INIT(0.f, 1.f, 1.f);
void console_receviced_callback(uint8_t *buffer, uint32_t len);
uint32_t color_convert_slv_to_argb(color_t hsv);


void main_task_init()
{
    aRGB_led_init();
    console_init();
    buzzer_init();
    pwm_init();

    CONSOLE.read_callback = console_receviced_callback;

    MAIN_TASK.run = main_task_run;
}

int main_task_run()
{
    // uint16_t psc = 0;
    // const uint16_t max_psc = 0xFFFF;
    // BUZZER.set_volume(0x00AA);

    uint32_t tone = 200;

    BUZZER.enable();
    BUZZER.set_tone(tone);
    PWM.set_tone(tone);
    BUZZER.disable();

    while (1)
    {
        while (ulTaskNotifyTake(pdTRUE, portMAX_DELAY) != pdPASS)
        {
        }

        ARGB_LED.set_color(color_convert_slv_to_argb(hsv));

        BUZZER.enable();
        // BUZZER.set_tone(tone);
        // PWM.set_tone(tone);
        osDelay(100);

        BUZZER.disable();

        // BUZZER.set_tone(0);
        // PWM.set_tone(0);

        // BUZZER.set_tone(tone);
        // PWM.set_tone(tone);
        // tone += 2;
        // if(tone > 0xFFFF)
        // {
        //     tone = 1;
        // }

        // BUZZER.set_frequency(psc);
        // psc += 5;
        // if(psc >= max_psc)
        // {
        //     psc = 0;
        // }

        // osDelay(1);
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
