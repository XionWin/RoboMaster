#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#include "aRGB_led.h"
#include "console.h"
#include "buzzer.h"
#include "pwm.h"

#include "main_task.h"
#include "sub_task.h"

    // Resources
    extern aRGB_led_t ARGB_LED;
    extern console_t CONSOLE;
    extern buzzer_t BUZZER;
    extern pwm_t PWM;

    // Stm32f4 functions
    /* Register in USART1_IRQHandler */
    void USART1_Rx_Idle_Callback(UART_HandleTypeDef *huart);

    extern main_task_t MAIN_TASK;
    extern sub_task_t SUB_TASK;

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H__ */