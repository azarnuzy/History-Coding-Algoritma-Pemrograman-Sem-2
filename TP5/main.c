#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP5 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
	//variabel n sebagai nilai dari banyaknya pecahan yang dibuat
	int n;
	scanf("%d", &n);
	int i;
	int pembilang[n], penyebut[n];
	//membuat pengulangan untuk membuat masukan
	for(i=0; i<n; i++){
		scanf("%d %d", &pembilang[i], &penyebut[i]);
	}
	//variabel m sebagai metode yang dipilih  untuk mengurutkan nilai
	//jika q = quickSort
	//jika b = bubbleSort
	//variabel z sebagai nilai yang diurutkan secara ascending atau descending
	char m,z;
	scanf(" %c %c", &m, &z);
	//memanggil prosedur untuk menampung nilai dari pecahan dari pembilang dan penyebut
	tampunganPecahan(n, pembilang, penyebut);
	//membuat syarat jika pengurutan secara quick sort
	if(m == 'q'){
		quickSort(n, pembilang, penyebut, z, 0, n-1);
	}
	//membuat syarat jika pengurutan secara bubble sort
	else{
		bubbleSOrt(n, pembilang, penyebut, z);
	}	
	//menampilkan nilai dari pembilang dan penyebut
	tampil(n, pembilang, penyebut);
	return 0;
}