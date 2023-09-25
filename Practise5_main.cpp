#include "Ebook.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    Ebook ebook1;
    Ebook ebook2("Sony", 6.8, true);

    cout << "Информация о первой электронной книге:" << endl;
    ebook1.print();

    cout << "\nИнформация о второй электронной книге:" << endl;
    ebook2.print();

    Ebook ebook3 = ebook2;
    cout << "\nИнформация о третьей электронной книге (копия второй):" << endl;
    ebook3.print();

    ebook1.rename("Amazon");
    cout << "\nИнформация о первой электронной книге после изменения производителя:" << endl;
    ebook1.print();

    Ebook* ebookDynamic1 = createEbook();
    Ebook* ebookDynamic2 = createEbook();

    cout << "\nИнформация о первой динамически созданной электронной книге:" << endl;
    if (ebookDynamic1 != nullptr) {
        ebookDynamic1->print();
        delete ebookDynamic1;
    }

    cout << "\nИнформация о второй динамически созданной электронной книге:" << endl;
    if (ebookDynamic2 != nullptr) {
        ebookDynamic2->print();
        delete ebookDynamic2;
    }

    return 0;
}
