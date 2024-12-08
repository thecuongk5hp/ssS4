#include <stdio.h>
#include <stdlib.h>

// Ð?nh ngh?a c?u trúc node
struct Node {
    int data;
    struct Node* next;
};

// Hàm t?o m?t node m?i
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm m?t node vào cu?i danh sách
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm in danh sách liên k?t
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Hàm xóa m?t node t?i v? trí ch? ð?nh
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sách r?ng.\n");
        return;
    }

    struct Node* temp = *head;

    // Xóa ph?n t? ð?u danh sách
    if (position == 0) {
        *head = temp->next; // Thay ð?i head
        free(temp);         // Gi?i phóng b? nh?
        return;
    }

    // Duy?t ð?n node trý?c node c?n xóa
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // N?u v? trí không h?p l?
    if (temp == NULL || temp->next == NULL) {
        printf("V? trí không h?p l?.\n");
        return;
    }

    // Node c?n xóa
    struct Node* next = temp->next->next;

    // Gi?i phóng node
    free(temp->next);

    // Liên k?t node trý?c ðó v?i node ti?p theo
    temp->next = next;
}

int main() {
    struct Node* head = NULL;

    // T?o danh sách liên k?t
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Danh sách ban ð?u: ");
    printList(head);

    // Xóa t?i v? trí 2
    int position;
    printf("Nh?p v? trí c?n xóa: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Danh sách sau khi xóa: ");
    printList(head);

    return 0;
}

