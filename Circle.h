#ifndef CIRCLE_H
#define CIRCLE_H

struct Point {
    double x;
    double y;
};

class Circle {
private:
    double x;
    double y;
    double r;

public:
    Circle();
    Circle(double x, double y, double r);

    double getX() const;
    double getY() const;
    double getR() const;

    double getDiameter() const;
    double getArea() const;
    double getPerimeter() const;

    int getIntersection(const Circle& other, Point* points) const;
};

#endif