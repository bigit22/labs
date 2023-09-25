#pragma once

typedef struct Ebook {
    char manufacturer[100];
    float screenSize;
    int hasBacklight;  // 0 for false, 1 for true
} Ebook;

void initializeEbook(Ebook* ebook, const char* manufacturer, float screenSize, int hasBacklight);
void printEbook(const Ebook* ebook);
int isEqual(const Ebook* ebook1, const Ebook* ebook2);
int isLess(const Ebook* ebook1, const Ebook* ebook2);
