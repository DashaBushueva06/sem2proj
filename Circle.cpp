#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() : x(0), y(0), r(1) {}

Circle::Circle(double x, double y, double r) : x(x), y(y) {
    if (r < 0) {
        this->r = 0;
    } else {
        this->r = r;
    }
}

double Circle::getX() const { return x; }
double Circle::getY() const { return y; }
double Circle::getR() const { return r; }

double Circle::getDiameter() const {
    return 2 * r;
}

double Circle::getArea() const {
    return std::acos(-1.0) * r * r;
}

double Circle::getPerimeter() const {
    return 2 * std::acos(-1.0) * r;
}

int Circle::getIntersection(const Circle& other, Point* points) const {
    double d = std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));

    if (d > r + other.r || d < std::abs(r - other.r) || (d == 0 && r == other.r)) {
        return 0;
    }

    double a = (r * r - other.r * other.r + d * d) / (2 * d);
    double h = std::sqrt(std::abs(r * r - a * a));
    
    double x3 = x + a * (other.x - x) / d;
    double y3 = y + a * (other.y - y) / d;

    if (d == r + other.r || d == std::abs(r - other.r)) {
        points[0].x = x3;
        points[0].y = y3;
        return 1;
    }

    points[0].x = x3 + h * (other.y - y) / d;
    points[0].y = y3 - h * (other.x - x) / d;
    points[1].x = x3 - h * (other.y - y) / d;
    points[1].y = y3 + h * (other.x - x) / d;

    return 2;
}