#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


//membuat fungsi untuk menghitung jumlah nilai dari kolom terakhir
int jumlahCol(int c, int matriks[][100]){
	int i;
	int total=0;

	for(i=0; i<c; i++){
		total = total + matriks[0][i];
	}
	return total;
}

//membuat prosedur untuk menampilkan matriks sesuai dengan syarat yang telah ditentukan
void result(int r, int c, int matriks[][100]){
	int i,j;

	int arah = jumlahCol(c, matriks) % 2;//sebagai nilai untuk menunjukan arah rotasi dari matriks
	int rotasi = jumlahCol(c, matriks) % 4;//sebagai nilai untuk menunjukan jumlah rotasi dari matriks

	/* PERMISALAN
	1. Bentuk Awal Matriks 2. Setelah di Refleksi 3. Setelah di Transpos
	1 2 3 4					  5 6 7 8				 5 1
	5 6 7 8					  1 2 3 4				 6 2
													 7 3
													 8 4

	ROTASI ARAH KIRI 
	Rotasi ke-0		Rotasi ke-1		Rotasi ke-2		Rotasi ke-3
	5 1				1 2 3 4			4 8				8 7 6 5
	6 2				5 6 7 8			3 7				4 3 2 1
	7 3								2 6
	8 4								1 5
	
	ROTASI ARAH KANAN 
	Rotasi ke-0		Rotasi ke-1		Rotasi ke-2		Rotasi ke-3
	5 1				8 7 6 5			4 8				1 2 3 4
	6 2				4 3 2 1			3 7				5 6 7 8
	7 3								2 6
	8 4								1 5
	*/
	if((arah == 1 && rotasi == 3) || (arah == 2 && rotasi == 1)){//bentuk yang sama akan terjadi untuk perputaran rotasi ke-1 menuju arah kiri dan ke-3 menuju arah kanan 
		for(i=0; i<r; i++){//membuat perulangan dengan keluaran sesuai dengan bentuk yang telah ada
			for(j=0; j<c; j++){
				if(j < c-1){
					printf("%d ",matriks[i][j]);
				}else{
					printf("%d\n",matriks[i][j]);
				}
			}
		}
		//mengeluarkan keluaran untuk syarat yang ini bentuknya akan sama seperti awal
		printf("Coba lagi besok!\n");
	}else if((arah == 1 && rotasi == 1) || (arah == 2 && rotasi == 3)){// bentuk yang sama akan terjadi untuk perputaran rotasi ke-1 menuju arah kanan dan ke-3 menuju arah kiri
		for(i=r-1; i>=0; i--){//membuat perulangan dengan keluaran sesuai dengan bentuk yang telah ada
			for(j=c-1; j>=0; j--){
				if(j > 0){
					printf("%d ",matriks[i][j]);
				}else{
					printf("%d\n",matriks[i][j]);
				}
			}
		}
		//mengeluarkan keluaran jika matriks tidak sama dengan awal
		printf("Wihh matrix yang seru!\n");
	}else if((rotasi == 0)){//bentuk dari rotasi ke-0 atau tetap pada posisi awal setelah tranpos dan refleksi serta arah perputaran tidak berpengaruh
		for(i=0; i<c; i++){//membuat perulangan dengan keluaran sesuai dengan bentuk yang telah ada 
			for(j=r-1; j>=0; j--){
				if(j > 0){
					printf("%d ",matriks[j][i]);
				}else{
					printf("%d\n",matriks[j][i]);
				}
			}
		}
		//mengeluarkan keluaran jika matriks tidak sama dengan awal
		printf("Wihh matrix yang seru!\n");
	}else{//bentuk dari rotasi ke-2 arah perputaran tidak berpengaruh
		for(i=c-1; i>=0; i--){//membuat perulangan dengan keluaran sesuai dengan bentuk yang telah ada 
			for(j=0; j<r; j++){
				if(j < r-1){
					printf("%d ",matriks[j][i]);
				}else{
					printf("%d\n",matriks[j][i]);
				}
			}
		}
		//mengeluarkan keluaran jika matriks tidak sama dengan awal
		printf("Wihh matrix yang seru!\n");
	}

}
