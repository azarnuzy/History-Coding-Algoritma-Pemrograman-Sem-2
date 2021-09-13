#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP7 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
    //sebagai masukan dari jumlah siswa
    int n;
    scanf("%d", &n);
    //sebagai iterator untuk pengulangan 
    int i,j;
    //sebagai nilai untuk melakukan pengecekan apakah data masukan sudah 
    //terurut dari kecil terbesar apa belum
    float max;
    //sebagai nilai untuk tipedata terstruktur dari data siswa
    data masukan;
    //sebagai pengulangan untuk masukan
    for(i=0; i<n; i++){
        //masukan berupa nama dan jumlah
        int temp = 0;
        scanf("%s", &masukan.nama[i]);
        scanf("%d", &masukan.jmlh[i]);
        //pengulangan masukan berupa nilai dan jumlah dari nilai setiap siswa
        for(j=0; j<masukan.jmlh[i]; j++){
            scanf("%d", &masukan.nilai[i][j]);
            temp += masukan.nilai[i][j];
        }
        //sebagai operasi untuk mendapatkan rata-rata 
        //max sebagai penampung untuk mendapatkan nilai terbesar 
        //yang nantinya akan dilakukan pengecekan pada nila terbesar dari 
        //sebelum terurut dan setelah diurut
        masukan.rata2[i] = (float) temp / masukan.jmlh[i];
        max = masukan.rata2[0];
        //memasukan nilai max
        if(max < masukan.rata2[i]){
            max = masukan.rata2[i];
        }
    }
    //meamsukan index yang ingin dicari
    int inx; 
    scanf("%d", &inx);
    //sebagai penampung dari nilai yang sudah diurut
    data urut;
    urut = selection(n, masukan);
    //seabgai keluaran dari nama-nama yang sudah terurut
    for(i=0; i<n; i++){
        printf("%s\n", urut.nama[i]);
    }
    printf("\n");
    //sebagai keluaran dari nama yang diinginkan sesuai dengan index
    //kondisi satu jika nilai sebelum dan setelah diurut sama maka dilakukan pencari binarysearch
    //kondisi dua jika nilai sebelum dan setelha diurut berbeda maka dilakukan pencarian sequentialsearch
    if(max == urut.rata2[n-1]){
        binarySearch(0, n-1, masukan, urut, inx);
    }else{
        sequentialSearch(n, masukan, urut, inx);
    }
    return 0;
}
