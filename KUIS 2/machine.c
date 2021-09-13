#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi KUIS2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

kurma tempHargaGram(int n, kurma a){
    int i;      //iterator
    kurma b;    //variabel untuk menyimpan dari nilai bungkusan a
    for(i=0; i<n; i++){
        b.hargaGram[i] = a.harga[i] / a.berat[i];   //nilai harga per gram
    }

    return b;   //mengembalikan bungkusan b
}

kurma selection(int n,kurma b, kurma a){
	int i,j;                    //iterator
	int indeks;                 //sebagai indeks dari nilai yang akan ditukar
	int tempHargaGram;			//seabagi tempat penampungan dari nilai yang akan di uruutkan
	char tempNama[100];         //penyimpanan sementara dari nama 
    char tempStatus[100];       //penyimpanan sementara dari status
    int tempBerat;              //penyimpanana sementara dari berat
    int tempHarga;              //penyimpanan sementara dari harga

    kurma c;   //variabel untuk menyimpan bungkusan a dan b sesuai dengan kebutuhan
    
    //perulangan untuk menyalin nilai dari bungkusan a dan b ke bungkusan c
    for(i=0; i<n; i++){
        c.hargaGram[i] = b.hargaGram[i];    
        c.berat[i] = a.berat[i];
        c.harga[i] = a.harga[i];
        strcpy(c.nama[i], a.nama[i]);
        strcpy(c.status[i], a.status[i]);
    }


	for(i=0; i<n-1; i++){	//membuat perulangan untuk menguruutkan nilai dengan cara selection
		indeks = i;         //menyimpan nilai awal indeks

		for(j=i+1; j<n; j++){	
            if(c.hargaGram[indeks] < c.hargaGram[j]){	//sebagai pengkondisian untuk mencari nilai yang lebih kecil
                indeks = j;						            //untuk menyimpan nilai dari indeks2 nilai yang lebih besar
            }
		}

        //untuk menukar nilai dari harga per gram
		tempHargaGram = c.hargaGram[i];		    
		c.hargaGram[i] = c.hargaGram[indeks];	
		c.hargaGram[indeks] = tempHargaGram;	
        //untuk menukar nilai dari berat 
        tempBerat = c.berat[i];                 
        c.berat[i] = c.berat[indeks];           
        c.berat[indeks] = tempBerat;
        //untuk menukar nilai dari harga
        tempHarga = c.harga[i];
        c.harga[i] = c.harga[indeks];
        c.harga[indeks] = tempHarga;
        //untuk menukar nilai dari status
        strcpy(tempStatus, c.status[i]);
        strcpy(c.status[i], c.status[indeks]);
        strcpy(c.status[indeks], tempStatus);
        //untuk menukar nilai dari nama
		strcpy(tempNama, c.nama[i]);
		strcpy(c.nama[i], c.nama[indeks]);
		strcpy(c.nama[indeks], tempNama);
	}

    return c;       //mengembalikan bungkusan c
    
}

int binarySearch(int i, int j, int bilCari, kurma c){
    int k;          //iterator
    int ketemu = 0; //sebagai nilai untuk dijadikan pengkondisian

    while(ketemu == 0 && i<= j){    //nilai akan berhenti jika bilangan yang dicari sudah ketemu dan nilai i <= j
        k = (int) (i+j) / 2;            //indeks untuk dijadikan sebagai nilai yang akan dicari

        if(c.hargaGram[k] == bilCari){      //kondisi jika harga per gram dan bil yang dicari sama
            ketemu = 1;                     //membuat ketemu bernilai 1
            c.ketemu = k;                   //membuat c.ketemu bernilai indeks k
        }else{
            if(c.hargaGram[k] < bilCari){   //kondisi jika harga per gram [k] kurang dari nilai yang dicari
                j = k - 1;                  //nilai dari j akan geser ke kiri
            }else{          
                i = k + 1;                  //nilai dari i akan geser ke kanan
            }
        }
    }

    if(ketemu != 1){       //kondisi jika nilai tidak dapat ditemukan 
        c.ketemu = -1;
    }

    return c.ketemu;       //mengembalikan niali dari indeks nilai yang ketemu   
}

void tampil(int n, kurma c){
    int status1;       //sebagai nilai untuk menentukan status 1 = premium, dan 0 = standar

    if(c.ketemu == -1){        //kondisi untuk tampilan jika tidak ditemukan nilai yang dicari
        printf("tidak ditemukan\n");
    }else{                     //kondisi untuk tampilan jika ditemukan nilai yang dicari

        if(strcmp(c.status[c.ketemu], "standar") == 0){     //kondisi untuk menentukan nilai dari status
            status1 = 0;
        }else{
            status1 = 1;
        }
        //menampilkan nilai sesuai dengan soal
        printf("nama kurma: %s\n", c.nama[c.ketemu]);
        printf("berat: %d gram\n", c.berat[c.ketemu]);
        printf("harga: %d\n", c.harga[c.ketemu]);
        printf("harga per berat: %d\n", c.hargaGram[c.ketemu]);
        printf("status premium: ");
        if(status1 == 0){
            printf("tidak\n");
        }else{
            printf("ya\n");
        }
    }
}