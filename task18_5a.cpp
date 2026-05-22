#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class ArrayProcessor {
private:
    T* arr;
    int size;

public:
    ArrayProcessor(int s) : size(s) {
        arr = new T[size];
    }
    ArrayProcessor(const T* source_arr, int s) : size(s) {
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = source_arr[i];
        }
    }
    ~ArrayProcessor() {
        delete[] arr;
    }
    void bubble_sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    static void bubble_sort_static(T* data_arr, int data_size) {
        for (int i = 0; i < data_size - 1; i++) {
            for (int j = 0; j < data_size - i - 1; j++) {
                if (data_arr[j] > data_arr[j + 1]) {
                    swap(data_arr[j], data_arr[j + 1]);
                }
            }
        }
    }
    void input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n = 5;
    ArrayProcessor<double> my_arr(n);
    cout << "Введіть " << n << " дійсних чисел:\n";
    my_arr.input();

    cout << "Початковий масив: ";
    my_arr.print();
    my_arr.bubble_sort();
    cout << "Відсортовано звичайним методом: ";
    my_arr.print();

    int raw_arr[] = {5, 2, 9, 1, 6};
    ArrayProcessor<int>::bubble_sort_static(raw_arr, 5);
    
    cout << "Статично відсортований сторонній масив: ";
    for (int i = 0; i < 5; i++) {
        cout << raw_arr[i] << " ";
    }
    cout << "\n";
}