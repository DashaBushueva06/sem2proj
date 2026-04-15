#include <stdio.h>
#include <stdlib.h>

double* create_and_input_vector(int n) {
    double *vec = (double*)malloc(n * sizeof(double));
    if (vec == NULL) return NULL;
    printf("Введіть %d елементів вектора: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i]);
    }
    return vec;
}
void clear_vector(double *vec) {
    if (vec != NULL) {
        free(vec);
    }
}
double* subtract_vectors(double *v1, double *v2, int n) {
    double *res = (double*)malloc(n * sizeof(double));
    if (res == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] - v2[i];
    }
    return res;
}

int main() {
    int n1, n2;
    printf("Введіть розмірність першого вектора: ");
    scanf("%d", &n1);
    double *v1 = create_and_input_vector(n1);

    printf("Введіть розмірність другого вектора: ");
    scanf("%d", &n2);
    double *v2 = create_and_input_vector(n2);

    if (n1 == n2 && v1 != NULL && v2 != NULL) {
        double *diff = subtract_vectors(v1, v2, n1);
        if (diff != NULL) {
            printf("Різниця векторів: ");
            for (int i = 0; i < n1; i++) {
                printf("%.2lf ", diff[i]);
            }
            printf("\n");
            clear_vector(diff);
        }
    } else {
        printf("Різниця неможлива.\n");
    }
    clear_vector(v1);
    clear_vector(v2);
}