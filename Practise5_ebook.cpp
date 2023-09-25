#include "Ebook.h"

using namespace std;

Ebook::Ebook() : screenSize(0), hasBacklight(false) {}

Ebook::Ebook(const string& manufacturer, double screenSize, bool hasBacklight) {
    init(manufacturer, screenSize, hasBacklight);
}

Ebook::Ebook(const Ebook& other) {
    manufacturer = other.manufacturer;
    screenSize = other.screenSize;
    hasBacklight = other.hasBacklight;
}

void Ebook::init(const string& newManufacturer, double newScreenSize, bool newHasBacklight) {
    if (newScreenSize <= 0) {
        throw invalid_argument("Некорректный размер экрана.");
    }

    manufacturer = newManufacturer;
    screenSize = newScreenSize;
    hasBacklight = newHasBacklight;
}

void Ebook::print() const {
    cout << "Производитель: " << manufacturer << ", ";
    cout << "Размер экрана: " << screenSize << " дюймов, ";
    cout << "Подсветка экрана: " << (hasBacklight ? "есть" : "нет") << endl;
}

void Ebook::rename(const string& newManufacturer) {
    manufacturer = newManufacturer;
}

Ebook::~Ebook() {}

Ebook* createEbook() {
    string manufacturer;
    double screenSize;
    bool hasBacklight;

    cout << "Введите производителя: ";
    cin >> manufacturer;

    cout << "Введите размер экрана (в дюймах): ";
    cin >> screenSize;

    cout << "Есть подсветка экрана (1 - да, 0 - нет): ";
    cin >> hasBacklight;

    Ebook* ebook = new Ebook();
    try {
        ebook->init(manufacturer, screenSize, hasBacklight);
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка инициализации: " << e.what() << endl;
        delete ebook;
        return nullptr;
    }

    return ebook;
}
