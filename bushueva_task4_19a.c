#include <stdio.h>

void task19a() {
    int n;
    double p = 1.0; 
    printf("Введіть натуральне число n (n>2):"); 
    if (scanf("%d", &n) !=1 || n<=2) {
        printf("n має бути натуральним числом більшим за 2.\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        p *= (1.0 + 1.0 / (i * i));
    }
    printf("Результат: n = %d: %lf\n", n, p);
}

int main() {
    task19a();
}