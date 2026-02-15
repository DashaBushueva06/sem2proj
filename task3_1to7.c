#include <stdio.h>
#include <stdint.h>
#include <math.h>

void task1_a(unsigned n) {
    unsigned char d1 = n % 10;         
    unsigned char d2 = (n / 10) % 10;   
    unsigned char d3 = (n / 100) % 10;  
    printf("Digits: %hhu, %hhu, %hhu\n", d1, d2, d3);
}

void task1_b(unsigned n) {
    unsigned char d1 = n % 10;
    unsigned char d2 = (n / 10) % 10;
    unsigned char d3 = (n / 100) % 10;
    printf("Sum of digits: %hhu\n", d1 + d2 + d3);
}

void task2() {
    int32_t a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int32_t sum = a + b;
    int32_t diff = a - b;
    int32_t prod = a * b;
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
}

void task3(){
    uint64_t a, b, c;
    int k = scanf("%lld, %lld, %lld", &a, &b, &c);
    if(k != 3) {
        printf("Invalid input. Please enter three integers separated by commas.\n");
        return;
    }

    printf("Numbers: %lld, %lld, %lld\n", a, b, c);
    uint64_t product = a * b ;
    uint64_t product2 = product * c;
    printf("Product: %llu %llu, %llu\n", product, product2, 1ULL<<31);
}

void task4(){
    uint8_t a, b;
    printf("Enter two 8-bit unsigned integers (0-255): ");
    int k = scanf("%hhu, %hhu", &a, &b);
    if(k != 2) {
        printf("Invalid input. Please enter two integers between 0 and 255 separated by a comma.\n");
        return;
    }
    printf("You entered: %hhu, %hhu\n", a, b);
    uint16_t product = (uint16_t)a * b; // Use 16-bit to prevent overflow
    printf("Product: %hu\n", product);
}

void task1() {
    unsigned n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    task1_a(n);
}

int max_abs(int x,int y){
    if (fabs(x)>fabs(y)) {
        return x;
    }
        return y;
}

void task5(){
    long a,b;
    printf("Enter two long integers: ");
    int k = scanf("%ld %ld", &a, &b);
    if(k != 2) {
        printf("Invalid input. Please enter two long integers.\n");
        return;
    }
    printf("You entered: %ld, %ld\n", a, b);

    long min = min_of_two_longs(a, b);
    long max = max_of_two_longs(a, b);
    printf("Minimum: %ld\n", min);
    printf("Maximum: %ld\n", max);
}

void task6(){
    int a,b,c;
    printf("Input 3 numbers:");
    scanf("%d %d %d", &a, &b, &c);
    int max_num = max_abs(a,b);
    max_num = max_abs(max_num, c);
    printf("max_num = %d", max_num);
}

void task7_a(){

    double a, b, c;
    printf("Input a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double D = b * b - 4 * a * c; 
    
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        printf("2 розв'язки: x1 = %.2f, x2 = %.2f\n", x1, x2);

    } else if (D == 0) {
        printf("1 розв'язок: x = %.2f\n", -b / (2 * a));

    } else {
        printf("Розв'язків немає.\n");
    }
}

void task7(){

    double a, b, c;
    printf("Input a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double D = b * b - 4 * a * c; 
    
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        printf("2 розв'язки: x1 = %.2f, x2 = %.2f\n", x1, x2);

    } else if (D == 0) {
        printf("1 розв'язок: x = %.2f\n", -b / (2 * a));

    } else {
        printf("Розв'язків немає.\n");
    }
}

int main() {
    //task1_a();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    task7();
} 