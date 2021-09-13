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

    arsipMatkul1 = fopen("ArsipMatkul1.dat", "w");
    arsipMatkul2 = fopen("ArsipMatkul2.dat", "w");

    scanf("%s", &rekaman.nim);

    while(strcmp(rekaman.nim, "XXXXXX") != 0){
        scanf("%s %s",&rekaman.nama, &rekaman.nilai);
        fprintf(arsipMatkul1, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        scanf("%s", &rekaman.nim);
    }

    fprintf(arsipMatkul1, "%s %s %s\n","XXXXXX", "XXXX", "X");

    scanf("%s", &rekaman.nim);

    while(strcmp(rekaman.nim, "XXXXXX") != 0){
        scanf("%s %s",&rekaman.nama, &rekaman.nilai);
        fprintf(arsipMatkul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        scanf("%s", &rekaman.nim);
    }

    fprintf(arsipMatkul2, "%s %s %s\n","XXXXXX", "XXXX", "X");

    fclose(arsipMatkul1);
    fclose(arsipMatkul2);
    return 0;
}
