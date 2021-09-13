#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP7 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat tipe data terstruktur untuk data anak yang mengikuti kegiatan 
//ekstrakurikuler

typedef struct {
    char nama[100][100];    //nama siswa
    int jmlh[100];          //jumlah kegiatan yang diikuti
    int nilai[100][100];    //nilai dari kegiatan yang diikuti
    float rata2[100];       //rata2 dari nilai kegiatan
}data;

data selection(int n,data masukan);     //sebagai fungsi untuk mengurutkan data sesuai dengan nilai rata2 
void binarySearch(int i, int j, data masukan, data urut, int indeks);   //sebagai prosedur untuk mencari nama sesuai dengan index yang diinginkan dengan urutan yang sudah terurut sebelumnya
void sequentialSearch(int n,data masukan, data urut, int index);        //sebagai prosedur untuk mencari nama sesuai dengan index yang diinginkan dengan urutan yang belum terurut sebelumnya
