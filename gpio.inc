# -----------------------------------------------------------------------------
#
#   STM32F1 GPIO
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .set    GPIO_BASE,              0x40010800

# -- GPIO Bits ----------------------------------------------------------------
    .set    MODE_IN,                0b00    /**< Input (reset)               */
    .set    MODE_OUT_10MHZ,         0b01    /**< Output @10MHz               */
    .set    MODE_OUT_2MHZ,          0b10    /**<        @2MHz                */
    .set    MODE_OUT_50MHZ,         0b11    /**<        @50MHz               */

    .set    CNF_IN_ANA,             0b00    /**< Input mode configs          */
    .set    CNF_IN_FLOAT,           0b01    /**        (reset)               */
    .set    CNF_IN_PULL,            0b10    /**                              */
    .set    CNF_IN_RESV,            0b11    /**                              */
    .set    CNF_OUT_PP,             0b00    /**< Output mode configs         */
    .set    CNF_OUT_OD,             0b01    /**                              */
    .set    CNF_OUT_AFPP,           0b10    /**                              */
    .set    CNF_OUT_AFOD,           0b11    /**                              */

# -- GPIO ---------------------------------------------------------------------
    .set    GPIOA_BASE_OFFSET,      0x0000
    .set    GPIOA_BASE,             GPIO_BASE + GPIOA_BASE_OFFSET
    .set    GPIOB_BASE_OFFSET,      0x0400
    .set    GPIOB_BASE,             GPIO_BASE + GPIOB_BASE_OFFSET
    .set    GPIOC_BASE_OFFSET,      0x0800
    .set    GPIOC_BASE,             GPIO_BASE + GPIOC_BASE_OFFSET
    .set    GPIOD_BASE_OFFSET,      0x0C00
    .set    GPIOD_BASE,             GPIO_BASE + GPIOD_BASE_OFFSET
    .set    GPIOE_BASE_OFFSET,      0x1000
    .set    GPIOE_BASE,             GPIO_BASE + GPIOE_BASE_OFFSET
    .set    GPIOF_BASE_OFFSET,      0x1400
    .set    GPIOF_BASE,             GPIO_BASE + GPIOF_BASE_OFFSET
    .set    GPIOG_BASE_OFFSET,      0x1800
    .set    GPIOG_BASE,             GPIO_BASE + GPIOG_BASE_OFFSET

    .set    GPIOx_CRL_OFFSET,       0x00    /**< use MODE_/CNF_IN_/CNF_OUT_  */
    .set    GPIOx_CRH_OFFSET,       0x04    /**                              */
    .set    GPIOx_IDR_OFFSET,       0x08
    .set    GPIOx_ODR_OFFSET,       0x0C
    .set    GPIOx_BSRR_OFFSET,      0x10
    .set    GPIOx_BRR_OFFSET,       0x14
    .set    GPIOx_LCKR_OFFSET,      0x18

# -- GPIOA --------------------------------------------------------------------
    .set    GPIOA_CRL,              GPIOA_BASE + GPIOx_CRL_OFFSET
    .set    GPIOA_CRH,              GPIOA_BASE + GPIOx_CRH_OFFSET
    .set    GPIOA_IDR,              GPIOA_BASE + GPIOx_IDR_OFFSET
    .set    GPIOA_ODR,              GPIOA_BASE + GPIOx_ODR_OFFSET
    .set    GPIOA_BSRR,             GPIOA_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOA_BRR,              GPIOA_BASE + GPIOx_BRR_OFFSET
    .set    GPIOA_LCKR,             GPIOA_BASE + GPIOx_LCKR_OFFSET

# -- GPIOB --------------------------------------------------------------------
    .set    GPIOB_CRL,              GPIOB_BASE + GPIOx_CRL_OFFSET
    .set    GPIOB_CRH,              GPIOB_BASE + GPIOx_CRH_OFFSET
    .set    GPIOB_IDR,              GPIOB_BASE + GPIOx_IDR_OFFSET
    .set    GPIOB_ODR,              GPIOB_BASE + GPIOx_ODR_OFFSET
    .set    GPIOB_BSRR,             GPIOB_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOB_BRR,              GPIOB_BASE + GPIOx_BRR_OFFSET
    .set    GPIOB_LCKR,             GPIOB_BASE + GPIOx_LCKR_OFFSET

