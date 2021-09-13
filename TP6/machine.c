#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP6 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

void insertion(int a,float n[], char s[][100], char m2){			//membuat prosedur untuk mengurutkan nilai dengan cara insertion
	int i,j;		//sebagai iterator
	float tempN;		//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempS[100];

	for(i=1; i<a; i++){		//membuat perulangan untuk mengurutkan nilai 
		tempN = n[i];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
		strcpy(tempS, s[i]);
		j=i-1;

		if(m2 == 'a'){		//membuat pengkondisian untuk cara mengurutkan dari kecil ke besar
			
			while(tempN < n[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih kecil dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				n[j+1] = n[j];				//nilai di depan akan menyimpan nilai sebelmnya 
				strcpy(s[j+1], s[j]);
				j--;						
			}	
		}else{								//membuat pengkondisian untuk cara mengurutkan dari besar ke kecil
	
			while(tempN > n[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				n[j+1] = n[j];				//nilai di depan akan menyimpan nilai sebelmnya 
				strcpy(s[j+1], s[j]);
				j--;
			}
		}

		n[j+1] = tempN;							//menyimpan nilai dari tampungan sementara
		strcpy(s[j+1], tempS);
	}

}

void selection(int a,float n[], char s[][100], char m2){
	int i,j;
	int indeks;
	float tempN;				//seabagi tempat penampungan dari nilai yang akan di urutkan
	char tempS[100];

	for(i=0; i<a-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<a; j++){	
			if(n[indeks] < n[j] && m2 == 'd'){ 			//sebagai pengkondisian untuk mencari nilai yang lebih kecil
				indeks = j;											//untuk menyimpan nilai dari inden2 nilai yang lebih kecil
			}else if(n[indeks] > n[j] && m2 == 'a'){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
				indeks = j;											//untuk menyimpan nilai dari inden2 nilai yang lebih kecil
			}
		}
		
		tempN = n[i];		//untuk menyimpan sementara dari nilai n[i]
		n[i] = n[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		n[indeks] = tempN;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, s[i]);
		strcpy(s[i], s[indeks]);
		strcpy(s[indeks], tempS);
	}
}

void bubbleSOrt(int a, float n[], char s[][100], char m2){
	int i;

	int tukar;		//membuat nilai untuk dijadikan sebagai syarat untuk melakukan pertukaran
	float tempN;	//membuat nilai untuk penampung
	char tempS[100];	
	//membuat pengulangan untuk pengurutan dengan do while
	do{	
		tukar = 0;	//menjadikan nilai tukar menjadi nol sebagai syarat terjadinya perulangan 
		for(i=0; i<a-1; i++){	//melakukan perulangan untuk membandingkan kedua nilai dan menukarnya
			if(m2 == 'a' && n[i+1] <n[i]){	//sebagai syarat ascending

				tempN = n[i+1];	//menyimpan nilai
				n[i+1] =n[i];
				n[i] = tempN;

				strcpy(tempS, s[i+1]);
                strcpy(s[i+1], s[i]);
                strcpy(s[i], tempS);

				tukar = 1;	//menjadikan tukar menjadi satu agar keluar dari perulangan 

 			}else if(m2 == 'd' && n[i+1] >n[i]){	//sebagai syarat descending

 				tempN = n[i+1];	//menampung nilai untuk dilakukan penukarang nilai
				n[i+1] =n[i];
				n[i] = tempN;

				strcpy(tempS, s[i+1]);
                strcpy(s[i+1], s[i]);
                strcpy(s[i], tempS);

				tukar = 1;

 			}
		}
	}while(tukar == 1);
    
}

void quickSort(int a, float n[], char s[][100], char m2, int kiri, int kanan){
	int i,j;
	//membuat variabel tempN bernilai float untuk menampung masukan.waktu sementara
	//tempuntuk menampung nilai sementara
	//membuat nilai awal dari iterator i dan j sebagai pivot dengan i = kiri dan j = kanan
	float tempN;
	char tempS[100];
	i = kiri;
	j = kanan;

	//membuat perulangan jika nilai i <= j 
	//perulangan dilakukan secara quicksort bagian pinggir sebagai pivotnya
	do{
		//dilakukan syarat jika pengurutan yang dingiinkan secara ascending
		if(m2 == 'a'){
			//membuat perulanganketika nilai dari masukan.waktu yang berada pada sisi kiri lebih kecil
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((n[i] <n[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai darin yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((n[j] >n[kiri]) && (i <= j)){
				j--;
			}
		}
		//dilakukan syarat jika pengurutan yang dingiinkan secara descending
		else{
			//membuat perulanganketika nilai darin yang berada pada sisi kiri lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((n[i] >n[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai darin yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((n[j] <n[kiri]) && (i <= j)){
				j--;
			}
		}
		//jika nilai i < j, maka dilakukan pertukaran nilai dari sisi kiri dan sisi kanan
		if(i < j){
			//penukaran untuk nilai
			tempN =n[i];
			n[i] =n[j];
			n[j] = tempN;
			//penukaran untuk nilai 
			strcpy(tempS, s[i]);
            strcpy(s[i], s[j]);
            strcpy(s[j], tempS);
			//nilai i dan j akan berubah ke kanan dan ke kiri
			i++;
			j--;
		}

	}while(i <= j);//perulangan akan dilakukan jika nilai dari i <= j
	//jika nilai dari sisi kiri masih < j maka dilakukan rekursif
	if(kiri < j){
		//dengan nilai dari sisi kanan di ubah menjadi j
		quickSort(a,n,s,m2, kiri, j);
	}
	//jika nilai dari sisi kanan > i maka dilakukan rekursif
	if(i < kanan){
		//dengan nilai dari sisi kiri di ubah menjadi i
		quickSort(a,n,s,m2, i, kanan);
	}
}

void gabung(int a, float n1[], char s1[][100], int b, float n2[], char s2[][100], float hasilN[], char hasilS[][100], char m2){
	int i=0, j=0, k=0, l=0;
	//membuat perulangan untuk dilakukan penggabungan dengan arr1 dan arr2
	while(i < a && j < b){
		if(m2 == 'a'){ 					//sebagai syarat untuk terjadinya penggabungan seacara ascending
			if(n1[i] < n2[j]){			
				hasilN[k] = n1[i];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s1[i]);	
				i++;
				k++;
			}else if(n2[j] < n1[i]){
				hasilN[k] = n2[j];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}else{
				hasilN[k] = n1[i];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s1[i]);
				i++;
				k++;
				hasilN[k] = n2[j];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}
		}else{
			if(n1[i] > n2[j]){
				hasilN[k] = n1[i];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s1[i]);	
				i++;
				k++;
			}else if(n2[j] > n1[i]){
				hasilN[k] = n2[j];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}else{
				hasilN[k] = n1[i];			//menyimpan nilai hasil dari penggabungan
				strcpy(hasilS[k], s1[i]);
				i++;
				k++;
				hasilN[k] = n2[j];
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}
		}
	}
	//sebagai syarat jika masih terdapat nilai yang belum dimasukan
	if(i < a){
		for(l=i; l<a; l++){
			hasilN[k] = n1[l];			//menyimpan nilai hasil dari penggabungan
			strcpy(hasilS[k], s1[l]);
			k++;
		}
	}
	//sebagai syarat jika masih terdapat nilai yang belum dimasukan
	if(j < b){
		for(l = j; l < b; l++){
			hasilN[k] = n2[l];		//menyimpan nilai hasil dari penggabungan
			strcpy(hasilS[k], s2[l]);
			k++;
		}
	}
}

