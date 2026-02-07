#include <stdio.h>
int main()
{
    double x, y;
    printf("Input x: ");
    scanf("%lf", &x);
    y = x*x;
    y = y*y;
    y = y*y;
    y = y/x;
    y = y*y;
    y = y*y;
    printf("y = %lf", y);
}