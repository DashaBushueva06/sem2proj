#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template <typename T>
class Polynome {
    list<T> c;

public:
    Polynome() {}
    Polynome(list<T> lst) : c(lst) {}

    void input() {
        c.clear();
        cout << "Введіть степінь полінома: ";
        int n;
        cin >> n;
        cout << "Введіть " << n + 1 << " коефіцієнтів:\n";
        for (int i = 0; i <= n; i++) {
            T x;
            cin >> x;
            c.push_back(x);
        }
    }

    void output() const {
        int power = 0;
        auto it = c.begin();
        for (; it != c.end(); ++it) {
            if (it != c.begin() && *it >= 0) cout << " + ";
            cout << *it << "x^" << power;
            power++;
        }
        cout << endl;
    }

    Polynome operator+(const Polynome& other) {
        list<T> res;
        auto it1 = c.begin();
        auto it2 = other.c.begin();
        
        while (it1 != c.end() || it2 != other.c.end()) {
            T sum = 0;
            if (it1 != c.end()) { sum += *it1; ++it1; }
            if (it2 != other.c.end()) { sum += *it2; ++it2; }
            res.push_back(sum);
        }
        return Polynome(res);
    }

    Polynome operator-(const Polynome& other) {
        list<T> res;
        auto it1 = c.begin();
        auto it2 = other.c.begin();
        
        while (it1 != c.end() || it2 != other.c.end()) {
            T diff = 0;
            if (it1 != c.end()) { diff += *it1; ++it1; }
            if (it2 != other.c.end()) { diff -= *it2; ++it2; }
            res.push_back(diff);
        }
        return Polynome(res);
    }
};

int main() {
    Polynome<double> p1, p2;
    cout << "Поліном 1\n";
    p1.input();
    
    cout << "Поліном 2\n";
    p2.input();
    
    cout << "\nПоліном 1: "; p1.output();
    cout << "Поліном 2: "; p2.output();
    
    Polynome<double> p_sum = p1 + p2;
    cout << "Сума: "; p_sum.output();
    
    Polynome<double> p_diff = p1 - p2;
    cout << "Різниця: "; p_diff.output();
}