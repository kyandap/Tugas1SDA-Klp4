// Mempartisi linked list berdasarkan nilai x
// Node < x di depan, >= x di belakang
// Kompleksitas waktu: O(n)
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

struct Node* partisiList(struct Node* head, int x) {
    struct Node *kecilHead = NULL, *kecilTail = NULL;
    struct Node *besarHead = NULL, *besarTail = NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->nilai < x) {
            if (kecilHead == NULL) {
                kecilHead = kecilTail = curr;
            } else {
                kecilTail->next = curr;
                kecilTail = curr;
            }
        } else {
            if (besarHead == NULL) {
                besarHead = besarTail = curr;
            } else {
                besarTail->next = curr;
                besarTail = curr;
            }
        }
        curr = curr->next;
    }

    if (kecilTail != NULL)
        kecilTail->next = besarHead;

    if (besarTail != NULL)
        besarTail->next = NULL;

    return (kecilHead != NULL) ? kecilHead : besarHead;
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
    head = tambahNode(head, 4);
    head = tambahNode(head, 3);
    head = tambahNode(head, 2);
    head = tambahNode(head, 5);
    head = tambahNode(head, 2);

    head = partisiList(head, 3);

    printList(head);

    return 0;
}