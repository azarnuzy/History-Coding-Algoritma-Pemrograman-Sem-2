#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
	int r,c;//membuat variabel baris dan kolom
	int i,j;//membuat variabel untuk itertor

	scanf("%d %d", &r, &c);//membuat masukan dari baris dan kolom

	int matriks[100][100];//membuat variabel matriks

	//membuat perulangan untuk masukan dari nilai matriks
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks[i][j]);
		}
	}

	//memanggil prosedur dari matriks
	result(r,c,matriks);

	return 0;
}