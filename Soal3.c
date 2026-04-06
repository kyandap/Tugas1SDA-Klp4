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

// Fungsi utama No 3: Menghapus Duplikasi
struct Node *hapusDuplikasi(struct Node *head)
{
    // Jika kalau kosong / 1 node, tidak ada duplikat
    if (head == NULL || head->next == NULL)
        return head;

    // Pointer untuk traversal
    struct Node *current = head;

    // Loop selama masih ada next
    while (current != NULL && current->next != NULL)
    {
        // Validasi apakah sama dengan next
        if (current->nilai == current->next->nilai)
        {
            // Jika sama, hapus node next
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            // Jika nilainya berbeda, lanjut ke node berikutnya
            current = current->next;
        }
    }
    return head;
}

int main()
{
    int n;

    // Input jumlah node
    printf("Masukkan jumlah node (0 - 300): ");
    scanf("%d", &n);

    // Validasi jumlah node
    if (n < 0 || n > 300)
    {
        printf("Error: Jumlah node di luar batas!\n");
        return 1; // Keluar dari program dengan kode error
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Jika n > 0, minta input nilai dari user
    if (n > 0)
    {
        printf("Silahkan masukkan %d nilai secara berurutan (ascending, antara -100 dan 100):\n", n);

        int nilaiSebelumnya = -101; // Set nilai awal di bawah batas minimal untuk perbandingan

        for (int i = 0; i < n; i++)
        {
            int val;
            printf("Node ke-%d: ", i + 1);
            scanf("%d", &val);

            // Validasi range nilai
            if (val < -100 || val > 100)
            {
                printf("Error: Nilai %d di luar batas [-100, 100]!\n", val);
                return 1; // Keluar dari program dengan kode error
            }

            // Validasi harus ascending
            if (val < nilaiSebelumnya)
            {
                printf("Error: Nilai harus diinput secara menaik (ascending)!\n");
                return 1; // Keluar dari program dengan kode error
            }
            nilaiSebelumnya = val;

            // Insert ke List
            struct Node *newNode = buatNode(val);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode; // Geser tail ke node terakhir
            }
        }
    }

    // Menampilkan hasil
    printf("\n--- HASIL ---\n");
    printf("Linked List Awal:\n");
    cetakList(head);

    head = hapusDuplikasi(head);

    printf("\nLinked List Setelah Duplikasi Dihapus:\n");
    cetakList(head);

    return 0; // Program berjalan dengan sukses
}