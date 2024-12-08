#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// H�m t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m node v�o cu?i danh s�ch
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// H�m in danh s�ch theo th? t? ng�?c
void printReverse(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    // Duy?t t?i node cu?i
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // In t? cu?i v? �?u
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// H�m ch�nh
int main() {
    Node* head = NULL;

    // Th�m d? li?u v�o danh s�ch li�n k?t ��i
    append(&head, 1);
    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Danh s�ch ng�?c: ");
    printReverse(head);

    // Th�m m?t danh s�ch kh�c
    Node* head2 = NULL;
    append(&head2, 10);
    append(&head2, 20);

    printf("Danh s�ch ng�?c: ");
    printReverse(head2);

    return 0;
}

