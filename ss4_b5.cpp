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

// H�m th�m n�t v�o cu?i danh s�ch
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

// H�m ch�n ph?n t? t?i v? tr� x�c �?nh
void insertAtPosition(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    // N?u ch�n ? �?u danh s�ch
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Duy?t �?n v? tr� tr�?c v? tr� c?n ch�n
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    // N?u v? tr� n?m ngo�i ph?m vi
    if (temp == NULL) {
        printf("V? tr� kh�ng h?p l?\n");
        free(newNode);
        return;
    }

    // Ch�n n�t v�o danh s�ch
    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, value, position;

    // Nh?p danh s�ch li�n k?t ban �?u
    printf("Nh?p s? l�?ng ph?n t?: ");
    scanf("%d", &n);

    printf("Nh?p c�c ph?n t?:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    // Hi?n th? danh s�ch ban �?u
    printf("Danh s�ch li�n k?t ban �?u:\n");
    display(head);

    // Nh?p gi� tr? v� v? tr� c?n ch�n
    printf("Nh?p gi� tr? c?n ch�n: ");
    scanf("%d", &value);
    printf("Nh?p v? tr� c?n ch�n: ");
    scanf("%d", &position);

    // Ch�n ph?n t? v�o danh s�ch
    insertAtPosition(&head, value, position);

    // Hi?n th? danh s�ch sau khi ch�n
    printf("Danh s�ch li�n k?t sau khi ch�n:\n");
    display(head);

    return 0;
}

