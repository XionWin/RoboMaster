
#ifndef __UART1_H__
#define __UART1_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

#define UART1_BUFFER_LEN 256
uint8_t huart1_Tx_buffer[UART1_BUFFER_LEN];
uint8_t huart1_Rx_buffer[UART1_BUFFER_LEN];

    typedef void (*uart1_write_func)(uint8_t *buffer, uint32_t len);
    typedef void (*uart1_read_callback)(uint8_t *buffer, uint32_t len);

    typedef struct
    {
        uart1_write_func write;
        uart1_read_callback read_callback;
    } uart1_t;

    void uart1_init();

#ifdef __cplusplus
}
#endif

#endif /* __UART1_H__ */
