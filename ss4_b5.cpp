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

// Hàm thêm nút vào cu?i danh sách
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

// Hàm chèn ph?n t? t?i v? trí xác ð?nh
void insertAtPosition(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    // N?u chèn ? ð?u danh sách
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Duy?t ð?n v? trí trý?c v? trí c?n chèn
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    // N?u v? trí n?m ngoài ph?m vi
    if (temp == NULL) {
        printf("V? trí không h?p l?\n");
        free(newNode);
        return;
    }

    // Chèn nút vào danh sách
    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, value, position;

    // Nh?p danh sách liên k?t ban ð?u
    printf("Nh?p s? lý?ng ph?n t?: ");
    scanf("%d", &n);

    printf("Nh?p các ph?n t?:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    // Hi?n th? danh sách ban ð?u
    printf("Danh sách liên k?t ban ð?u:\n");
    display(head);

    // Nh?p giá tr? và v? trí c?n chèn
    printf("Nh?p giá tr? c?n chèn: ");
    scanf("%d", &value);
    printf("Nh?p v? trí c?n chèn: ");
    scanf("%d", &position);

    // Chèn ph?n t? vào danh sách
    insertAtPosition(&head, value, position);

    // Hi?n th? danh sách sau khi chèn
    printf("Danh sách liên k?t sau khi chèn:\n");
    display(head);

    return 0;
}

