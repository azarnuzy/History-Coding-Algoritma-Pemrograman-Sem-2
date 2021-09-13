#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP8 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//tipe data terstruktur yang berisi bagian2 sub film
typedef struct {
    char judulFilm[100][100];   //sebagai judul film
    char id_s[100][100];        //sebagai id sutradara
    char id_g[100][100];        //sebagai id genre
    char id_b[100][100];        //sebagai id bioskop
    char n_s[100][100];         //sebagai nama sutradara
    char n_g[100][100];         //sebagai nama genre
    char n_b[100][100];         //sebagai nama bioskop
}film;                          //sebagai bungkusan sebuah tipe data film

//variabel untuk menentukan panjang dari tabel
int maxJudul;   //sebagai nilai max panjang judul
int maxSut;     //sebagai nilai max panjang sutradara
int maxGen;     //sebagai nilai max panjang genre
int maxBio;     //sebagai nilai max panjang bioskop
int maxTot;     //sebagai nilai max panjangn total dari judul, sutradara, genre, bioskop

film searchIdGenre(char idCari[], int itr);             //sebagai fungsi untuk menemukan genre berdasarkan id genre
film searchIdSutradara(char idCari[], int itr);         //sebagai fungsi untuk menemukan sutradara berdasarkan id sutradara
film searchIdBioskop(char idCari[], int itr);           //sebagai fungsi untuk menemukan bioskop berdasarkan id bioskop
void getMax(film list, film fullList, int n);           //sebagai prosedur untuk menemukan nilai panjangn maksimal dari setiap bagian sub film 
void tampilanDat(film list, film fullList, int n);      //sebagai prosedur untuk menampilkan hasil akhir di file .dat
void tampilanConsole(film list, film fullList, int n);  //sebagai prosedur untuk menampilkan hasil akhir di console
    