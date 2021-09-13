#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


int indeks;             //variabel untuk indeks dari kata yang dimasukan
int indeksKereta;       //variabel untuk indeks pada kereta
int panjangKata;        //variabel untuk menunjukan panjang dari sebuah kata
char ckata[200];        //variabel untuk menunjukan sebuah kata yang 

int judul1, judul2, judul3; //variabel untuk panjang judul tabel

typedef struct
{
    char id[100];
    char nama[100];
    char kelas[100];
}transportasi;  //type struct untuk data kereta

transportasi keretahasil[100];  //nilai untuk kereta yang ditampilkan

void STARTKATA(char pita[]);                    //prosedur untuk memulai sebuah program dan mendapatkan kata awal
void RESETKATA();                               //prosedur untuk mereset sebuah kata
int EOPKATA(char pita[]);                       //fungsi untuk menentukan akhir dari kalimat
void INCKATA(char pita[]);                      //prosedur untuk menelusuri setiap kata di dalam suatu kalimat
char* GETCKATA();                               //prosedur untuk mengambil kata yang sedang ditelusuri
int GETPANJANGKATA();                           //fungsi untuk mendapatkan panjang dari sebuah kata                                 
void insertion(int a,char s[][100]);            //prosedur untuk mengurutkan kata berdasarkan dengan abjad
void insertData(char pita[], transportasi *data);       //prosedur untuk memasukan nilai 
int sequentialSearch(int indeksData,char atribut[], char cariKata[], transportasi data[]); //fungsi untuk mencari nilai yang dicari
void getMaxLen(transportasi data[], int indeksData);    //prosedur untuk mendapatkan nilai maksimal atribut
void stripTabel(int len);                               //prosedur untuk menampilkan strip pada tabel
void containtJudulTable(char jId[], char jNama[], char jKelas[]);   //prosedur untuk menampilkan judul
void containtTabel(int len, char containt[]);           //prosedur untuk menampilkan perdata kereta
void tampilData(transportasi data[], int i);            //prosedur untuk menampilkan data kereta
void tampilTData(transportasi data[], int indeksData);  //prosedur untuk menampilkan tabel data kereta