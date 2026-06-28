#include <stdio.h>
#include <conio.h> // getch() için

// 1. Durumları (Modları) tanımlıyoruz (Okunabilirlik için)
#define IDLE 0
#define ALARM_ACTIVE 1
#define MAINTENANCE 2

int main() {
    // 2. Sistemin başlangıç durumunu belirliyoruz
    int systemState = IDLE; 
    char tus;

    printf("--- Akilli Ev Paneli Basladi ---\n");
    printf("Tuslar: [A]larm, [S]tatus, [R]eset\n\n");

    // 3. Makinenin kalbi: Sonsuz Döngü
    while(1) {
        
        // 4. Duruma göre davran (Switch-Case)
        switch(systemState) {
            
            case IDLE:
                printf("[MOD: BEKLEME] Her sey yolunda. Komut bekleniyor...\n");
                break;
                
            case ALARM_ACTIVE:
                printf("[MOD: ALARM!] DIKKAT DIKKAT! SİRENLER ÇALIYOR!\n");
                break;
                
            case MAINTENANCE:
                printf("[MOD: BAKIM] Sistem bakimda. Lutfen bekleyin...\n");
                break;
        }

        // 5. Dışarıdan etki (Girdi) bekle
        tus = getch(); // Kullanıcı tuşa basana kadar sistem burada donar

        // 6. Gelen tuşa göre "Durum Değiştir" (State Transition)
        if (tus == 'A' || tus == 'a') {
            systemState = ALARM_ACTIVE;
        } 
        else if (tus == 'R' || tus == 'r') {
            systemState = IDLE;
        } 
        else if (tus == 'S' || tus == 's') {
            systemState = MAINTENANCE;
        }
        else {
            printf("Gecersiz Tus!\n");
        }
    }

    return 0;
}