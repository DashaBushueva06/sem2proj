#include "Rat.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Fraction::gcd(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Fraction::reduce() {
    int common_divisor = gcd(nom, den);
    nom /= common_divisor;
    den /= common_divisor;
    
    if (den < 0) {
        nom = -nom;
        den = -den;
    }
}

Fraction::Fraction() : nom(1), den(1) {}

Fraction::Fraction(int n, int d) {
    nom = n;
    if (d == 0) {
        std::cerr << "Знаменник 0. Встановлено 1." << std::endl;
        den = 1;
    } else {
        den = d;
    }
    reduce();
}

void Fraction::setNom(int n) {
    nom = n;
    reduce();
}

void Fraction::setDen(int d) {
    if (d == 0) {
        std::cerr << "Знаменник не може бути 0" << std::endl;
        return;
    }
    den = d;
    reduce();
}

void Fraction::input() {
    std::cout << "Введіть nom: ";
    std::cin >> nom;
    int d;
    do {
        std::cout << "Введіть den (не 0): ";
        std::cin >> d;
        if (d == 0) {
            std::cout << "Помилка!" << std::endl;
        }
    } while (d == 0);
    den = d;
    reduce();
}

void Fraction::output() const {
    if (den == 1) {
        std::cout << nom;
    } else {
        std::cout << nom << "/" << den;
    }
}

double Fraction::toDouble() const {
    return static_cast<double>(nom) / den;
}

Fraction Fraction::add(const Fraction& other) const {
    return Fraction(nom * other.den + other.nom * den,
                    den * other.den);
}

Fraction Fraction::multiply(const Fraction& other) const {
    return Fraction(nom * other.nom, den * other.den);
}

Fraction Fraction::operator+(const Fraction& other) const { return add(other); }
Fraction Fraction::operator*(const Fraction& other) const { return multiply(other); }

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(nom * other.den - other.nom * den,
                    den * other.den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.nom == 0) {
        std::cerr << "Помилка: Ділення на 0!" << std::endl;
        return *this; 
    }
    return Fraction(nom * other.den, den * other.nom);
}

bool Fraction::operator==(const Fraction& other) const {
    return (nom == other.nom && den == other.den);
}

bool Fraction::operator!=(const Fraction& other) const { 
    return !(*this == other); 
}

bool Fraction::operator<(const Fraction& other) const {
    return (nom * other.den < other.nom * den);
}

bool Fraction::operator>(const Fraction& other) const {
    return (nom * other.den > other.nom * den);
}