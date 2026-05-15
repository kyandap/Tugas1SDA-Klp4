#include <stdio.h>

#define MAX 25

int V, H, N;
int papan[MAX][MAX];   // 0 = kosong, 1 = batu

// Fungsi rekursif simulasi air
int simulasi(int baris, int kolom) {
    // Jika keluar dari batas kolom
    if (kolom < 1 || kolom > H)
        return 0;

    // Turun sampai menemukan batu
    while (baris <= V && papan[baris][kolom] == 0) {
        baris++;
    }

    // Jika sampai dasar tanpa batu
    if (baris > V)
        return 0;

    // Kena batu -> hitung 1 tabrakan
    int tabrakan = 1;

    // Cari ujung kiri batu pada baris ini
    int kiri = kolom;
    while (kiri > 1 && papan[baris][kiri - 1] == 1) {
        kiri--;
    }

    // Cari ujung kanan batu pada baris ini
    int kanan = kolom;
    while (kanan < H && papan[baris][kanan + 1] == 1) {
        kanan++;
    }

    // Air bercabang dari luar batu
    tabrakan += simulasi(baris + 1, kiri - 1);
    tabrakan += simulasi(baris + 1, kanan + 1);

    return tabrakan;
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File data.txt tidak ditemukan.\n");
        return 1;
    }

    // Baca ukuran peta dan jumlah batu
    fscanf(fp, "%d %d %d", &V, &H, &N);

    // Inisialisasi papan kosong
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= H; j++) {
            papan[i][j] = 0;
        }
    }

    // Baca data batu
    for (int k = 0; k < N; k++) {
        int v1, h1, v2, h2;
        fscanf(fp, "%d %d %d %d", &v1, &h1, &v2, &h2);

        // Batu horizontal
        if (v1 == v2) {
            for (int j = h1; j <= h2; j++) {
                papan[v1][j] = 1;
            }
        }
        // Batu vertikal
        else if (h1 == h2) {
            for (int i = v1; i <= v2; i++) {
                papan[i][h1] = 1;
            }
        }
    }

    fclose(fp);

    int maksimum = 0;

    // Coba semua kolom awal
    for (int kolom = 1; kolom <= H; kolom++) {
        int hasil = simulasi(1, kolom);
        if (hasil > maksimum) {
            maksimum = hasil;
        }
    }

    // Output hasil maksimum
    printf("%d\n", maksimum);

    return 0;
}