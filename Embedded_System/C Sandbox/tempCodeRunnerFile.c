#include <stdio.h>
#include <string.h>

struct listem
{
    char harfler[50];
    int sayilar;
};


int main () {
    
    struct listem k1;
    strcpy(k1.harfler,"Ahmet");
    k1.sayilar = 31;
    struct listem *isaret = &k1;
    printf("Degistirilmemis\n%c\n%d",k1.harfler,k1.sayilar);
    strcpy(k1.harfler,"Duran");
    isaret->sayilar = 69;
    printf("Degistirilmis:\n%c\n%d",k1.harfler,k1.sayilar);
}