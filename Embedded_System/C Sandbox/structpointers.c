#include <stdio.h>
#include <string.h>

struct listem
{
    char harfler[50];
    int sayilar;
};


int main () {
    struct listem k1;
    struct listem *isaret = &k1;
    strcpy(k1.harfler,"Ahmet");
    k1.sayilar = 31;
    printf("Degistirilmemis\n%s\n%d\n",k1.harfler,k1.sayilar);
    strcpy(isaret->harfler,"Duran");
    isaret->sayilar = 69;
    printf("Degistirilmis:\n%s\n%d\n",k1.harfler,k1.sayilar);
}