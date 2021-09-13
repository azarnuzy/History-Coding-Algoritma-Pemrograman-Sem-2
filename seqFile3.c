#include <stdio.h>
#include <string.h>
//arsip beruntun dengan pencarian
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
    arsipMatkul = fopen("ArsipMatkul.dat", "r");

    char kataCari[10];
    scanf("%s", kataCari);

    printf("Isi arsip beruntun adalah: \n");
    fscanf(arsipMatkul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    if(strcmp(rekaman.nim, "XXXXXX") == 0){
        printf("arsip kosong\n");
    }else {
        if(strcmp(kataCari, "XXXXXX") == 0){
            printf("Tidak ditemukan");
        }else{
            while(strcmp(rekaman.nim, "XXXXXX") != 0 && strcmp(rekaman.nim, kataCari) != 0){
                fscanf(arsipMatkul,"%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
            }

            if(strcmp(rekaman.nim, kataCari) == 0){
                printf("NIM : %s\n", rekaman.nim);
                printf("Nama : %s\n", rekaman.nama);
                printf("Nilai : %s\n", rekaman.nilai);
            }else{
                printf("Tidak ditemukan \n");
            }
        }

    }
    fclose(arsipMatkul);
    return 0;
}
