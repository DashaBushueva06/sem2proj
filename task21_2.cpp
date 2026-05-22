#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    if (!(cin >> n >> x)) return 0;

    list<int> lst;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        lst.push_back(val);
    }

    stable_partition(lst.begin(), lst.end(), [x](int elem) {
        return elem <= x; 
    });

    for (int val : lst) {
        cout << val << " ";
    }
    cout << "\n";
}