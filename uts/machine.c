#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

void kalPerGram(int n, dessert a, float k[]){
    int i;
    for(i=0; i<n; i++){
        k[i] = (float)a.kalori[i] / a.berat[i];
    }

}

void insertion(int n, dessert a, float k[]){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
	int i,j;		//sebagai iterator
	float tempN;		//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempS[100];
    int tempA, tempB, tempC;

	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		tempN = k[i];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
        tempA = a.kalori[i];
        tempB = a.berat[i];
        tempC = a.harga[i];
		strcpy(tempS, a.makanan[i]);
		j=i-1;
	
		while(tempN > k[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
			k[j+1] = k[j];				//nilai di depan akan menyimpan nilai sebelmnya 
            a.kalori[j+1] = a.kalori[j];
            a.berat[j+1] = a.berat[j];
            a.harga[j+1] = a.harga[j];
			strcpy(a.makanan[j+1], a.makanan[j]);
			j--;
		}

		k[j+1] = tempN;							//menyimpan nilai dari tampungan sementara
        a.kalori[j+1] = tempA;
        a.berat[j+1] = tempB;
        a.harga[j+1] = tempC;
		strcpy(a.makanan[j+1], tempS);
	}

/* 	for(i=0; i<n; i++){
		printf("%s %d %d %d - %0.2f\n", a.makanan[i], a.kalori[i], a.berat[i], a.harga[i], k[i]);
	} */
}

