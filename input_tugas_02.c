#include <stdio.h>
#include "input_tugas_02.h"

int V;
int H;
int N;

Batu batu[500];

void bacaData()
{

    FILE *fp;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("File tidak ditemukan\n");
        return;
    }

    fscanf(fp, "%d %d %d", &V, &H, &N);

    for (int i = 0; i < N; i++)
    {

        fscanf(fp, "%d %d %d %d",
               &batu[i].v1,
               &batu[i].h1,
               &batu[i].v2,
               &batu[i].h2);
    }

    fclose(fp);
}