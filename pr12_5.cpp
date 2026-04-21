#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    char fname[50];
    cout << "File name: ";
    cin >> fname;

    ifstream f(fname);
    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    string line, longest = "";
    while (getline(f, line)) {
        if (line.length() > longest.length()) {
            longest = line;
        }
    }
    f.close();

    cout << "Longest line: " << longest << endl;
    cout << "Length: " << longest.length() << endl;
}