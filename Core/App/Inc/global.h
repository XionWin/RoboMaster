#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#include "aRGB_led.h"
#include "console.h"
    // Resources
    extern aRGB_led_t ARGB_LED;
    extern console_t CONSOLE;

    // Stm32f4 functions
    /* Register in USART1_IRQHandler */
    void USART1_Rx_Idle_Callback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H__ */