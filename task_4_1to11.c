#include <stdio.h>
#include <math.h>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();

int main(){
    int task_num;
    printf("Enter task number: ");
    if(scanf("%d", &task_num) != 1) return 1;

    if(task_num == 1){
        printf("Task 1: Iterated Sine\n");
        task1();
    } else if(task_num == 2){
        printf("Task 2: Factorial\n");
        task2();
    } else if(task_num == 3){
        printf("Task 3: Sum of Series\n");
        task3();
    } else if(task_num == 4){
        printf("Task 4: Sum of Series (Advanced)\n");
        task4();
    } else if(task_num == 5){
        printf("Task 5: Double Factorial\n");
        task5();
    } else if(task_num == 6){
        printf("Task 6: Square roots\n");
        task6();
    } else if(task_num == 7){
        printf("Task 7: Tailor Exponent\n");
        task7();
    } else if(task_num == 8){
        printf("Task 8: Power of 4\n");
        task8();
    } else if(task_num == 9){
        printf("Task 9: Power of 2\n");
        task9();
    } else if(task_num == 10){
        printf("Task 10: Machine zero\n");
        task10();
    } else if(task_num == 11){
        printf("Task 11: PSeudo array avg:\n");
        task11();
    } else {
        printf("Invalid task number.\n");
    }
}

void task1(){
    unsigned n;
    double x, y;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    printf("Enter a real number: ");
    scanf("%lf", &x);
    y = x;
    for(unsigned i=0; i<n; i++){
        y = sin(y);
    }
    printf("Result: %lf\n", y);
}

void task2(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    printf("%u! = ", n);
    for(unsigned i=1; i<n; i++) printf("%u*", i);
    printf("%u\n", n);
    printf("%u! = ", n);
    for(unsigned i=n; i>1; i--) printf("%u*", i);
    printf("%u\n", 1);
}

void task3(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    double x, y, power = 1.0;
    printf("Enter x: ");
    scanf("%lf", &x);
    y = 1.0;
    for(int i=1; i<=n; i++){
        power *= x;
        y += power;
    }
    printf("Result (a): %g\n", y);

    double x_b, y_b, sum_b = 1.0, p_x, p_y = 1.0;
    printf("Enter x for (b): "); scanf("%lf", &x_b);
    printf("Enter y for (b): "); scanf("%lf", &y_b);
    p_x = x_b;
    for(int i=1; i<=n; i++){
        p_y *= y_b;
        p_x *= p_x; // x^(2^i)
        sum_b += p_y * p_x;
    }
    printf("Result (b): %g\n", sum_b);
}

void task4(){
    unsigned n;
    double x, sum = 0, power = 1.0;
    printf("n = "); scanf("%u", &n);
    printf("x = "); scanf("%lf", &x);
    for(unsigned i=1; i<=n; i++){
        power *= x;
        sum += i * power;
    }
    printf("Result: %lf\n", sum);
}

void task5(){
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    unsigned long long double_factorial = 1UL;
    if(n % 2 == 0){
        for(unsigned i=1; i<=n/2; i++) double_factorial *= (2*i);
    } else {
        for(unsigned i=0; i<=n/2; i++) double_factorial *= (2*i+1);
    }
    printf("Double factorial of %u is %llu\n", n, double_factorial);
}

void task6(){
    unsigned n;
    printf("n = "); scanf("%u", &n);
    double res_a = 0, res_b = 0;
    for(int i=0; i<n; i++) res_a = sqrt(2 + res_a);
    for(int i=n; i>=1; i--) res_b = sqrt(3*i + res_b);
    printf("6a: %lf, 6b: %lf\n", res_a, res_b);
}

void task7(){
    unsigned n;
    double x, sum = 1.0, term = 1.0;
    printf("n = "); scanf("%u", &n);
    printf("x = "); scanf("%lf", &x);
    for(unsigned i=1; i<=n; i++){
        term *= x / i;
        sum += term;
    }
    printf("Result: %lf\n", sum);
}

void task8(){
    unsigned m, k = 0; unsigned long long p = 1;
    printf("m = "); scanf("%u", &m);
    while(p * 4 <= m) { p *= 4; k++; }
    printf("k = %u\n", k);
}

void task9(){
    unsigned n, r = 0; unsigned long long p = 1;
    printf("n = "); scanf("%u", &n);
    while(p <= n) { p *= 2; r++; }
    printf("r = %u\n", r);
}

void task10(){
    float a = 1.0f;
    while(a + 1.0f != 1.0f) a /= 2.0f;
    printf("Machine zero: %e\n", a);
}

void task11(){
    int i = 0; double x, sum = 0, prod = 1;
    do {
        printf("a[%d] = ", i);
        scanf("%lf", &x);
        if(x == 0) break;
        sum += x; prod *= x; i++;
    } while(1);
    if(i > 0) {
        printf("Arithmetic mean: %g\n", sum/i);
        printf("Geometric mean: %g\n", pow(prod, 1.0/i));
    } else printf("No numbers entered.\n");
}

void task2() {}
void task3() {}
void task4() {}
void task5() {}
void task6() {}
void task7() {}
void task8() {}
void task9() {}
void task10() {}
void task11() {}