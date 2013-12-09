#pragma once

#include <stddef.h>
#include <stdint.h>

class Console {
private:

  volatile uint16_t * const buffer;
  const unsigned int width = 80U;
  const unsigned int lines = 25U;

  unsigned int x = 0U;
  unsigned int y = 0U;

  void clearLine(unsigned int line);


public:
  Console(volatile uint16_t* const buffer);
  Console();

  void clear();
  void printk(const char* s);
};
