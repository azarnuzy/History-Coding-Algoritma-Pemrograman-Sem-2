#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilaiMatkul;

int main(int argc, char const *argv[])
{
    nilaiMatkul rekaman;
    FILE *arsipMatkul1;
    FILE *arsipMatkul2;
    FILE *arsipMatkul3;

    arsipMatkul1 = fopen("ArsipMatkul1.dat", "r");
    arsipMatkul2 = fopen("ArsipMatkul2.dat", "r");
    arsipMatkul3 = fopen("ArsipMatkul3.dat", "w");

    printf("Mulai proses penggabungan : \n");
    fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    while(strcmp(rekaman.nim, "XXXXXX") != 0){
        fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        fscanf(arsipMatkul1, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
    }

    fscanf(arsipMatkul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    while(strcmp(rekaman.nim, "XXXXXX") != 0){
        fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        fscanf(arsipMatkul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
    }

    fprintf(arsipMatkul3, "%s %s %s\n", "XXXXXX", "XXXX", "X");
    printf("Penggabungan selesai!");
    fclose(arsipMatkul3);
    return 0;
}
