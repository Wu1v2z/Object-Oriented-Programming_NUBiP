#include <iostream>
using namespace std;

class Hourglass {
    double a;
    double b;

public:
    // Constructor without parameters
    Hourglass() {
        a = 0;
        b = 0;
        cout << "Конструктор без параметрiв викликаний" << endl;
    }

    // Constructor with parameters
    Hourglass(double A, double B) {
        a = A;
        b = B;
        cout << "Конструктор з параметрами викликаний" << endl;
    }

    // Destructor
    ~Hourglass() {
        cout << "Деструктор викликаний" << endl;
    }

    // Methods set
    void setA(double A) { a = A; }
    void setB(double B) { b = B; }

    // Methods get
    double getA() { return a; }
    double getB() { return b; }

    // Method for calculating area (for example: area = a * b / 2)
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