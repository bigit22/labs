#include <stdio.h>
#include "ebook.h"
#include "list.h"

int main() {
    Ebook ebook1, ebook2, ebook3;
    initializeEbook(&ebook1, "Sony", 6.8, 1);
    initializeEbook(&ebook2, "Amazon", 7.0, 0);
    initializeEbook(&ebook3, "Kobo", 6.5, 1);

    LinkedList* list = createList();
    if (list == NULL) {
        printf("Failed to create list.\n");
        return 1;
    }

    appendToList(list, &ebook1);
    appendToList(list, &ebook2);
    appendToList(list, &ebook3);

    printf("Список электронных книг:\n");
    printList(list);

    removeFromList(list);

    printf("\nСписок после удаления первой книги:\n");
    printList(list);


