#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double sum_sqr(double* r, size_t n){
    double s = 0;
    for (size_t i = 0; i < n; i++) s += r[i] * r[i];
    return s;
}

void task1(){
    size_t n;
    printf("Input n: ");
    scanf("%zu", &n);
    double* r = (double*)malloc(sizeof(double) * n);
    
    for (size_t i = 0; i < n; i++) {
        printf("r[%zu] = ", i);
        scanf("%lf", &r[i]);
    }
    
    printf("Sum of squares: %lf\n", sum_sqr(r, n));
    free(r);
}

int is_perfect_power(int num, int power){
    if (num < 0) return 0;
    int root = (int)(pow(num, 1.0/power) + 0.5);
    int res = 1;
    for(int i=0; i<power; i++) res *= root;
    return (res == num);
}

int input_until_zero(int* arr, int max_n){
    int count = 0;
    printf("Input integers (0 to stop): \n");
    for (int i = 0; i < max_n; i++) {
        int val;
        scanf("%d", &val);
        if (val == 0) break;
        arr[i] = val;
        count++;
    }
    return count;
}

void task2() {
    int arr[100]; 
    int n = input_until_zero(arr, 100);
    int sq = 0, cb = 0;
    for (int i = 0; i < n; i++) {
        if (is_perfect_power(arr[i], 2)) sq++;
        if (is_perfect_power(arr[i], 3)) cb++;
    }
    printf("Total numbers: %d. Perfect squares: %d, Perfect cubes: %d\n", n, sq, cb);
}


double* create_vector(int n) {
    return (double*)malloc(n * sizeof(double));
}

void task3(){
    int n;
    printf("Input vector size n: ");
    scanf("%d", &n);
    double *v1 = create_vector(n), *v2 = create_vector(n), *v_diff = create_vector(n);
    
    printf("Input vector 1:\n");
    for(int i=0; i<n; i++) scanf("%lf", &v1[i]);
    printf("Input vector 2:\n");
    for(int i=0; i<n; i++) scanf("%lf", &v2[i]);
    for(int i=0; i<n; i++) v_diff[i] = v1[i] - v2[i]; 
    printf("Result difference vector: ");
    for(int i=0; i<n; i++) printf("%.2lf ", v_diff[i]);
    printf("\n");
    
    free(v1); free(v2); free(v_diff);
}

void task4(){
    int n;
    printf("Input n for n*n matrix: ");
    scanf("%d", &n);
    
    double* A = (double*)calloc(n * n, sizeof(double));
    double* B = (double*)calloc(n * n, sizeof(double));
    double* C = (double*)calloc(n * n, sizeof(double));
    
    printf("Input Matrix A:\n");
    for(int i=0; i < n*n; i++) scanf("%lf", &A[i]);
    printf("Input Matrix B:\n");
    for(int i=0; i < n*n; i++) scanf("%lf", &B[i]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                C[i*n + j] += A[i*n + k] * B[k*n + j];
            }
        }
    }
    
    printf("Result Product Matrix C:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) printf("%.2lf ", C[i*n + j]);
        printf("\n");
    }
    free(A); free(B); free(C);
}

int main(){
    task3();
    task4();
}