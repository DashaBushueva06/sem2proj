#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double* create_matrix(int n) {
    double* m = (double*)calloc(n * n, sizeof(double));
    return m;
}

int input_matrix(double* m, int n) {
    printf("Ведіть елементи матриці %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &m[i * n + j]);
        }
    }
    return true;
}

void free_matrix(double* m) {
    if (m != NULL) {
        free(m);
    }
}

double* multiply_matrices(double* A, double* B, int n) {
    double* C = create_matrix(n);
    if (C == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
    return C;
}

void print_matrix(double* m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2lf ", m[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Ведіть розмірність n для квадратних матриць: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Розмірність не додатня\n");
        return 0;
    }

    double* A = create_matrix(n);
    double* B = create_matrix(n);

    if (input_matrix(A, n) && input_matrix(B, n)) {

        double* C = multiply_matrices(A, B, n);

        if (C != NULL) {
            printf("\nРезультат добутку матриць A та B:\n");
            print_matrix(C, n);
            free_matrix(C);
        }
    }
    free_matrix(A);
    free_matrix(B);
}