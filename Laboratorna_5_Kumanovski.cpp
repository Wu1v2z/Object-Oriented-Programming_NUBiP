#include <iostream>
#include <cmath> // Для std::sqrt, якщо знадобиться, але тут не потрібен, лише для демонстрації

using namespace std;

class Sandglass {
private:
    double a; // Основа
    double b; // Висота

public:
    // Конструктор за замовчуванням 
    Sandglass() : a(0.0), b(0.0) {}

    // Конструктор з параметрами 
    Sandglass(double base, double height) : a(base), b(height) {
        if (a < 0) a = 0; // Запобігаємо від'ємним розмірам
        if (b < 0) b = 0;
    }

    // Методи доступу (Getter/Setter)

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    void setA(double newA) {
        a = (newA >= 0) ? newA : 0;
    }

    void setB(double newB) {
        b = (newB >= 0) ? newB : 0;
    }


    // Обчислює та повертає площу фігури S = (a * b) / 2
    double calculateArea() const {
        return (a * b) / 2.0;
    }

    // Перевантаження операторів 

    // Перевантаження бінарного оператора '+' 
    Sandglass operator+(const Sandglass& op2) const {
    
        double new_a = a + op2.a;
        double new_b = b + op2.b;
        return Sandglass(new_a, new_b);
    }

    // Перевантаження префіксного оператора '++' (вимога g та 3)
    Sandglass& operator++() {

        a++;
        b++;
        return *this; // Повертає посилання на модифікований об'єкт
    }

    // Перевантаження постфіксного оператора '++' (вимога g та 3)
    Sandglass operator++(int notused) {
        Sandglass temp = *this;
        a++;  
        b++;
        return temp;
    }

    // Оголошення дружньої функції для перевантаження оператора '<<'
    friend ostream& operator<<(ostream& os, const Sandglass& obj);
};

// Визначення дружньої функції для перевантаження оператора '<<'
ostream& operator<<(ostream& os, const Sandglass& obj) {
    os << "Фігура 'Пісочний годинник':" << endl;
    os << "  Основа (a): " << obj.a << endl;
    os << "  Висота (b): " << obj.b << endl;
    os << "  Площа (S): " << obj.calculateArea();
    return os;
}

// Головна функція для демонстрації

int main() {
    // Створення об'єктів (вимога a, b)
    Sandglass s1(5.0, 10.0);    // Конструктор з параметрами
    Sandglass s2(3.0, 6.0);     // Конструктор з параметрами
    Sandglass s3;               // Конструктор без параметра

    cout << "--- Початкові об'єкти ---" << endl;
    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;
    cout << "S3: " << s3 << endl;

    // Демонстрація оператора '+' (вимога e)
    cout << "\n--- Оператор '+' (s3 = s1 + s2) ---" << endl;
    s3 = s1 + s2; // Перевантажений оператор +
    cout << "s3 = s1 + s2:" << endl;
    cout << s3 << endl;

    // Демонстрація постфіксного '++' (вимога g та 3)
    cout << "\n--- Постфіксний '++' (s3 = s2++) ---" << endl;
    cout << "S2 до: " << s2.getA() << ", " << s2.getB() << endl;
    s3 = s2++;
    cout << "S3 після (старе s2): " << s3.getA() << ", " << s3.getB() << endl;
    cout << "S2 після (інкремент): " << s2.getA() << ", " << s2.getB() << endl;

    // Демонстрація префіксного '++' (вимога g та 3)
    cout << "\n--- Префіксний '++' (s3 = ++s2) ---" << endl;
    cout << "S2 до: " << s2.getA() << ", " << s2.getB() << endl;
    s3 = ++s2;
    cout << "S2 після (інкремент): " << s2.getA() << ", " << s2.getB() << endl;
    cout << "S3 після (нове s2): " << s3.getA() << ", " << s3.getB() << endl;

    return 0;
}