#include "std_types_.h"

extern int main(void);

void __attribute__((weak)) defaultHandler(void);

void __attribute__((weak)) resetHandler(void);

void __attribute__((weak, alias("defaultHandler"))) NMI_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) HardFault_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) MemManage_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) BusFault_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) UsageFault_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SVCall_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DebugMonitor_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) PendSV_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SysTick_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) WWDG_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) PVD_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TAMP_STAMP_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) RTC_WKUP_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) FLASH_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) RCC_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI0_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI1_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI3_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI4_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream0_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream1_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream3_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream4_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream5_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream6_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) ADC_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI9_5_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_BRK_TIM9_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_UP_TIM10_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_TRG_COM_IM11_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_CC_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM3_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM4_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C1_EV_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C1_ER_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C2_EV_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C2_ER_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SPI1_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SPI2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) USART1_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) USART2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) EXTI15_10_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) RTC_Alarm_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) OTG_FS_WKUP_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Stream7_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SDIO_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) TIM5_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SPI3_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream0_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream1_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream2_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream3_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream4_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) OTG_FS_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream5_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream6_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) DMA2_Stream7_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) USART6_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C3_EV_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) I2C3_ER_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) FPU_Handler (void);
void __attribute__((weak, alias("defaultHandler"))) SPI4IRQHandler (void);


extern uint32 _e_stack;
extern uint32 _s_data_FLASH;
extern uint32 _s_data;
extern uint32 _e_data;
extern uint32 _s_bss;
extern uint32 _e_bss;

typedef void (*PF_Handler)(void);

__attribute__((section(".isr_vector"), used)) PF_Handler Vector_Table[] = {
  (PF_Handler) &_e_stack;
  resetHandler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVCall_Handler,
  DebugMonitor_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_Handler,
  PVD_Handler,
  TAMP_STAMP_Handler,
  RTC_WKUP_Handler,
  FLASH_Handler,
  RCC_Handler,
  EXTI0_Handler,
  EXTI1_Handler,
  EXTI2_Handler,
  EXTI3_Handler,
  EXTI4_Handler,
  DMA1_Stream0_Handler,
  DMA1_Stream1_Handler,
  DMA1_Stream2_Handler,
  DMA1_Stream3_Handler,
  DMA1_Stream4_Handler,
  DMA1_Stream5_Handler,
  DMA1_Stream6_Handler,
  ADC_Handler,
  0,
  0,
  0,
  0,
  EXTI9_5_Handler,
  TIM1_BRK_TIM9_Handler,
  TIM1_UP_TIM10_Handler,
  TIM1_TRG_COM_IM11_Handler,
  TIM1_CC_Handler,
  TIM2_Handler,
  TIM3_Handler,
  TIM4_Handler,
  I2C1_EV_Handler,
  I2C1_ER_Handler,
  I2C2_EV_Handler,
  I2C2_ER_Handler,
  SPI1_Handler,
  SPI2_Handler,
  USART1_Handler,
  USART2_Handler,
  0,
  EXTI15_10_Handler,
  RTC_Alarm_Handler,
  OTG_FS_WKUP_Handler,
  0,
  0,
  0,
  0,
  DMA1_Stream7_Handler,
  0,
  SDIO_Handler,
  TIM5_Handler,
  SPI3_Handler,
  0,
  0,
  0,
  0,
  DMA2_Stream0_Handler,
  DMA2_Stream1_Handler,
  DMA2_Stream2_Handler,
  DMA2_Stream3_Handler,
  DMA2_Stream4_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  OTG_FS_Handler,
  DMA2_Stream5_Handler,
  DMA2_Stream6_Handler,
  DMA2_Stream7_Handler,
  USART6_Handler,
  I2C3_EV_Handler,
  I2C3_ER_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  FPU_Handler,
  0,
  0,
  SPI4IRQHandler
};

void __attribute__((section(".text"))) resetHandler(void) {
  uint32 *memSrcAddr = (uint32 *)&_s_data_FLASH;
  uint32 *memDstAddr = (uint32 *)&_s_data;

  uint32 sectionSize = &_e_data - &_s_data;

  for (int i = 0; i < sectionSize; ++i) {
    *memDstAddr++ = *memSrcAddr++;
  }

  memDstAddr = (uint32*)&_s_bss;
  sectionSize = &_e_bss -  &_s_bss;

  for (int i = 0; i < sectionSize; ++i) {
    *memDstAddr++ = 0;
  }

  main();

}


void __attribute__((section(".text"))) defaultHandler(void) {
  for (;;) {
  }
}


/*



*/
