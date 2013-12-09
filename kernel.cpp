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

  for(auto i = 0U; i < 30; ++i)
    {
      console.printk("Hello, world!\n");
    }
}
