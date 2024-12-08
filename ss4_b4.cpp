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

// H�m t?m ki?m m?t gi� tr? trong danh s�ch li�n k?t
int search(Node* head, int target) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return index; // Tr? v? v? tr� n?u t?m th?y
        }
        temp = temp->next;
        index++;
    }
    return -1; // Tr? v? -1 n?u kh�ng t?m th?y
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
    int n, value, target;

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

    // Hi?n th? danh s�ch
    printf("Danh s�ch li�n k?t:\n");
    display(head);

    // Nh?p gi� tr? c?n t?m ki?m
    printf("Nh?p gi� tr? c?n t?m: ");
    scanf("%d", &target);

    // T?m ki?m v� in k?t qu?
    int result = search(head, target);
    if (result != -1) {
        printf("T?m th?y t?i v? tr�: %d\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}

