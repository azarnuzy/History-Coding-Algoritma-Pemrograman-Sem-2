#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//tipe data terstruktur untuk data mahasiswa 
typedef struct{
    char nama[100][100];
    int nilai1[100];
    int nilai2[100];
}mahasiswa;

mahasiswa insertion(int n,mahasiswa in);    //sebagai prosedur untuk mengurutkan data kelompok berdasarkan nama
mahasiswa gabungTerurut(int n, mahasiswa in1, int m, mahasiswa in2);    //menggabungkan secara terurut kel1 dan kel2
void tampil(int n, mahasiswa out);          //menampilkan nilai dari hasil penggabungan 