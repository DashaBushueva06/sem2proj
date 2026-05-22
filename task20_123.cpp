#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

void task1() {
    ifstream file("input.txt");
    if (!file.is_open()) return;

    map<string, int> word_count;
    string word;

    while (file >> word) {
        string clean_word = "";
        for (char ch : word) {
            if (isalnum(ch)) {
                clean_word += ch;
            }
        }
        if (!clean_word.empty()) {
            word_count[clean_word]++;
        }
    }
    file.close();

    for (const auto& pair : word_count) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

void task2() {
    int n;
    if (!(cin >> n) || n <= 0) return;

    multiset<double> numbers;
    for (int i = 0; i < n; i++) {
        double val;
        cin >> val;
        numbers.insert(val);
    }

    while (numbers.size() > 1) {
        auto it1 = numbers.begin();
        auto it2 = next(it1);
        
        double sum = *it1 + *it2;
        
        numbers.erase(it1);
        numbers.erase(it2);
        
        numbers.insert(sum);
    }

    if (!numbers.empty()) {
        cout << *numbers.begin() << "\n";
    }
}

struct Point {
    int x1, x2;
};

struct Segment {
    Point p1, p2;
    double length;
};

void task3() {
    ifstream infile("points.txt");
    if (!infile.is_open()) return;

    vector<Point> points;
    string token;

    while (getline(infile, token, ')')) {
        size_t start = token.find('(');
        if (start == string::npos) continue;
        
        string coords = token.substr(start + 1);
        stringstream ss(coords);
        string val1, val2;
        
        if (getline(ss, val1, ',') && getline(ss, val2)) {
            Point p;
            p.x1 = stoi(val1);
            p.x2 = stoi(val2);
            points.push_back(p);
        }
    }
    infile.close();

    vector<Segment> segments;
    int m = points.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            Segment seg;
            seg.p1 = points[i];
            seg.p2 = points[j];
            seg.length = sqrt(pow(points[i].x1 - points[j].x1, 2) + pow(points[i].x2 - points[j].x2, 2));
            segments.push_back(seg);
        }
    }

    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.length < b.length;
    });

    ofstream outfile("segments.txt");
    if (!outfile.is_open()) return;

    for (const auto& seg : segments) {
        outfile << "(" << seg.p1.x1 << " , " << seg.p1.x2 << ") , "
                << "(" << seg.p2.x1 << " , " << seg.p2.x2 << ")\n";
    }
    outfile.close();
}

int main() {
    return 0;
}