#include <stdio.h>

#define N 100

int input(double a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Score[%d]=", i + 1);
        scanf("%lf", &a[i]);
    }
    return n;
}

void task17() {
    int n;
    double scores[N];
    printf("Enter number of judges:");
    scanf("%d", &n);
    input(scores, n);

    double min = scores[0];
    double max = scores[0];
    double sum = 0;

    for(int i=0;i<n;i++) {
        if(scores[i] < min) min = scores[i];
        if(scores[i] > max) max = scores[i];
        sum += scores[i];
    }

    double result=(sum-min-max)/(n-2);

    printf("\nMin: %.2f, Max: %.2f", min, max);
    printf("\nFinal score: %.2f\n", result);
}

int main() {
    task17();
}