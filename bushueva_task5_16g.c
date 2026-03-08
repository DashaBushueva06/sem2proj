#include <stdio.h>
#include <math.h> 

void task16g() {
    double sum = 0.0;
    double term = 1.0; 
    int k = 0;       
    double x, eps;
    printf("Введіть x:");
    if (scanf("%lf", &x) != 1) return;
    
    printf("Введіть точність епсілон: ");
    if (scanf("%lf", &eps) != 1 || eps<=0) {
        printf("Епсілон має бути більше 0.\n");
        return;
    }
    while (fabs(term)>= eps) {
        sum += term;
        k++;
        term *= (x * x) / ((2 * k) * (2 * k - 1));
        if (k>100000) break;
    }
    printf("\nРезультат: %lf\n", sum);
    printf("Кількість доданих членів: %d\n", k);
}

int main() {
    task16g();
}