#include <iostream>
#include <cmath>
#include "Rat.h"

int main() {
    Fraction r1; 
    std::cout << "r1: ";
    r1.output();
    std::cout << std::endl;

    Fraction r2(6, 8);
    std::cout << "r2 (6/8): ";
    r2.output();
    std::cout << std::endl;

    Fraction r3;
    r3.input();
    std::cout << "r3: ";
    r3.output();
    std::cout << std::endl;

    Fraction sum = r2 + r3;
    Fraction product = r2 * r3;

    std::cout << "r2 + r3 = ";
    sum.output();
    std::cout << std::endl;

    std::cout << "r2 * r3 = ";
    product.output();
    std::cout << std::endl;

    if (r2 > r3) {
        std::cout << "r2 > r3" << std::endl;
    } else if (r2 < r3) {
        std::cout << "r2 < r3" << std::endl;
    } else {
        std::cout << "r2 == r3" << std::endl;
    }

    Fraction arr[] = { Fraction(1, 2), Fraction(-3, 4), Fraction(5, 6), Fraction(-1, 8), Fraction(2, 3) };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Fraction min_frac = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_frac) {
            min_frac = arr[i];
        }
    }
    
    std::cout << "Масив: ";
    for (int i = 0; i < n; ++i) {
        arr[i].output();
        std::cout << "  ";
    }
    std::cout << "\nНайменше раціональне число в масиві: ";
    min_frac.output();
    std::cout << std::endl;

    Fraction series_sum(0, 1);
    int n_term = 1;
    int sign = 1;
    double term_val;

    do {
        Fraction term(sign, n_term * n_term);
        series_sum = series_sum + term;
        term_val = std::abs(term.toDouble());
        sign = -sign;
        n_term++;
    } while (term_val >= 0.01);

    std::cout << "\nСума ряду з точністю 0.01: ";
    series_sum.output();
    std::cout << " (у десятковому вигляді: " << series_sum.toDouble() << ")" << std::endl;

    double pi_squared_over_12 = (std::acos(-1.0) * std::acos(-1.0)) / 12.0;
    std::cout << "Значення pi^2 / 12: " << pi_squared_over_12 << std::endl;
    
    if (std::abs(series_sum.toDouble() - pi_squared_over_12) < 0.05) {
        std::cout << "Ряд дійсно сходиться до відповідного числа" << std::endl;
    }
}