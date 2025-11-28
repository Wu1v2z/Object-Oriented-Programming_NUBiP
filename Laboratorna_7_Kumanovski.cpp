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
