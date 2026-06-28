//static
#include <stdio.h>
#include <stdint.h>
void gecenYolcu() {
    static int sayac;
    sayac++;
    printf("Gecen yolcu:%d\n",sayac); 
}

void turnike() {
    uint8_t dugme;
    switchcase:
    printf("Gecmek icin 1'e basiniz:");
    scanf("%d",&dugme);
    
    switch (dugme) {
        
        case 1:
        printf("Basarili!\n");
        break;

        default:
        printf("Lutfen gecerli bir tuslama yapiniz...\n");
        goto switchcase;
        break;
    }
    
}

int main () {
    while (1) {
        turnike();
        gecenYolcu();
    }
    return 0;
}