# -- GPIOC --------------------------------------------------------------------
    .set    GPIOC_CRL,              GPIOC_BASE + GPIOx_CRL_OFFSET
    .set    GPIOC_CRH,              GPIOC_BASE + GPIOx_CRH_OFFSET
    .set    GPIOC_IDR,              GPIOC_BASE + GPIOx_IDR_OFFSET
    .set    GPIOC_ODR,              GPIOC_BASE + GPIOx_ODR_OFFSET
    .set    GPIOC_BSRR,             GPIOC_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOC_BRR,              GPIOC_BASE + GPIOx_BRR_OFFSET
    .set    GPIOC_LCKR,             GPIOC_BASE + GPIOx_LCKR_OFFSET

# -- GPIOD --------------------------------------------------------------------
    .set    GPIOD_CRL,              GPIOD_BASE + GPIOx_CRL_OFFSET
    .set    GPIOD_CRH,              GPIOD_BASE + GPIOx_CRH_OFFSET
    .set    GPIOD_IDR,              GPIOD_BASE + GPIOx_IDR_OFFSET
    .set    GPIOD_ODR,              GPIOD_BASE + GPIOx_ODR_OFFSET
    .set    GPIOD_BSRR,             GPIOD_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOD_BRR,              GPIOD_BASE + GPIOx_BRR_OFFSET
    .set    GPIOD_LCKR,             GPIOD_BASE + GPIOx_LCKR_OFFSET

# -- GPIOE --------------------------------------------------------------------
    .set    GPIOE_CRL,              GPIOE_BASE + GPIOx_CRL_OFFSET
    .set    GPIOE_CRH,              GPIOE_BASE + GPIOx_CRH_OFFSET
    .set    GPIOE_IDR,              GPIOE_BASE + GPIOx_IDR_OFFSET
    .set    GPIOE_ODR,              GPIOE_BASE + GPIOx_ODR_OFFSET
    .set    GPIOE_BSRR,             GPIOE_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOE_BRR,              GPIOE_BASE + GPIOx_BRR_OFFSET
    .set    GPIOE_LCKR,             GPIOE_BASE + GPIOx_LCKR_OFFSET

# -- GPIOF --------------------------------------------------------------------
    .set    GPIOF_CRL,              GPIOF_BASE + GPIOx_CRL_OFFSET
    .set    GPIOF_CRH,              GPIOF_BASE + GPIOx_CRH_OFFSET
    .set    GPIOF_IDR,              GPIOF_BASE + GPIOx_IDR_OFFSET
    .set    GPIOF_ODR,              GPIOF_BASE + GPIOx_ODR_OFFSET
    .set    GPIOF_BSRR,             GPIOF_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOF_BRR,              GPIOF_BASE + GPIOx_BRR_OFFSET
    .set    GPIOF_LCKR,             GPIOF_BASE + GPIOx_LCKR_OFFSET

# -- GPIOG --------------------------------------------------------------------
    .set    GPIOG_CRL,              GPIOG_BASE + GPIOx_CRL_OFFSET
    .set    GPIOG_CRH,              GPIOG_BASE + GPIOx_CRH_OFFSET
    .set    GPIOG_IDR,              GPIOG_BASE + GPIOx_IDR_OFFSET
    .set    GPIOG_ODR,              GPIOG_BASE + GPIOx_ODR_OFFSET
    .set    GPIOG_BSRR,             GPIOG_BASE + GPIOx_BSRR_OFFSET
    .set    GPIOG_BRR,              GPIOG_BASE + GPIOx_BRR_OFFSET
    .set    GPIOG_LCKR,             GPIOG_BASE + GPIOx_LCKR_OFFSET
