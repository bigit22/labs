#pragma once
#include "ebook.h"

typedef struct Node {
    Ebook* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createList();
void appendToList(LinkedList* list, Ebook* ebook);
void removeFromList(LinkedList* list);
void printList(const LinkedList* list);
void addOrdered(LinkedList* list, Ebook* ebook);
void removeEbook(LinkedList* list, Ebook* ebook);
void clearList(LinkedList* list);
