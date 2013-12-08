#pragma once

#include <stddef.h>
#include <stdint.h>

class Console {
private:

  volatile uint16_t * const buffer;
  const uint32_t width = 80;
  const uint32_t lines = 25;

  uint32_t x = 0;
  uint32_t y = 0;

public:
  Console(volatile uint16_t* const buffer);
  Console();

  void clear();
  void printk(const char* s);
};
