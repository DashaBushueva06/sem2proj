#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int input_array(double *arr, int n) {
    printf("Ведіть %d дійсних чисел: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    return true;
}

double sum_of_squares(double *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }
    return sum;
}

int main() {
    int n;
    printf("Ведіть натуральне n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Число n має бути натуральним\n");
    }
    double *arr = (double*)malloc(n * sizeof(double));

    if (input_array(arr, n)) {
        double result = sum_of_squares(arr, n);
        printf("Сума квадратів елементів: %.4lf\n", result);
    }
    free(arr);
}