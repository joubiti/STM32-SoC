/* Wrapper for Multi tasking.
 * 
 * Copyright 2013-2020 The MathWorks, Inc.
 */
 
/* Header file for multitasking */
#ifndef _ARM_CORTEX_M_MULTITASKING_
#define _ARM_CORTEX_M_MULTITASKING_

#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
    #include "MW_target_hardware_resources.h"
#endif

#if defined(__ARMCOMPILER_VERSION) && (__ARMCOMPILER_VERSION > 6000000)
	#define ARM_CLANG_COMPILER 1
#endif

#if defined (__GNUC__) || defined(ARM_CLANG_COMPILER)
	#define MW_ASM	__asm volatile
#elif defined (__TMS470__)
	#define MW_ASM	__asm
#endif


/* Inline syntax */
#if defined (__GNUC__) || (ARM_CLANG_COMPILER)
    #define MW_ASM    __asm volatile
    #define MW_STATIC_INLINE  static inline
    #define MW_NAKED_ATTRIBUTE  __attribute__ ((naked))
#elif defined (__TMS470__)
    #define MW_ASM    __asm
    #define MW_STATIC_INLINE static inline
    #define MW_NAKED_ATTRIBUTE  
#endif


/* TI ARM Compiler equivalents to CMSIS */
#if defined (__TMS470__)
    unsigned long  __get_BASEPRI(void);
    void __set_BASEPRI(unsigned long basePri);

    #define __DSB() __asm (" DSB\n");
    #define __ISB() __asm (" ISB\n");
#endif

#define stringify(x) #x
  
/*
 * Function Name: mw_blockLowerPriorityTasks
 * Returns      : void
 * Inputs       : interrupt request number (IRQn_Type)
 */
#if defined (__GNUC__) || defined (ARM_CLANG_COMPILER)
// Function definition compatible with GCC ARM and ARMCLANG compilers
__attribute__((used)) MW_STATIC_INLINE void mw_blockLowerPriorityTasks(IRQn_Type isrNum)
{
	#if (__CORTEX_M >= 3)
        unsigned long isrPri = NVIC_GetPriority(isrNum);
        isrPri = (isrPri+1) << (8U - __NVIC_PRIO_BITS);
        __set_BASEPRI(isrPri);
	#else
	#endif
}


#else

// Function definition compatible with other compilers
MW_STATIC_INLINE void mw_blockLowerPriorityTasks(IRQn_Type isrNum)
{
	#if (__CORTEX_M >= 3)
        unsigned long isrPri = NVIC_GetPriority(isrNum);
        isrPri = (isrPri+1) << (8U - __NVIC_PRIO_BITS);
        __set_BASEPRI(isrPri);
	#else
	#endif
}

#endif


/* BASEPRI register is available from Cortex-M3 */
/* The preprocessor __CORTEX_M comes from CMSIS files.  If not, __CORTEX_M should be explicitly defined based on the Cortex-M architecture of the processor. */
#if (__CORTEX_M >= 3)
 #define ARM_CORTEX_M_PUSH_BASEPRI()  MW_ASM (" MRS R0, BASEPRI \n"      \
                                              " PUSH {R0, R1}   \n");        /* Dummy R1 for alignment */
#else
 #define ARM_CORTEX_M_PUSH_BASEPRI()
#endif


/* In GCC, functions with 'naked' attributes doesn't include prolog. */ 
/* For TI ARM toolchain, the below prolog is added only in DEBUG (-g) mode. This prolog needs to be 
   added in non-debug mode. */
/*This macro should be called before calling arm_cortex_m_call_thread_with_context_switch(). */
#if defined (__GNUC__) || (ARM_CLANG_COMPILER) //|| (defined (__TMS470__) && !defined (_DEBUG))
#define ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR()  MW_ASM (" MRS R0, APSR    \n"      \
                                                              " PUSH {R0, LR}   \n");
#else
#define ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR()
#endif

/* Preamble for Rentrant ISR */
#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)
/* Start of defines for multitasking*/
#if defined (ARM_CLANG_COMPILER)
/* Re-entrant ISR MACROS for  armclang compiler */
#define MW_RENTRANT_ISR_FUNCTION_BEGIN(MW_ISR_NAME, MW_IRQ_NUMBER)            \
MW_NAKED_ATTRIBUTE void MW_ISR_NAME(void) {                                   \
    ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR();                             \
    ARM_CORTEX_M_PUSH_BASEPRI();                                              \
    MW_ASM (" MOV R0, #" stringify(MW_IRQ_NUMBER));                           \
    MW_ASM (" BL mw_blockLowerPriorityTasks");

#define MW_CALL_ISR_FUNCTION(MW_ISR_FUNCTION_NAME)                            \
	MW_ASM ("    .global arm_cortex_m_call_thread_with_context_switch\n");	  \
    MW_ASM (" LDR R0, =" stringify(MW_ISR_FUNCTION_NAME));                    \
    MW_ASM (" BL arm_cortex_m_call_thread_with_context_switch");

#else
/* Re-entrant ISR MACROS for  GCC and TI Arm Compiler */
#define MW_RENTRANT_ISR_FUNCTION_BEGIN(MW_ISR_NAME, MW_IRQ_NUMBER)            \
MW_NAKED_ATTRIBUTE void MW_ISR_NAME(void) {                                   \
    ARM_CORTEX_M_PUSH_THREADS_PSR_AND_RET_ADDR();                             \
    ARM_CORTEX_M_PUSH_BASEPRI();                                              \
    mw_blockLowerPriorityTasks((IRQn_Type)(MW_IRQ_NUMBER));

#define MW_CALL_ISR_FUNCTION(MW_ISR_FUNCTION_NAME)                            \
    arm_cortex_m_call_thread_with_context_switch(MW_ISR_FUNCTION_NAME);
	
#endif
/* End of defines for multitasking*/
#else
	
/* Start of defines for unitasking*/
#define MW_RENTRANT_ISR_FUNCTION_BEGIN(MW_ISR_NAME, MW_IRQ_NUMBER)            \
void MW_ISR_NAME(void) {

#define MW_CALL_ISR_FUNCTION(MW_ISR_FUNCTION_NAME)                            \
    MW_ISR_FUNCTION_NAME();
/* End of defines for unitasking*/	
#endif

/* Postable for Rentrant ISR */
#define MW_RENTRANT_ISR_FUNCTION_END()                \
}

                                                              
#ifdef __cplusplus
extern "C" {
#endif                                                                      
    void arm_cortex_m_call_thread_with_context_switch(void (*isr_routine_ptr)(void));
#ifdef __cplusplus
}
#endif                                                                 

#endif /* _ARM_CORTEX_M_MULTITASKING_ */
