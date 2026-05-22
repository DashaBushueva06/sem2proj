#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BoolVector {
private:
    vector<bool> vec;

public:
    BoolVector() {}
    BoolVector(const vector<bool>& v) : vec(v) {}

    void input() {
        int n;
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            vec[i] = (val != 0);
        }
    }

    void output() const {
        for (bool b : vec) cout << b << " ";
        cout << "\n";
    }

    BoolVector conj(const BoolVector& other) const {
        vector<bool> res(min(vec.size(), other.vec.size()));
        transform(vec.begin(), vec.begin() + res.size(), other.vec.begin(), res.begin(), logical_and<bool>());
        return BoolVector(res);
    }

    BoolVector disj(const BoolVector& other) const {
        vector<bool> res(min(vec.size(), other.vec.size()));
        transform(vec.begin(), vec.begin() + res.size(), other.vec.begin(), res.begin(), logical_or<bool>());
        return BoolVector(res);
    }

    BoolVector invert() const {
        vector<bool> res(vec.size());
        transform(vec.begin(), vec.end(), res.begin(), logical_not<bool>());
        return BoolVector(res);
    }

    pair<int, int> count_zeros_ones() const {
        int ones = count(vec.begin(), vec.end(), true);
        return {vec.size() - ones, ones};
    }
};

int main() {
}