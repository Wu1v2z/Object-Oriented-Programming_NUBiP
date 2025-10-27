#include <iostream>
using namespace std;

class Hourglass {
    double a;
    double b;

public:
    // Конструктор без параметрів
    Hourglass() {
        a = 0;
        b = 0;
        cout << "Конструктор без параметрiв викликаний" << endl;
    }

    // Конструктор з параметрами
    Hourglass(double A, double B) {
        a = A;
        b = B;
        cout << "Конструктор з параметрами викликаний" << endl;
    }

    // Деструктор
    ~Hourglass() {
        cout << "Деструктор викликаний" << endl;
    }

    // Методи set
    void setA(double A) { a = A; }
    void setB(double B) { b = B; }

    // Методи get
    double getA() { return a; }
    double getB() { return b; }

    // Метод для обчислення площі (для прикладу: площа = a * b / 2)
    double area() {
        return (a * b) / 2.0;
    }

    // Функція print_sqrt()
    void print_sqrt() {
        cout << "a = " << a << ", b = " << b
             << ", площа = " << area() << endl;
    }
};

// Тип покажчика на функцію-член без параметрів
typedef void (Hourglass::*FuncPtr)();

int main() {
    // Створення об’єкта за допомогою конструктора без параметрів
    Hourglass h1;
    h1.print_sqrt();

    // Створення об’єкта за допомогою конструктора з параметрами
    Hourglass h2(4, 6);
    h2.print_sqrt();

    // Використання покажчика на об’єкт
    Hourglass *ptr = new Hourglass(10, 5);
    ptr->print_sqrt();

    // Використання покажчика на функцію
    FuncPtr f = &Hourglass::print_sqrt;
    (ptr->*f)();

    delete ptr; // руйнування динамічного об’єкта (викличе деструктор)

    cout << "Кiнець програми" << endl;
    return 0;
}