void selection(int n,dessert a ,float k[]){
	int i,j;
	int indeks;
	float tempN;				//seabagi tempat penampungan dari nilai yang akan di urutkan
    int tempA, tempB, tempC;
	char tempS[100];

	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
			if(k[indeks] < k[j]){ 			//sebagai pengkondisian untuk mencari nilai yang lebih kecil
				indeks = j;											//untuk menyimpan nilai dari inden2 nilai yang lebih kecil
			}
		}
		
		tempN = k[i];		//untuk menyimpan sementara dari nilai k[i]
		k[i] = k[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		k[indeks] = tempN;	//menukar nilai dari nilai yang ditukar di atas

        tempA = a.kalori[i];		//untuk menyimpan sementara dari nilai a.kalori[i]
		a.kalori[i] = a.kalori[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		a.kalori[indeks] = tempA;	//menukar nilai dari nilai yang ditukar di atas

        tempB = a.berat[i];		//untuk menyimpan sementara dari nilai a.berat[i]
		a.berat[i] = a.berat[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		a.berat[indeks] = tempB;	//menukar nilai dari nilai yang ditukar di atas

        tempC = a.harga[i];		//untuk menyimpan sementara dari nilai a.harga[i]
		a.harga[i] = a.harga[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		a.harga[indeks] = tempC;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, a.makanan[i]);
		strcpy(a.makanan[i], a.makanan[indeks]);
		strcpy(a.makanan[indeks], tempS);
	}
}

void bubbleSOrt(int n, dessert a ,float k[]){
	int i;

	int tukar;
	float tempN;
	int tempA, tempB, tempC;
	char tempS[100];

	do{
		tukar = 0;
		for(i=0; i<n-1; i++){
			if(k[i+1] >k[i]){

 				tempN = k[i+1];
				k[i+1] =k[i];
				k[i] = tempN;

				tempA = a.kalori[i+1];
				a.kalori[i+1] =a.kalori[i];
				a.kalori[i] = tempA;

				tempB = a.berat[i+1];
				a.berat[i+1] =a.berat[i];
				a.berat[i] = tempB;

				tempC = a.harga[i+1];
				a.harga[i+1] =a.harga[i];
				a.harga[i] = tempC;

				strcpy(tempS, a.makanan[i+1]);
                strcpy(a.makanan[i+1], a.makanan[i]);
                strcpy(a.makanan[i], tempS);

				tukar = 1;

 			}
		}
	}while(tukar == 1);
	
}

void quickSort(int n, dessert a, int kiri, int kanan,float k[]){
	int i,j;
	//membuat variabel tempN bernilai double untuk menampung masukan.waktu sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
	//membuat nilai awal dari iterator i dan j sebagai pivot dengan i = kiri dan j = kanan
	float tempN;
	int tempA, tempB, tempC;
	char tempS[100];
	i = kiri;
	j = kanan;

	//membuat perulangan jika nilai i <= j 
	//perulangan dilakukan secara quicksort bagian pinggir sebagai pivotnya
	do{
		//dilakukan syarat jika pengurutan yang dingiinkan secara ascending
		//membuat perulanganketika nilai darin yang berada pada sisi kiri lebih besar
		//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
		while((k[i] >k[kanan]) && (i <= j)){
			i++;
		}
		//membuat perulanganketika nilai darin yang berada pada sisi kanan lebih besar
		//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
		while((k[j] <k[kiri]) && (i <= j)){
			j--;
		}
		//jika nilai i < j, maka dilakukan pertukaran nilai dari sisi kiri dan sisi kanan
		if(i < j){
			//penukaran untuk nilain
			tempN =k[i];
			k[i] =k[j];
			k[j] = tempN;
			//penukaran untuk nilai pembilang
			tempA =a.kalori[i];
			a.kalori[i] =a.kalori[j];
			a.kalori[j] = tempA;

			tempB = a.berat[i];
			a.berat[i] =a.berat[j];
			a.berat[j] = tempB;

			tempC =a.harga[i];
			a.harga[i] =a.harga[j];
			a.harga[j] = tempC;

			strcpy(tempS, a.makanan[i]);
            strcpy(a.makanan[i], a.makanan[j]);
            strcpy(a.makanan[j], tempS);
			//nilai i dan j akan berubah ke kanan dan ke kiri
			i++;
			j--;
		}

	}while(i <= j);//perulangan akan dilakukan jika nilai dari i <= j
	//jika nilai dari sisi kiri masih < j maka dilakukan rekursif
	if(kiri < j){
		//dengan nilai dari sisi kanan di ubah menjadi j
		quickSort(n,a,kiri,j,k);
	}
	//jika nilai dari sisi kanan > i maka dilakukan rekursif
	if(i < kanan){
		//dengan nilai dari sisi kiri di ubah menjadi i
		quickSort(n,a,i,kanan,k);
	}
}

void tampung(int n, dessert a){
    int i;
    for(i=0; i<n; i++){
        hasilKal[i] = a.kalori[i];
		hasilBer[i] = a.berat[i];
		hasilHar[i] = a.harga[i];
		strcpy(hasilNeg[i], a.negara);
		strcpy(hasilMak[i], a.makanan[i]);
    }
}

void gabung(int n,float k1[], int m, float k2[], dessert a, dessert b, dessert hasil, float k3[]){
	int i=0, j=0, count=0, l=0;
    
	while(i < n && j < m){
		if(k1[i] > k2[j]){
			k3[count] = k1[i];
			hasil.kalori[count] = hasilKal[i];
			hasil.berat[count] = hasilBer[i];
			hasil.harga[count] = hasilHar[i];
			strcpy(hasil.hasilN1[count], hasilNeg[i]);
			strcpy(hasil.makanan[count], a.makanan[i]);
			i++;
			count++;
		}
		
		else if(k2[j] > k1[i]){
			k3[count] = k2[j];
			hasil.kalori[count] = b.kalori[j];
			hasil.berat[count] = b.berat[j];
			hasil.harga[count] = b.harga[j];
			strcpy(hasil.hasilN1[count], b.negara);
			strcpy(hasil.makanan[count], b.makanan[j]);
			j++;
			count++;
		}
		
		else{
			k3[count] = k1[i];
			hasil.kalori[count] = hasilKal[i];
			hasil.berat[count] = hasilBer[i];
			hasil.harga[count] = hasilHar[i];
			strcpy(hasil.hasilN1[count], hasilNeg[i]);
			strcpy(hasil.makanan[count], a.makanan[i]);
			i++;
			count++;

			k3[count] = k2[j];
			hasil.kalori[count] = b.kalori[j];
			hasil.berat[count] = b.berat[j];
			hasil.harga[count] = b.harga[j];
			strcpy(hasil.hasilN1[count], b.negara);
			strcpy(hasil.makanan[count], b.makanan[j]);
			j++;
			count++;
		}
	}

	if(i < n){
		for(l=i; l<n; l++){
			k3[count] = k1[l];
			hasil.kalori[count] = hasilKal[l];
			hasil.berat[count] = hasilBer[l];
			hasil.harga[count] = hasilHar[l];
			strcpy(hasil.hasilN1[count], hasilNeg[l]);
			strcpy(hasil.makanan[count], hasilMak[l]);
			count++;
		}
	}

	if(j < m){
		for(l = j; l <m; l++){
			k3[count] = k2[l];
			hasil.kalori[count] = b.kalori[l];
			hasil.berat[count] = b.berat[l];
			hasil.harga[count] = b.harga[l];
			strcpy(hasil.hasilN1[count], b.negara);
			strcpy(hasil.makanan[count], b.makanan[l]);
			count++;
		}
	}
    
    tampung(n+m,hasil);
} 

void tampil(int n, float hasilK2[]){
    int i;
    int temp1, temp2;
    for(i=0; i<n; i++){
        temp1 = hasilK2[i];
        temp2 = (hasilK2[i] - temp1) * 100;
        printf("- %s %s %d %d %d - ", hasilNeg[i], hasilMak[i], hasilKal[i], hasilBer[i], hasilHar[i]);
        if(temp2 != 0){
            printf("%0.2f\n", hasilK2[i]);
        }else{
            printf("%d\n", temp1 );
        }
    }
}

void tampilNegara(int n, dessert a, float k[]){
    int i;
    int temp1, temp2;
    
    for(i=0; i<n; i++){
        temp1 = k[i];
        temp2 = (k[i] - temp1) * 100;
        printf("- %s %d %d %d - ", a.makanan[i], a.kalori[i], a.berat[i], a.harga[i]);
        if(temp2 != 0){
            printf("%0.2f\n", k[i]);
        }else{
            printf("%d\n", temp1);
        }
    }
}
