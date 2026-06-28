//ASCII
#include <stdio.h>
void harfAl() {
    char harf;
    printf("Lutfen mini bir harf girin:");
    scanf("%c",&harf);
    harf = harf - 32;
    printf("ASCII karsiligi:%d,\n yeni buyuk hali:%c",harf,harf);
}
int main() {
    harfAl();
    return 0;
}