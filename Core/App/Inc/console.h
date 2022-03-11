
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "stm32f4xx_hal.h"

#define CONSOLE_BUFFER_LEN 256

typedef void (*console_Rx_callback)(uint8_t * buffer, uint32_t len);

typedef struct {
    const uint32_t BUFFER_MAX_LEN;
    uint8_t * writeBuffer;
    uint8_t * readBuffer;
    uint32_t availableReadLength;
    console_Rx_callback receivedCallback;
} console_t;

uint8_t CONSOLE_WRITE_BUFFER[CONSOLE_BUFFER_LEN];
uint8_t CONSOLE_READ_BUFFER[CONSOLE_BUFFER_LEN];

extern console_t CONSOLE;

void console_init();
void console_write(char * buf, uint8_t len);
int console_read(char * buf);

#ifdef __cplusplus
}
#endif

#endif /* __CONSOLE_H__ */

