#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node
struct Node
{
    int nilai;
    struct Node *next;
};

// Fungsi membuat node baru
struct Node *buatNode(int nilai)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->nilai = nilai;
    newNode->next = NULL;
    return newNode;
}

// Fungsi menampilkan linked list
void cetakList(struct Node *head)
{
    if (head == NULL)
    {
        printf("[]\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->nilai);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi utama No 4: Menghapus Node ke-n dari posisi akhir
struct Node *hapusDariAkhir(struct Node *head, int n)
{
    // Membuat dummy biar aman kalau hapus head
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->nilai = 0;
    dummy->next = head;

    struct Node *slow = dummy;
    struct Node *fast = dummy;

    // Menggeser fast n langkah
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // Memajukan kedua pointer bersamaan sampai fast di ujung list
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Pointer slow tepat sebelum node yang dihapus
    struct Node *nodeYangAkanDihapus = slow->next;

    // Melepas node
    slow->next = slow->next->next;

    // Free memory
    free(nodeYangAkanDihapus);

    // Mengambil head yang baru dari sebelah dummy node
    struct Node *newHead = dummy->next;
    free(dummy); // Menghapus dummy node dari memori

    return newHead;
}

int main()
{
    int sz, n; // Deklarasi variabel

    // Input jumlah node sz
    printf("Masukkan jumlah node (sz) [1 - 30]: ");
    scanf("%d", &sz);

    // Validasi input sz
    if (sz < 1 || sz > 30)
    {
        printf("Error: Jumlah node harus antara 1 sampai 30!\n");
        return 1; // Keluar dari program dengan kode error
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Input jumlah dan rentang nilai
    printf("Masukkan %d nilai secara berurutan (antara 0 sampai 100):\n", sz);
    for (int i = 0; i < sz; i++)
    {
        int val; // Variabel temporary untuk iterasi saat ini
        printf("Node ke-%d: ", i + 1);
        scanf("%d", &val);

        // Validasi nilai [0, 100]
        if (val < 0 || val > 100)
        {
            printf("Error: Nilai node %d di luar batas [0, 100]!\n", val);
            return 1; // Keluar dari program dengan kode error
        }

        struct Node *newNode = buatNode(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Input posisi n yang ingin dihapus dari belakang
    printf("Masukkan posisi node dari belakang yang ingin dihapus (n) [1 - %d]: ", sz);
    scanf("%d", &n);

    // Validasi nilai n
    if (n < 1 || n > sz)
    {
        printf("Error: Posisi n harus antara 1 sampai ukuran list (%d)!\n", sz);
        return 1; // Keluar dari program dengan kode error
    }

    // Menampilkan hasil
    printf("\n--- HASIL ---\n");
    printf("Linked List Awal:\n");
    cetakList(head);

    head = hapusDariAkhir(head, n);

    printf("\nLinked List Setelah Node ke-%d dari akhir dihapus:\n", n);
    cetakList(head);

    return 0;
}