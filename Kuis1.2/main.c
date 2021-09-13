#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
	long n,m;	//membuat variabel untuk dua buah nilai integer

	scanf("%d %d", &n, &m);		//membuat masukan untuk dua buah nilai integer

	kelipatan(n,m);				//memanggil fungsi rekursif untuk mengeluarkan hasil dengan n > 0

	return 0;
}