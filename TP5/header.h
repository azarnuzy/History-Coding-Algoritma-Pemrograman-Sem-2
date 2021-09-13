#include <stdio.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP5 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
double pecahan[1000];	//membuat variabel gloabal untuk patokan nilai yang ingin diurutkan
//sebagai prosedur untuk menampung nilai pecahan dari nilai pembilang dan penyebut
void tampunganPecahan(int n, int pembilang[], int penyebut[]);					
//sebagai prosedur untuk sorting dengan cara bubble sort		
void bubbleSOrt(int n, int pembilang[], int penyebut[], char z);
//sebagai prosedur untuk sorting dengan cara quicksort
void quickSort(int n, int pembilang[], int penyebut[], char z, int kiri, int kanan);
//sebagai prosedur untuk menampilkan hasil
void tampil(int n, int pembilang[], int penyebut[]);