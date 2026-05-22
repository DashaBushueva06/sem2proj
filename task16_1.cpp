#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    unsigned byear;

public:
    Person() : name(""), byear(0) {}
    Person(string n, unsigned y) : name(n), byear(y) {}

    virtual int input() {
        cin >> name >> byear;
        return 1;
    }
    virtual void show() const {
        cout << name << " " << byear;
    }
    string get_name() const { return name; }

    friend fstream& operator>>(fstream& in, Person& p) {
        in >> p.name >> p.byear;
        return in;
    }
    friend fstream& operator<<(fstream& out, const Person& p) {
        out << p.name << " " << p.byear << " ";
        return out;
    }
};

class Znayomiy : public Person {
private:
    string phone;

public:
    Znayomiy() : Person(), phone("") {}
    Znayomiy(string n, unsigned y, string p) : Person(n, y), phone(p) {}

    int input() override {
        Person::input();
        cin >> phone;
        return 1;
    }
    void show() const override {
        Person::show();
        cout << " " << phone;
    }

    string get_phone() const { return phone; }
    void set_phone(string p) { phone = p; }

    friend fstream& operator>>(fstream& in, Znayomiy& z) {
        string n;
        unsigned y;
        if (in >> n >> y >> z.phone) {
            z.name = n;
            z.byear = y;
        }
        return in;
    }
    friend fstream& operator<<(fstream& out, const Znayomiy& z) {
        out << z.name << " " << z.byear << " " << z.phone << "\n";
        return out;
    }
};

class PhoneBook {
private:
    vector<Znayomiy> list;
    const size_t max_size = 100;
    string filename;
    void load_from_file() {
        list.clear();
        fstream file(filename, ios::in);
        if (!file.is_open()) return;
        Znzack:
        Znayomiy z;
        while (file >> z) {
            if (list.size() < max_size) {
                list.push_back(z);
            }
        }
        file.close();
    }
    void save_to_file() {
        fstream file(filename, ios::out);
        if (!file.is_open()) return;
        for (const auto& z : list) {
            file << z;
        }
        file.close();
    }

public:
    PhoneBook(string file) : filename(file) {
        load_from_file();
    }
    void add_znayomiy() {
        if (list.size() >= max_size) {
            return;
        }
        Znayomiy z;
        z.input();
        list.push_back(z);
        save_to_file();
    }
    void find_phone_by_name() const {
        string search_name;
        cin >> search_name;
        for (const auto& z : list) {
            if (z.get_name() == search_name) {
                z.show();
                cout << "\n";
                return;
            }
        }
    }
    void change_phone_by_name() {
        string search_name, new_phone;
        cin >> search_name >> new_phone;
        for (auto& z : list) {
            if (z.get_name() == search_name) {
                z.set_phone(new_phone);
                save_to_file();
                return;
            }
        }
    }
    void print_all() const {
        for (const auto& z : list) {
            z.show();
            cout << "\n";
        }
    }
};

int main() {
}