_e_stack = ORIGIN(RAM) + LENGTH(RAM);

MEMORY
{
    RAM     (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH   (xr)  : ORIGIN = 0x08000000, LENGTH = 256K
}

SECTIONS
{
    .isr_vector :
    {
        *(.isr_vector)
        *(.isr_vector*)
    } > FLASH

    .text :
    {
        *(.init)
        *(.init*)
        *(.text)
        *(.text*)
    } > FLASH

    .rodata :
    {
        *(.rodata)
        *(.rodata*)
    } > FLASH

    _s_data_FLASH = LOADADDR(.data);

    .data :
    {
        _s_data = .;
        *(.data)
        *(.data*)
        _e_data = .;
    } > RAM AT> FLASH

    .bss :
    {
        _s_bss = .;
        *(.bss)
        *(.bss*)
        _e_bss = .;
    } > RAM

}

