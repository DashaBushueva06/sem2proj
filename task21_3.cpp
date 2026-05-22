#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int sum_k_largest(vector<int> vec, int k) {
    if (k > vec.size()) return 0;
    sort(vec.begin(), vec.end(), greater<int>());
    return accumulate(vec.begin(), vec.begin() + k, 0);
}

vector<int> get_k_smallest(vector<int> vec, int k) {
    if (k > vec.size()) return vector<int>();
    sort(vec.begin(), vec.end());
    return vector<int>(vec.begin(), vec.begin() + k);
}

int main() {
    return 0;
}