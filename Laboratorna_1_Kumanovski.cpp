include <iostream>
using namespace std;

class Hourglass {
    double a; // first 
    double b; // second
}

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

    

