//if else
#include <stdio.h>
int main () {
    int resistor;
    int current;
    int voltage;
    printf("akim ve resistor degerlerini giriniz:\n");
    printf("resistor:\n");
    scanf("%d",&resistor);
    printf("akim:\n");
    scanf("%d",&current);
    voltage = current*resistor;
    printf("voltage:%dV\n",voltage);
    if (voltage >= 220) {
        printf("Attention, High Voltage!\n");
    }
    else {
        printf("No problem\n");
    }
return 0;
}