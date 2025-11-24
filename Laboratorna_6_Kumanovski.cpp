#include <iostream>
#include <string>
using namespace std;

// ---------------- БАЗОВИЙ КЛАС ----------------
class Engine {
protected:
    double power;      // потужність у кВт
    double weight;     // маса двигуна

public:
    Engine(double p = 0, double w = 0) : power(p), weight(w) {
        cout << "Створено Engine\n";
    }

    virtual ~Engine() {
        cout << "Видалено Engine\n";
    }

    virtual void Info() const {
        cout << "Двигун: потужність = " << power
             << " кВт, маса = " << weight << " кг\n";
    }
};

// ------------ ДВИГУН ВНУТРІШНЬОГО ЗГОРЯННЯ -------------
class ICEngine : public Engine {
protected:
    double volume;    // робочий об'єм

public:
    ICEngine(double p = 0, double w = 0, double v = 0)
        : Engine(p, w), volume(v) 
    {
        cout << "Створено ICEngine\n";
    }

    ~ICEngine() {
        cout << "Видалено ICEngine\n";
    }

    void Info() const override {
        cout << "ДВЗ: " << "потужність = " << power
             << " кВт, маса = " << weight
             << " кг, об'єм = " << volume << " л\n";
    }
};

// -------------------- ДИЗЕЛЬ ---------------------
class Diesel : public ICEngine {
private:
    double compression;     // ступінь стиснення

public:
    Diesel(double p = 0, double w = 0, double v = 0, double c = 0)
        : ICEngine(p, w, v), compression(c) 
    {
        cout << "Створено Diesel\n";
    }

    ~Diesel() {
        cout << "Видалено Diesel\n";
    }

    void Info() const override {
        cout << "Дизельний двигун: потужність = " << power
             << " кВт, маса = " << weight
             << " кг, об'єм = " << volume
             << " л, ступінь стиснення = " << compression << endl;
    }
};

// турбореактивний двигун
class TurboJet : public Engine {
private:
    double thrust;    // тяга в Ньютонах

public:
    TurboJet(double p = 0, double w = 0, double t = 0)
        : Engine(p, w), thrust(t) 
    {
        cout << "Створено TurboJet\n";
    }

    ~TurboJet() {
        cout << "Видалено TurboJet\n";
    }

    void Info() const override {
        cout << "Турбореактивний двигун: потужність = " << power
             << " кВт, маса = " << weight
             << " кг, тяга = " << thrust << " Н\n";
    }
};

// main функція
int main() {
    setlocale(0, "Ukr");

    Engine e(100, 150);
    ICEngine ice(120, 180, 2.0);
    Diesel d(180, 220, 3.5, 18);
    TurboJet jet(5000, 900, 20000);

    cout << "\nІнформація про об'єкти:\n\n";

    e.Info();
    ice.Info();
    d.Info();
    jet.Info();

    return 0;
}
