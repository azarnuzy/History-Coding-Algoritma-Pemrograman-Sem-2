#include <stdio.h>
#include <string.h>
//menyalin arsip beruntun
typedef struct {
    char nim[100];
    char nama[100];
    char nilai[100];
}nilaiMatkul;

int main(int argc, char const *argv[])
{
    nilaiMatkul rekaman;
    FILE *arsipMatkul1;
    FILE *arsipMatkul2; 

    arsipMatkul1 = fopen("ArsipMatkul.dat", "r");
    arsipMatkul2 = fopen("ArsipMatkul.bak", "w");

    printf("Mulai proses menyalin: \n");

    fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    if(strcmp(rekaman.nim, "XXXXXX") == 0){
        printf("arsip kosong");
    }else{
        while(strcmp(rekaman.nim, "XXXXXX") != 0){
            fprintf(arsipMatkul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);

            fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
        }

        fprintf(arsipMatkul2, "%s %s %s\n", "XXXXXX", "XXXX", "X");
    }

    printf("proses menyalin file selesai\n");
    fclose(arsipMatkul1);
    fclose(arsipMatkul2);
    return 0;
}
