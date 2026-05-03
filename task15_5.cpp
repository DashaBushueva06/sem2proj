#include <iostream>
#include <vector>
#include "Circle.h"

void printCenterOfMass(const std::vector<Circle>& circles) {
    if (circles.empty()) {
        std::cout << "Немає кіл для розрахунку.\n";
        return;
    }

    double sumX = 0;
    double sumY = 0;
    double totalArea = 0;

    for (const auto& c : circles) {
        double area = c.getArea();
        sumX += c.getX() * area;
        sumY += c.getY() * area;
        totalArea += area;
    }

    if (totalArea == 0) {
        std::cout << "Загальна площа дорівнює нулю.\n";
    } else {
        std::cout << "Центр мас системи кіл: (" 
                  << sumX / totalArea << ", " 
                  << sumY / totalArea << ")\n";
    }
}

int main() {
    std::vector<Circle> circles;
    int choice;

    do {
        std::cout << "\n1. Додати коло\n"
                  << "2. Видалити коло \n"
                  << "3. Вирахувати центр мас\n"
                  << "4. Знайти перетин двох перших кіл\n"
                  << "5. Вивести інформацію про всі кола\n"
                  << "0. Вийти\n"
                  << "Вибір: ";
        std::cin >> choice;

        if (choice == 1) {
            double x, y, r;
            std::cout << "Введіть X, Y та радіус: ";
            std::cin >> x >> y >> r;
            circles.push_back(Circle(x, y, r));
        } 
        else if (choice == 2) {
            if (!circles.empty()) {
                circles.pop_back();
                std::cout << "Останнє коло видалено.\n";
            } else {
                std::cout << "Список порожній.\n";
            }
        } 
        else if (choice == 3) {
            printCenterOfMass(circles);
        } 
        else if (choice == 4) {
            if (circles.size() >= 2) {
                Point pts[2];
                int count = circles[0].getIntersection(circles[1], pts);
                std::cout << "Кількість точок перетину: " << count << "\n";
                for (int i = 0; i < count; ++i) {
                    std::cout << "Точка " << i + 1 << ": (" << pts[i].x << ", " << pts[i].y << ")\n";
                }
            } else {
                std::cout << "Потрібно щонайменше 2 кола.\n";
            }
        }
        else if (choice == 5) {
            for (size_t i = 0; i < circles.size(); ++i) {
                std::cout << "Коло " << i + 1 << ": Центр(" << circles[i].getX() 
                          << ", " << circles[i].getY() << "), Радіус=" << circles[i].getR() 
                          << ", S=" << circles[i].getArea() << ", P=" << circles[i].getPerimeter() << "\n";
            }
        }
    } while (choice != 0);
}