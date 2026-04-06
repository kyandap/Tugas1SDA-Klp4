

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* buatNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void cetakList(struct Node* head) {
    struct Node* temp = head;
    if (!temp) {
        printf("[]\n");
        return;
    }
    printf("[");
    while (temp) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp) printf(", ");
    }
    printf("]\n");
}

struct Node* hapusElemen(struct Node* head, int x) {
    // Hapus head berulang
    while (head && head->data == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    if (!head) return head;
    
    // Cari di tengah
    struct Node* prev = head;
    struct Node* curr = head->next;
    while (curr) {
        if (curr->data == x) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    printf("=== SOAL 7: HAPUS SEMUA ELEMEN ===\n\n");
    
    // Test Case 1: [1,2,6,3,4,5,6] hapus 6
    struct Node* head = buatNode(1);
    head->next = buatNode(2);
    head->next->next = buatNode(6);
    head->next->next->next = buatNode(3);
    head->next->next->next->next = buatNode(4);
    head->next->next->next->next->next = buatNode(5);
    head->next->next->next->next->next->next = buatNode(6);
    
    printf("Input:  ");
    cetakList(head);
    head = hapusElemen(head, 6);
    printf("Output: ");
    cetakList(head);
    
    printf("\n--- Test Case 2: Semua 7 ---");
    head = buatNode(7);
    head->next = buatNode(7);
    head->next->next = buatNode(7);
    printf("\nInput:  ");
    cetakList(head);
    head = hapusElemen(head, 7);
    printf("Output: ");
    cetakList(head);
    
    return 0;
}