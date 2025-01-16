#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
//apisiz
void clockinit();

int main (void)
{
    clockinit();

    while(1)
    {

    }

}

void clockinit()
{
    SYSCTL_RCC2_R &= 0x7FFFFFF;
    SYSCTL_RCC2_R &= ~SYSCTL_RCC2_USERCC;

    SYSCTL_RCC_R |= SYSCTL_RCC_BYPASS;
    SYSCTL_RCC_R &= ~SYSCTL_RCC_USESYSDIV;

    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~SYSCTL_RCC_XTAL_M) | SYSCTL_RCC_XTAL_16MHZ;

    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~SYSCTL_RCC_OSCSRC_M) | SYSCTL_RCC_OSCSRC_MAIN;

    SYSCTL_RCC_R &= ~SYSCTL_RCC_PWRDN; //  pll çalýþýyor ama devrede deðil

    SYSCTL_RCC_R &= ~SYSCTL_RCC_SYSDIV_M;

    SYSCTL_RCC_R |= 3<<22 ; //  /4 yaptýk 50 mhz (böldük)

    SYSCTL_RCC_R |= SYSCTL_RCC_USESYSDIV;

    while(SYSCTL_RIS_R & SYSCTL_RIS_PLLLRIS == 0);

    SYSCTL_RCC_R &= ~SYSCTL_RCC_BYPASS;

}
