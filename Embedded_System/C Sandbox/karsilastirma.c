//karsilastirma
#include <stdio.h>
int main () {
    float akuVoltaj;
    printf("Akunun voltaj degerini giriniz:\n");
    scanf("%f", &akuVoltaj);
    if (akuVoltaj > 14.4) {
        printf("Asiri sarj tehlikesi!\n");
    }
    else if (akuVoltaj >= 11.4 && akuVoltaj <= 14.4) {
        printf("Batarya normal, sistem calisiyor.\n");
    }
    else {
        printf("Dusuk Voltaj! Derin desarj korumasi aktif.");
    }
return 0;
}