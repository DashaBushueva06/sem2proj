#include <iostream>
#include <string>

using namespace std;

void mod_str(string &s) {
    int first_st = s.find_first_of(",");
    int last_st = s.find_last_of(",");
    if (first_st == string::npos) {
        while (s[0] == ' ') {
            s.erase(0, 1);
        }
        return;
    }
    if (first_st == last_st) {
        s.erase(0, last_st - first_st);
        return;
    }
    s = s.substr(first_st, last_st - first_st);
}

int main() {
    string u;
    getline(cin, u);
    mod_str(u);
    cout << u;
}