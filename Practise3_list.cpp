#include "list.h"
#include <stdlib.h>

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

void appendToList(LinkedList* list, Ebook* ebook) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        return;
    }

    newNode->data = ebook;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void removeFromList(LinkedList* list) {
    if (list->head == NULL) {
        return;  // List is already empty
    }

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void printList(const LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printEbook(current->data);
        current = current->next;
    }
}

void addOrdered(LinkedList* list, Ebook* ebook) {
    if (list->head == NULL || isLess(ebook, list->head->data)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            return;  // Handle memory allocation failure
        }

        newNode->data = ebook;
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && !isLess(ebook, current->next->data)) {
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;  // Handle memory allocation failure
    }

    newNode->data = ebook;
    newNode->next = current->next;
    current->next = newNode;
}

void removeEbook(LinkedList* list, Ebook* ebook) {
    if (list->head == NULL) {
        return;  // List is empty
    }

    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (isEqual(current->data, ebook)) {
            if (prev == NULL) {
                // Removing the first node
                list->head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}

void clearList(LinkedList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}
