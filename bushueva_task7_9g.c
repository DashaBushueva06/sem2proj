#include <stdio.h>
#include <math.h>

#define N 10 

int input_double_array(double ar[], int n) {
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i + 1); 
        int ch = scanf("%lf", &ar[i]);
        if (ch != 1) return i;
    }
    return n;
}

double min_odd_positions(double ar[], int n) {
    double minimum = ar[0]; 
    for (int i = 2; i < n; i += 2) {
        if (ar[i] < minimum) {
            minimum = ar[i];
        }
    }
    return minimum;
}

void task9g() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > N) {
        printf("Invalid size\n");
        return;
    }
    double mas[N];
    int count = input_double_array(mas, n);
    if (count > 0) {
        double result = min_odd_positions(mas, count);
        printf("\nMinimum = %.3lf\n", result);
    }
}

int main() {
    task9g();
}