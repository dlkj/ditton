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
  for(auto position = buffer; position < buffer + width * lines; ++position)
    {
      *position = 0;
    }
  
  x = y = 0;
}

void Console::clearLine(unsigned int line){
  for(auto position = buffer + width * line; position < (buffer + width * (line + 1)); ++position)
    {
      *position = 0;
    }
}

void Console::printk(const char* s)
{
  const uint16_t color = 7;

  while (*s != '\0'){

    if(x == 0) {
      clearLine(y);
    }

    const char current = *s++;

    switch(current)
      {
      case '\n':
        x = 0;
        ++y;
        break;
      default:
        buffer[x + y * width] = current | color << 8;
        ++x;
        break;
      }

    if(y >= lines)
      {
        x = 0;
        y = 0;
      }
        
    if(x >= width)
      {
        x = 0;
        ++y;
      }
  }
}
