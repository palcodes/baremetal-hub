ENTRY(Reset_Handler)

MEMORY
    {
        FLASH(rx):ORIGIN = 0x08000000, LENGTH = 512K
        SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 128K
    }

/* _estack = ORIGIN(SRAM) + LENGTH(SRAM); */

SECTIONS
    {
     /* Vector table must be first in flash */
        .vectors :
            {
                /* . = ALIGN(4); */
                KEEP(*(.vectors))
            } > FLASH

    /* Program code and read only data */
        .text :
            {
                /* . = ALIGN(4); */
                *(.text*)
                *(.rodata*)
                _etext = .;
            } > FLASH

    /* Initialized data copied from flash to RAM */
        .data :  AT(_etext)
            {
                /* . = ALIGN(4); */
                _sdata = .;
                *(.data*)
                _edata = .;
                /* addr = LOADADDR(.data) */
           } > SRAM


    /* Zero initialized data */
        .bss  :
            {
                /* . = ALIGN(4); */
                _sbss = .;
                *(.bss*)
                _ebss = .;
            } > SRAM

    /* End of SRAM */
        _end = .;
    }
