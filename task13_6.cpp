#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int partio_parse(const string &s, double *mas, int n) {
    stringstream u(s);
    double v;
    int a = 0;
    while (a < n && u >> v) {
        mas[a] = v;
        a++;
    }
    return a;
}

int main() {
    string b;
    getline(cin, b);
    int n;
    cin >> n;
    double *c = new double[n];
    int k = partio_parse(b, c, n);
    for (int d = 0; d < k; d++) {
        cout << "a[" << d << "]=" << c[d] << " ";
    }
    delete[] c;
}