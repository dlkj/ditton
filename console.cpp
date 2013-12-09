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

void Console::scrollBuffer(){
  auto position = buffer;
  while(position < buffer + width * (lines - 1))
    {
      *position = *(position + width);
      ++position;
    }
  while(position < buffer + (width * lines))
    {
      *position++ = 0;
    }
}

void Console::printk(const char* s)
{
  const uint16_t color = 7;

  while (*s != '\0'){

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

    while(y >= lines)
      {
        x = 0;
        --y;
        scrollBuffer();
      }
        
    if(x >= width)
      {
        x = 0;
        ++y;
      }
  }
}
