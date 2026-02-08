#include <stdio.h>
#include <math.h>

int main(){
    double a1, a2, a3, r, S;
    double pi = 3.14159265;
    printf("Enter r: ");
    scanf("%lf", &r);
    printf("Enter 3 angles: ");
    scanf("%lf %lf %lf", &a1, &a2, &a3);

    S = r * r * (1.0/tan(a1/2 * pi/180) + 1.0/tan(a2/2 * pi/180) + 1.0/tan(a3/2 * pi/180));
    printf("Area of triangle S = %.2lf\n", S);
}