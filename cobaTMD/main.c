/* #include <stdio.h>
#include <string.h>

typedef struct {
    char id[100];
    char data1[100];
    char data2[100];
    char data3[100];
    char data4[100];
}tabel;

typedef struct  
{
    char id[100][100];
    char data1[100][100];
    char data2[100][100];
    char data3[100][100];
    char data4[100][100];
}tabel1;

int indeksAnggota;

tabel getFile(char table[]) {
    FILE *tabelFile;
    tabel data;
    tabel1 dataBaru;
    char nameFile[50];
    sprintf(nameFile, "%s.dat", table);
    tabelFile = fopen(nameFile, "r");

    fscanf(tabelFile, "%s %s %s %s %s\n", data[indeksAnggota].id, data[indeksAnggota].data1,data[indeksAnggota].data2,data[indeksAnggota].data3,data[indeksAnggota].data4);

    dataBaru
    fclose(tabelFile);

    
}

void tampil(tabel data[], int indeksTabel) {
    int i;
    for(i=0; i<indeksTabel; i++){
        printf("%s %s %s %s %s\n", data[i].id, data[i].data1, data[i].data2, data[i].data3, data[i].data4);
    }
}

int main(int argc, char const *argv[])
{
    indeksAnggota = 0;
    tabel tanggota[100];
    
    getFile(&tanggota[indeksAnggota], "Anggota");

    while(strcmp(tanggota[indeksAnggota].id, "####") != 0 ){
        printf("%s\n", tanggota[indeksAnggota].id);
        indeksAnggota++;
        getFile(&tanggota[indeksAnggota], "tAnggota");
    }
    indeksAnggota++;
    tampil(tanggota, indeksAnggota);

    return 0;
}
 */