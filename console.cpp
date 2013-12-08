#include "console.h"

Console::Console(volatile uint16_t* const buffer):
  buffer(buffer)
{
}
  
Console::Console(): Console((volatile uint16_t*) 0xB8000)
{
}

void Console::clear()
{
  for(volatile uint16_t* position = buffer; position < buffer + width * lines; ++position)
    {
      *position = 0;
    }
  
  x = y = 0;
}

void Console::printk(const char* s)
{
  const uint16_t color = 7;
  
  while (*s != '\0'){
    buffer[x + y * width] = *s++ | color << 8;
    
    ++x;

    if(x >= width)
      {
        x = 0;
        ++y;
      }

    if(y >= lines)
      {
        x = 0;
        y = 0;
      }
  }
}
