#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Mountain {
    char name[50];
    int height;
};

int input_Mountain(struct Mountain *x) {
    printf("Назва гори та її висота: ");
    scanf("%s %d", &(*x).name, &x->height);
    return true;
}

void print_Mountain(struct Mountain x) {
    printf("Гора: %-15s | Висота: %d м\n", x.name, x.height);
}

void find_highest(struct Mountain *arr, int n) {
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].height > arr[max_idx].height) {
            max_idx = i;
        }
    }
    printf("\nНайвища вершина: %s\n", arr[max_idx].name);
}

void find_height_by_name(struct Mountain *arr, int n, char *search_name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, search_name) == 0) {
            printf("Висота гори %s становить %d м\n", arr[i].name, arr[i].height);
            return;
        }
    }
    printf("Вершини з назвою '%s' немає в масиві.\n", search_name);
}

int main() {
    int n;
    printf("Введіть кількість гір: ");
    scanf("%d", &n);
    struct Mountain mountains[n];

    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        input_Mountain(&mountains[i]);
    }

    printf("\nСписок усіх гір:\n");
    for (int i = 0; i < n; i++) {
        print_Mountain(mountains[i]);
    }
    find_highest(mountains, n);
    char target[50];
    printf("\nВведіть назву гори: ");
    scanf("%s", target);
    find_height_by_name(mountains, n, target);
}