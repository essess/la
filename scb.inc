# -----------------------------------------------------------------------------
#
#   STM32F1 SCB
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .set    SCB_BASE,               0xE000ED00

# -- ACTLR --------------------------------------------------------------------
    .set    SCB_ACTLR_OFFSET,       -0x0CF8   /* @0xE000E008 */
    .set    SCB_ACTLR,              SCB_BASE + SCB_ACTLR_OFFSET

# -- CPUID --------------------------------------------------------------------
    .set    SCB_CPUID_OFFSET,       0x00
    .set    SCB_CPUID,              SCB_BASE + SCB_CPUID_OFFSET

# -- ICSR ---------------------------------------------------------------------
    .set    SCB_ICSR_OFFSET,        0x04
    .set    SCB_ICSR,               SCB_BASE + SCB_ICSR_OFFSET

# -- VTOR ---------------------------------------------------------------------
    .set    SCB_VTOR_OFFSET,        0x08
    .set    SCB_VTOR,               SCB_BASE + SCB_VTOR_OFFSET

# -- AIRCR --------------------------------------------------------------------
    .set    SCB_AIRCR_OFFSET,       0x0C
    .set    SCB_AIRCR,              SCB_BASE + SCB_AIRCR_OFFSET
