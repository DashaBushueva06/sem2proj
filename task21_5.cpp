#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { 
        return toupper(c); 
    });
    cout << s << "\n";
}