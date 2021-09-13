#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP4 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

void ubahNilai(int n, laporan masukan){					//membuat prosedur untuk mengubah nilai dari tipedata terstruktur menjadi integer
	int i;	//membuat iterator

	for(i=0; i<n; i++){									//membuat perulangan untuk mengubah nilai
		tempNama[i] = masukan.nama[i][0];				//menyimpan nama
		tempHarga[i] = masukan.harga[i];				//menyimpan harga
		tempNilai[i] = masukan.nilai[i] * 1000 + .5;	//menyimpan nilai *+.5 agar nilai dari float menjadi presisi
	}
}

void insertion(int n,int x[], laporan masukan){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
	int i,j;		//sebagai iterator
	int temp;		//seabagi tempat penampungan dari nilai yang akan di urutkan

	char tempNama1[100];
	int tempHarga1;
	float tempNilai1;

	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		temp = x[i];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
		strcpy(tempNama1, masukan.nama[i]);
		tempHarga1 = masukan.harga[i];
		tempNilai1 = masukan.nilai[i];	
		j=i-1;

		if(strcmp(urut, "asc") == 0){		//membuat pengkondisian untuk cara mengurutkan dari kecil ke besar
			
			while(temp < x[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih kecil dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				x[j+1] = x[j];				//nilai di depan akan menyimpan nilai sebelmnya 
				strcpy(masukan.nama[j+1], masukan.nama[j]);
				masukan.harga[j+1] = masukan.harga[j];
				masukan.nilai[j+1] = masukan.nilai[j];
				j--;						
			}	
		}else{								//membuat pengkondisian untuk cara mengurutkan dari besar ke kecil
	
			while(temp > x[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				x[j+1] = x[j];				//nilai di depan akan menyimpan nilai sebelmnya 
				strcpy(masukan.nama[j+1], masukan.nama[j]);
				masukan.harga[j+1] = masukan.harga[i];
				masukan.nilai[j+1] = masukan.nilai[i];
				j--;
			}
		}

		x[j+1] = temp;							//menyimpan nilai dari tampungan sementara
		strcpy(masukan.nama[j+1], tempNama1);
		masukan.harga[j+1] = tempHarga1;
		masukan.nilai[j+1] = tempNilai1;
	}

	tampil(n, masukan);
}

void selection(int n, int x[], laporan masukan){
	int i,j;
	int index1;
	int temp;				//seabagi tempat penampungan dari nilai yang akan di urutkan
	char tempNama1[100];
	int tempHarga1;
	float tempNilai1;

	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		index1 = i;

		for(j=i+1; j<n; j++){	
			if(x[index1] < x[j] && strcmp(urut, "asc")){ 			//sebagai pengkondisian untuk mencari nilai yang lebih kecil
				index1 = j;											//untuk menyimpan nilai dari index2 nilai yang lebih kecil
			}else if(x[index1] > x[j] && strcmp(urut, "desc")){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
				index1 = j;											//untuk menyimpan nilai dari index2 nilai yang lebih kecil
			}
		}
		
		temp = x[i];		//untuk menyimpan sementara dari nilai x[i]
		x[i] = x[index1];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		x[index1] = temp;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempNama1, masukan.nama[i]);
		strcpy(masukan.nama[i], masukan.nama[index1]);
		strcpy(masukan.nama[index1], tempNama1);

		tempHarga1 = masukan.harga[i];
		masukan.harga[i] = masukan.harga[index1];
		masukan.harga[index1] = tempHarga1;


		tempNilai1 = masukan.nilai[i];
		masukan.nilai[i] = masukan.nilai[index1];
		masukan.nilai[index1] = tempNilai1;

	}

	tampil(n, masukan);
}

void tampil(int n, laporan masukan){								//membuat prosedur untuk nilai tampilan dari nilai yang telah diurutkan
	int i;
	for(i=0; i<n; i++){												//sebagai perulangan untuk keluaran
		int harga1 = masukan.harga[i];								//membuat tempat penyimpanan sementara agar pada code tidak ditulis terlalu panjang
		float nilai1 = masukan.nilai[i];							//membuat tempat penyimpanan sementara agar pada code tidak ditulis terlalu panjang
		printf("%s %d %0.1f\n", masukan.nama[i], harga1, nilai1);	//membuat keluaran sesuai dengan yang telah diurutkan
	}
}