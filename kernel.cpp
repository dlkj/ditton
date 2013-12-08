#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

extern "C"
void kernel_main()
{
  uint16_t* terminalBuffer = (uint16_t*) 0xB8000;
  terminalBuffer[0] = 'H' | 15 << 8;
  terminalBuffer[1] = 'e' | 15 << 8;
  terminalBuffer[2] = 'l' | 15 << 8;
  terminalBuffer[3] = 'l' | 15 << 8;
  terminalBuffer[4] = 'o' | 15 << 8;
  terminalBuffer[5] = ',' | 15 << 8;
  terminalBuffer[6] = ' ' | 15 << 8;
  terminalBuffer[7] = 'w' | 15 << 8;
  terminalBuffer[8] = 'o' | 15 << 8;
  terminalBuffer[9] = 'r' | 15 << 8;
  terminalBuffer[10] = 'l' | 15 << 8;
  terminalBuffer[11] = 'd' | 15 << 8;
  terminalBuffer[12] = '!' | 15 << 8;
}
