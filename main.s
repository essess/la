# -----------------------------------------------------------------------------
#
#   Langton's Ant: [https://www.youtube.com/watch?v=NWBToaXK5T0]
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .include    "gpio.inc"

    .syntax     unified

# -----------------------------------------------------------------------------
#   @public
#   the 'meat' - on entry r12 contains GPIO_BASE
# -----------------------------------------------------------------------------
    .section    .text.main
    .func       main
    .global     main
    .align
main:
    ldr         r0, [r12, GPIOC_BASE_OFFSET+GPIOx_ODR_OFFSET]
toggle:
    eors        r0, #1<<13
    str         r0, [r12, GPIOC_BASE_OFFSET+GPIOx_ODR_OFFSET]
    b           toggle
    .endfunc
# -----------------------------------------------------------------------------
    .end
