//sizeof
#include <stdio.h>
long a;
double b;
unsigned long c;
unsigned int e = 40000;
int g;
float h;
char yar[10];
int main() {
    printf("%d\n",sizeof(int));
    printf("%u\n",sizeof(unsigned int));
    printf("%f\n",sizeof(float));
    printf("%lf\n",sizeof(double));
    printf("%ld\n",sizeof(long int));
    printf("%lu\n",sizeof(unsigned long));
    printf("%u",e);
    return 0;
}