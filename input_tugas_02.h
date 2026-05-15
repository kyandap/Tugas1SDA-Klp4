#ifndef INPUT_H
#define INPUT_H

typedef struct {
    int v1, h1;
    int v2, h2;
} Batu;

extern int V;
extern int H;
extern int N;

extern Batu batu[500];

void bacaData();

#endif