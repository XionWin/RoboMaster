#include "console.h"

extern UART_HandleTypeDef huart1;

console_t CONSOLE;

void console_write(uint8_t * buffer, uint32_t len);

void console_init()
{
    CONSOLE.write = console_write;
    CONSOLE.read_callback = NULL;

    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
    HAL_UART_Receive_DMA(&huart1, huart1_Rx_buffer, UART_BUFFER_LEN);
}

void console_write(uint8_t * buffer, uint32_t len)
{
    HAL_UART_Transmit_DMA(&huart1, buffer, len);
}