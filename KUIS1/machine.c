#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


//membuat fungsi untuk menentukan jumlah yang dibayar oleh pemain
int membeli(makanan matriks[][100], int b1, int k1, int indexI[], int indexJ[], int n){
	int i;			//sebagai iterator

	int pemain = 0;	//sebagai nilai untuk dijadikan kembalian dari fungsi

	//membuat perulangan untuk menentukan berapa harga yang harus dibayar oleh pemain
	for(i=0; i<n; i++){
		if(indexI[i] == b1 && indexJ[i] == k1){	//sebagai syarat jika pemain tersebut memesan menu yang ada pada sel maka ada harga yang harus ditambahkan
			pemain = pemain + matriks[b1][k1].harga;
		}
	}

	return pemain;
}

//membuat prosedur untuk mengeluarkan pemenang dan jumlah harga yang harus dibayar oleh pemain
void result(int x, int y){

	printf("pemain pertama %d\n", x);
	printf("pemain kedua %d\n",y );

	if(x < y){			//sebagai pengkondisian jika pemain pertama lebih sedikit biaya yang dikeluarkan
		printf("pemenangnya pemain pertama\n");
	}else if(y < x){	//sebagai pengkondisian jika pemain kedua lebih sedikit biaya yang dikeluarkan
		printf("pemenangnya pemain kedua\n");
	}else{				//sebagai pengkondisian jika kedua pemain memiliki pembayaran yang sama
		printf("tidak ada pemenang\n");
	}

}