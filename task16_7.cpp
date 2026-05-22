#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.1415926535;

struct Point { 
    double x, y; 
};

class Figure {
protected:
    Point center;
public:
    Figure(Point c) : center(c) {}
    virtual ~Figure() {}
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    void move(double dx, double dy) { center.x += dx; center.y += dy; }
    virtual void rotate(double angle) {}
    
    // Спрощена перевірка перетину: через радіуси описаних кіл
    virtual double get_radius() const = 0;
    bool intersects(Figure* other) {
        double dist = sqrt(pow(center.x - other->center.x, 2) + pow(center.y - other->center.y, 2));
        return dist < (this->get_radius() + other->get_radius());
    }
};

class Trapezoid : public Figure {
    double a, b, c, d, h;
public:
    Trapezoid(Point ctr, double base1, double base2, double side1, double side2, double height) 
        : Figure(ctr), a(base1), b(base2), c(side1), d(side2), h(height) {}
    double perimeter() const override { return a + b + c + d; }
    double area() const override { return 0.5 * (a + b) * h; }
    double get_radius() const override { return max({a, b, c, d}); }
};

class Parallelogram : public Figure {
    double a, b, h;
public:
    Parallelogram(Point ctr, double side1, double side2, double height) 
        : Figure(ctr), a(side1), b(side2), h(height) {}
    double perimeter() const override { return 2 * (a + b); }
    double area() const override { return a * h; }
    double get_radius() const override { return max(a, b); }
};

class Circle : public Figure {
    double r;
public:
    Circle(Point ctr, double radius) : Figure(ctr), r(radius) {}
    double perimeter() const override { return 2 * PI * r; }
    double area() const override { return PI * r * r; }
    double get_radius() const override { return r; }
};

int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<Figure*> figs;

    for (int i = 0; i < n; i++) {
        int type; Point ctr; cin >> type >> ctr.x >> ctr.y;
        if (type == 1) { double a, b, c, d, h; cin >> a >> b >> c >> d >> h; figs.push_back(new Trapezoid(ctr, a, b, c, d, h)); }
        else if (type == 2) { double a, b, h; cin >> a >> b >> h; figs.push_back(new Parallelogram(ctr, a, b, h)); }
        else if (type == 3) { double r; cin >> r; figs.push_back(new Circle(ctr, r)); }
    }
    vector<Figure*> valid;
    for (auto f : figs) {
        if (all_of(valid.begin(), valid.end(), [f](Figure* v) { return !f->intersects(v); })) 
            valid.push_back(f);
    }
    double total_a = 0, total_p = 0, max_a = 0;
    for (auto f : valid) {
        total_a += f->area();
        total_p += f->perimeter();
        max_a = max(max_a, f->area());
    }
    cout << total_a << " " << total_p << "\n" << max_a << "\n";
    for (auto f : figs) delete f;
}