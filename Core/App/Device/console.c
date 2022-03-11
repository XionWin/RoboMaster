#include "console.h"

console_t CONSOLE = {CONSOLE_BUFFER_LEN, CONSOLE_WRITE_BUFFER, CONSOLE_READ_BUFFER, 0, NULL};
void console_init()
{
}

void console_write(char * buf, uint8_t len)
{

}


int console_read(char * buf)
{
    return 0;
}