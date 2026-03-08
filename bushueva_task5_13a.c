#include <stdio.h>

void task13a(){
    int n;
    double a[n + 3]; 
    double p = 1.0;
    a[0] = 1.0;
    a[1] = 1.0;
    a[2] = 3.0;

    printf("Введіть n (n>=0):");
    if (scanf("%d", &n) !=1 || n<0) {
        printf("n має бути невід'ємним.\n");
        return;
    }
    for (int k=3; k<=n; k++) {
        a[k] = a[k-3] + (a[k-2] / (2.0 * k - 1.0));
    }
    for (int k=0; k<=n; k++) {
        p *= a[k];
    }
    printf("Результат: P(%d) = %lf\n", n, p);
}

int main() {
    task13a();
}