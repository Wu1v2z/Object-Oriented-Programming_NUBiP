#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class GeometricFigure {
public:
    virtual double Area() const = 0;   // чисто віртуальна функція
    virtual void Info() const {
        cout << "Геометрична фігура" << endl;
    }
    virtual ~GeometricFigure() {}
};

class Triangle : public GeometricFigure {
protected:
    double a, b, c; // сторона трикутника
public:
    Triangle(double A, double B, double C) : a(A), b(B), c(C) {}

    void Info() const override {
        cout << "Трикутник зі сторонами: "
             << a << ", " << b << ", " << c << endl;
    }
};
