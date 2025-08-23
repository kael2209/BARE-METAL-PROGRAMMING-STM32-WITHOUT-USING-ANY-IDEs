#include <stdint.h>

#define RCC_APB2ENR			(*((volatile uint32_t*)0x40021018U))
#define GPIOA_BASE			0x40010800

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIOA_TypeDef;

#define GPIOA			((GPIOA_TypeDef*)GPIOA_BASE)

