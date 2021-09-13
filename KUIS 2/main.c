#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi KUIS2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
    int n;              //banyaknya array dari masukan yang diinginkan
    scanf("%d", &n);    //memasukan elemen array 
    int i;              //iterator

    kurma a;            //bungkusan untuk menyimpan masukan 
                        
    for(i=0; i<n; i++){ //perulangan untuk masukan sesuai dengan soal
        scanf("%s %d %d %s", &a.nama[i], &a.berat[i], &a.harga[i], &a.status[i]);
    }

    scanf("%d", &a.cariHargaGram);  //masukan dari harga per gram yang dicari

    kurma b = tempHargaGram(n, a);  //menyimpan fungsi tempHargaGram kepada bungkusan b
    kurma c = selection(n, b, a);   //menyimpan fungsi selection kepada bungkusan c
    c.ketemu = binarySearch(0, n-1, a.cariHargaGram, c);    //menyimpan fungsi binarySearch kepada c.ketemu
    tampil(n, c);                   //menampilkan nilai sesuai dengan soal

    return 0;
}
