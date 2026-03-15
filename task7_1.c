#include <stdio.h>

#define N 5

int input_array(int ar[N]) {
    for (int i = 0; i < N; i++) {
        printf("Input ar[%d] = ", i);
        int ch = scanf("%d", &ar[i]);
        if (ch != 1) return i; 
    }
    return N;
}

int count_less_than(int ar[], int n, double x) {
    int count = 0;
    for (int i = 0; i < n; i++) { /
        if (ar[i] < x) {
            count++;
        }
    }
    return count; 
}

void task1() {
    int mas[N];
    double threshold;
    int k = input_array(mas);
    printf("Enter a real number: ");
    scanf("%lf", &threshold);
    int result = count_less_than(mas, k, threshold);
    printf("Count of elements less than %.2f = %d\n", threshold, result);
}

int main() {
    task1();
    return 0;
}