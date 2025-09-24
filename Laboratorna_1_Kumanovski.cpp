#include <iostream>
using namespace std;

class Hourglass {
    double a; // first 
    double b; // second

public:

    Hourglass() {
        a = 0;
        b = 0;
        cout << "Конструктор без параметрів" << endl;   
    }

    Hourglass(double A; double B) {
        a = A;
        b = B;
        cout << "Конструктор з параметрами" << end;
    }   

    ~Hourglass() {
        cout << "Деструктор" << endl;
    }

    void setA(double A) { a = A; }
    void setB(double B) { b = B; }

    double getA() { return a; }
    double getB() { return b; }
    
    double area() {
        return (a * b)/ 2.0;
    }

    void print_sqrt() {
        cout << "a = " << a << ", b = " << b << ", площа = " << area() << endl;
    }
};

typedef void (Hourglass::*FuncPtr)();

int main() {
    Hourglass h1;
    h1.print_sqrt();

    Hourglass h2(4, 6);
    h2.print_sqrt
}