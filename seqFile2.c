#include <stdio.h>
#include <string.h>
//arsip beruntun tanpa pencarian
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
    printf("Isi arsip beruntun adalah: \n");
    fscanf(arsipMatkul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    if(strcmp(rekaman.nim, "XXXXXX") == 0){
        printf("arsip konsong\n");
    }else {
        do{
            printf("NIM : %s\n", rekaman.nim);
            printf("Nama : %s\n", rekaman.nama);
            printf("Nilai : %s\n", rekaman.nilai);
            fscanf(arsipMatkul,"%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
        }while(strcmp(rekaman.nim, "XXXXXX") != 0);
    }
    fclose(arsipMatkul);
    
    return 0;
}


