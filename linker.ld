MEMORY
    {
        FLASH(rx):ORIGIN = 0x08000000, LENGTH = 512K
        SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 128K
    }

SECTIONS
    {
     /* Vector table must be first in flash */
        .vectors :
            {
                KEEP(*(.vectors))
            } > FLASH

    /* Program code and read only data */
        .text :
            {
                *(.text*)
                *(.rodata*)
                _etext = .;
            } > FLASH

    /* Initialized data copied from flash to RAM */
        .data :  AT(_etext)
            {
                _sdata = .;
                *(.data*)
                _edata = .;
                /* addr = LOADADDR(.data) */
           } > SRAM


    /* Zero initialized data */
        .bss  :
            {
                _sbss = .;
                *(.bss)
                _ebss = .;
            } > SRAM

    /* End of SRAM */
        _end = .;
    }
