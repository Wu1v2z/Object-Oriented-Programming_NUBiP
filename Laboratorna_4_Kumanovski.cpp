#include <iostream>
using namespace std;

class MyArray {
private:
    int size;
    double* arr;

public:
    // Конструктор
    MyArray(int n) {
        size = n;
        arr = new double[size];

        // Генерація масиву згідно з варіантом 11
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                arr[i] = i + 5.1;     // парний індекс
            } else {
                arr[i] = i - 4.2;     // непарний індекс
            }
        }
    }

    // Конструктор копії
    MyArray(const MyArray& other) {
        size = other.size;
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Деструктор
    ~MyArray() {
        delete[] arr;
    }

    int getSize() const {
        return size;
    }

    double getElement(int i) const {
        return arr[i];
    }

    // Функція виведення масиву (для перевірки)
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Функція, що приймає об’єкт класу і виконує завдання
double processArray(MyArray obj) {
    double sum = 0;

    // Кожний другий елемент: індекси 1,3,5,7,9,11
    for (int i = 1; i < obj.getSize(); i += 2) {
        sum += obj.getElement(i);
    }

    return sum;
}

int main() {
    setlocale(0, "Ukr");

    MyArray mas(12);

    cout << "Згенерований масив:\n";
    mas.print();

    double result = processArray(mas);

    cout << "Сума кожного другого елемента: " << result << endl;

    return 0;
}
