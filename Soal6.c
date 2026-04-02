#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int nilai;
    struct Node *next;
};

struct Node* tambahNode(struct Node* head, int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->nilai = nilai;
    baru->next = NULL;

    if (head == NULL) return baru;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    return head;
}

bool apaPalindrom(struct Node* head) {
    int arr[1000];
    int i = 0;

    struct Node* temp = head;

    while (temp != NULL) {
        arr[i++] = temp->nilai;
        temp = temp->next;
    }

    int kiri = 0, kanan = i - 1;
    while (kiri < kanan) {
        if (arr[kiri] != arr[kanan])
            return false;
        kiri++;
        kanan--;
    }

    return true;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->nilai);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = tambahNode(head, 1);
    head = tambahNode(head, 2);

    printf("Linked List: ");
    printList(head);

    if (apaPalindrom(head))
        printf("Hasil: true\n");
    else
        printf("Hasil: false\n");

    return 0;
}
