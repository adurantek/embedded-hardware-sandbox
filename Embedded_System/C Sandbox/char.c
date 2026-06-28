//char
#include <stdio.h>
#include <string.h>
char komut[15];
void bluetoothKomut() {
    printf("Lutfen komut giriniz;");
    scanf("%s",komut);
}
void komutGoster() {
    printf("%s islemi gerceklestiriliyor...",komut);
    if (strcmp(komut, "AC") == 0) {
        printf("ACILDI");
    }
    else if (strcmp(komut, "KAPAT") == 0) {
        printf("KAPATILDI");
    }
    else {
        printf("GECERSIZ ISLEM");
    }
}

int main() {
    bluetoothKomut();
    komutGoster();
    return 0;
}