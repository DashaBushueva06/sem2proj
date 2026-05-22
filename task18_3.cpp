#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class BlackBoxException : public runtime_error {
public:
    BlackBoxException(const string& msg) : runtime_error(msg) {}
};

template <typename T>
class BlackBox {
private:
    vector<T> data;
    const size_t max_size = 100;
public:
    BlackBox() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }
    BlackBox(const T* arr, size_t size) {
        srand(static_cast<unsigned int>(time(nullptr)));
        size_t limit = min(size, max_size);
        for (size_t i = 0; i < limit; i++) {
            data.push_back(arr[i]);
        }
    }
    void push(const T& element) {
        if (data.size() >= max_size) {
            throw BlackBoxException("Помилка push: Чорна скринька переповнена (макс. 100 елементів)!");
        }
        for (const auto& item : data) {
            if (item == element) {
                throw BlackBoxException("Помилка push: Такий елемент уже існує в чорній скриньці!");
            }
        }
        data.push_back(element);
    }
    T pop() {
        if (data.empty()) {
            throw BlackBoxException("Помилка pop: Чорна скринька порожня!");
        }
        int index = rand() % data.size();
        T element = data[index];
        data.erase(data.begin() + index);
        return element;
    }
    T xpop() {
        if (data.empty()) {
            throw BlackBoxException("Помилка xpop: Чорна скринька порожня!");
        }
        int index = rand() % data.size();
        return data[index];
    }
    size_t size() const {
        return data.size();
    }
};
int main() {
    try {
        BlackBox<int> box;
        box.push(10);
        box.push(20);
        box.push(30);

        cout << "Випадковий елемент без видалення (xpop): " << box.xpop() << "\n";
        cout << "Видалений випадковий елемент (pop): " << box.pop() << "\n";
        cout << "Поточний розмір: " << box.size() << "\n";
    }
    catch (const BlackBoxException& e) {
        cerr << "Виключення BlackBox: " << e.what() << "\n";
    }
}