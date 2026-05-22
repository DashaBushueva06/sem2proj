#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> input_vector(int dim) {
    vector<double> b;
    for (int i = 0; i < dim; i++) {
        double c;
        cin >> c;
        b.push_back(c);
    }
    return b;
}

double norma(const vector<double> &d) {
    double f = 0;
    for (double g : d) {
        f = f + g * g;
    }
    return sqrt(f);
}

double sum_norma(const vector<vector<double>> &q) {
    double p = 0;
    for (vector<double> g : q) {
        p += norma(g);
    }
    return p;
}

int main() {
    int n, d;
    cout << "Input n, d: ";
    cin >> n >> d;
    
    vector<vector<double>> S;
    for (int i = 0; i < n; i++) {
        vector<double> Z = input_vector(d);
        S.push_back(Z);
    }
    cout << sum_norma(S);
}