void tampil(int n, float hasilN2[], char hasilS2[][100]){
	int i;				//menampilkan keluaran dari hasil yang telah ditampilkan
	printf("Daftar Lagu Keluarga:\n");
	for(i=0; i<n; i++){
		printf("%0.2f %s\n",hasilN2[i], hasilS2[i]);
	}
	printf("\nLagunya Ibnu:\n");
}

void cariLagu(int n,int m, float n1[], char s1[][100], float hasilN2[], char hasilS2[][100]){
	int i=0,j=0;
	char temp[100];
	int cek;
	int count = 0;
	for(i=0; i<m; i++){			//membuat perulangan untuk mencari lagu ibnu yang akan diputar
		strcpy(temp, s1[i]);
		cek= 0;
		j=0;
		while(cek == 0 && j < n){				//sebagai syarat untuk menemukan lagu ibnu di gabungan lagu
			if(strcmp(temp, hasilS2[j]) == 0){		//sebagai syarat jika terdapat lagu ibnu di setengah gabungan lagu
				cek = 1;
				count++;
			}
			j++;
		}
		//menampilkan lagu ibnu jika ketemu
		if(cek == 1){
			printf("%s\n",hasilS2[j-1] );
		} 
	}
	//menampilkan lagu ibnu jika tidak ketemu
	if(count == 0){
		printf("Tidak memutar lagu Ibnu\n");
	}

}