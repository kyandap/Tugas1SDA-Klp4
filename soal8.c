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

// Helper: Reverse list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Main function: Reorder list
void reorderList(struct Node* head) {
    if (!head || !head->next) return;
    
    // 1. Find middle (slow-fast pointer)
    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 2. Reverse second half
    struct Node* second = reverseList(slow->next);
    
    // 3. Merge alternately
    struct Node *first = head;
    while (second) {
        struct Node *next1 = first->next;
        struct Node *next2 = second->next;
        
        first->next = second;
        second = next1;
        
        if (next1) next1->next = second;
        first = next1;
        second = next2;
    }
}

int main() {
    printf("=== SOAL 8: REORDER LIST ===\n\n");
    
    // Test Case 1: [1,2,3,4] → [1,4,2,3]
    struct Node* head = buatNode(1);
    head->next = buatNode(2);
    head->next->next = buatNode(3);
    head->next->next->next = buatNode(4);
    
    printf("Test 1:\n");
    printf("Input:  ");
    cetakList(head);
    reorderList(head);
    printf("Output: ");
    cetakList(head);
    
    printf("\n--- Test Case 2: [1,2,3,4,5] ---");
    head = buatNode(1);
    head->next = buatNode(2);
    head->next->next = buatNode(3);
    head->next->next->next = buatNode(4);
    head->next->next->next->next = buatNode(5);
    
    printf("\nInput:  ");
    cetakList(head);
    reorderList(head);
    printf("Output: ");
    cetakList(head);
    
    return 0;
}