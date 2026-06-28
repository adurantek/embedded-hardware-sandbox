//pointer
#include <stdio.h>

// 1. ADIM: Fonksiyonumuz dışarıdan iki tane ADRES (Pointer) alacak.
// "Bana iki tane int değişkenin RAM'deki yerini söyle" diyoruz.
void yerDegistir(int *adres1, int *adres2) {
    
    // *adres1 demek: "adres1'in gösterdiği kutunun İÇİNDEKİ DEĞER" demektir.
    
    int gecici = *adres1; // 1. kutunun içindeki değeri (10), gecici kutuya koy.
    *adres1 = *adres2;    // 2. kutunun içindeki değeri (50), 1. kutunun içine yaz.
    *adres2 = gecici;     // gecici kutudaki değeri (10), 2. kutunun içine yaz.
}

int main() {
    // İki tane normal, masum yerel (local) değişken.
    int x = 10;
    int y = 50;

    printf("Once: x = %d, y = %d\n", x, y);

    // 2. ADIM: SİHRİN GERÇEKLEŞTİĞİ YER!
    // Fonksiyona x ve y'nin DEĞERLERİNİ (10 ve 50) değil, 
    // RAM'deki ADRESLERİNİ (&x ve &y) gönderiyoruz!
    yerDegistir(&x, &y);

    printf("Sonra: x = %d, y = %d\n", x, y);

    return 0;
}