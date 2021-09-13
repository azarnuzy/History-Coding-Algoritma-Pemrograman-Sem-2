#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP7 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//prosedur pencarian secara binary search
void binarySearch(int i, int j, data masukan, data urut, int indeks){
    //k sebagai iterator 
    //ketemu sebagai boolean untuk pengecekan kondisi
    int k;
    int ketemu = 0;
    //pengulangan untuk melakukan pencarian
    while(ketemu == 0 && i<= j){
        //pencarian dilakukan dengan membagi dua nilai
        k = (int) (i+j) / 2;
        //kondisi jika nilai yang dicari telah sama
        if(strcmp(masukan.nama[k], urut.nama[indeks]) == 0){
            //keluaran untuk nama yang dicari
            printf("Yang Diminta : %s\n", masukan.nama[k]);
            ketemu = 1;
        }
        //kondisi jika nilai yang dicari berbeda
        else{
            //kondisi jika data yang dicari lebih besar maka bergeser ke kiri
            if(masukan.nama[k] > urut.nama[indeks]){
                j = k - 1;
            }
            //kondisi jika data yang dicari lebih kecil maka bergeser ke kanan
            else{
                i = k + 1;
            }
        }
    }
} 
//prosedur pencarian secara sequential search
void sequentialSearch(int n,data masukan, data urut, int indeks){
    int i=0;
    //sebagai kondisi untuk menemukan yang ingin dicari
    int ketemu = 0;
    //perulangan untuk menemukan nilai yang dicari
    while(i < n && ketemu == 0){
        //kondisi jika nilai yang dicari telah ketem
        if(strcmp(masukan.nama[i], urut.nama[indeks]) == 0){
            //keluaran untuk nilai yang dicari
            //mengganti kondisi ketemu sehingga perulangan berhenti
            printf("Yang Diminta : %s\n", masukan.nama[i]);
            ketemu = 1;
        }
        //kondisi jika nilai yang dicari belum ketemu dan terus bergeser nilainya
        else {
            i++;
        }
    }
}
data selection(int n,data masukan){
	int i,j;
	int indeks;
	float tempN;				//seabagi tempat penampungan dari nilai yang akan di urutkan
	char tempS[100];

    data urut;

    for(i=0; i<n; i++){
        urut.rata2[i] = masukan.rata2[i];
        strcpy(urut.nama[i], masukan.nama[i]);
    }

	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
            if(urut.rata2[indeks] > urut.rata2[j]){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
                indeks = j;						            //untuk menyimpan nilai dari inden2 nilai yang lebih kecil
            }
		}
		
		tempN = urut.rata2[i];		//untuk menyimpan sementara dari nilai urut.rata2[i]
		urut.rata2[i] = urut.rata2[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		urut.rata2[indeks] = tempN;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, urut.nama[i]);
		strcpy(urut.nama[i], urut.nama[indeks]);
		strcpy(urut.nama[indeks], tempS);
	}

    return urut;
    
}
