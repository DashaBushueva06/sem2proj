#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Address {
    char street[50];
    char building[10];
    int apartment;
};
struct Resident {
    char surname[50];
    char city[50];
    struct Address addr;
};
int input_Resident(struct Resident *x) {
    printf("Прізвище: "); scanf("%s", &(*x).surname);
    printf("Місто: "); scanf("%s", &x->city);
    printf("Вулиця: "); scanf("%s", &(*x).addr.street);
    printf("Будинок: "); scanf("%s", &x->addr.building);
    printf("Квартира: "); scanf("%d", &(*x).addr.apartment);
    return true;
}

void find_matches(struct Resident *arr, int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].city, arr[j].city) != 0) {
                if (strcmp(arr[i].addr.street, arr[j].addr.street) == 0 &&
                    strcmp(arr[i].addr.building, arr[j].addr.building) == 0 &&
                    arr[i].addr.apartment == arr[j].addr.apartment) {               
                    printf("Знайдено збіг за адресою: вул. %s, буд. %s, кв. %d\n", 
                           arr[i].addr.street, arr[i].addr.building, arr[i].addr.apartment);
                    printf("1. %s (%s)\n", arr[i].surname, arr[i].city);
                    printf("2. %s (%s)\n", arr[j].surname, arr[j].city);
                    found = true;
                }
            }
        }
    }

    if (!found) {
        printf("Збігів не знайдено.\n");
    }
}

int main() {
    int n;
    printf("Введіть кількість мешканців: ");
    scanf("%d", &n);
    struct Resident *p = (struct Resident*)malloc(n * sizeof(struct Resident));
    for (int i = 0; i < n; i++) {
        printf("\nМешканець №%d:\n", i + 1);
        input_Resident(&p[i]);
    }
    find_matches(p, n);
    free(p);
}