#include <stdio.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat matriks tipe data terstruktur 
typedef struct{
	char jenis[100];	//sebagai string dari jenis makanan
	int harga;			//sebagai integer dari harga makanan
}makanan;				//sebagai bungkusan dari tipe data terstruktur makanan

//membuat fungsi untuk menentukan jumlah yang dibayar oleh pemain
int membeli(makanan matriks[][100], int b1, int k1, int indexI[], int indexJ[], int n);

//membuat prosedur untuk mengeluarkan pemenang dan jumlah harga yang harus dibayar oleh pemain
void result(int x, int y);
