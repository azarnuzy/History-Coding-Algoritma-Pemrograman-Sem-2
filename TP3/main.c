#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP3 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
	int n;//sebagai banyaknya bakteri yang ingin di cek

	scanf("%d", &n);//memberi masukan dari banyaknya bakteri

	int a[n],b[n],c[n];//membuat array of integer sebagai nilai dari a = jam ke-0, b= jam ke-1, dan c = jumlah jam

	int i;//sebagai variabel untuk perulangan

	for(i=0; i<n; i++){//membuat perulangan untuk masukan jam
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}

	int temp = 0;//sebagai nilai sementara dari fungsi jumlah

	for(i=0 ; i< n; i++){//sebagai perulangan untuk mendapatkan jumlah bakteri 
		temp = jumlah(a[i], b[i], c[i], 0);//sebagai nilai sementara dari jumlah bakteri
		printf("%d\n",temp );//mengeluarkan nilai dari jumlah bakteri
	}
	return 0;
}