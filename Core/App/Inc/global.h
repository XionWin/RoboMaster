
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "aRGB_led.h"
#include "console.h"

extern aRGB_led_t ARGB_LED;

#define UART_BUFFER_LEN 256
uint8_t huart1_Tx_buffer[UART_BUFFER_LEN];
uint8_t huart1_Rx_buffer[UART_BUFFER_LEN];

extern console_t CONSOLE;



#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H__ */