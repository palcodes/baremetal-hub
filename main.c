#define GPIOA_BASE 0x40020000
#define RCC_BASE 0x40023830

// We can write these using the offset
#define RCC_AHB1ENR *((volatile unsigned int *)0x40023830)
#define GPIOA_MODER *((volatile unsigned int *)0x40020000)
#define GPIOA_BSRR *((volatile unsigned int *)0x40020018)

int main() {

  // enable bit 0 of the RCC_AHB1ENR
  RCC_AHB1ENR |= (1 << 0);

  GPIOA_MODER &= ~(3 << 10);
  GPIOA_MODER |= (1 << 10);

  GPIOA_BSRR |= (1 << 5);
}
