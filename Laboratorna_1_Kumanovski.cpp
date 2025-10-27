#include <iostream>
using namespace std;

class Hourglass {
    double a;
    double b;

public:
    //Constructor without parameters
    Hourglass() {
        a = 0;
        b = 0;
        cout << "Конструктор без параметрiв викликаний" << endl;
    }

    //Constructor with parameters
    Hourglass(double A, double B) {
        a = A;
        b = B;
        cout << "Конструктор з параметрами викликаний" << endl;
    }

    //Destructor
    ~Hourglass() {
        cout << "Деструктор викликаний" << endl;
    }

    //Methods set
    void setA(double A) { a = A; }
    void setB(double B) { b = B; }

    //Methods get
    double getA() { return a; }
    double getB() { return b; }

    //Method for calculating area (for example: area = a * b / 2)
    double area() {
        return (a * b) / 2.0;
    }

    //Function print_sqrt()
    void print_sqrt() {
        cout << "a = " << a << ", b = " << b
             << ", площа = " << area() << endl;
    }
};

//Type of pointer to a member function without parameters
typedef void (Hourglass::*FuncPtr)();

int main() {
    //Creating an object using the constructor without parameters
    Hourglass h1;
    h1.print_sqrt();

    //Creating an object using a constructor with parameters
    Hourglass h2(4, 6);
    h2.print_sqrt();

    //Using a pointer to an object
    Hourglass *ptr = new Hourglass(10, 5);
    ptr->print_sqrt();

    //Using a pointer to a function
    FuncPtr f = &Hourglass::print_sqrt;
    (ptr->*f)();

    delete ptr; //destruction of a dynamic object

    cout << "Кiнець програми" << endl;
    return 0;
}