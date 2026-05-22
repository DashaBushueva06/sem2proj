#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};
struct Segment {
    Point p1, p2;
};

bool get_intersection(Segment s1, Segment s2, Point& intersect) {
    double A1 = s1.p2.y - s1.p1.y;
    double B1 = s1.p1.x - s1.p2.x;
    double C1 = A1 * s1.p1.x + B1 * s1.p1.y;
    double A2 = s2.p2.y - s2.p1.y;
    double B2 = s2.p1.x - s2.p2.x;
    double C2 = A2 * s2.p1.x + B2 * s2.p1.y;
    double det = A1 * B2 - A2 * B1;

    if (abs(det) < 1e-9) {
        return false;
    }

    double x = (B2 * C1 - B1 * C2) / det;
    double y = (A1 * C2 - A2 * C1) / det;
    auto on_segment = [](double q, double r, double t) {
        return t >= min(q, r) - 1e-9 && t <= max(q, r) + 1e-9;
    };

    if (on_segment(s1.p1.x, s1.p2.x, x) && on_segment(s1.p1.y, s1.p2.y, y) &&
        on_segment(s2.p1.x, s2.p2.x, x) && on_segment(s2.p1.y, s2.p2.y, y)) {
        intersect.x = x;
        intersect.y = y;
        return true;
    }
    return false;
}

int main() {
    int n;
    if (!(cin >> n) || n < 2) return 0;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x >> segments[i].p2.y;
    }
    map<double, Point> intersections;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point pt;
            if (get_intersection(segments[i], segments[j], pt)) {
                intersections[pt.x] = pt;
            }
        }
    }

    if (!intersections.empty()) {
        Point min_x_point = intersections.begin()->second;
        cout << min_x_point.x << " " << min_x_point.y << "\n";
    } else{
        cout << "No intersections found\n";
    }
}