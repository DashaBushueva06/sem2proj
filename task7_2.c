#include <stdio.h>

#define N 4 

void print_array(int a[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i < N - 1) printf(","); 
    }
    printf("\n");
}

у
void reverse(int a[N]) {
    for (int i = 0; i < N / 2; i++) {
        int tmp = a[i];
        a[i] = a[N - 1 - i];
        a[N - 1 - i] = tmp;
    }
}

int main() {
    int mas[N] = {5, 112, 4, 3};
    printf("Original: ");
    print_array(mas);
    reverse(mas);
    printf("Reversed: ");
    print_array(mas);
}