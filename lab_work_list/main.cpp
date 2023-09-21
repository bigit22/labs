#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// ��������� ��� ���� ������
struct Node {
    int data;
    struct Node* next;
};

// ������� ��� �������� ������ ����
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������� ��� ���������� �������� � ������ (� �������� �������)
void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        int i;
        for (i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        }
        else {
            printf("������� ������� �� ������� ������.\n");
        }
    }
}

// ������� ��� ��������� ������ �������� ������ �� ������
int getNodeData(struct Node* head, int position) {
    struct Node* current = head;
    int i;
    for (i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        return current->data;
    }
    else {
        printf("������� ������� �� ������� ������.\n");
        return -1; // ���������� �������� �� ��������� � ������ ������
    }
}

// ������� ��� ��������� ������ �������� ������ �� ������
struct Node* getNodeAddress(struct Node* head, int position) {
    struct Node* current = head;
    int i;
    for (i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

// ������� ��� �������� �������� ������ �� ������
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("������ ����, ���������� ������� �������.\n");
        return;
    }
    struct Node* toDelete;
    if (position == 0) {
        toDelete = *head;
        *head = (*head)->next;
    }
    else {
        struct Node* current = *head;
        int i;
        for (i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL && current->next != NULL) {
            toDelete = current->next;
            current->next = current->next->next;
        }
        else {
            printf("������� ������� �� ������� ������.\n");
            return;
        }
    }
    free(toDelete);
}

// ������� ��� �������� ���������� ��������� � ������
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

struct Node* replaceNegativeWithAbsolute(struct Node* head) {
    struct Node* current = head;
    struct Node* lastReplacement = NULL;

    while (current != NULL) {
        if (current->data < 0) {
            current->data = abs(current->data); // �������� ������������� �������� �� ������
            lastReplacement = current; // ��������� ����� ��������� ������
        }
        current = current->next;
    }

    return lastReplacement;
}

// ������� ��� �������� ������ L3 �� ���������, �������� � L1 � �� �������� � L2
int createListL3(struct Node* L1, struct Node* L2, struct Node** L3) {
    int length = 0;
    struct Node* currentL1 = L1;

    while (currentL1 != NULL) {
        int data = currentL1->data;
        // ���������, ������ �� ������� L1 � ������ L2
        int found = 0;
        struct Node* currentL2 = L2;
        while (currentL2 != NULL) {
            if (currentL2->data == data) {
                found = 1;
                break;
            }
            currentL2 = currentL2->next;
        }

        // ���� ������� �� ������ � L2, ��������� ��� � L3
        if (!found) {
            insertNode(L3, data, length);
            length++;
        }

        currentL1 = currentL1->next;
    }

    return length;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    struct Node* L1 = NULL;
    struct Node* L2 = NULL;
    struct Node* L3 = NULL;

    // ���������� ��������� � ������
    insertNode(&L1, -10, 0);
    insertNode(&L1, -20, 1);
    insertNode(&L1, -30, 1);
    insertNode(&L1, -20, 2);
    insertNode(&L1, -450, 3);
    insertNode(&L1, -300, 4);

    insertNode(&L2, -110, 0);
    insertNode(&L2, -120, 1);
    insertNode(&L2, -30, 1);
    insertNode(&L2, -120, 2);
    insertNode(&L2, -4150, 3);
    insertNode(&L2, -300, 4);

    //������ ������ L3 �� ���������, ������� ������ � ������ L1 � �� ������ � ������ L2. ���������� ����� ������ ������.
    int lengthL3 = createListL3(L1, L2, &L3);
    printf("����� ������ L3: %d\n", lengthL3);

    // ��������� ������ �������� �� ������ � ����� �� �����
    int data = getNodeData(L1, 1);
    if (data != -1) {
        printf("�������� �������� �� ������� 1: %d\n", L1);
    }

    // �������� � ������ ��� ������������� �������� ��������� �� �� ������
    replaceNegativeWithAbsolute(L1);
    
    // ��������� ������ �������� �� ������ � ����� �� �����
    struct Node* node = getNodeAddress(L1, 1);
    if (node != NULL) {
        printf("����� �������� �� ������� 1: %p\n", (void*)node);
    }

    // �������� �������� �� ������
    deleteNode(&L1, 0);

    // ������� ���������� ��������� � ������
    int count = countNodes(L1);
    printf("���������� ��������� � ������: %d\n", count);

    return 0;
}
