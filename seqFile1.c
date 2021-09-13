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
    FILE *arsipMatkul;
    arsipMatkul = fopen("ArsipMatkul.dat", "w");
    printf("Tuliskan rekaman satu persatu: \n\n");

    printf("Masukan NIM: ");
    scanf("%s", &rekaman.nim);

    while(strcmp(rekaman.nim, "XXXXXX") != 0 ){
        printf("Masukan Nama: ");
        scanf("%s", &rekaman.nama);
        printf("Masukan Nilai: ");
        scanf("%s", &rekaman.nilai);

        fprintf(arsipMatkul, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);

        printf("Masukan NIM: ");
        scanf("%s", &rekaman.nim);
    }

    fprintf(arsipMatkul, "%s %s %s\n", "XXXXXX", "XXXX", "X");
    fclose(arsipMatkul);
    return 0;
}
