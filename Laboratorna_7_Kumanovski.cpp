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

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double A) : Triangle(A, A, A) {}

    double Area() const override {
        return (sqrt(3) / 4) * a * a;
    }

    void Info() const override {
        cout << "Рівносторонній трикутник зі стороною " << a << endl;
    }
};

