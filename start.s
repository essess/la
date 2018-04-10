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
    .include    "rcc.inc"
    .include    "afio.inc"
    .include    "flash.inc"
    .include    "scb.inc"

    .extern     main

    .syntax     unified

# -----------------------------------------------------------------------------
#   @public
#   entry point
# -----------------------------------------------------------------------------
    .section    .text.start
    .func       start
    .global     start
    .align
    .thumb_func
start:
    ldr         r11, =RCC_BASE                  /**< setup PLL               */
    ldr         r0, =(PLLSRC_HSE|PLLMUL_x9|PPRE1_HCLKDIV2|ADCPRE_PCLK2DIV6)
    str         r0, [r11, RCC_CFGR_OFFSET]
    ldr         r0, [r11, RCC_CR_OFFSET]        /**< kickoff HSE/PLL         */
    ldr         r1, =(PLLON|HSEON)
    orrs        r0, r1
    str         r0, [r11, RCC_CR_OFFSET]
    ldr         r0, =(FLITFEN|SRAMEN)           /**< route peripheral clocks */
    str         r0, [r11, RCC_AHBENR_OFFSET]
    ldr         r0, =(PWREN|BKPEN)
    str         r0, [r11, RCC_APB1ENR_OFFSET]
    ldr         r0, =(IOPCEN|IOPAEN|AFIOEN)
    str         r0, [r11, RCC_APB2ENR_OFFSET]
    ldr         r10, =AFIO_BASE                 /**< free up unused dbg pins */
    ldr         r0, =(0b010<<24)
    str         r0, [r10, AFIO_MAPR_OFFSET]
    ldr         r12, =GPIO_BASE                 /**< setup PC13 LED ...      */
    ldr         r0, =((CNF_IN_FLOAT<<30)|(MODE_IN<<28)|(CNF_IN_FLOAT<<26)|(MODE_IN<<24)|(CNF_OUT_OD<<22)|(MODE_OUT_2MHZ<<20)|(CNF_IN_FLOAT<<18)|(MODE_IN<<16)|(CNF_IN_FLOAT<<14)|(MODE_IN<<12)|(CNF_IN_FLOAT<<10)|(MODE_IN<< 8)|(CNF_IN_FLOAT<< 6)|(MODE_IN<< 4)|(CNF_IN_FLOAT<< 2)|(MODE_IN<< 0))
    str         r0, [r12, GPIOC_BASE_OFFSET+GPIOx_CRH_OFFSET]
    ldr         r0, =__bss_start__          /**< clear bss - guaranteed word */
    eors        r1, r1                      /*   aligned and mod 4 by linker */
    ldr         r2, =__bss_end__            /*   script                      */
1:  cmp         r0, r2
    itt         lt
    strlt       r1, [r0], #4
    blt         1b
    ldr         r0, =__data_load_start__    /**< copyup data - also aligned  */
    ldr         r1, =__data_start__         /*   and mod 4                   */
    ldr         r2, =__data_load_end__
1:  cmp         r0, r2
    ittt        lt
    ldrlt       r3, [r0], #4
    strlt       r3, [r1], #4
    blt         1b
    ldr         r0, =__ram_vectors_start__  /**< copyup vectors ..           */
    ldr         r1, =__vectors_end__
    ldr         r2, =__ram_vectors_end__
1:  cmp         r0, r2
    ittt        lt
    ldrlt       r3, [r1, #-4]!
    strlt       r3, [r2, #-4]!
    blt         1b
    ldr         r9, =SCB_BASE               /*   .. and set new vector base  */
    str         r0, [r9, SCB_VTOR_OFFSET]
    movw        r0, #(400*2)                /**< ~8cycles per chk loop @ HSI */
lock_wait:                                  /*   ~400us typ for HSE and PLL  */
    cbz         r0, lock_fail               /*   to stabilize                */
    subs        r0, #1
    ldr         r1, [r11, #RCC_CR_OFFSET]
    tst         r1, #PLLRDY
    beq         lock_wait
lock_ok:
    ldr         r0, =FLASH_ACR                  /**< 2ws for 72MHz flash ops */
    mov         r1, #LATENCY_2WS
    ldr         r2, [r0]
    orrs        r2, r1
    str         r2, [r0]
    ldr         r0, [r11, RCC_CFGR_OFFSET]      /**< switchover              */
    mov         r1, #SW_PLL
    orrs        r0, r1
    str         r0, [r11, RCC_CFGR_OFFSET]
    b           main
lock_fail:
    mov         r0, #(1<<13)                    /**< led off ...             */
    str         r0, [r12, GPIOC_BASE_OFFSET+GPIOx_BSRR_OFFSET]
    wfi                                         /*   ... sleep               */
    b           lock_fail
    .endfunc
# -----------------------------------------------------------------------------
    .end
