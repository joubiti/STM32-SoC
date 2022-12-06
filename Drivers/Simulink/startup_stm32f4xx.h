/* GNU GCC startup file for STM32F4xx*/

/* Copyright 2013-2020 The MathWorks, Inc. */
#ifndef __STARTUP_STM32F4XX_H__
#define __STARTUP_STM32F4XX_H__

#ifdef USE_RTX
	#define __STACK_SIZE       512      /*!< Stack size (in Words)           */
#else
	#define __STACK_SIZE       2048      /*!< Stack size (in Words)           */
#endif

#ifndef STACK_SIZE
    #define STACK_SIZE 64
#endif


         
#ifdef __STARTUP_STM32F4XX_C__

#define WEAK __attribute__((weak))  

#if defined(__GNUC__) && !defined(__ARMCOMPILER_VERSION)

/* These symbols are defined in the linker command file */
	extern unsigned long _sidata; 
	extern unsigned long _sdata;
	extern unsigned long _edata;
	extern unsigned long _sbss; 
	extern unsigned long _ebss;  

	extern void _start(void);
		
#endif

/* External functions referenced in this startup file */
extern int main(void);
extern void SystemInit(void);
void ResetHandler(void);

/* Exception handlers */
void WEAK Reset_Handler(void);
void WEAK NMI_Handler(void);
void WEAK HardFault_Handler(void);
void WEAK MemManage_Handler(void);
void WEAK BusFault_Handler(void);
void WEAK UsageFault_Handler(void);
void WEAK SVC_Handler(void);
void WEAK DebugMon_Handler(void);
void WEAK PendSV_Handler(void);
void WEAK SysTick_Handler(void);
/* Peripheral interrupts */
void WEAK WWDG_IRQHandler(void);
void WEAK PVD_IRQHandler(void);
void WEAK TAMP_STAMP_IRQHandler(void);
void WEAK RTC_WKUP_IRQHandler(void);
void WEAK FLASH_IRQHandler(void);
void WEAK RCC_IRQHandler(void);
void WEAK EXTI0_IRQHandler(void);
void WEAK EXTI1_IRQHandler(void);
void WEAK EXTI2_IRQHandler(void);
void WEAK EXTI3_IRQHandler(void);
void WEAK EXTI4_IRQHandler(void);
void WEAK DMA1_Stream0_IRQHandler(void);
void WEAK DMA1_Stream1_IRQHandler(void);
void WEAK DMA1_Stream2_IRQHandler(void);
void WEAK DMA1_Stream3_IRQHandler(void);
void WEAK DMA1_Stream4_IRQHandler(void);
void WEAK DMA1_Stream5_IRQHandler(void);
void WEAK DMA1_Stream6_IRQHandler(void);
void WEAK ADC_IRQHandler(void);
void WEAK CAN1_TX_IRQHandler(void);
void WEAK CAN1_RX0_IRQHandler(void);
void WEAK CAN1_RX1_IRQHandler(void);
void WEAK CAN1_SCE_IRQHandler(void);
void WEAK EXTI9_5_IRQHandler(void);
void WEAK TIM1_BRK_TIM9_IRQHandler(void);
void WEAK TIM1_UP_TIM10_IRQHandler(void);
void WEAK TIM1_TRG_COM_TIM11_IRQHandler(void);
void WEAK TIM1_CC_IRQHandler(void);
void WEAK TIM2_IRQHandler(void);
void WEAK TIM3_IRQHandler(void);
void WEAK TIM4_IRQHandler(void);
void WEAK I2C1_EV_IRQHandler(void);
void WEAK I2C1_ER_IRQHandler(void);
void WEAK I2C2_EV_IRQHandler(void);
void WEAK I2C2_ER_IRQHandler(void);
void WEAK SPI1_IRQHandler(void);
void WEAK SPI2_IRQHandler(void);
void WEAK USART1_IRQHandler(void);
void WEAK USART2_IRQHandler(void);
void WEAK USART3_IRQHandler(void);
void WEAK EXTI15_10_IRQHandler(void);
void WEAK RTC_Alarm_IRQHandler(void);
void WEAK OTG_FS_WKUP_IRQHandler(void);
void WEAK TIM8_BRK_TIM12_IRQHandler(void);
void WEAK TIM8_UP_TIM13_IRQHandler(void);
void WEAK TIM8_TRG_COM_TIM14_IRQHandler(void);
void WEAK TIM8_CC_IRQHandler(void);
void WEAK DMA1_Stream7_IRQHandler(void);
void WEAK FSMC_IRQHandler(void);
void WEAK SDIO_IRQHandler(void);
void WEAK TIM5_IRQHandler(void);
void WEAK SPI3_IRQHandler(void);
void WEAK UART4_IRQHandler(void);
void WEAK UART5_IRQHandler(void);
void WEAK TIM6_DAC_IRQHandler(void);
void WEAK TIM7_IRQHandler(void);
void WEAK DMA2_Stream0_IRQHandler(void);
void WEAK DMA2_Stream1_IRQHandler(void);
void WEAK DMA2_Stream2_IRQHandler(void);
void WEAK DMA2_Stream3_IRQHandler(void);
void WEAK DMA2_Stream4_IRQHandler(void);
void WEAK ETH_IRQHandler(void);
void WEAK ETH_WKUP_IRQHandler(void);
void WEAK CAN2_TX_IRQHandler(void);
void WEAK CAN2_RX0_IRQHandler(void);
void WEAK CAN2_RX1_IRQHandler(void);
void WEAK CAN2_SCE_IRQHandler(void);
void WEAK OTG_FS_IRQHandler(void);
void WEAK DMA2_Stream5_IRQHandler(void);
void WEAK DMA2_Stream6_IRQHandler(void);
void WEAK DMA2_Stream7_IRQHandler(void);
void WEAK USART6_IRQHandler(void);
void WEAK I2C3_EV_IRQHandler(void);
void WEAK I2C3_ER_IRQHandler(void);
void WEAK OTG_HS_EP1_OUT_IRQHandler(void);
void WEAK OTG_HS_EP1_IN_IRQHandler(void);
void WEAK OTG_HS_WKUP_IRQHandler(void);
void WEAK OTG_HS_IRQHandler(void);
void WEAK DCMI_IRQHandler(void);
void WEAK CRYP_IRQHandler(void);
void WEAK HASH_RNG_IRQHandler(void);
void WEAK FPU_IRQHandler(void);

#endif	/* __STARTUP_STM32F4XX_C__ */
#endif /* __STARTUP_STM32F4XX_H__ */

