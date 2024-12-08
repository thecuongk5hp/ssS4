#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c node
struct Node {
    int data;
    struct Node* next;
};

// H�m t?o m?t node m?i
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m m?t node v�o cu?i danh s�ch
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

// H�m in danh s�ch li�n k?t
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// H�m x�a m?t node t?i v? tr� ch? �?nh
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Danh s�ch r?ng.\n");
        return;
    }

    struct Node* temp = *head;

    // X�a ph?n t? �?u danh s�ch
    if (position == 0) {
        *head = temp->next; // Thay �?i head
        free(temp);         // Gi?i ph�ng b? nh?
        return;
    }

    // Duy?t �?n node tr�?c node c?n x�a
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // N?u v? tr� kh�ng h?p l?
    if (temp == NULL || temp->next == NULL) {
        printf("V? tr� kh�ng h?p l?.\n");
        return;
    }

    // Node c?n x�a
    struct Node* next = temp->next->next;

    // Gi?i ph�ng node
    free(temp->next);

    // Li�n k?t node tr�?c �� v?i node ti?p theo
    temp->next = next;
}

int main() {
    struct Node* head = NULL;

    // T?o danh s�ch li�n k?t
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Danh s�ch ban �?u: ");
    printList(head);

    // X�a t?i v? tr� 2
    int position;
    printf("Nh?p v? tr� c?n x�a: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Danh s�ch sau khi x�a: ");
    printList(head);

    return 0;
}

