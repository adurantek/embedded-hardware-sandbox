//2 boyutlu diziler
#include <stdio.h>
int main() {
    
    int matris[3][3] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    
    for (int i = 0; i <= 2; i++) {
        printf("\n");
        for (int u = 0; u <= 2 ; u++) {

            int secilen = matris[i][u];
            printf("%d",secilen);

        }
    }
return 0;
}
