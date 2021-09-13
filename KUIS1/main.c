#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


int main(int argc, char const *argv[])
{
	
	int b,k;		//b = baris || k = kolom
	int n;			//sebagai banyaknya isi tipe data terstruktur
	int i,j;		//sebagai iterator

	scanf("%d %d", &b, &k);		//membuat masukan untuk baris dan kolom
	scanf("%d", &n);			//membuat masukan untuk banyak masukan makanan dan harga

	int m;				//sebagai banyaknya pilihan dari setiap pemain
	makanan matriks[100][100];	//sebagai variabel untuk menampung masukan

	//memanggil prosedur nilaiAwal dari matriks

	int b1,k1;						//sebagai baris dan kolom untuk masukan dari jenis makanan dan harga
	int indexI[100], indexJ[100]; 	//sebagai penyimpan untuk index masukan dari jenis makanan dan harga

	//membuat perulangan untuk menjadikan nilai dari matriks.harga bernilai 0
	for(i=0; i<b; i++){
		for(j=0; j<k; j++){
			matriks[i][j].harga = 0;
		}
	}

	//membuat perulangan untuk masukan urutan baris, kolom, jenis makanan, dan harga
	for(i=0; i<n; i++){
		scanf("%d %d", &b1, &k1);				//sebagai masukan dari urutan baris dan kolom
		indexI[i] = b1;
		indexJ[i] = k1;
		scanf("%s", &matriks[b1][k1].jenis);	//sebagai masukan dari jenis makanan sesuai dengan baris dan kolom
		scanf("%d", &matriks[b1][k1].harga);	//sebagai masukan dari harga makanan sesuai dengan baris dan kolom
	}

	//membuat masukan untuk menentukan  banyaknya urutan koordinat pemain pertama memilih makanan
	scanf("%d", &m);					//sebagai masukan untuk banyak pemain memilih makanan sesuai sel

	int pemain1 = 0,  pemain2 = 0;		//sebagai variabel untuk koordinat dari pemain

	//membuat perulangan untuk memasukan sel dari pemain pertama
	for(i=0; i<m; i++){
		scanf("%d %d", &b1, &k1);
		pemain1 = pemain1 + membeli(matriks, b1, k1, indexI, indexJ, n);//sebagai nilai dari harga yang harus dibayar oleh pemain pertama
	}

	//membuat perulangan untuk memasukan sel dari pemain kedua
	for(i=0; i<m; i++){
		scanf("%d %d", &b1, &k1);
		pemain2 = pemain2 + membeli(matriks, b1, k1, indexI, indexJ, n);//sebagai nilai dari harga yang harus dibayar oleh pemain kedua
	}

	//memanggil prosedur untuk keluaran hasil dari jumlah harga dari pemain yang harus dibayar dan pemenangnya 
	result(pemain1, pemain2);
	return 0;
}