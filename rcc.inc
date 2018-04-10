# -----------------------------------------------------------------------------
#
#   STM32F1 RCC
#
#   Copyright (c) 2015 Sean Stasiak. All rights reserved.
#   Developed by: Sean Stasiak <sstasiak@protonmail.com>
#   Refer to license terms in license.txt; In the absence of such a file,
#   contact me at the above email address and I can provide you with one.
#
# -----------------------------------------------------------------------------

    .set    RCC_BASE,               0x40021000

# -- CR -----------------------------------------------------------------------
    .set    RCC_CR_OFFSET,          0x00
    .set    RCC_CR,                 RCC_BASE + RCC_CR_OFFSET
    .set    CR_RESV_MASK,           0b11111100111100000000000000000100
    .set    CR_BIC_MASK,            ~CR_RESV_MASK
    .set    PLLRDY,                 (0b1<<25)
    .set    PLLON,                  (0b1<<24)
    .set    CSSON,                  (0b1<<19)
    .set    HSEBYP,                 (0b1<<18)
    .set    HSERDY,                 (0b1<<17)
    .set    HSEON,                  (0b1<<16)
    .set    HSICAL,                 (0b11111111<<8)     /**< masks           */
    .set    HSITRIM,                (0b11111<<3)        /**                  */
    .set    HSIRDY,                 (0b1<< 1)
    .set    HSION,                  (0b1<< 0)

# -- CFGR ---------------------------------------------------------------------
    .set    RCC_CFGR_OFFSET,        0x04
    .set    RCC_CFGR,               RCC_BASE + RCC_CFGR_OFFSET
    .set    CFGR_RESV_MASK,         0b11111000100000000000000000000000
    .set    CFGR_BIC_MASK,          ~CFGR_RESV_MASK
    .set    MCO_NONE,               ( 0b000<<24)
    .set    MCO_SYSCLK,             ( 0b100<<24)
    .set    MCO_HSI,                ( 0b101<<24)
    .set    MCO_HSE,                ( 0b110<<24)
    .set    MCO_PLLDIV2,            ( 0b111<<24)
    .set    USBPRE_PLLDIV1,         (   0b1<<22)
    .set    PLLMUL_x2,              (0b0000<<18)
    .set    PLLMUL_x3,              (0b0001<<18)
    .set    PLLMUL_x4,              (0b0010<<18)
    .set    PLLMUL_x5,              (0b0011<<18)
    .set    PLLMUL_x6,              (0b0100<<18)
    .set    PLLMUL_x7,              (0b0101<<18)
    .set    PLLMUL_x8,              (0b0110<<18)
    .set    PLLMUL_x9,              (0b0111<<18)
    .set    PLLMUL_x10,             (0b1000<<18)
    .set    PLLMUL_x11,             (0b1001<<18)
    .set    PLLMUL_x12,             (0b1010<<18)
    .set    PLLMUL_x13,             (0b1011<<18)
    .set    PLLMUL_x14,             (0b1100<<18)
    .set    PLLMUL_x15,             (0b1101<<18)
    .set    PLLMUL_x16,             (0b1110<<18)
    .set    PLLXTPRE_HSEDIV1,       (   0b0<<17)
    .set    PLLXTPRE_HSEDIV2,       (   0b1<<17)
    .set    PLLSRC_HSIDIV2,         (   0b0<<16)
    .set    PLLSRC_HSE,             (   0b1<<16)
    .set    ADCPRE_PCLK2DIV2,       (  0b00<<14)
    .set    ADCPRE_PCLK2DIV4,       (  0b01<<14)
    .set    ADCPRE_PCLK2DIV6,       (  0b10<<14)
    .set    ADCPRE_PCLK2DIV8,       (  0b11<<14)
    .set    PPRE2_HCLKDIV1,         ( 0b000<<11)
    .set    PPRE2_HCLKDIV2,         ( 0b100<<11)
    .set    PPRE2_HCLKDIV4,         ( 0b101<<11)
    .set    PPRE2_HCLKDIV8,         ( 0b110<<11)
    .set    PPRE2_HCLKDIV16,        ( 0b111<<11)
    .set    PPRE1_HCLKDIV1,         ( 0b000<< 8)
    .set    PPRE1_HCLKDIV2,         ( 0b100<< 8)
    .set    PPRE1_HCLKDIV4,         ( 0b101<< 8)
    .set    PPRE1_HCLKDIV8,         ( 0b110<< 8)
    .set    PPRE1_HCLKDIV16,        ( 0b111<< 8)
    .set    HPRE_SYSCLKDIV1,        (0b0000<< 4)
    .set    HPRE_SYSCLKDIV2,        (0b1000<< 4)
    .set    HPRE_SYSCLKDIV4,        (0b1001<< 4)
    .set    HPRE_SYSCLKDIV8,        (0b1010<< 4)
    .set    HPRE_SYSCLKDIV16,       (0b1011<< 4)
    .set    HPRE_SYSCLKDIV64,       (0b1100<< 4)
    .set    HPRE_SYSCLKDIV128,      (0b1101<< 4)
    .set    HPRE_SYSCLKDIV256,      (0b1110<< 4)
    .set    HPRE_SYSCLKDIV512,      (0b1111<< 4)
    .set    SWS_HSI,                (  0b00<< 2)
    .set    SWS_HSE,                (  0b01<< 2)
    .set    SWS_PLL,                (  0b10<< 2)
    .set    SW_HSI,                 (  0b00<< 0)
    .set    SW_HSE,                 (  0b01<< 0)
    .set    SW_PLL,                 (  0b10<< 0)

