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

// Hàm xóa ph?n t? ð?u tiên c?a danh sách
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sách tr?ng\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
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
    int n, value;

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

    // Hi?n th? danh sách ban ð?u
    printf("Danh sách ban ð?u:\n");
    display(head);

    // Xóa ph?n t? ð?u tiên
    deleteHead(&head);

    // Hi?n th? danh sách sau khi xóa
    printf("Danh sách sau khi xóa ph?n t? ð?u:\n");
    display(head);

    return 0;
}

