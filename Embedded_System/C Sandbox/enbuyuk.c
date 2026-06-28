//en buyuk
#include <stdio.h>
int main () {
    int sicakliklar[6];
    int enBuyuk = 0;
    for (int i = 0; i < 6; i++) {
        printf("%d. Sicaklik degerini giriniz:",i+1);
        scanf("%d", &sicakliklar[i]);
        if (sicakliklar[i] > enBuyuk) {
            enBuyuk = sicakliklar[i];
        }
    }
    printf("En yuksek sicaklik: %d", enBuyuk);
}