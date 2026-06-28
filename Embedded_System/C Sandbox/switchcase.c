//switch-case
#include <stdio.h>
int main () {
    int a;
    printf("Numlock tuslarina gore robot hareketini saglayiniz.");
    scanf("%d", &a);
    switch (a) {
        case 8:
            printf("Yukari hareket ediyor!");
            break;
        case 4:
            printf("Sola hareket ediyor!");
            break;
        case 6:
            printf("Saga hareket ediyor!");
            break;
        case 2:
            printf("Asagi hareket ediyor!");
            break;
        default:
            printf("Gecersiz islem!");
            break;
    }
return 0;
}