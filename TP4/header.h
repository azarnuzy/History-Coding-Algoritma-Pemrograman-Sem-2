#include <stdio.h>
#include <string.h>

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP4 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

typedef struct{
	char nama[100][100];
	int harga[100];
	float nilai[100];
}laporan;	//membuat tipe data terstruktur untuk laporan dari masukan user

char metode[100],urut[100],patokan[100];			//membuat variabel untuk masukan metode, urutan dari besar/kecil, dan patokan sebagai apa yang harus diurutkan
int tempNama[100], tempHarga[100], tempNilai[100];	//membuat variabel untuk tempat sementara dari laporan masukan berupa nama, harga, dan nilai
void ubahNilai(int n, laporan masukan);				//membuat prosedur untuk mengubah nilai dari nama, harga, dan penilain menjadi integer
void insertion(int n,int x[], laporan masukan);		//membuat prosedur untuk mengurutkan dengan cara insertion
void selection(int n, int x[], laporan masukan);	//membuat prosedur untuk mengurutkan dengan cara selection
void tampil(int n, laporan masukan);				//membuat prosedur untuk menampilkan hasil yang sudah diurutkan