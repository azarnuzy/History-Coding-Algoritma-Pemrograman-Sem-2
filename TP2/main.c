#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/


int main(int argc, char const *argv[])
{
    int r, c, i, j, k;

    scanf("%d %d", &r, &c);//memasukan nilai dari baris dan kolom 

    //membuat perulangan untuk memasukan nama mahasiswa serta nilai 
    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            scanf("%s", matriks[i][j].nama);
            for( k = 0; k < 3; k++){
                scanf("%d", &matriks[i][j].nilai[k]);
            }
            //melakukan operasi untuk dapat menentukan nilai rata2 dari mahasiswa 
            matriks[i][j].rata2 = (float)(matriks[i][j].nilai[0] + matriks[i][j].nilai[1] + matriks[i][j].nilai[2]) / 3; 
        }
    }

	i=0;
	j=0;

	char namaKursi[100][100];//membuat variabel untuk masukan mahasiswa yang akan dilakukan pertukaran 

	int count = 0;
	//membuat perulangan masukan dan berhenti ketika ada kata stop
	while(strcmp(namaKursi[i-1],"stop") != 0){
		scanf("%s", &namaKursi[i]);
		i++;
	}
	//sebagai variabel penghitung banyak orang yang ingin melakukan pertukaran tempat duduk
	count = i;

	spasi1(r,c);//memanggil prosedur  dari spasi
	printf("Posisi Bangku Awal:\n");
	stPos(r,c);//memanggil prosedur untuk menampilkan posisi awal tempat duduk
	searchName(r,c,namaKursi, count);//memanggil prosedur untuk mencari mahasiswa yang akan melakukan pertukaran
	spasi1(r,c);//memanggil prosedur  dari spasi
	printf("\nPosisi Bangku Setelah Nilai Dicek:\n");
	stPos(r,c);//memanggil prosedur untuk menampilakn posisi akhir setelah dilakukan pertukaran tempat duduk

	return 0;
}