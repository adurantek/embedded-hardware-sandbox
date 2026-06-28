//GİRİS
#include <stdio.h>

float voltaj(float c, float r) {
    float v;
    v=c*r;
    return v;
}
int main () {
    float a,b;
    printf("Akim ve Direnc degerlerini giriniz.\nAkim:");
    scanf("%f",&a);
    printf("Direnc:");
    scanf("%f",&b);
    printf("voltaj: %f",voltaj(a,b));
}