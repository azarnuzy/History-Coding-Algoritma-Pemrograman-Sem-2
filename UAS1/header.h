#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UAS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int indeks;                     //variabel untuk indeks dari kata yang dimasukan
char ckata[200];                //variabel untuk menunjukan sebuah kata yang 
char subKata[10];               //variabel untuk menunjukan subkata yang dicari
char subsKata[100][10];         //variabel untuk menampung nilai dari subkata yang memenuhi
int panjangKata;                //variabel untuk menunjukan panjang dari sebuah kata
int indeksSubKata;              

void STARTKATA(char pita[]);                    //prosedur untuk memulai sebuah program dan mendapatkan kata awal
void RESETKATA();                               //prosedur untuk mereset sebuah kata
int EOPKATA(char pita[]);                       //prosedur untuk menentukan akhir dari kalimat
void INCKATA(char pita[]);                      //fungsi untuk menelusuri setiap kata di dalam suatu kalimat
char* GETCKATA();                               //prosedur untuk mengambil kata yang sedang ditelusuri
int GETPANJANGKATA();                           //prosedur untuk mendapatkan panjang dari sebuah kata        
int CHECKHURUF(char churuf);                    //fungsi untuk mengecek huruf di kata apakah konsonan atau vokal
int CHECKSUBKATA(char kata[]);                  //fungsi untuk mengecek subkata apakah sesuai atau tidak 
void CARIVOKAL(char pita[]);                    //prosedur untuk mencari subkata vokal konsonan konsonan vokal
void TAMPIL();                                  //prosedur untuk menampilkan hasil 