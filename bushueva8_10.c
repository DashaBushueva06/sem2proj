#include <stdio.h>
#include <stdlib.h>

void task10(){
    int n;
    printf("n:");
    if (scanf("%d", &n) != 1) return;

    int N = 2 * n; 
    double* matrix = (double*)malloc(N*N*sizeof(double));
    double* rotated = (double*)malloc(N*N*sizeof(double));

    if (matrix == NULL || rotated == NULL) {
        printf("Вибрано погане n\n");
        return;
    }

    printf("Введіть елементи матриці %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Element [%d][%d] = ", i, j);
            scanf("%lf", &matrix[i * N + j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[(N - 1 -i)*N + (N -1-j)] = matrix[i * N + j];
        }
    }
    printf("\nМатриця після повороту:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2lf\t", rotated[i * N + j]);
        }
        printf("\n");
    }
    free(matrix);
    free(rotated);
}

int main(){   
    task10();
}