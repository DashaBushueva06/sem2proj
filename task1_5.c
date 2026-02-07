#include <stdio.h>

int main(){
    double x, y, z;
    printf("\nx=");
    scanf("%lf",&x);

    x = x*x;
    y = x*x; // x^4
    printf("x^4=%g\n", x);
    y = x*x*x; // x^6
    printf("x^6=%g\n", y);

}