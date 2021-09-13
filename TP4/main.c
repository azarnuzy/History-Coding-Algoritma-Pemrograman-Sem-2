#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP4 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{
	int n; 				//membuat variabel berupa banyaknya jumlah data
	scanf("%d", &n);	//membuat masukan untuk banyaknya jumlah data

	int i;				//membuat iterator	
	laporan masukan;	//membuat variabel bungkusan dari tipe data terstruktur

	for(i=0; i<n; i++){	//membuat perulangan untuk memasukan masukan
		scanf("%s", &masukan.nama[i]);							//membuat masukan untuk user berupa nama
		scanf("%d %f", &masukan.harga[i], &masukan.nilai[i]);	//membuat masukan untuk user berupa harga dan nilai yang diberikan
	}

	scanf("%s", &metode);	//membuat masukan untuk user berupa metode 
	scanf("%s", &urut);		//membuat masukan untuk user berupa urutan yang diinginkan apa dari kecil ke besar atau sebaliknya
	scanf("%s", &patokan);	//membuat masukan untuk user berupa patokan yang ingin dijadikan sebagai sesuatu yang ingin diurutkan

	ubahNilai(n,masukan);	//memanggil prosedur untuk mengubah nilai dari tipedata terstruktur laporan menjadi nilai integer 
							//*fungsi untuk nilai tersebut diubah adalah untuk dijadikan sebagai acuan dari hal yang ingin diurutkan 

	if(strcmp(metode, "insertion") == 0){			//membuat pengkondisian jika metode pengurutan yang diinginkan adalah insertion
		if(strcmp(patokan, "nama") == 0 ){			//membuat pengkondisian bersarang jika patokan yang diinginkan adalah nama
			insertion(n, tempNama, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara insertion
		}else if(strcmp(patokan, "harga") == 0){	//membuat pengkondisian bersarang jika patokan yang diinginkan adalah harga	
			insertion(n, tempHarga, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara insertion
		}else{										//membuat pengkondisian bersarang jika patokan yang diinginkan adalah penilaian
			insertion(n, tempNilai, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara insertion
		}
	}else{
		if(strcmp(patokan, "nama") == 0 ){			//membuat pengkondisian bersarang jika patokan yang diinginkan adalah nama
			selection(n, tempNama, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara selection
		}else if(strcmp(patokan, "harga") == 0){	//membuat pengkondisian bersarang jika patokan yang diinginkan adalah harga	
			selection(n, tempHarga, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara selection
		}else{										//membuat pengkondisian bersarang jika patokan yang diinginkan adalah penilaian
			selection(n, tempNilai, masukan);		//memanggil prosedur dari pengurutan dengan menggunakan cara selection
		}
	}

	return 0;
}