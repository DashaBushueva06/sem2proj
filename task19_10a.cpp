#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Auto {
private:
    string brand;  
    string model;
    string number;
    int owner_id;  

public:
    Auto() : brand(""), model(""), number(""), owner_id(0) {}
    Auto(string b, string m, string n, int id) 
        : brand(b), model(m), number(n), owner_id(id) {}

    void input() {
        cout << "Марка: ";
        cin >> brand;
        cout << "Модель: ";
        cin >> model;
        cout << "Номер: ";
        cin >> number;
        cout << "ID власника: ";
        cin >> owner_id;
    }

    void output() const {
        cout << "Марка: " << brand 
             << " | Модель: " << model 
             << " | Номер: " << number 
             << " | ID власника: " << owner_id << endl;
    }
    string get_brand() const {
        return brand;
    }
};

int main() {
    int n;
    cout << "Введіть кількість автомобілів: ";
    cin >> n;
    vector<Auto> garage;

    for (int i = 0; i < n; i++) {
        cout << "\nВведіть дані для авто #" << i + 1 << ":\n";
        Auto temp;
        temp.input();
        garage.push_back(temp);
    }

    string search_brand;
    cout << "\nВведіть марку автомобіля для пошуку: ";
    cin >> search_brand;
    cout << "\nРезультати пошуку для марки \"" << search_brand << "\":\n";
    bool found = false;
    
    for (const auto& car : garage) {
        if (car.get_brand() == search_brand) {
            car.output();
            found = true;
        }
    }
    if (!found) {
        cout << "Автомобілів марки " << search_brand << " не знайдено." << endl;
    }
}