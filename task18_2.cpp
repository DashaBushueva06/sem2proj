#include <iostream>
#include <stack>

using namespace std;

namespace MyNamespace {
    template <typename T>
    class Stack {
    private:
        T* arr;
        int capacity;
        int top_index;

        void resize() {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i <= top_index; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }

    public:
        Stack() {
            capacity = 4;
            arr = new T[capacity];
            top_index = -1;
        }
        ~Stack() {
            delete[] arr;
        }
        void push(T val) {
            if (top_index + 1 >= capacity) {
                resize();
            }
            arr[++top_index] = val;
        }
        void pop() {
            if (top_index >= 0) {
                top_index--;
            }
        }
        T top() const {
            return arr[top_index];
        }
        bool empty() const {
            return top_index == -1;
        }
    };

    template <typename T, typename StackType>
    int input_array_to_zero(T*& target_array, StackType& st) {
        T val;
        int count = 0;
        while (cin >> val && val != 0) {
            st.push(val);
            count++;
        }
        if (count == 0) {
            target_array = nullptr;
            return 0;
        }
        target_array = new T[count];

        for (int i = count - 1; i >= 0; i--) {
            target_array[i] = st.top();
            st.pop();
        }

        return count;
    }
}

int main() {
    using namespace MyNamespace;

    cout << "Введіть цілі числа (0 для завершення):\n";
    int* int_arr = nullptr;
    std::stack<int> stl_stack;
    
    int size_int = input_array_to_zero(int_arr, stl_stack);

    cout << "Результат (масив цілих чисел): ";
    for (int i = 0; i < size_int; i++) {
        cout << int_arr[i] << " ";
    }
    cout << "\nКількість елементів: " << size_int << "\n\n";
    delete[] int_arr;
    cout << "Введіть дійсні числа (0 для завершення):\n";
    double* double_arr = nullptr;
    MyNamespace::Stack<double> custom_stack;

    int size_double = input_array_to_zero(double_arr, custom_stack);

    cout << "Результат (масив дійсних чисел): ";
    for (int i = 0; i < size_double; i++) {
        cout << double_arr[i] << " ";
    }
    cout << "\nКількість елементів: " << size_double << "\n";
    delete[] double_arr;
}