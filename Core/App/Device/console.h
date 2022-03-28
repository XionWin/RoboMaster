
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

#define UART_BUFFER_LEN 256
    uint8_t huart1_Tx_buffer[UART_BUFFER_LEN];
    uint8_t huart1_Rx_buffer[UART_BUFFER_LEN];

    typedef void (*console_write_func)(uint8_t *buffer, uint32_t len);
    typedef void (*console_read_callback)(uint8_t *buffer, uint32_t len);

    typedef struct
    {
        console_write_func write;
        console_read_callback read_callback;
    } console_t;

    void console_init();

#ifdef __cplusplus
}
#endif

#endif /* __CONSOLE_H__ */
