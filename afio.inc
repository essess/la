# -----------------------------------------------------------------------------
#
#   STM32F1 AFIO
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .set    AFIO_BASE,              0x40010000

# -- EVCR ---------------------------------------------------------------------
    .set    AFIO_EVCR_OFFSET,       0x00
    .set    AFIO_EVCR,              AFIO_BASE + AFIO_EVCR_OFFSET
    .set    EVCR_RESV_MASK,         0b11111111111111111111111100000000
    .set    EVCR_BIC_MASK,          ~EVCR_RESV_MASK
    .set    EVOE,                   (   0b1<<7)
    .set    PORT_PA,                ( 0b000<<4)
    .set    PORT_PB,                ( 0b001<<4)
    .set    PORT_PC,                ( 0b010<<4)
    .set    PORT_PD,                ( 0b011<<4)
    .set    PORT_PE,                ( 0b100<<4)
    .set    PIN_0,                  (0b0000<<0)
    .set    PIN_1,                  (0b0001<<0)
    .set    PIN_2,                  (0b0010<<0)
    .set    PIN_3,                  (0b0011<<0)
    .set    PIN_4,                  (0b0100<<0)
    .set    PIN_5,                  (0b0101<<0)
    .set    PIN_6,                  (0b0110<<0)
    .set    PIN_7,                  (0b0111<<0)
    .set    PIN_8,                  (0b1000<<0)
    .set    PIN_9,                  (0b1001<<0)
    .set    PIN_10,                 (0b1010<<0)
    .set    PIN_11,                 (0b1011<<0)
    .set    PIN_12,                 (0b1100<<0)
    .set    PIN_13,                 (0b1101<<0)
    .set    PIN_14,                 (0b1110<<0)
    .set    PIN_15,                 (0b1111<<0)

# -- MAPR ---------------------------------------------------------------------
    .set    AFIO_MAPR_OFFSET,       0x04
    .set    AFIO_MAPR,              AFIO_BASE + AFIO_MAPR_OFFSET
    .set    MAPR_RESV_MASK,         0b11111000111000010000000000000000
    .set    MAPR_BIC_MASK,          ~MAPR_RESV_MASK
