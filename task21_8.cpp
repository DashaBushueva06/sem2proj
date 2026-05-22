#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) return 0;
    vector<string> words;
    for (int i = 1; i < argc; i++) {
        words.push_back(argv[i]);
    }
    sort(words.begin(), words.end());
    do {
        for (size_t i = 0; i < words.size(); i++) {
            cout << words[i] << (i + 1 == words.size() ? "" : " ");
        }
        cout << "\n";
    } while (next_permutation(words.begin(), words.end()));
}