//bytewise
#include <stdio.h>
#include <stdint.h>
#include <string.h>
uint8_t PORTD;
int main() {
    PORTD = PORTD | (1 << 5);
    printf("%d\n",PORTD);
    PORTD = PORTD ^ (1 << 5);
    printf("%d\n",PORTD);
    PORTD = PORTD | (1 << 5);
    printf("%d",PORTD);
    return 0;
}