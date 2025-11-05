#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
    double real;   // дійсна частина
    double imag;   // уявна частина

public:
    // Конструктор без параметрів
    Complex() {
        real = 0.0;
        imag = 0.0;
    }

    // Конструктор з параметрами
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Методи встановлення значень
    void setReal(double r) {
        real = r;
    }

    void setImag(double i) {
        imag = i;
    }

    // Методи отримання значень
    double getReal() {
        return real;
    }

    double getImag() {
        return imag;
    }

    // Метод виводу
    void print() {
        cout << fixed << setprecision(2);
        cout << "(" << real;
        if (imag >= 0)
            cout << " + i" << imag << ")";
        else
            cout << " - i" << -imag << ")";
        cout << endl;
    }

    // Оголошення дружньої функції
    friend Complex frd(Complex a, Complex b);
};

// Дружня функція, що повертає суму двох комплексних чисел
Complex frd(Complex a, Complex b) {
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}

int main() {
    setlocale(0, "Ukr");

    // Створення двох об’єктів з параметрами
    Complex c1(2.5, 3.7);
    Complex c2(1.2, -4.3);

    cout << "Перше комплексне число: ";
    c1.print();

    cout << "Друге комплексне число: ";
    c2.print();

    // Виклик дружньої функції
    Complex sum = frd(c1, c2);

    cout << "Сума двох комплексних чисел: ";
    sum.print();

    return 0;
}
