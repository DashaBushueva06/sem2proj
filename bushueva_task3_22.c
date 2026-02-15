#include <stdio.h>

void task3_22() {
    double x, y, z, r, h;

    printf("Input (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Input r, h: ");
    scanf("%lf %lf", &r, &h);

    if (x * x + y * y <= r * r && z >= 0 && z <= h) {
        printf("Точка належить циліндру\n");
    } else {
        printf("Точка не належить циліндру\n");
    }
}

int main() {
    task3_22(); 
}