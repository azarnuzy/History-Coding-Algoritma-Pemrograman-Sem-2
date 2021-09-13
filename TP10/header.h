#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP10 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


int indeks;             //variabel untuk indeks dari kata yang dimasukan
int indeksBaku;         //variabel untuk indeks dari kata baku yang didapat
int indeksTidakBaku;    //variabel untuk indeks dari kata tidak baku yang didapat
int panjangKata;        //variabel untuk menunjukan panjang dari sebuah kata
char ckata[200];                //variabel untuk menunjukan sebuah kata yang 
char kataBaku[100][100];        //variabel untuk menyimpan kata baku
char kataTidakBaku[100][100];   //variabel untuk menyimpan kata tidak baku

void STARTKATA(char pita[]);                    //prosedur untuk memulai sebuah program dan mendapatkan kata awal
void RESETKATA();                               //prosedur untuk mereset sebuah kata
int EOPKATA(char pita[]);                       //prosedur untuk menentukan akhir dari kalimat
void INCKATA(char pita[]);                      //prosedur untuk menelusuri setiap kata di dalam suatu kalimat
char* GETCKATA();                               //prosedur untuk mengambil kata yang sedang ditelusuri
int GETPANJANGKATA();                           //prosedur untuk mendapatkan panjang dari sebuah kata                                 
void insertion(int a,char s[][100]);            //prosedur untuk mengurutkan kata berdasarkan dengan abjad
int hitungKata(char kata[], int panjangKata);   //prosedur untuk mendapatkan jumlah huruf ascii dalam sebuah kata 