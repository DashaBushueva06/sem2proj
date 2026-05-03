#ifndef RAT_H
#define RAT_H

class Fraction {
private:
    int nom;
    int den;

    int gcd(int a, int b) const;
    void reduce();

public:
    Fraction();
    Fraction(int nom, int den);

    void setNom(int nom);
    void setDen(int den);

    void input();
    void output() const;
    double toDouble() const;

    Fraction add(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
};

#endif