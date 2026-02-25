// Forward declare the reset handler
void Reset_Handler(void);
void HardFault_Handler(void);
void Default_Handler(void);

// Vector table
// __attribute__((section(".vectors"))) tells the linker to place this in a specific section
// which your linker script will map to 0x08000000 (start of flash)
__attribute__((section(".vectors"))) void (*vector_table[])(void) = {
    (void (*)(void))0x20020000, // initial stack pointer (top of RAM, 128KB)
    Reset_Handler,              // reset
    Default_Handler,            // NMI
    HardFault_Handler,          // hardfault
    Default_Handler,            // memmanage
    Default_Handler,            // busfault
    Default_Handler,            // usagefault
    0,                          // reserved
    0,
    0,
    0,
    Default_Handler,            // SVcall
    Default_Handler,            // DebugMonitor
    0,
    Default_Handler,            // PendSV
    Default_Handler,            // SysTick
};

void Reset_Handler(void) {
    while(1);
}

void HardFault_Handler(void) {
    while(1);
}
