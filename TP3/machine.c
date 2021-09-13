#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP3 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int jumlah(int a, int b, int c, int x){//sebagai fungsi untuk menghitung jumlah bakteri

	int temp;//sebagai variabel untuk menyimpan nilai dari jumlah bakteri

	if(x == c-2){//sebagai kondisi ketika jam yang diinginkan
		temp = a*a + 2*b;//sebagai operasi dari jumlah bakteri 
		return temp;//mengembalikan jumlah bakteri sesuai dengan operasi di atas
	}else{
		temp = (a*a) + (2*b);//sebagai operasi dari jumlah bakteri
		return jumlah(b, temp, c, x+1);//mengembalikan nilai sebagai rekursif dari jumlah bakteri selanjutnya
	}
}