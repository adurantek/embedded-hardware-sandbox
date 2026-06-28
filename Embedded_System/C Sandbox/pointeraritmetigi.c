//pointer aritmetiği
#include <stdio.h>

int a;

int main() {
    
    int sayi;
    printf("Kac sicaklik gireceksiniz:");
    scanf("%d",&sayi);
    float sicakliklar[sayi];

void sicaklikAl(a) {
    for (int i=0;i<=a-1;i++) {
        printf("\n%d. sicaklik:",i+1);
        scanf("%f",&sicakliklar[i]);
    }
}
    
void sicaklikGoster() {
    float *ptr = sicakliklar;
    for (int i=0; i <= sayi-1 ;i++) {
        printf("%.1f\n",*ptr);
        ptr++;
    }
}

    sicaklikAl(sayi);
    sicaklikGoster();
    return 0;
}