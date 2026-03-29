#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void printday(struct Date x) {
    printf("%2d.%2d.%4d", x.day, x.month, x.year);
}

int inputday(struct Date *x) {
    printf("Ведіть дату");
    scanf("%d %d %d", &(*x).day, &x->month, &x->year);
    return true; 
}

int main() {
    struct Date y;
    inputday(&y);
    printday(y);
}