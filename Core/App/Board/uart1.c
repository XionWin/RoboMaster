#include "uart1.h"

extern UART_HandleTypeDef huart1;

uart1_t UART1;

void uart1_write(uint8_t *buffer, uint32_t len);

void uart1_init()
{
    UART1.write = uart1_write;
    UART1.read_callback = NULL;

    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
    HAL_UART_Receive_DMA(&huart1, huart1_Rx_buffer, UART1_BUFFER_LEN);
}

void uart1_write(uint8_t *buffer, uint32_t len)
{
    HAL_UART_Transmit_DMA(&huart1, buffer, len);
}