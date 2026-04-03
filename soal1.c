// Menggabungkan beberapa linked list ascending
// menjadi satu linked list descending
// Kompleksitas waktu: O(n log n) / O(n^2) tergantung insert
#include <stdio.h>
#include <stdlib.h>

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
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = baru;
    return head;
}

// sorted descending insert
struct Node* insertDesc(struct Node* head, int nilai) {
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));
    baru->nilai = nilai;
    baru->next = NULL;

    if (head == NULL || nilai > head->nilai) {
        baru->next = head;
        return baru;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->nilai >= nilai)
        curr = curr->next;

    baru->next = curr->next;
    curr->next = baru;

    return head;
}

struct Node* gabungList(struct Node** list, int ukuranList) {
    struct Node* hasil = NULL;

    for (int i = 0; i < ukuranList; i++) {
        struct Node* curr = list[i];

        while (curr != NULL) {
            hasil = insertDesc(hasil, curr->nilai);
            curr = curr->next;
        }
    }

    return hasil;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->nilai);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list[3];

    list[0] = NULL;
    list[0] = tambahNode(list[0], 1);
    list[0] = tambahNode(list[0], 4);
    list[0] = tambahNode(list[0], 5);

    list[1] = NULL;
    list[1] = tambahNode(list[1], 1);
    list[1] = tambahNode(list[1], 3);
    list[1] = tambahNode(list[1], 4);

    list[2] = NULL;
    list[2] = tambahNode(list[2], 2);
    list[2] = tambahNode(list[2], 6);

    struct Node* hasil = gabungList(list, 3);

    printList(hasil);

    return 0;
}