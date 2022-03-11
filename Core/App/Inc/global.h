#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#include "aRGB_led.h"
#include "console.h"

    extern aRGB_led_t ARGB_LED;
    extern console_t CONSOLE;

    void USART1_Rx_Idle_Callback(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H__ */