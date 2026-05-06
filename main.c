#include "main.h"

int main() {
  // for (volatile unsigned int i = 0; i < 500000; i++)
  // ;

  // 1. Enable GPIOA clock
  RCC_AHB1ENR |= (1 << 0); // enable bit 0 of the RCC_AHB1ENR

  // 2. Configure GPIOA pin 5 (PA5) as output (MODER bits[11:10])
  GPIOA_MODER &= ~(3 << 10); // first we clear bits 11:10
  GPIOA_MODER |= (1 << 10);  // then we set bit 10 (output mode)

  // 3. Blink loop
  while (1) {
    GPIOA_ODR |= (1 << 5); // set PA5 high (turn on)
    for (volatile unsigned int i = 0; i < 500000; i++)
      ; // wait for 500,000 cycles
    GPIOA_ODR &= ~(1 << 5);
    for (volatile unsigned int i = 0; i < 500000; i++)
      ; // wait for 500,000 cycles
    // set PA5 low (upper 16 bits = reset)
  }
}
