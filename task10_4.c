#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int numerator;    
    unsigned int denominator;
} Rational;

void reduce(Rational *x) {
    int a = x->numerator;
    if (a < 0) a = -a;
    int b = x->denominator;
    
    while (b) {
        a %= b;
        int t = a; a = b; b = t;
    }
    int common = a; 

    x->numerator /= common;
    x->denominator /= common;
}

Rational sum(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    res.denominator = a.denominator * b.denominator;
    reduce(&res);
    return res;
}

Rational product(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;
    reduce(&res);
    return res;
}

int compare(Rational a, Rational b) {
    long long left = (long long)a.numerator * b.denominator;
    long long right = (long long)b.numerator * a.denominator;
    if (left > right) return 1;
    if (left < right) return -1;
    return 0;
}

int input_Rational(Rational *x) {
    printf("Ведіть чисельник та знаменник: ");
    scanf("%d %u", &(*x).numerator, &x->denominator);
    
    if (x->denominator == 0) {
        printf("Знаменник не може бути нулем!\n");
        return false;
    }  
    reduce(x);
    return true;
}

void print_Rational(Rational x) {
    printf("%d/%u", x.numerator, x.denominator);
}

int main() {
    Rational r1, r2;
    if (input_Rational(&r1)) {
        if (input_Rational(&r2)) {
            printf("\nПерше число: "); print_Rational(r1);
            printf("\nДруге число: "); print_Rational(r2);

            Rational s = sum(r1, r2);
            printf("\n\nСума: "); print_Rational(s);

            Rational p = product(r1, r2);
            printf("\nДобуток: "); print_Rational(p);

            int res = compare(r1, r2);
            if (res == 1) printf("\n\nРезультат: Перше число більше");
            else if (res == -1) printf("\n\nРезультат: Друге число більше");
            else printf("\n\nРезультат: Числа рівні");
            printf("\n");
        }
    }
}