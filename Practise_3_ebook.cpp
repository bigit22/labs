#include "ebook.h"
#include <stdio.h>
#include <string.h>

void initializeEbook(Ebook* ebook, const char* manufacturer, float screenSize, int hasBacklight) {
    snprintf(ebook->manufacturer, sizeof(ebook->manufacturer), "%s", manufacturer);
    ebook->screenSize = screenSize;
    ebook->hasBacklight = hasBacklight;
}

void printEbook(const Ebook* ebook) {
    printf("Производитель: %s, ", ebook->manufacturer);
    printf("Размер экрана: %.1f дюймов, ", ebook->screenSize);
    printf("Подсветка экрана: %s\n", (ebook->hasBacklight) ? "есть" : "нет");
}

int isEqual(const Ebook* ebook1, const Ebook* ebook2) {
    return (strcmp(ebook1->manufacturer, ebook2->manufacturer) == 0 &&
        ebook1->screenSize == ebook2->screenSize &&
        ebook1->hasBacklight == ebook2->hasBacklight);
}

int isLess(const Ebook* ebook1, const Ebook* ebook2) {
    // Define your comparison rule here. For simplicity, let's compare based on screen size.
    return (ebook1->screenSize < ebook2->screenSize);
}
