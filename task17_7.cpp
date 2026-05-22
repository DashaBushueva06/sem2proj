#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class TextFileException : public runtime_error {
public:
    TextFileException(const string& msg) : runtime_error(msg) {}
};

class TextFileProcessor {
private:
    string filename;
    int numbers_count;
    int rows_count;

    void update_counts() {
        ifstream file(filename);
        if (!file.is_open()) {
            throw TextFileException("Помилка читання: Не вдалося відкрити файл для оновлення статистики!");
        }
        numbers_count = 0;
        rows_count = 0;
        string line;

        while (getline(file, line)) {
            rows_count++;
            stringstream ss(line);
            double val;
            while (ss >> val) {
                numbers_count++;
            }
            if (!ss.eof()) {
                throw TextFileException("Помилка даних: У файлі зустрічаються не дійсні числа!");
            }
        }
        file.close();
    }

public:
    TextFileProcessor(string fname) : filename(fname), numbers_count(0), rows_count(0) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            throw TextFileException("Помилка створення: Не вдалося створити або відкрити файл " + filename);
        }
        file.close();
        update_counts();
    }
    void input_from_console() {
        ofstream file(filename, ios::out);
        if (!file.is_open()) {
            throw TextFileException("Помилка запису: Не вдалося відкрити файл для введення даних!");
        }
        int n;
        cout << "Введіть кількість рядків для введення: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            cout << "Введіть рядок " << i + 1 << " (числа через пропуск): ";
            string line;
            getline(cin, line);
            stringstream ss(line);
            double val;
            while (ss >> val) {}
            if (!ss.eof()) {
                throw TextFileException("Помилка введення: Рядок містить не дійсні числа!");
            }
            
            file << line << "\n";
        }
        file.close();
        update_counts();
    }
    void create_from_matrix(const vector<vector<double>>& matrix) {
        ofstream file(filename, ios::out);
        if (!file.is_open()) {
            throw TextFileException("Помилка запису: Не вдалося відкрити файл для створення з матриці!");
        }
        for (const auto& row : matrix) {
            for (size_t i = 0; i < row.size(); i++) {
                file << row[i] << (i + 1 == row.size() ? "" : " ");
            }
            file << "\n";
        }
        file.close();
        update_counts();
    }
    double get_number_by_index(int target_index) {
        if (target_index < 0 || target_index >= numbers_count) {
            throw TextFileException("Помилка індексу: Некоректний номер числа (вихід за межі)!");
        }
        ifstream file(filename);
        if (!file.is_open()) {
            throw TextFileException("Помилка читання: Не вдалося відкрити файл!");
        }
        double val;
        int current_index = 0;
        while (file >> val) {
            if (current_index == target_index) {
                file.close();
                return val;
            }
            current_index++;
        }
        file.close();
        throw TextFileException("Помилка: Число не знайдено при читанні.");
    }
    void print_to_console() {
        ifstream file(filename);
        if (!file.is_open()) {
            throw TextFileException("Помилка читання: Не вдалося відкрити файл для виведення змісту!");
        }
        string line;
        cout << "--- Зміст файлу " << filename << " ---\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
    void append_row(const vector<double>& new_row) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            throw TextFileException("Помилка запису: Не вдалося відкрити файл для додавання рядка");
        }

        for (size_t i = 0; i < new_row.size(); i++) {
            file << new_row[i] << (i + 1 == new_row.size() ? "" : " ");
        }
        file << "\n";
        file.close();
        update_counts();
    }

    void remove_number(int row_index, int col_index) {
        if (row_index < 0 || row_index >= rows_count) {
            throw TextFileException("Помилка індексу: Некоректний номер рядка!");
        }
        ifstream file(filename);
        if (!file.is_open()) {
            throw TextFileException("Помилка читання: Не вдалося відкрити файл для видалення!");
        }
        vector<vector<double>> temp_matrix;
        string line;

        while (getline(file, line)) {
            vector<double> current_row;
            stringstream ss(line);
            double val;
            while (ss >> val) {
                current_row.push_back(val);
            }
            temp_matrix.push_back(current_row);
        }
        file.close();

        if (col_index < 0 || col_index >= static_cast<int>(temp_matrix[row_index].size())) {
            throw TextFileException("Помилка індексу: Некоректне місце числа в рядку!");
        }

        temp_matrix[row_index].erase(temp_matrix[row_index].begin() + col_index);
        create_from_matrix(temp_matrix);
    }
    int get_numbers_count() const { return numbers_count; }
    int get_rows_count() const { return rows_count; }
};

int main() {
    try {
        TextFileProcessor tf("data.txt");
        tf.input_from_console();
        tf.print_to_console();
        cout << "Всього рядків: " << tf.get_rows_count() << ", всього чисел: " << tf.get_numbers_count() << "\n";
    } 
    catch (const TextFileException& e) {
        cerr << "Перехоплено виключення: " << e.what() << "\n";
    }
}