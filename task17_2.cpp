#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class PersonException : public runtime_error {
public:
    PersonException(const string& msg) : runtime_error(msg) {}
};

class Person {
protected:
    string fullname;
    string gender;
    int age;

public:
    Person() : fullname(""), gender(""), age(0) {}
    virtual ~Person() {}

    virtual void input() {
        cout << "ПІБ: ";
        cin.ignore();
        getline(cin, fullname);
        cout << "Стать: ";
        cin >> gender;
        cout << "Вік: ";
        cin >> age;
        if (age < 0 || age > 120) {
            throw PersonException("Некоректний вік особи!");
        }
    }

    virtual void show() const {
        cout << "ПІБ: " << fullname << " | Стать: " << gender << " | Вік: " << age;
    }

    virtual string get_vuz() const {
        return "Не належить до ВНЗ";
    }
};

class Student : virtual public Person {
protected:
    int course;
    string group;
    string vuz;

public:
    Student() : course(0), group(""), vuz("") {}

    void input() override {
        Person::input();
        cout << "Курс: ";
        cin >> course;
        if (course < 1 || course > 6) {
            throw PersonException("Некоректний курс студента!");
        }
        cout << "Група: ";
        cin >> group;
        cout << "ВНЗ (Студент): ";
        cin.ignore();
        getline(cin, vuz);
    }

    void show() const override {
        Person::show();
        cout << " | Курс: " << course << " | Група: " << group << " | ВНЗ: " << vuz;
    }

    string get_vuz() const override { return vuz; }
};

class Teacher : virtual public Person {
protected:
    string vuz;
    string position;

public:
    Teacher() : vuz(""), position("") {}

    void input() override {
        Person::input();
        cout << "ВНЗ (Викладач): ";
        cin.ignore();
        getline(cin, vuz);
        cout << "Посада: ";
        getline(cin, position);
    }

    void show() const override {
        Person::show();
        cout << " | ВНЗ: " << vuz << " | Посада: " << position;
    }

    string get_vuz() const override { return vuz; }
};

class Aspirant : public Student, public Teacher {
public:
    Aspirant() : Person(), Student(), Teacher() {}

    void input() override {
        Person::input();
        cout << "Курс аспірантури: ";
        cin >> course;
        cout << "Група: ";
        cin >> group;
        cout << "Посада (напрям/кафедра): ";
        cin.ignore();
        getline(cin, position);
        cout << "Спільний ВНЗ для Аспіранта: ";
        string shared_vuz;
        getline(cin, shared_vuz);
        Student::vuz = shared_vuz;
        Teacher::vuz = shared_vuz;
    }

    void show() const override {
        Person::show();
        cout << " | Аспірант ВНЗ: " << Student::vuz << " | Курс: " << course << " | Група: " << group << " | Робота: " << position;
    }

    string get_vuz() const override {
        if (Student::vuz != Teacher::vuz) {
            throw PersonException("Помилка узгодження: дані ВНЗ аспіранта суперечать один одному");
        }
        return Student::vuz;
    }
};

int main() {
    int n;
    cout << "Введіть кількість людей: ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<Person*> community;

    for (int i = 0; i < n; i++) {
        cout << "\nОберіть тип (1 - Студент, 2 - Викладач, 3 - Аспірант): ";
        int type;
        cin >> type;
        
        Person* p = nullptr;
        if (type == 1) p = new Student();
        else if (type == 2) p = new Teacher();
        else if (type == 3) p = new Aspirant();
        else {
            cout << "Невірний тип\n";
            i--;
            continue;
        }

        try {
            p->input();
            community.push_back(p);
        } 
        catch (const PersonException& e) {
            cerr << "Помилка введення елемента: " << e.what() << ". Спробуйте ще раз для цієї особи.\n";
            delete p;
            i--;
        }
    }
    cout << "\nСписок зареєстрованих людей та їхні ВНЗ:\n";
    for (auto p : community) {
        p->show();
        try {
            cout << "Визначений ВНЗ: " << p->get_vuz() << "\n";
        } 
        catch (const PersonException& e) {
            cerr << "Помилка визначення ВНЗ: " << e.what() << "\n";
        }
    }
    for (auto p : community) delete p;
}