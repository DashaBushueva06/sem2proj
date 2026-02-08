#include <stdio.h>
#include <math.h> 

double softSign(double x) {
    return x / (1 + fabs(x));
}

double softSign_derivative(double x) {
    double bottom = 1 + fabs(x);
    return 1 / (bottom * bottom);
}

int main(){
    double x;
    printf("Input x: ");
    scanf("%lf", &x);
    printf("f(x)  = %lf\n", softSign(x));
    printf("f'(x) = %lf\n", softSign_derivative(x));
}