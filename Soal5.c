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
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    return head;
}

struct Node* ganjilGenapList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node *ganjilHead = NULL, *ganjilTail = NULL;
    struct Node *genapHead = NULL, *genapTail = NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->nilai % 2 != 0) {
            if (ganjilHead == NULL) {
                ganjilHead = ganjilTail = curr;
            } else {
                ganjilTail->next = curr;
                ganjilTail = curr;
            }
        } else {
            if (genapHead == NULL) {
                genapHead = genapTail = curr;
            } else {
                genapTail->next = curr;
                genapTail = curr;
            }
        }
        curr = curr->next;
    }

    if (ganjilTail != NULL)
        ganjilTail->next = genapHead;

    if (genapTail != NULL)
        genapTail->next = NULL;

    return (ganjilHead != NULL) ? ganjilHead : genapHead;
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

    head = tambahNode(head, 2);
    head = tambahNode(head, 1);
    head = tambahNode(head, 5);
    head = tambahNode(head, 3);
    head = tambahNode(head, 6);
    head = tambahNode(head, 4);
    head = tambahNode(head, 7);

    head = ganjilGenapList(head);

    printList(head);

    return 0;
}
