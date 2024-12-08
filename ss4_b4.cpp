#include <stdio.h>
#include <stdlib.h>

// C?u trúc nút c?a danh sách liên k?t
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm t?o m?t nút m?i
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm ph?n t? vào cu?i danh sách
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

// Hàm t?m ki?m m?t giá tr? trong danh sách liên k?t
int search(Node* head, int target) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return index; // Tr? v? v? trí n?u t?m th?y
        }
        temp = temp->next;
        index++;
    }
    return -1; // Tr? v? -1 n?u không t?m th?y
}

// Hàm hi?n th? danh sách liên k?t
void display(Node* head) {
    if (head == NULL) {
        printf("Danh sách tr?ng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    Node* head = NULL;
    int n, value, target;

    // Nh?p s? lý?ng ph?n t?
    printf("Nh?p s? ph?n t? n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Nh?p các ph?n t?:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            append(&head, value);
        }
    }

    // Hi?n th? danh sách
    printf("Danh sách liên k?t:\n");
    display(head);

    // Nh?p giá tr? c?n t?m ki?m
    printf("Nh?p giá tr? c?n t?m: ");
    scanf("%d", &target);

    // T?m ki?m và in k?t qu?
    int result = search(head, target);
    if (result != -1) {
        printf("T?m th?y t?i v? trí: %d\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}

