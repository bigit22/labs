#pragma once

#include <iostream>
#include <string>

using namespace std;

class Ebook {
private:
    string manufacturer;
    double screenSize;
    bool hasBacklight;

public:
    Ebook();
    Ebook(const string& manufacturer, double screenSize, bool hasBacklight);
    Ebook(const Ebook& other);

    void init(const string& manufacturer, double screenSize, bool hasBacklight);
    void print() const;
    void rename(const string& newManufacturer);

    ~Ebook();
};

Ebook* createEbook();
