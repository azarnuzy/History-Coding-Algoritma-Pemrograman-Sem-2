#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[50];
    char nama[50];
    float nilai;
}nilaiMatkul;

nilaiMatkul tabel[5];

void isi(int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%s %s %f", &tabel[i].nim, &tabel[i].nama, &tabel[i].nilai);
    }
}

void sequentialSearch(int n, char nimCari[]){
    int i=0;
    int ketemu = 0;
    while(i < n && ketemu == 0){
        printf("%s %s\n", tabel[i].nim, nimCari);
        if(strcmp(tabel[i].nim, nimCari) == 0){
            ketemu = 1;
        }else {
            i++;
        }
    }

    if(ketemu == 1){
        printf("nim: %s\n", tabel[i].nim);
        printf("nama: %s\n", tabel[i].nama);
        printf("nilai: %0.2f\n", tabel[i].nilai);
    }else{
        printf("tidak ditemukan\n");
    }
}

void binarySearch(int i, int j, float bilCari){
    int k;
    int ketemu = 0;

    while(ketemu == 0 && i<= j){
        k = (int) (i+j) / 2;
        if(tabel[k].nilai == bilCari){
            ketemu = 1;
        }else{
            if(tabel[k].nilai > bilCari){
                j = k - 1;
            }else{
                i = k + 1;
            }
        }
    }

    if(ketemu == 1){
        printf("ada pada tabel\n");
    }else{
        printf("tidak ditemukan\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    isi(n);
    char nimCari[50];
    scanf("%s", &nimCari);

    float nilaiCari;
    scanf("%f", &nilaiCari);
    sequentialSearch(n, nimCari);
    binarySearch(0, n-1, nilaiCari);
    
    return 0;
}
