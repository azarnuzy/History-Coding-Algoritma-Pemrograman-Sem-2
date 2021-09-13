#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    int nilai[3];
    float rata2;
}masukan;

masukan matriks[100][100];

void stPos(int r, int c );
void searchName(int r, int c, char namaKursi[][100], int count);
int cekRata(int x, int y);
void swap(char x[], char y[], float *a, float *b);
void scPos(int r,int c);