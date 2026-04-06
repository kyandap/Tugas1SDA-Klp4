#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int nilai;
    struct Node *next;
}Node;

Node *buatNode (int nilai) {
    Node *node = malloc (sizeof(Node));
    node->nilai = nilai;
    node->next = NULL;
    return node;
}
void cetakList (Node *head) {  /*Fungsi mencetak Linked List*/
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->nilai);
        temp = temp->next;
    }
    printf("\n");
}
/*Fungsi mengecek apakah nilai ada dalam array num*/
bool isInArr (int *num, int numSize, int value) {
   for (int i=0; i<numSize; i++) {
        if (num[i] == value) {
            return true;
        }
   }
   return false;
}

/*Fungsi Utama menghapus node dengan nilai dalam array*/
Node *modifiedList (int *num, int numSize, Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node dummy;
    dummy.next = head;
    Node *prev = &dummy;
    Node *current = head;

    while (current != NULL) {
        if (isInArr(num, numSize, current->nilai)) {
            prev->next = current->next;
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return dummy.next;
}

int main () {

    /*Test Case 1: num=[1,2,3] dan head=[1,2,3,4,5]*/
    int num1[] = {1,2,3};
    int numSize1 = 3;
    
    Node *head1 = buatNode(1);
    head1->next = buatNode(2);
    head1->next->next = buatNode(3);
    head1->next->next->next = buatNode(4);
    head1->next->next->next->next = buatNode(5);
    
    printf("Test Case 1:\n");
    printf("Input: num = {1,2,3}, head = {1,2,3,4,5}\n");
    printf("Sebelum: ");
    cetakList(head1);

    head1 = modifiedList (num1, numSize1, head1);
    printf("Setelah: ");
    cetakList(head1);
    printf("\n");

    /*Test Case 2: num=[1] dan head=[1,2,1,2,1,2]*/
    int num2[] = {1};
    int numSize2 = 1;    

    Node *head2 = buatNode(1);
    head2->next = buatNode(2);
    head2->next->next = buatNode(1);
    head2->next->next->next = buatNode(2);
    head2->next->next->next->next = buatNode(1);
    head2->next->next->next->next->next = buatNode(2);
    
    printf("Test Case 2:\n");
    printf("Input: num = {1}, head = {1,2,1,2,1,2}\n");
    printf("Sebelum: ");
    cetakList(head2);

    head2 = modifiedList (num2, numSize2, head2);
    printf("Setelah: ");
    cetakList(head2);
    printf("\n");

    /*Test Case 3: num=[5] dan head=[1,2,3,4]*/
    int num3[] = {5};
    int numSize3 = 1;    

    Node *head3 = buatNode(1);
    head3->next = buatNode(2);
    head3->next->next = buatNode(3);
    head3->next->next->next = buatNode(4);
    
    printf("Test Case 3:\n");
    printf("Input: num = {5}, head = {1,2,3,4}\n");
    printf("Sebelum: ");
    cetakList(head3);

    head3 = modifiedList (num3, numSize3, head3);
    printf("Setelah: ");
    cetakList(head3);
    printf("\n");

    return 0;
}