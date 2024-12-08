#include <stdio.h>
#include <stdlib.h>

// C?u tr�c n�t c?a danh s�ch li�n k?t
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m t?o m?t n�t m?i
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m ph?n t? v�o cu?i danh s�ch
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// H�m x�a ph?n t? �?u ti�n c?a danh s�ch
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh s�ch tr?ng\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// H�m hi?n th? danh s�ch li�n k?t
void display(Node* head) {
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

// H�m ch�nh
int main() {
    Node* head = NULL;
    int n, value;

    // Nh?p s? l�?ng ph?n t?
    printf("Nh?p s? ph?n t? n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Nh?p c�c ph?n t?:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            append(&head, value);
        }
    }

    // Hi?n th? danh s�ch ban �?u
    printf("Danh s�ch ban �?u:\n");
    display(head);

    // X�a ph?n t? �?u ti�n
    deleteHead(&head);

    // Hi?n th? danh s�ch sau khi x�a
    printf("Danh s�ch sau khi x�a ph?n t? �?u:\n");
    display(head);

    return 0;
}

