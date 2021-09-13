#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat masukan tipe data terstruktuk sebagai bagian dari matriks
typedef struct{
    char nama[100];//sebagai variabel dari nama mahasiswa
    int nilai[100];//sebagai variabel dari nilai-nilai mahasiswa
    float rata2;//sebagai variabel dari rata-rata nilai mahasiswa
}masukan;

int max[100];//sebagai variabel untuk  nama terpanjang
masukan matriks[100][100];//membuat variabel global untuk matriks

void spasi1(int r, int c);//membuat prosedur untuk mencari nama terpanjang
void stPos(int r, int c );//membuat prosedur untuk menampilkan posisi bangku awal
void searchName(int r, int c, char namaKursi[][100], int count);//membuat prosedur untuk mencari nama mahasiswa yang akan di lakukan perpindahan tempat duduk
int cekRata(float x, float y);//membuat fungsi untuk mengecek nilai rata-rata dari dua mahasiswa yang akan di tukar tempat duduknya
void swap(char x[], char y[], float *a, float *b);//membuat prosedur untuk mengganti posisi bangku mahasiswa 