#include "console.h"

Console::Console(volatile uint16_t* buffer):
  buffer(buffer)
{
}
  
Console::Console(): Console((volatile uint16_t*) 0xB8000)
{
}

void Console::clear()
{
  for(volatile uint16_t* position = (volatile uint16_t*)buffer; position < buffer + width * lines; ++position)
    {
      *position = 0;
    }
}

void Console::printk(const char* s)
{
  volatile uint16_t* terminalBuffer = (volatile uint16_t*) 0xB8000;
  const uint16_t color = 7;
  
  while (*s != '\0'){
    *terminalBuffer++ = *s++ | color << 8;
  }
}
