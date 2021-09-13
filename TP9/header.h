#include <stdio.h>
#include <string.h>

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP9 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int indeks;                         //variabel untuk menentukan indeks dari id
char cc;                            //variabel untuk menyimpan karakter saat proses terjadi
void START(char id[]);            //prosedur untuk mulai
void INC(char id[]);              //prosedur untuk bertambahnya indeks karakter
int EOP();                          //fungsi untuk melakukan pengecekan akhir dari id
void ADV(char id[]);              //prosedur untuk melakukan pengecekan terhadap spasi
char GETCC();                       //fungsi untuk mendapatkan karakter
