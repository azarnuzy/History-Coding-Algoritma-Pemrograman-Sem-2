#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP5 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat prosedur untuk menampung nilai dari pembilang dan penyebut dan dijadikan pecahan
//untuk nilai yang akan dijadikan sebagai patokan pengurutan
void tampunganPecahan(int n, int pembilang[], int penyebut[]){
	int i;
	//membuat perulangan untuk menampung nilai
	//pecahan[] disini dijadikan sebagai bilangan double agar nilai besar dan kecil 
	//yang ingin diurutkan lebih presisis
	for(i=0; i<n; i++){
		pecahan[i] = (double)pembilang[i] / penyebut[i];
	}
}

void bubbleSOrt(int n, int pembilang[], int penyebut[], char z){
	int i;
	///membuat variabel tukar untuk syarat terjadinya perulangan do while
	//membuat variabel temp1 bernilai double untuk menampung pecahan sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
	int tukar;
	double temp1;
	int temp2,temp3;

	//melakukan perulangan jika nilai tukar bernilai 1/benar maka terus terjadi
	//di dalam perulangan do while terdapat sorting dengan cara bubble sort
	//bubble sort = menukarkan dua buah bilangan secara terus menerus sampai pengurutan selesai
	do{
		tukar = 0;
		for(i=0; i<n-1; i++){
			//sebagai syarat untuk perulangan secara ascending
			if(z == 'a' && pecahan[i+1] < pecahan[i]){
				//operasi untuk menukarkan nilai pecahan yang saling berdampingan 2 nilai
				temp1 = pecahan[i+1];
				pecahan[i+1] = pecahan[i];
				pecahan[i] = temp1;
				//operasi untuk menukarkan nilai pembilang yang saling berdampingan 2 nilai
				temp2 = pembilang[i+1];
				pembilang[i+1] = pembilang[i];
				pembilang[i] = temp2;
				//operasi untuk menukarkan nilai penyebut yang saling berdampingan 2 nilai
				temp3 = penyebut[i+1];
				penyebut[i+1] = penyebut[i];
				penyebut[i] = temp3;
				//membuat nilai tukar menjadi 1
				tukar = 1;

 			}
 			//sebagai syarat untuk perulangan secara descending
 			else if(z == 'd' && pecahan[i+1] > pecahan[i]){
 				//operasi untuk menukarkan nilai pecahan yang saling berdampingan 2 nilai
 				temp1 = pecahan[i+1];
				pecahan[i+1] = pecahan[i];
				pecahan[i] = temp1;
				//operasi untuk menukarkan nilai pembilang yang saling berdampingan 2 nilai
				temp2 = pembilang[i+1];
				pembilang[i+1] = pembilang[i];
				pembilang[i] = temp2;
				//operasi untuk menukarkan nilai penyebut yang saling berdampingan 2 nilai
				temp3 = penyebut[i+1];
				penyebut[i+1] = penyebut[i];
				penyebut[i] = temp3;
				//membuat nilai tukar menjadi 1
				tukar = 1;

 			}
		}
	}while(tukar == 1);
}

void quickSort(int n, int pembilang[], int penyebut[], char z, int kiri, int kanan){
	int i,j;
	//membuat variabel temp1 bernilai double untuk menampung pecahan sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
	//membuat nilai awal dari iterator i dan j sebagai pivot dengan i = kiri dan j = kanan
	double temp1;
	int temp2, temp3;
	i = kiri;
	j = kanan;

	//membuat perulangan jika nilai i <= j 
	//perulangan dilakukan secara quicksort bagian pinggir sebagai pivotnya
	do{
		//dilakukan syarat jika pengurutan yang dingiinkan secara ascending
		if(z == 'a'){
			//membuat perulanganketika nilai dari pecahan yang berada pada sisi kiri lebih kecil
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((pecahan[i] < pecahan[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai dari pecahan yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((pecahan[j] > pecahan[kiri]) && (i <= j)){
				j--;
			}
		}
		//dilakukan syarat jika pengurutan yang dingiinkan secara descending
		else{
			//membuat perulanganketika nilai dari pecahan yang berada pada sisi kiri lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((pecahan[i] > pecahan[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai dari pecahan yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((pecahan[j] < pecahan[kiri]) && (i <= j)){
				j--;
			}
		}
		//jika nilai i < j, maka dilakukan pertukaran nilai dari sisi kiri dan sisi kanan
		if(i < j){
			//penukaran untuk nilai pecahan
			temp1 = pecahan[i];
			pecahan[i] = pecahan[j];
			pecahan[j] = temp1;
			//penukaran untuk nilai pembilang
			temp2 = pembilang[i];
			pembilang[i] = pembilang[j];
			pembilang[j] = temp2;
			//penukaran untuk nilai penyebut
			temp3 = penyebut[i];
			penyebut[i] = penyebut[j];
			penyebut[j] = temp3;
			//nilai i dan j akan berubah ke kanan dan ke kiri
			i++;
			j--;
		}

	}while(i <= j);//perulangan akan dilakukan jika nilai dari i <= j
	//jika nilai dari sisi kiri masih < j maka dilakukan rekursif
	if(kiri < j){
		//dengan nilai dari sisi kanan di ubah menjadi j
		quickSort(n, pembilang, penyebut, z, kiri, j);
	}
	//jika nilai dari sisi kanan > i maka dilakukan rekursif
	if(i < kanan){
		//dengan nilai dari sisi kiri di ubah menjadi i
		quickSort(n, pembilang, penyebut, z, i, kanan);
	}
}

void tampil(int n, int pembilang[], int penyebut[]){
	int i;
	//menampilkan nilai dari pembilang
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%d   ", pembilang[i]);
		}else{
			printf("%d\n",pembilang[i] );
		}
	}
	//menampilkan tanda per(-) dan , 
	for(i=0; i<n; i++){
		if(i<n-1){
			printf("- , ");
		}else{
			printf("-\n");
		}
	}
	//menampilkan nilai dari penyebut
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%d   ",penyebut[i] );
		}else{
			printf("%d\n",penyebut[i] );
		}
	}
}