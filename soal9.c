#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int nilai;
    struct Node *next;
}Node;

/*Fungsi membuat node baru*/
Node *buatNode (int nilai) {
    Node* node = malloc (sizeof(Node));
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

/*Fungsi Utama untuk membalik List dari posisi kiri ke kanan*/
Node *reserveAntara (Node *head, int kiri, int kanan) {
    if (head == NULL || kiri > kanan) {  /*Jika list kosong atau kiri > kanan, return head*/
        return head;
    }

Node dummyNode;   /*Gunakan dummy node untuk menghilangkan penghapusan head*/
dummyNode.next = head;
Node *prev = &dummyNode;

/*Untuk pindah ke posisi sebelum kiri (posisi kiri-1)*/
for (int i=1; i<kiri; i++) {
    prev = prev->next;
}

/*prev berada di posisi kiri-1, mulai reserve dari kiri ke kanan*/
Node *current = prev->next;   //posisi kiri
Node *tail = current;
Node *prevReserve = NULL;
Node *nextNode = NULL;
int count = kanan - kiri+1; /*Menghitung jumlah node yang akan di-reserve*/

for (int i=0; i<count; i++) {
    nextNode = current->next;
    current->next = prevReserve;
    prevReserve = current;
    current = nextNode;
}

/*Menghubungkan tail dari bagian yang di-reserve ke head selanjutnya*/
prev->next = prevReserve;   /*hubungkan prev ke head baru hasil reserve*/
tail->next = current;  /*hubungkan tail ke sisa list*/

return dummyNode.next;
}

int main () {

/*Test Case 1: [1,5,3,7,5] kiri = 2, lalu kanan = 4*/
Node *head1 = buatNode(1);
head1->next = buatNode(5);
head1->next->next = buatNode(3);
head1->next->next->next = buatNode(7);
head1->next->next->next->next = buatNode(5);

printf("Test Case 1: \n");
printf("Input: [1,5,3,7,5], kiri = 2, kanan = 4\n");
printf("Sebelum: ");
cetakList(head1);

head1 = reserveAntara(head1, 2, 4);
printf("Sesudah: ");
cetakList(head1);
printf("\n");

/*Test Case 2: [5] kiri = 1, lalu kanan = 1*/
Node *head2 = buatNode(5);

printf("Test Case 2:\n");
printf("Input: [5], kiri = 1, kanan = 1\n");
printf("Sebelum: ");
cetakList(head2);

head2 = reserveAntara(head2, 1, 1);
printf("Sesudah: ");
cetakList(head2);
return 0;
}