//while dongusu
#include <stdio.h>

int main () {
    float sicaklik = 0;
    while (1) {
        printf("Kazan sicaklik degerini giriniz...");
        scanf("%f", &sicaklik);
        if (sicaklik > 100) {
            printf("!!! TEHLIKE: Kazan Kayniyor! Sistemi Kapat! !!!\n");
        }
        else if (sicaklik <= 100 && sicaklik >= 80) {
            printf("Uyari: Sicaklik yuksek, fanlar devrede.\n");
        }
        else if (sicaklik < 80 && sicaklik > 0) {
            printf("Sistem normal calisiyor.\n");
        }
            else {
            printf("Sistem cok soguk, kapatiliyor");
            break;
        }
    }
return 0;
}