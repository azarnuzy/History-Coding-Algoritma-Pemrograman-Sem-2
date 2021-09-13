#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

void spasi1(int r, int c){//fungsi dari banyaknya spasi untuk keluaran

	int i,j;
	//membuat perulangan untuk mencari nama terpanjang
	for(i=0; i<c; i++){
		max[i] = strlen(matriks[0][i].nama);
		for(j=0; j<r; j++){
			if(max[i] < strlen(matriks[j][i].nama)){
				max[i] = strlen(matriks[j][i].nama);
			}
		}
	}
}

void stPos(int r, int c ){//prosedur menampilkan posisi bangku awal
	int i,j,k;

	//membuat perulangan untuk menampilkan posisi awal bangku
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(j < c-1){
				printf("%s",matriks[i][j].nama);
				for(k=0; k<(max[j]+2)-strlen(matriks[i][j].nama); k++){//sebagai perulangan untuk menentukan nilai spasi 
					printf(" ");
				}
			}else{
				printf("%s\n",matriks[i][j].nama);
			}
		}
	}
}

int cekRata(float x, float y){//fungsi untuk mengecek nilai rata2 bangku mahasiswa yang akan di tukar
	//nilai x sebagai nilai dari mahasiswa yang berada di sebelah kanan
	//nilai y sebagai nilai dari mahasiswa yang berada di sebelah kiri
	if(x > y){
		return 1;
	}else{
		return 0;
	}
}

void swap(char x[], char y[], float *a, float *b){//sebagai prosedur untuk mengganti posisi jika syarat dari pertukaran telah terpenuhi

	char temp[100];//temp sebagai penampung sementara dari string nama orang sebelah kanan
	strcpy(temp,y);//membuat nilai temp menjadi nama orang sebelah kanan
	strcpy(y, x);//menukar string orang sebelah kiri menjadi sebelah kanan
	strcpy(x, temp);//menukar string orang sebelah kanan menjadi sebelah kiri
	float temp1 = *b;//membuat temp1 sebagi penampung sementara dari nilai rata2 mahasiswa sebelah kanan
	*b = *a;//menukar nilai rata2 sebalah kanan menjadi nilai mahasiswa sebelah kiri
	*a = temp1;//menukar nilai rata2 mahasiswa sebelah kiri menjadi nilai mahasiswa sebelah kanan
}

void searchName(int r, int c, char namaKursi[][100], int count){//sebagai prosedur untuk menacri nama orang yang akan di lakukan pertukaran tempat duduk
	int i,j,k;

	j=0;
	k=0;
	int index1[100],index2[100];//sebagi nilai dari index mahasiswa yang akan dilakukan pertukaran
	int cek=0;
	//membuat perulangan untuk mencari mahasiswa yang akan ditukarkan tempat duduk
	for(i=0; i< count ; i++){//count disini sebagai pembatas dari mahasiswa yang melakukan pertukaran
		cek = 0;
		j=0;
		//membuat perulangan untuk mencari mahasiswa yang akan melakukan pertukaran tempat duduk 
		while(j < r && cek != 1){//jika sudah ditemuakan mahasiswa yang akan melakukan pertukaran maka perulangan akan berhenti 
			k=0;
			while(k < c && cek != 1){
				if(strcmp(matriks[j][k].nama, namaKursi[i]) == 0){//sebagai syarat jika nama mahasiswa yang melakukan perulangan ditemukan 
					cek = 1;//sebagai pembatas jika mahasiswa sudah ditemukan
					index1[i] = j;//memasukan nilai index dari mahasiswa yang ditemukan
					index2[i] = k;//memasukan nilai index dari mahasiswa yang ditemukan
				}
				k++;
			}
			j++;
		}

		if(i % 2 == 1){//sebagai syarat untuk dapat membandingkan antar kedua mahasiswa apakah bisa untuk melakukan pertukaran
			if(cekRata(matriks[index1[i-1]][index2[i-1]].rata2, matriks[index1[i]][index2[i]].rata2) == 1){//melakukan pengecekan dengan fungsi cekRata
				swap(matriks[index1[i-1]][index2[i-1]].nama, matriks[index1[i]][index2[i]].nama, &matriks[index1[i-1]][index2[i-1]].rata2, &matriks[index1[i]][index2[i]].rata2);//melakukan pertukaran melalui prosedur swap
			}
		}
	}
}
