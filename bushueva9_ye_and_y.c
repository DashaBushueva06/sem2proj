#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(double** matrix, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%7.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double** create_matrix(int n, int m){
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100 / 10.0; 
        }
    }
    return matrix;
}


void task_ye(){
    int n, m, k;

    printf("Введіть n,m,k:");
    scanf("%d %d %d", &n, &m, &k);

    double** matrix = create_matrix(n, m);
    printf("Початкова матриця:\n");
    print_matrix(matrix, n, m);

    matrix = (double**)realloc(matrix, (n + k) * sizeof(double*));
    for (int i = n; i < n + k; i++) {
        matrix[i] = (double*)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0.0;
        }
    }

    printf("\nМатриця після додавання %d рядків:\n", k);
    print_matrix(matrix, n + k, m);
    for (int i = 0; i < n + k; i++) free(matrix[i]);
    free(matrix);
}

void task_y(){
    int n, m;
    printf("Введіть n,m:");
    scanf("%d %d", &n, &m);

    double** matrix = create_matrix(n, m);
    printf("Початкова матриця:\n");
    print_matrix(matrix, n, m);

    int new_m = m + (m / 2); 

    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)realloc(matrix[i], new_m * sizeof(double));
        int old_j = m - 1;
        int new_j = new_m - 1;
        
        while (old_j >= 0) {
            matrix[i][new_j] = matrix[i][old_j];
            if (old_j % 2 != 0) {
                new_j--;
                matrix[i][new_j] = 1.11; 
            }
            old_j--;
            new_j--;
        }
    }
    printf("\nМатриця після додавання стовпців після парних:\n");
    print_matrix(matrix, n, new_m);
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int main(){
    srand(time(NULL));
    task_ye();
    task_y();
}