# -- CIR ----------------------------------------------------------------------
    .set    RCC_CIR_OFFSET,         0x08
    .set    RCC_CIR,                RCC_BASE + RCC_CIR_OFFSET
    .set    CIR_RESV_MASK,          0b11111111011000001110000001100000
    .set    CIR_BIC_MASK,           ~CIR_RESV_MASK

# --     RSTR -----------------------------------------------------------------
# -- APB2RSTR -----------------------------------------------------------------
    .set    RCC_APB2RSTR_OFFSET,    0x0C
    .set    RCC_APB2RSTR,           RCC_BASE + RCC_APB2RSTR_OFFSET
    .set    APB2RSTR_RESV_MASK,     0b11111111110001110000000000000010
    .set    APB2RSTR_BIC_MASK,      ~APB2RSTR_RESV_MASK

# -- APB1RSTR -----------------------------------------------------------------
    .set    RCC_APB1RSTR_OFFSET,    0x10
    .set    RCC_APB1RSTR,           RCC_BASE + RCC_APB1RSTR_OFFSET
    .set    APB1RSTR_RESV_MASK,     0b11000101000000010011011000000000
    .set    APB1RSTR_BIC_MASK,      ~APB1RSTR_RESV_MASK

# --    ENR -------------------------------------------------------------------
# -- AHBENR -------------------------------------------------------------------
    .set    RCC_AHBENR_OFFSET,      0x14
    .set    RCC_AHBENR,             RCC_BASE + RCC_AHBENR_OFFSET
    .set    AHBENR_RESV_MASK,       0b11111111111111111111101010101000
    .set    AHBENR_BIC_MASK,        ~AHBENR_RESV_MASK
    .set    SDIOEN,                 (0b1<<10)
    .set    FSMCEN,                 (0b1<< 8)
    .set    CRCEN,                  (0b1<< 6)
    .set    FLITFEN,                (0b1<< 4)
    .set    SRAMEN,                 (0b1<< 2)
    .set    DMA2EN,                 (0b1<< 1)
    .set    DMA1EN,                 (0b1<< 0)

