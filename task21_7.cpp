#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) return 0;
    string word = argv[1];
    sort(word.begin(), word.end());
    do {
        cout << word << "\n";
    } while (next_permutation(word.begin(), word.end()));

}