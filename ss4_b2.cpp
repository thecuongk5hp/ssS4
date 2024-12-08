#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Kh�ng th? c?p ph�t b? nh?.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m node v�o �?u danh s�ch
Node* addToHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// H�m in danh s�ch li�n k?t
void printLinkedList(Node* head) {
    if (head == NULL) {
        printf("Danh s�ch tr?ng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// H�m gi?i ph�ng b? nh? c?a danh s�ch li�n k?t
void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// H�m ch�nh
int main() {
    int n;
    printf("Nh?p s? l�?ng ph?n t? n (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("S? l�?ng ph?n t? kh�ng h?p l?.\n");
        return 1;
    }

    Node* head = NULL;

    if (n > 0) {
        printf("Nh?p gi� tr? c�c ph?n t?: ");
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);
            head = addToHead(head, value);
        }
    }

    printf("Nh?p gi� tr? c?n ch�n v�o �?u danh s�ch: ");
    int newValue;
    scanf("%d", &newValue);

    head = addToHead(head, newValue);

    printf("Danh s�ch sau khi ch�n: ");
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}

