//struct
#include <stdio.h>
#include <string.h>

struct dcMotor {
    int hiz;
    char isim[20];
    int id;
};
struct dcMotor ozellik;
void motorDeger() {
    printf("Motor id giriniz:");
    scanf("%d",&ozellik.id);
    printf("Motor hizini giriniz:");
    scanf("%d",&ozellik.hiz);
    printf("Motor ismini giriniz:");
    scanf("%s",ozellik.isim);
}

void motorDegerGoster() {
    printf("Motor numarasi:%d",ozellik.id);
    printf("Motor hizi:%d",ozellik.hiz);
    printf("Motor ismi:%s",ozellik.isim);
}
int main() {
    motorDeger();
    motorDegerGoster();
    return 0;
}