#define GPIOA_BASE 0x40020000
#define RCC_BASE 0x40023800

// We can write these using the offset
#define RCC_AHB1ENR *((volatile unsigned int *)0x40023830)
#define GPIOA_MODER *((volatile unsigned int *)0x40020000)
#define GPIOA_BSRR *((volatile unsigned int *)0x40020018)
#define GPIOA_ODR *((volatile unsigned int *)0x40020014)
