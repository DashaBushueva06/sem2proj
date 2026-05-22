#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point3D {
    int x1, x2, x3;
};
struct Segment3D {
    Point3D p1, p2;
    double length;
};

int main() {
    ifstream infile("points3d.txt");
    if (!infile.is_open()) {
        return 1;
    }
    vector<Point3D> points;
    string token;

    while (getline(infile, token, ':')) {
        stringstream ss(token);
        string val1, val2, val3;
        
        if (getline(ss, val1, ',') && getline(ss, val2, ',') && getline(ss, val3)) {
            Point3D p;
            p.x1 = stoi(val1);
            p.x2 = stoi(val2);
            p.x3 = stoi(val3);
            points.push_back(p);
        }
    }
    infile.close();

    vector<Segment3D> segments;
    size_t m = points.size();
    
    for (size_t i = 0; i < m; i++) {
        for (size_t j = i + 1; j < m; j++) {
            Segment3D seg;
            seg.p1 = points[i];
            seg.p2 = points[j];
            seg.length = sqrt(pow(points[i].x1 - points[j].x1, 2) + 
                              pow(points[i].x2 - points[j].x2, 2) + 
                              pow(points[i].x3 - points[j].x3, 2));
            segments.push_back(seg);
        }
    }
    sort(segments.begin(), segments.end(), [](const Segment3D& a, const Segment3D& b) {
        return a.length < b.length;
    });

    ofstream outfile("segments3d.txt");
    if (!outfile.is_open()) {
        return 1;
    }
    for (const auto& seg : segments) {
        outfile << seg.p1.x1 << "," << seg.p1.x2 << "," << seg.p1.x3 << " : "
                << seg.p2.x1 << "," << seg.p2.x2 << "," << seg.p2.x3 << "\n";
    }
    outfile.close();
}