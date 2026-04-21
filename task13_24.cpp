#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int total_chars = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            total_chars++;
        }
    }

    if (total_chars == 0) return 0;

    stringstream ss(s);
    string word;
    while (ss >> word) {
        double percent = (double)word.length() / total_chars * 100;
        cout << word << ": " << fixed << setprecision(2) << percent << "%" << endl;
    }
}