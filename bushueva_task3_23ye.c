#include <stdio.h>
#include <math.h>
#include <float.h>

void task3_23ye(double a, double x) {
    double f, df;

    if (a < 0) {
        f = -log(1 - a * (x + a)) / a;
    } else if (a == 0) {
        f = x;
    } else { 
        f = (exp(a * x) - 1) / a + a;
    }

    if (a < 0) {
        double d = 1 - a * (x + a);
        df = (d == 0) ? DBL_MAX : 1.0 / d;
    } else if (a == 0) {
        df = 1.0;
    } else { 
        double ex = exp(a * x);
        df = isinf(ex) ? DBL_MAX : ex;
    }

    printf("f(a, x) = %g\n", f);
    printf("f'(a, x) = %g\n", df);
}

int main() {
    double a, x;
    printf("Input a, x: ");
    scanf("%lf %lf", &a, &x);
    task3_23ye(a, x);
}