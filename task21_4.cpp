#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

clock_t time_generator() {
    return clock();
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    list<clock_t> times;
    generate_n(back_inserter(times), n, time_generator);
    times.sort();
    times.unique();
    copy(times.begin(), times.end(), ostream_iterator<clock_t>(cout, " "));
    cout << "\n";
}