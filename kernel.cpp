#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

class Console {
private:

  const volatile uint16_t* buffer;
  const uint32_t width = 80;
  const uint32_t lines = 25;

  uint32_t x = 0;
  uint32_t y = 0;

public:
  Console(volatile uint16_t* buffer):
    buffer(buffer)
  {
  }
  
  Console(): Console((volatile uint16_t*) 0xB8000)
  {
  }

  void clear(){
    for(volatile uint16_t* position = (volatile uint16_t*)buffer; position < buffer + width * lines; ++position)
      {
        *position = 0;
      }

  }

  void printk(const char* s)
  {
    volatile uint16_t* terminalBuffer = (volatile uint16_t*) 0xB8000;
    const uint16_t color = 7;

    while (*s != '\0'){
      *terminalBuffer++ = *s++ | color << 8;
    }
  }
};

extern "C"
void kernel_main()
{

  Console console;
  
  console.clear();
  console.printk("Hello, world!");
}
