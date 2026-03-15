#include <stdio.h>
#define N 50

int input_array(int ar[N]) {
    for (int i = 0; i < N; i++) {
        printf("Input ar[%d] = ", i);
        int ch = scanf("%d", &ar[i]);
        if (ch != 1 || ar[i] == 0) return i; 
    }
    return N;
}

void odds(int x[], int n) {
    int evens = 0; 
    int odds_count = 0;  
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) {
            evens++;
        } else {
            odds_count++;
        }
    }
    printf("Evens = %d, Odds = %d\n", evens, odds_count);
}

int main() {
    int mas[N];
    int count = input_array(mas);
    if (count > 0) {
        odds(mas, count);
    } else {
        printf("No numbers entered.\n");
    }   
    return 0;
}