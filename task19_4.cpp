#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int get_max_element(const list<int>& lst) {
    auto max_it = max_element(lst.begin(), lst.end());
    return *max_it;
}

int main() {
    int n, m;
    cout << "Введіть розміри матриці n та m: ";
    cin >> n >> m;

    vector<list<int>> matrix(n);

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < n; i++) {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            int element;
            cin >> element;
            matrix[i].push_back(element);
        }
    }
    sort(matrix.begin(), matrix.end(), [](const list<int>& a, const list<int>& b) {
        return get_max_element(a) > get_max_element(b);
    });

    cout << "\nВідсортована матриця:\n";
    for (int i = 0; i < n; i++) {
        int row_max = get_max_element(matrix[i]);
        cout << "[Максимум: " << row_max << "] -> ";
        for (int val : matrix[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}