#include <stdio.h>
#include <string.h>

int main () {
    volatile int *ptr = (int*)0x02000;
    printf(":%p\n",ptr);
    volatile int *ptrr = 0x01000;
    printf(":%p\n",ptrr);
}