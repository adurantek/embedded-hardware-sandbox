#include <stdio.h>
#include <stdint.h>
struct telemetry {
    uint16_t altitude;
    uint16_t temperature;
    uint8_t batteryLevel;
};

struct telemetry drone[5];
void updateBattery(struct telemetry *t, uint8_t newLevel) {
    t->batteryLevel = newLevel;
}

int main() {
    uint8_t yeniBatarya;
    int i;
    printf("kacinci batarya degissin: \n");
    scanf("%d",&i);
    printf("yeni batarya seviyesi kac olsun: \n");
    scanf("%d",&yeniBatarya);
    struct telemetry *p = &drone[i];
    updateBattery(p,yeniBatarya);
    printf("Yeni batarya seviyesi : %d",drone[i].batteryLevel);
    return 0;
}