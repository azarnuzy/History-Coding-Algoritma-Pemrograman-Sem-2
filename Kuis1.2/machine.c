#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat fungsi rekursif untuk membuat perulangan dengan nilai n dibagi 2 dan m dikali 2
int kelipatan(long n, long m){
	if(n == 0){//sebagai base case dari perulangan jika n = 0 maka perulangan tersebut akan berhenti
		return 1;
	}else{
		printf("(%d|%d)\n",n,m );//mengeluarkan hasil sesuai dengan nilai dari paramater

		return kelipatan(n/2,m*2);//membuat fungsi tersebut kembali menjalankan fungsinya sampai kondisi yang telah ditentukan
	}
}
