# -----------------------------------------------------------------------------
#
#   STM32F1 FLASH
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .set    FLASH_BASE,              0x40022000

# -- ACR ----------------------------------------------------------------------
    .set    FLASH_ACR_OFFSET,       0x00
    .set    FLASH_ACR,              FLASH_BASE + FLASH_ACR_OFFSET
    .set    ACR_RESV_MASK,          0b11111111111111111111111111000000
    .set    ACR_BIC_MASK,           ~ACR_RESV_MASK
    .set    PRFTBS,                 (  0b1<<5)
    .set    PRFTBE,                 (  0b1<<4)
    .set    HLFCYA,                 (  0b1<<3)
    .set    LATENCY_0WS,            (0b000<<0)
    .set    LATENCY_1WS,            (0b001<<0)
    .set    LATENCY_2WS,            (0b010<<0)
