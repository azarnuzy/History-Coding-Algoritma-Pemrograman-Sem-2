#include <stdio.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi Kuis 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//membuat matriks tipe data terstruktur 
typedef struct{
	char jenis[100];	//sebagai string dari jenis makanan
	int harga;			//sebagai integer dari harga makanan
}makanan;				//sebagai bungkusan dari tipe data terstruktur 


//membuat fungsi untuk menentukan jumlah yang dibayar oleh pemain
int membeli(makanan matriks[][100], int b, int k, int index1[], int index2[], int m){
	int i,j,l;

	int temp =0;

	for(i=0; i<b; i++){
		for(j=0; j<k; j++){
			for(l=0; l<m; l++){
				if(index1[l] == i && index2[l] == j){
					temp = temp + matriks[i][j].harga;
				}
			}
		}
	}

	return temp; 
}

//membuat prosedur untuk mengeluarkan pemenang dan jumlah harga yang harus dibayar oleh pemain
void result(int x, int y){

	printf("pemain pertama %d\n", x);
	printf("pemain kedua %d\n",y );

	if(x < y){			//sebagai pengkondisian jika pemain pertama lebih sedikit biaya yang dikeluarkan
		printf("pemenangnya adalah pemain pertama\n");
	}else if(y < x){	//sebagai pengkondisian jika pemain kedua lebih sedikit biaya yang dikeluarkan
		printf("pemenangnya adalah pemain kedua\n");
	}else{				//sebagai pengkondisian jika kedua pemain memiliki pembayaran yang sama
		printf("tidak ada pemenang\n");
	}

}

int main(int argc, char const *argv[])
{
	
	int b,k;		//b = baris || k = kolom
	int n;			//sebagai banyaknya isi tipe data terstruktur
	int i,j;		//sebagai iterator

	scanf("%d %d", &b, &k);		//membuat masukan untuk baris dan kolom
	scanf("%d", &n);			//membuat masukan untuk banyak masukan makanan dan harga

	int m;				//sebagai banyaknya pilihan dari setiap pemain
	makanan matriks[100][100];	//sebagai variabel untuk menampung masukan

	//memanggil prosedur nilaiAwal dari matriks

	int b1,k1;						//sebagai baris dan kolom untuk masukan dari jenis makanan dan harga
	int indexI[100], indexJ[100]; 	//sebagai penyimpan untuk index masukan dari jenis makanan dan harga

	for(i=0; i<b; i++){
		for(j=0; j<k; j++){
			matriks[i][j].harga = 0;
		}
	}

	//membuat perulangan untuk masukan urutan baris, kolom, jenis makanan, dan harga
	for(i=0; i<n; i++){
		scanf("%d %d", &b1, &k1);				//sebagai masukan dari urutan baris dan kolom
		/*indexI[i] = b1;
		indexJ[i] = k1;*/
		scanf("%s", &matriks[b1][k1].jenis);	//sebagai masukan dari jenis makanan sesuai dengan baris dan kolom
		scanf("%d", &matriks[b1][k1].harga);	//sebagai masukan dari harga makanan sesuai dengan baris dan kolom
	}

	//membuat masukan untuk menentukan  banyaknya urutan koordinat pemain pertama memilih makanan
	scanf("%d", &m);					//sebagai masukan untuk banyak pemain memilih makanan sesuai sel

	int pemain1 = 0,  pemain2 = 0;		//sebagai variabel untuk koordinat dari pemain

	int index1[m], index2[m];

	//membuat perulangan untuk memasukan sel dari pemain pertama
	for(i=0; i<m; i++){
		scanf("%d %d", &index1[i], &index2[i]);
		/*pemain1 = pemain1 + membeli(matriks, b1, k1, indexI, indexJ, n);//sebagai nilai dari harga yang harus dibayar oleh pemain pertama*/
	}

	pemain1 = membeli(matriks, b, k, index1, index2, m);

	//membuat perulangan untuk memasukan sel dari pemain kedua
	for(i=0; i<m; i++){
		scanf("%d %d", &index1[i], &index2[i]);
	/*	pemain2 = pemain2 + membeli(matriks, b1, k1, indexI, indexJ, n);//sebagai nilai dari harga yang harus dibayar oleh pemain kedua*/
	}

	pemain2 = membeli(matriks, b, k, index1, index2, m);
	//memanggil prosedur untuk keluaran hasil dari jumlah harga dari pemain yang harus dibayar dan pemenangnya 
	result(pemain1, pemain2);
	return 0;
}