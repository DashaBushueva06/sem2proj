#include <stdio.h>
#include <math.h>


void task1() {
    printf("Завдання 1\n");
    double x, y;
    printf("Введіть х та у: ");
    scanf("%lf %lf", &x, &y);

    if ((x - 1) >= 0 && (y - 1) >= 0) {
        double result = sqrt(x - 1) + sqrt(y - 1);
        printf("Результат = %f\n\n", result);
    } else {
        printf("Помилка: підкореневий вираз менший за нуль!\n\n");
    }
}


void task2() {
    printf("Завдання 2\n");
    double x, y;
    printf("Введіть х та у: ");
    scanf("%lf %lf", &x, &y);

    x = x + y;
    y = x - y;
    x = x - y;

    printf("Після обміну: x = %g, y = %g\n\n", x, y);
}


void task3() {
    printf("Завдання 3\n");
    double a;
    printf("Введіть довжину ребра куба a: ");
    scanf("%lf", &a);

    if (a > 0) {
        printf("Об'єм куба V = %f\n", pow(a, 3));
        printf("Площа поверхні S = %f\n\n", 6 * pow(a, 2));
    } else {
        printf("Помилка: ребро має бути > 0!\n\n");
    }
}


void task4() {
    printf("Завдання 4\n");
    int n;
    printf("Введіть n: ");
    scanf("%d", &n);

    if (n <= 0) { printf("Помилка: n має бути > 0\n\n"); return; }

    double p_a = 1.0;
    for (int i = 1; i <= n; i++) {
        p_a *= (1.0 + 1.0 / (i * i));
    }

    double p_b = 1.0;
    for (int i = 1; i <= n; i++) {
        double sign = (i % 2 == 0) ? -1.0 : 1.0;
        p_b *= (1.0 + sign / pow(2, i));
    }

    printf("а) Результат = %f\n", p_a);
    printf("б) Результат = %f\n\n", p_b);
}


void task5() {
    printf("Завдання 5\n");
    double x_prev3 = -99.0, x_prev2 = -99.0, x_prev1 = -99.0;
    int n = 4;

    while (1) {
        double x_n = x_prev1 + x_prev3 + 100.0;
        if (x_n > 0) {
            printf("Найменший додатний член: x_%d = %f\n\n", n, x_n);
            break;
        }
        x_prev3 = x_prev2;
        x_prev2 = x_prev1;
        x_prev1 = x_n;
        n++;
    }
}


void task6() {
    printf("Завдання 6\n");
    int n;
    printf("Введіть n для ланцюгових дробів: ");
    scanf("%d", &n);

    if (n <= 0) { printf("Помилка: n має бути > 0\n\n"); return; }

    double res_a = 6.0;
    for (int i = 1; i < n; i++) { res_a = 6.0 + 1.0 / res_a; }

    double res_b = 4.0 * n + 2.0;
    for (int i = n - 1; i >= 1; i--) { res_b = (4.0 * i + 2.0) + 1.0 / res_b; }
    res_b = 2.0 + 1.0 / res_b;

    double res_v = 2.0;
    for (int i = 2 * n - 1; i >= 1; i--) {
        res_v = ((i % 2 == 0) ? 2.0 : 1.0) + 1.0 / res_v;
    }
    res_v = 1.0 + 1.0 / res_v;

    printf("а) b_n = %f\n", res_a);
    printf("б) lambda_n = %f\n", res_b);
    printf("в) x_2n = %f\n\n", res_v);
}

void task7() {
    printf("Завдання 7\n");
    int n;
    printf("Введіть n для обчислення суми S_n: ");
    scanf("%d", &n);

    if (n <= 0) { printf("Помилка: n має бути > 0\n\n"); return; }

    double a1 = 0.0, a2 = -1.0;
    double b1 = -1.0, b2 = 0.0;
    double sum = 0.0;

    if (n >= 1) sum += pow(2, 1) / (a1 + b1 * b1);
    if (n >= 2) sum += pow(2, 2) / (a2 + b2 * b2);
    for (int k = 3; k <= n; k++) {
        double a_k = a2 / (k - 1) + a1 - 2.0 * b2;
        double b_k = b2 - b1 + a2 - 1.0;
        
        sum += pow(2, k) / (a_k + b_k * b_k);
        a1 = a2; a2 = a_k;
        b1 = b2; b2 = b_k;
    }

    printf("Сума S_%d = %f\n\n", n, sum);
}

void task8() {
    printf("Завдання 8\n");
    double x, eps;
    printf("Введіть x та точність eps (наприклад, 0.0001): ");
    scanf("%lf %lf", &x, &eps);

    double term_a = 1.0;
    double sum_a = term_a;
    int k = 1;
    while (fabs(term_a) > eps) {
        term_a = -term_a * x / k;
        sum_a += term_a;
        k++;
    }
    double term_b = x;
    double sum_b = term_b;
    int m = 1;
    while (fabs(term_b) > eps) {
        term_b = -term_b * x * x * (2 * m - 1) / (m * (2 * m + 1));
        sum_b += term_b;
        m++;
    }
    printf("а) Ряд Тейлора для e^(-x) = %f | Стандартний exp(-x) = %f\n", sum_a, exp(-x));
    printf("б) Ряд Тейлора для Ф(x)   = %f\n\n", sum_b);
}


int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
}