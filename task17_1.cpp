#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <numeric>

using namespace std;

class RationalException : public runtime_error {
public:
    RationalException(const string& msg) : runtime_error(msg) {}
};

class Rational {
private:
    int num;
    int den;
    void optimize() {
        if (den == 0) {
            throw RationalException("Знаменник не може дорівнювати нулю!");
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = gcd(abs(num), den);
        num /= g;
        den /= g;
    }

public:
    Rational() : num(0), den(1) {}

    Rational(int n, int d) : num(n), den(d) {
        if (d == 0) {
            throw RationalException("Помилка ініціалізації: знаменник рівний нулю!");
        }
        optimize();
    }
    void set_num(int n) {
        num = n;
        optimize();
    }
    void set_den(int d) {
        if (d == 0) {
            throw RationalException("Помилка setter: знаменник не може бути нулем!");
        }
        den = d;
        optimize();
    }

    int get_num() const { return num; }
    int get_den() const { return den; }

    Rational operator-(const Rational& other) const {
        return Rational(num * other.den - other.num * den, den * other.den);
    }
    Rational operator-(int value) const {
        return Rational(num - value * den, den);
    }

    Rational operator/(const Rational& other) const {
        if (other.num == 0) {
            throw RationalException("Помилка ділення: ділення на нуль (чисельник другого дробу є нулем)!");
        }
        return Rational(num * other.den, den * other.num);
    }
    friend istream& operator>>(istream& in, Rational& r) {
        int n, d;
        if (in >> n >> d) {
            if (d == 0) {
                throw RationalException("Помилка введення: знаменник рівний нулю!");
            }
            r.num = n;
            r.den = d;
            r.optimize();
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.num << "/" << r.den;
        return out;
    }
    friend void write_to_file(const string& filename, const Rational& r) {
        ofstream file(filename);
        if (!file.is_open()) {
            throw RationalException("Помилка: Не вдалося відкрити файл " + filename + " для запису!");
        }
        file << r << "\n";
        file.close();
    }
};

int main() {
    try {
        Rational r1, r2;
        cout << "Введіть перший дріб (чисельник і знаменник): ";
        cin >> r1;
        cout << "Введіть другий дріб (чисельник і знаменник): ";
        cin >> r2;

        cout << "Різниця дробова: " << (r1 - r2) << "\n";
        cout << "Частка: " << (r1 / r2) << "\n";

        write_to_file("rational.txt", r1 - r2);
    } 
    catch (const RationalException& e) {
        cerr << "Обробка виключення в тілі програми: " << e.what() << "\n";
    }
}