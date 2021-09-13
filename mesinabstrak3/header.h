#include <stdio.h>
#include <string.h>

typedef struct  
{
    char nim[10];
    char nama[100];
    char nilai[7];
}mahasiswa;

int indeks;     
int panjangKata;
char currentKata[50];

void startKata(char pita[]);
void resetKata();
void incKata(char pita[]);
char *getCurrentKata();
int getPanjangKata();
int eopKata(char pita[]);
void insertData(char pita[], mahasiswa *data);
