#include <stddef.h>
#include <stdint.h>

#include "console.h"

#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

extern "C"
void kernel_main()
{

  Console console;
  
  console.clear();
  console.printk("Hello, world!");
}
