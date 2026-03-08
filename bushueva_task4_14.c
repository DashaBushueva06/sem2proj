#include <stdio.h>

void task14() {
    int current, prev;
    int count = 0;

    printf("Введіть послідовність цілих ненульових чисел:\n");

    if (scanf("%d", &prev) != 1 || prev == 0) {
        printf("Послідовність порожня\n");
        return;
    }

    while (1) {
        if (scanf("%d", &current) != 1 || current == 0) {
            break; 
        }
        if ((prev > 0 && current < 0) || (prev < 0 && current > 0)) {
            count++;
        }
        prev = current;
    }

    printf("\nЗнак змінився %d раз(ів).\n", count);
}

int main() {
    task14();
}