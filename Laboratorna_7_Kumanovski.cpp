#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Абстрактна геометрична фігура 

class GeometricFigure {
public:
    virtual double Area() const = 0;   // чисто віртуальна функція
    virtual void Info() const {
        cout << "Геометрична фігура" << endl;
    }
    virtual ~GeometricFigure() {}
};

// трикутник

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

class Trapezoid : public GeometricFigure {
private:
    double a, b, h; // основа1, основа2, висота
public:
    Trapezoid(double A, double B, double H)
        : a(A), b(B), h(H) {}

    double Area() const override {
        return (a + b) * h / 2.0;
    }

    void Info() const override {
        cout << "Трапеція з основами " << a
             << " і " << b << ", висота " << h << endl;
    }
};

int main() {
    setlocale(0, "Ukr");

    vector<GeometricFigure*> figures;

    figures.push_back(new EquilateralTriangle(5));
    figures.push_back(new Trapezoid(4, 7, 3));
    figures.push_back(new EquilateralTriangle(10));

    cout << "Виведення площ через поліморфізм:\n\n";

    for (auto f : figures) {
        f->Info();
        cout << "Площа = " << f->Area() << "\n\n";
    }

    // очищення пам'яті
    for (auto f : figures)
        delete f;

    return 0;
}