# -- APB2ENR ------------------------------------------------------------------
    .set    RCC_APB2ENR_OFFSET,     0x18
    .set    RCC_APB2ENR,            RCC_BASE + RCC_APB2ENR_OFFSET
    .set    APB2ENR_RESV_MASK,      0b11111111110001110000000000000010
    .set    APB2ENR_BIC_MASK,       ~APB2ENR_RESV_MASK
    .set    TIM11EN,                (0b1<<21)
    .set    TIM10EN,                (0b1<<20)
    .set    TIM9EN,                 (0b1<<19)
    .set    ADC3EN,                 (0b1<<15)
    .set    USART1EN,               (0b1<<14)
    .set    TIM8EN,                 (0b1<<13)
    .set    SPI1EN,                 (0b1<<12)
    .set    TIM1EN,                 (0b1<<11)
    .set    ADC2EN,                 (0b1<<10)
    .set    ADC1EN,                 (0b1<< 9)
    .set    IOPGEN,                 (0b1<< 8)
    .set    IOPFEN,                 (0b1<< 7)
    .set    IOPEEN,                 (0b1<< 6)
    .set    IOPDEN,                 (0b1<< 5)
    .set    IOPCEN,                 (0b1<< 4)
    .set    IOPBEN,                 (0b1<< 3)
    .set    IOPAEN,                 (0b1<< 2)
    .set    AFIOEN,                 (0b1<< 0)

# -- APB1ENR ------------------------------------------------------------------
    .set    RCC_APB1ENR_OFFSET,     0x1C
    .set    RCC_APB1ENR,            RCC_BASE + RCC_APB1ENR_OFFSET
    .set    APB1ENR_RESV_MASK,      0b11000101000000010011011000000000
    .set    APB1ENR_BIC_MASK,       ~APB1ENR_RESV_MASK
    .set    DACEN,                  (0b1<<29)
    .set    PWREN,                  (0b1<<28)
    .set    BKPEN,                  (0b1<<27)
    .set    CANEN,                  (0b1<<25)
    .set    USBEN,                  (0b1<<23)
    .set    I2C2EN,                 (0b1<<22)
    .set    I2C1EN,                 (0b1<<21)
    .set    UART5EN,                (0b1<<20)
    .set    UART4EN,                (0b1<<19)
    .set    USART3EN,               (0b1<<18)
    .set    USART2EN,               (0b1<<17)
    .set    SPI3EN,                 (0b1<<15)
    .set    SPI2EN,                 (0b1<<14)
    .set    WWDGEN,                 (0b1<<11)
    .set    TIM14EN,                (0b1<< 8)
    .set    TIM13EN,                (0b1<< 7)
    .set    TIM12EN,                (0b1<< 6)
    .set    TIM7EN,                 (0b1<< 5)
    .set    TIM6EN,                 (0b1<< 4)
    .set    TIM5EN,                 (0b1<< 3)
    .set    TIM4EN,                 (0b1<< 2)
    .set    TIM3EN,                 (0b1<< 1)
    .set    TIM2EN,                 (0b1<< 0)

# -- BDCR ---------------------------------------------------------------------
    .set    RCC_BDCR_OFFSET,        0x20
    .set    RCC_BDCR,               RCC_BASE + RCC_BDCR_OFFSET
    .set    BDCR_RESV_MASK,         0b11111111111111100111110011111000
    .set    BDCR_BIC_MASK,          ~BDCR_RESV_MASK
    .set    BDRST,                  ( 0b1<<16)
    .set    RTCEN,                  ( 0b1<<15)
    .set    RTCSEL_NONE,            (0b00<< 8)
    .set    RTCSEL_LSE,             (0b01<< 8)
    .set    RTCSEL_LSI,             (0b10<< 8)
    .set    RTCSEL_HSE,             (0b11<< 8)
    .set    LSEBYP,                 ( 0b1<< 2)
    .set    LSERDY,                 ( 0b1<< 1)
    .set    LSEON,                  ( 0b1<< 0)

# -- CSR ----------------------------------------------------------------------
    .set    RCC_CSR_OFFSET,         0x24
    .set    RCC_CSR,                RCC_BASE + RCC_CSR_OFFSET
    .set    CSR_RESV_MASK,          0b00000010111111111111111111111100
    .set    CSR_BIC_MASK,           ~CSR_RESV_MASK
    .set    LPWRRSTF,               (0b1<<31)
    .set    WWDGRSTF,               (0b1<<30)
    .set    IWDGRSTF,               (0b1<<29)
    .set    SFTRSTF,                (0b1<<28)
    .set    PORRSTF,                (0b1<<27)
    .set    PINRSTF,                (0b1<<26)
    .set    RMVF,                   (0b1<<24)
    .set    LSIRDY,                 (0b1<< 1)
    .set    LSION,                  (0b1<< 0)
