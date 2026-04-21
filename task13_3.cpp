#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string remove_last(const string &s) {
    stringstream u(s);
    string word, result = "";
    while (u >> word) {
        result += word;
        result[result.length() - 1] = ' ';
    }
    return result;
}