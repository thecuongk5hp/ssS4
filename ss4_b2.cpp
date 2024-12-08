#include <stdio.h>
#include <stdlib.h>

// Ð?nh ngh?a c?u trúc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm t?o node m?i
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không th? c?p phát b? nh?.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm node vào ð?u danh sách
Node* addToHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Hàm in danh sách liên k?t
void printLinkedList(Node* head) {
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

// Hàm gi?i phóng b? nh? c?a danh sách liên k?t
void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Hàm chính
int main() {
    int n;
    printf("Nh?p s? lý?ng ph?n t? n (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("S? lý?ng ph?n t? không h?p l?.\n");
        return 1;
    }

    Node* head = NULL;

    if (n > 0) {
        printf("Nh?p giá tr? các ph?n t?: ");
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);
            head = addToHead(head, value);
        }
    }

    printf("Nh?p giá tr? c?n chèn vào ð?u danh sách: ");
    int newValue;
    scanf("%d", &newValue);

    head = addToHead(head, newValue);

    printf("Danh sách sau khi chèn: ");
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}

