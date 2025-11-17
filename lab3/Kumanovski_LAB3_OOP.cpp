#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string surname;
    string name;
    int math, physics, inform;

public:
    void Set(string s, string n, int m, int p, int i) {
        surname = s;
        name = n;
        math = m;
        physics = p;
        inform = i;
    }

    double Average() const {
        return (math + physics + inform) / 3.0;
    }

    string FullName() const {
        return surname + " " + name;
    }

    void Print() const {
        cout << FullName() << " — середній бал: " << Average() << endl;
    }
};

int main() {
    setlocale(0, "Ukr");

    ifstream fin("data.txt");

    if (!fin) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 0;
    }

    // 1. Спочатку рахуємо кількість рядків
    int count = 0;
    string temp;
    while (getline(fin, temp))
        count++;

    // 2. Створюємо динамічний масив студентів
    Student* arr = new Student[count];

    // 3. Знову відкриваємо файл для читання
    fin.clear();
    fin.seekg(0);

    // 4. Зчитування
    for (int i = 0; i < count; i++) {
        string sur, name;
        int m, p, info;
        fin >> sur >> name >> m >> p >> info;
        arr[i].Set(sur, name, m, p, info);
    }

    fin.close();

    // 5. Сортування за середнім балом (спадання)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i].Average() < arr[j].Average()) {
                swap(arr[i], arr[j]);
            }
        }
    }

    // 6. Виведення студентів з балом > 4
    cout << "\nСтуденти з середнім балом більше 4:\n";
    for (int i = 0; i < count; i++) {
        if (arr[i].Average() > 4.0) {
            arr[i].Print();
        }
    }

    delete[] arr;

    return 0;
}
