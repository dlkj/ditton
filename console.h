#pragma once

#include <stddef.h>
#include <stdint.h>

class Console {
private:

  const volatile uint16_t* buffer;
  const uint32_t width = 80;
  const uint32_t lines = 25;

  uint32_t x = 0;
  uint32_t y = 0;

public:
  Console(volatile uint16_t* buffer);
  Console();

  void clear();
  void printk(const char* s);
};
