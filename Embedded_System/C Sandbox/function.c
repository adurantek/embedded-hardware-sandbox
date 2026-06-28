//function
#include <stdio.h>
int button = 1;
void sistemDurdurma () {
    printf("Sistem durduruldu!");
}
void sistemDurumu() {
    while (1) {
        printf("Sistem calisiyor...Durdurmak icin 0'a basin\n");
        scanf("%d",&button);
        switch (button) {
            case 0:
                sistemDurdurma();
                break;
            default:
                printf("hatali deger!");
                sistemDurumu();
                button = 1;
        }
    break;
}
}
int main() {
    sistemDurumu();
return 0;
}