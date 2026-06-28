//for dongusu
#include <stdio.h>
int main () {
    float toplam = 0,okuma = 0;
    for (int i = 0; i <= 2; i++) {
        printf("sensor degerini giriniz\n");
        scanf("%f", &okuma);
        toplam = toplam + okuma;
    }
    toplam = toplam/3;
    printf("%f",toplam);
return 0;
}