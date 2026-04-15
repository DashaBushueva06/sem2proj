#include <stdio.h>
#include <stdbool.h>

struct Date {
    int day;
    int month;
    int year;
};

int days_in_month(int m, int y) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        return 29;
    }
    return days[m];
}

void printday(struct Date x) {
    printf("%02d.%02d.%4d", x.day, x.month, x.year);
}

int inputday(struct Date *x) {
    printf("Ведіть дату (день місяць рік): ");
    scanf("%d %d %d", &(*x).day, &x->month, &x->year);
    return true;
}

struct Date get_tomorrow(struct Date d) {
    d.day++;
    if (d.day > days_in_month(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

void print_weekday(struct Date d) {
    char *days[] = {"Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота", "Неділя"};
    int a = (14 - d.month) / 12;
    int y = d.year - a;
    int m = d.month + 12 * a - 2;
    int day_index = (d.day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    printf("День тижня: %s\n", days[day_index]);
}

int main() {
    struct Date today, tomorrow;

    if (inputday(&today)) {
        printf("Поточна дата:");
        printday(today);
        printf("\n");
        print_weekday(today);
        tomorrow = get_tomorrow(today);
        printf("Завтра буде: ");
        printday(tomorrow);
        printf("\n");
    }
}