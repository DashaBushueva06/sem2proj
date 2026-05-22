#include <stdio.h>
#include <math.h>


void task1() {
    printf("Завдання 1\n");
    double x;
    printf("Введіть х для косинуса: ");
    scanf("%lf", &x);
    printf("cos = %f\n\n", cos(x));
}


void task2() {
    printf("Завдання 2\n");
    double a, b;
    printf("Введіть катети a і b: ");
    scanf("%lf %lf", &a, &b);
    printf("Гіпотенуза = %f\n\n", hypot(a, b));
}


void task3() {
    printf("Завдання 3\n");
    double s1, s2, s3;
    printf("Введіть 3 сторони трикутника: ");
    scanf("%lf %lf %lf", &s1, &s2, &s3);
    double p = (s1 + s2 + s3) / 2.0;
    double area3 = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    printf("Площа = %f\n\n", area3);
}


void task4() {
    printf("Завдання 4\n");
    double x;
    printf("Введіть x для многочленів: ");
    scanf("%lf", &x);
    
    // а) y = x^4 + 2*x^2 + 1
    double x2 = x * x;
    double ya = x2 * (x2 + 2) + 1;
    
    // б) y = x^4 + x^3 + x^2 + x + 1 - дз
    double yb = x * (x * (x * (x + 1) + 1) + 1) + 1;
    
    printf("а) y = %f\n", ya);
    printf("б) y = %f\n\n", yb);
}


void task5() {
    printf("Завдання 5\n");
    double x, y;
    for (int i = 0; i < 3; i++) {
        printf("Введіть x та y для функції Розенброка (пара %d): ", i + 1);
        scanf("%lf %lf", &x, &y);
        double ros = 100 * pow(x * x - y, 2) + pow(x - 1, 2);
        printf("Результат = %f\n", ros);
    }
    printf("\n");
}


void task6() {
    printf("Завдання 6\n");
    double ax, ay, bx, by, cx, cy;
    
    printf("Введіть точку А (x y): ");
    scanf("%lf %lf%*c", &ax, &ay); 
    
    printf("Введіть точку B (x y): ");
    scanf("%lf %lf%*c", &bx, &by);
    
    printf("Введіть точку C (x y): ");
    scanf("%lf %lf", &cx, &cy);

    double ab = hypot(ax - bx, ay - by);
    double bc = hypot(bx - cx, by - cy);
    double ca = hypot(cx - ax, cy - ay);

    double p = (ab + bc + ca) / 2.0;
    double area6 = sqrt(p * (p - ab) * (p - bc) * (p - ca));
    printf("Площа трикутника = %f\n", area6);
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
}