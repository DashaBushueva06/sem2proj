#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y, z;
};

double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main() {
    char fname[] = "points.txt";
    ifstream f(fname);
    if (!f.is_open()) {
        cerr << "Error" << endl;
        return -1;
    }

    vector<Point> p;
    Point temp;
    char c;
    while (f >> temp.x >> c >> temp.y >> c >> temp.z >> c) {
        p.push_back(temp);
    }
    f.close();

    double max_d = 0;
    Point p1, p2;

    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            double d = dist(p[i], p[j]);
            if (d > max_d) {
                max_d = d;
                p1 = p[i];
                p2 = p[j];
            }
        }
    }

    cout << "Max distance: " << max_d << endl;
    cout << "Point 1: " << p1.x << " " << p1.y << " " << p1.z << endl;
    cout << "Point 2: " << p2.x << " " << p2.y << " " << p2.z << endl;
}