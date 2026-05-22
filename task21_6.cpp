#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Sum {
private:
    T total;
public:
    Sum() : total(0) {}
    void operator()(T n) { 
        total += n; 
    }
    T get_sum() const { 
        return total; 
    }
};
int main() {
    vector<double> vec = {1.5, 2.5, 3.5, 4.5};
    Sum<double> s = for_each(vec.begin(), vec.end(), Sum<double>());
    cout << s.get_sum() << "\n";
    return 0;
}