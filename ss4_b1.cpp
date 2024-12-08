#include <stdio.h>
#include <stdlib.h>

// Ð?nh ngh?a c?u trúc node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Hàm t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm node vào cu?i danh sách
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

// Hàm in danh sách theo th? t? ngý?c
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
    // In t? cu?i v? ð?u
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    Node* head = NULL;

    // Thêm d? li?u vào danh sách liên k?t ðôi
    append(&head, 1);
    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Danh sách ngý?c: ");
    printReverse(head);

    // Thêm m?t danh sách khác
    Node* head2 = NULL;
    append(&head2, 10);
    append(&head2, 20);

    printf("Danh sách ngý?c: ");
    printReverse(head2);

    return 0;
}

