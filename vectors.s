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

    .extern     __stack_start__
    .extern     start

# -----------------------------------------------------------------------------
    .section    .vectors, "a"
                                    /*   description:                        */
    .word       __stack_start__     /**< inital msp value                    */
    .word       start               /**< reset                               */
    .word       nmi                 /**< nmi, css                            */
    .word       hflt                /**< hard fault                          */
    .word       memmng              /**< mem manager                         */
    .word       busfault            /**< bus fault                           */
    .word       usagefault          /**< usage fault                         */
    .word       defhnd              /**< -+- reserved                        */
    .word       defhnd              /**<  |                                  */
    .word       defhnd              /**<  |                                  */
    .word       defhnd              /**< -+                                  */
    .word       svccall             /**< system service call                 */
    .word       dbgmon              /**< debug monitor                       */
    .word       defhnd              /**< reserved                            */
    .word       pendsvc             /**< pend service request                */
    .word       systick             /**< system tick                         */
    .word       wwdg                /**< windowed watchdog                   */
    .word       pvd                 /**< PVD [EXTI16]                        */
    .word       tamper              /**< tamper detect                       */
    .word       rtc                 /**< RTC                                 */
    .word       flash               /**< FLASH                               */
    .word       rcc                 /**< RCC                                 */
    .word       exti0               /**< EXTI line 0                         */
    .word       exti1               /**< EXTI line 1                         */
    .word       exti2               /**< EXTI line 2                         */
    .word       exti3               /**< EXTI line 3                         */
    .word       exti4               /**< EXTI line 4                         */
    .word       dma1ch1             /**< DMA1 channel 1                      */
    .word       dma1ch2             /**< DMA1 channel 2                      */
    .word       dma1ch3             /**< DMA1 channel 3                      */
    .word       dma1ch4             /**< DMA1 channel 4                      */
    .word       dma1ch5             /**< DMA1 channel 5                      */
    .word       dma1ch6             /**< DMA1 channel 6                      */
    .word       dma1ch7             /**< DMA1 channel 7                      */
    .word       adc                 /**< ADC1/2                              */
    .word       usbhp_cantx         /**< USB High Priority/CAN1 TX           */
    .word       usblp_canrx0        /**< USB Low Prority/CAN1 RX0            */
    .word       canrx1              /**< CAN1 RX1                            */
    .word       cansce              /**< CAN1 SCE                            */
    .word       exti95              /**< EXTI line[9:5]                      */
    .word       tim1brk             /**< TIM1 break                          */
    .word       tim1upd             /**< TIM1 update                         */
    .word       tim1trgcom          /**< TIM1 trig/commutation               */
    .word       tim1cc              /**< TIM1 capture/compare                */
    .word       tim2                /**< TIM2                                */
    .word       tim3                /**< TIM3                                */
    .word       tim4                /**< TIM4                                */
    .word       i2c1ev              /**< I2C1 event                          */
    .word       i2c1er              /**< I2C1 error                          */
    .word       i2c2ev              /**< I2C2 event                          */
    .word       i2c2er              /**< I2C2 error                          */
    .word       spi1                /**< SPI1                                */
    .word       spi2                /**< SPI2                                */
    .word       usart1              /**< USART1                              */
    .word       usart2              /**< USART2                              */
    .word       usart3              /**< USART3                              */
    .word       exti1510            /**< EXTI line[15:10]                    */
    .word       rtcalarm            /**< RTC alarm [EXTI17]                  */
    .word       usbwkup             /**< USB wakeup [EXTI18]                 */
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
    .weak       nmi
    .thumb_set  nmi, defhnd

    .weak       hflt
    .thumb_set  hflt, defhnd

    .weak       memmng
    .thumb_set  memmng, defhnd

    .weak       busfault
    .thumb_set  busfault, defhnd

    .weak       usagefault
    .thumb_set  usagefault, defhnd

    .weak       svccall
    .thumb_set  svccall, defhnd

    .weak       dbgmon
    .thumb_set  dbgmon, defhnd

    .weak       pendsvc
    .thumb_set  pendsvc, defhnd

    .weak       systick
    .thumb_set  systick, defhnd

    .weak       wwdg
    .thumb_set  wwdg, defhnd

    .weak       pvd
    .thumb_set  pvd, defhnd

    .weak       tamper
    .thumb_set  tamper, defhnd

    .weak       rtc
    .thumb_set  rtc, defhnd

    .weak       flash
    .thumb_set  flash, defhnd

    .weak       rcc
    .thumb_set  rcc, defhnd

    .weak       exti0
    .thumb_set  exti0, defhnd

    .weak       exti1
    .thumb_set  exti1, defhnd

    .weak       exti2
    .thumb_set  exti2, defhnd

    .weak       exti3
    .thumb_set  exti3, defhnd

    .weak       exti4
    .thumb_set  exti4, defhnd

    .weak       dma1ch1
    .thumb_set  dma1ch1, defhnd

    .weak       dma1ch2
    .thumb_set  dma1ch2, defhnd

    .weak       dma1ch3
    .thumb_set  dma1ch3, defhnd

    .weak       dma1ch4
    .thumb_set  dma1ch4, defhnd

    .weak       dma1ch5
    .thumb_set  dma1ch5, defhnd

    .weak       dma1ch6
    .thumb_set  dma1ch6, defhnd

    .weak       dma1ch7
    .thumb_set  dma1ch7, defhnd

    .weak       adc
    .thumb_set  adc, defhnd

    .weak       usbhp_cantx
    .thumb_set  usbhp_cantx, defhnd

    .weak       usblp_canrx0
    .thumb_set  usblp_canrx0, defhnd

    .weak       canrx1
    .thumb_set  canrx1, defhnd

    .weak       cansce
    .thumb_set  cansce, defhnd

    .weak       exti95
    .thumb_set  exti95, defhnd

    .weak       tim1brk
    .thumb_set  tim1brk, defhnd

    .weak       tim1upd
    .thumb_set  tim1upd, defhnd

    .weak       tim1trgcom
    .thumb_set  tim1trgcom, defhnd

    .weak       tim1cc
    .thumb_set  tim1cc, defhnd

    .weak       tim2
    .thumb_set  tim2, defhnd

    .weak       tim3
    .thumb_set  tim3, defhnd

    .weak       tim4
    .thumb_set  tim4, defhnd

    .weak       i2c1ev
    .thumb_set  i2c1ev, defhnd

    .weak       i2c1er
    .thumb_set  i2c1er, defhnd

    .weak       i2c2ev
    .thumb_set  i2c2ev, defhnd

    .weak       i2c2er
    .thumb_set  i2c2er, defhnd

    .weak       spi1
    .thumb_set  spi1, defhnd

    .weak       spi2
    .thumb_set  spi2, defhnd

    .weak       usart1
    .thumb_set  usart1, defhnd

    .weak       usart2
    .thumb_set  usart2, defhnd

    .weak       usart3
    .thumb_set  usart3, defhnd

    .weak       exti1510
    .thumb_set  exti1510, defhnd

    .weak       rtcalarm
    .thumb_set  rtcalarm, defhnd

    .weak       usbwkup
    .thumb_set  usbwkup, defhnd
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
#   default int handler
# -----------------------------------------------------------------------------
    .section    .text.defhnd
    .global     defhnd
    .func       defhnd
    .align
    .thumb_func
defhnd:
    bkpt        #0                  /**< TODO: hard reset                    */
    .endfunc
# -----------------------------------------------------------------------------
    .end
