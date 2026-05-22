#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace MyNamespace {
    template <typename T>
    T my_max(T a, T b) {
        return (a > b) ? a : b;
    }
    template <>
    const char* my_max<const char*>(const char* a, const char* b) {
        return (strcmp(a, b) > 0) ? a : b;
    }
    class Rational {
    private:
        int num;
        int den;
    public:
        Rational() : num(0), den(1) {}
        Rational(int n, int d) : num(n), den(d) {}

        bool operator>(const Rational& other) const {
            return (num * other.den) > (other.num * den);
        }
        friend ostream& operator<<(ostream& out, const Rational& r) {
            out << r.num << "/" << r.den;
            return out;
        }
    };
}

int main() {
    using namespace MyNamespace;
    cout << my_max(5, 10) << "\n";
    cout << my_max(5.7, 3.1) << "\n";
    cout << my_max("яблуко", "груша") << "\n";
    Rational r1(1, 2), r2(2, 3);
    cout << my_max(r1, r2) << "\n";

}