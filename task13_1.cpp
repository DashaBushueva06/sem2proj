#include <iostream>
#include <string>

using namespace std;

string good_str(const string &s) {
    int first_st = s.find_first_of(":");
    int last_st = s.find_last_of(":");
    if (last_st <= first_st) {
        return "";
    }
    return s.substr(first_st, last_st - first_st + 1);
}

int main() {
    string u;
    getline(cin, u);
    string v = good_str(u);
    cout << v;
}