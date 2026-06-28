//makrolar ve kütüphaneler
#include <stdio.h>
#include <math.h>
#define PI 3.14

float veriAl() {
    float r;
    printf("Yaricap giriniz:");
    scanf("%f",&r);
    return r;
}

float alanHesapla(float ar) {
    return PI * pow(ar,2);
}

int main() {
    float a;
    a = veriAl();
    printf("%f\n",alanHesapla(a));
    char harf;
    printf("lutfen bir sayi veya harf giriniz:");
    scanf(" %c",&harf);
    printf("ASCII DEGERI:%d, HARF ISE:%c",harf,harf);
    return 0;
}