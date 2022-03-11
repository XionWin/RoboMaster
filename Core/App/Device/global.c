#include "global.h"

extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;

void USART1_Rx_Idle_Callback(UART_HandleTypeDef *huart)
{
    uint32_t temp;
    if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE) != RESET)
    {
        __HAL_UART_CLEAR_IDLEFLAG(&huart1);
        // temp = huart1.Instance->ISR;
        // temp = huart1.Instance->ICR;
        // temp = huart1.Instance->RDR;
        HAL_UART_DMAStop(&huart1);
        temp = hdma_usart1_rx.Instance->NDTR; // DMA stream x number of data register
        size_t rec_len = UART_BUFFER_LEN - temp;

        if (CONSOLE.read_callback != NULL)
        {
            CONSOLE.read_callback(huart1_Rx_buffer, rec_len);
        }
        HAL_UART_Receive_DMA(&huart1, huart1_Rx_buffer, UART_BUFFER_LEN);
    }
}