#include <stdio.h>
#include <math.h>

int input_until_zero(int *arr, int max_size) {
    int count = 0;
    int num;
    printf("Введіть цілі числа: ");
    for (int i = 0; i < max_size; i++) {
        scanf("%d", &num);
        if (num == 0) break;
        arr[i] = num;
        count++;
    }
    return count;
}

int is_perfect_square(int n) {
    if (n < 0) return 0;
    int root = (int)round(sqrt(n));
    return (root * root == n);
}

int is_perfect_cube(int n) {
    int root = (int)round(pow(n, 1.0/3.0));
    return (root * root * root == n);
}

int main() {
    int data[100];
    int n = input_until_zero(data, 100);

    int squares = 0, cubes = 0;
    for (int i = 0; i < n; i++) {
        if (is_perfect_square(data[i])) squares++;
        if (is_perfect_cube(data[i])) cubes++;
    }
    printf("Кількість повних квадратів: %d\n", squares);
    printf("Кількість повних кубів: %d\n", cubes);
}