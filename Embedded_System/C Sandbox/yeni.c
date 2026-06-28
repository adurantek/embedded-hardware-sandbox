#include <stdio.h>
#include <stdint.h>
int main () {
    uint16_t controlReg,*controlRegPoint;
    controlRegPoint = &controlReg;
    controlReg |= (1 << 7) | (1 << 3);
    printf("Sayi: %d\n",controlReg);
    printf("Hex: 0x%X\n", controlReg);
    printf("Adresi: %p\n",controlRegPoint);
    controlReg &= ~(1 << 12);
    printf("Sayi: %d\n",controlReg);
    printf("Hex: 0x%X\n", controlReg);
    controlReg ^= (1 << 0);
    printf("Sayi: %d\n",controlReg);
    printf("Hex: 0x%X\n", controlReg);
    return 0;
}