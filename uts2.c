#include <stdio.h>
#include <string.h>

typedef struct{
    char makanan[100][100];
    char negara[100];
    int kalori[100];
    int berat[100];
    int harga[100];
    float k[100];
	char n[100][100];
}dessert;


void kalPerGram(int n, dessert a, float k[]);
dessert insertion(int n,dessert a, float k[]);
dessert selection(int n,dessert a , float k[]);
dessert bubbleSOrt(int n, dessert a , float k[]);
dessert quickSort(int n, dessert a, int kiri, int kanan, float k[]);
dessert gabungTerurut(int n, dessert a,float k1[], int m, dessert b, float k2[], float hasilK[]);


int main(int argc, char const *argv[])
{
    int i;
    dessert a,b,c;
    int n1,n2,n3;
    char m[100];
    scanf("%s", m);

    scanf("%s", &a.negara);
    scanf("%d", &n1);
    for(i=0; i<n1; i++){
        scanf("%s", &a.makanan[i]);
        scanf("%d %d %d", &a.kalori[i], &a.berat[i], &a.harga[i]);
    }

    scanf("%s", &b.negara);
    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%s", &b.makanan[i]);
        scanf("%d %d %d", &b.kalori[i], &b.berat[i], &b.harga[i]);
    }

    scanf("%s", &c.negara);
    scanf("%d", &n3);
    for(i=0; i<n3; i++){
        scanf("%s", &c.makanan[i]);
        scanf("%d %d %d", &c.kalori[i], &c.berat[i], &c.harga[i]);
    }
    
	float k1[100], k2[100], k3[100];
    float hasilK1[100], hasilK2[100];

    kalPerGram(n1, a, k1);
    kalPerGram(n2, b, k2);
    kalPerGram(n3, c, k3);
	
    if(strcmp(m, "is") == 0){
		a = insertion(n1, a, k1);
		b = insertion(n2, b, k2);
		c = insertion(n3, c, k3);
	}else if(strcmp(m, "ss") == 0){
        a = selection(n1, a, k1);
        b = selection(n2, b, k2);
		c = selection(n3, c, k3);
    }else if(strcmp(m, "bs") == 0){
        a = bubbleSOrt(n1, a, k1);
		b= bubbleSOrt(n2, b, k2);
		c = bubbleSOrt(n3, c, k3);
    }else{
        a = quickSort(n1, a, 0, n1-1, k1);
		b = quickSort(n2, b, 0, n2-1, k2);
		c = quickSort(n3, c, 0, n3-1, k3);
    }
    dessert hasil1, hasil2;

    hasil1 = gabungTerurut(n1, a,k1, n2, b,k2, hasilK1);
    hasil2 = gabungTerurut(n1+n2, hasil1,hasilK1, n3, c,k3, hasilK2);  
	
    for(i=0; i<n1+n2+n3; i++){
        printf("%s %s %d %d %d - %0.2f\n", hasil2.n[i], hasil2.makanan[i], hasil2.kalori[i], hasil2.berat[i], hasil2.harga[i], hasilK2[i]);
    } 
    return 0;
}

dessert gabungTerurut(int n, dessert a,float k1[], int m, dessert b, float k2[], float hasilK[]){
	int i=0, j=0, count=0, l=0;
    dessert c;
	while(i < n && j < m){
		if(k1[i] > k2[j]){
			hasilK[count] = k1[i];
            strcpy(c.makanan[count],a.makanan[i] );
			strcpy(c.n[count], a.n[i]);
			c.berat[count] = a.berat[i];
			c.kalori[count] = a.kalori[i];
			c.harga[count] = a.harga[i];
			i++;
			count++;
		}else if(k2[j] > k1[i]){
			hasilK[count] = k2[j];
            strcpy(c.makanan[count], b.makanan[j]);
			strcpy(c.n[count], b.n[j]);
			c.berat[count] = b.berat[j];
			c.kalori[count] = b.kalori[j];
			c.harga[count] = b.harga[j];
			j++;
			count++;
		}else{
			hasilK[count] = k1[i];
            strcpy(c.makanan[count],a.makanan[i] );
			strcpy(c.n[count], a.n[i]);
			c.berat[count] = a.berat[i];
			c.kalori[count] = a.kalori[i];
			c.harga[count] = a.harga[i];
			i++;
			count++;

			hasilK[count] = k2[j];
            strcpy(c.makanan[count], b.makanan[j]);
			strcpy(c.n[count], b.n[j]);
			c.berat[count] = b.berat[j];
			c.kalori[count] = b.kalori[j];
			c.harga[count] = b.harga[j];
			j++;
			count++;
		}
	}

	if(i < n){
		for(l=i; l<n; l++){
			hasilK[count] = k1[l];
            strcpy(c.makanan[count],a.makanan[l] );
			strcpy(c.n[count], a.n[l]);
			c.berat[count] = a.berat[l];
			c.kalori[count] = a.kalori[l];
			c.harga[count] = a.harga[l];
			count++;
		}
	}

	if(j < m){
		for(l = j; l < m; l++){
			hasilK[count] = k2[l];
            strcpy(c.makanan[count], b.makanan[l]);
			strcpy(c.n[count], b.n[l]);
			c.berat[count] = b.berat[l];
			c.kalori[count] = b.kalori[l];
			c.harga[count] = b.harga[l];
			count++;
		}
	}
    return c;
}

void kalPerGram(int n, dessert a, float k[]){

    int i;
    for(i=0; i<n; i++){
        k[i] = (float)a.kalori[i] / a.berat[i];
    }
}

dessert insertion(int n, dessert a, float k[]){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
	int i,j;		//sebagai iterator
	float tempN;		//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempS[100], tempNeg[100];
    int tempA, tempB, tempC;
    dessert b;

	for(i=0; i<n; i++){
		b.kalori[i] = a.kalori[i];
        b.berat[i] = a.berat[i];
        b.harga[i] = a.harga[i];
		strcpy(b.makanan[i], a.makanan[i]);
		strcpy(b.n[i], a.negara);
	}

	

	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		tempN = k[i];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
        tempA = b.kalori[i];
        tempB = b.berat[i];
        tempC = b.harga[i];
		strcpy(tempS, b.makanan[i]);
		strcpy(tempNeg, b.n[i]);
		j=i-1;
	
		while(tempN > k[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
			k[j+1] = k[j];				//nilai di depan akan menyimpan nilai sebelmnya 
            b.kalori[j+1] = b.kalori[j];
            b.berat[j+1] = b.berat[j];
            b.harga[j+1] = b.harga[j];
			strcpy(b.makanan[j+1], b.makanan[j]);
			strcpy(b.n[j+1], b.n[j]);
			j--;
		}

		k[j+1] = tempN;							//menyimpan nilai dari tampungan sementara
        b.kalori[j+1] = tempA;
        b.berat[j+1] = tempB;
        b.harga[j+1] = tempC;
		strcpy(b.makanan[j+1], tempS);
		strcpy(b.n[j+1], tempNeg);
	}

    return b;

/* 	for(i=0; i<n; i++){
		printf("%s %d %d %d - %0.2f\n", a.makanan[i], a.kalori[i], a.berat[i], a.harga[i], k[i]);
	} */
}

dessert selection(int n,dessert a, float k[]){
	int i,j;
	int indeks;
	float tempN;				//seabagi tempat penampungan dari nilai yang akan di urutkan
    int tempA, tempB, tempC;
	char tempS[100];
	char tempNeg[100];
    dessert b;

	for(i=0; i<n; i++){
		b.kalori[i] = a.kalori[i];
        b.berat[i] = a.berat[i];
        b.harga[i] = a.harga[i];
		strcpy(b.makanan[i], a.makanan[i]);
		strcpy(b.n[i], a.negara);
	}

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

        tempA = b.kalori[i];		//untuk menyimpan sementara dari nilai b.kalori[i]
		b.kalori[i] = b.kalori[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		b.kalori[indeks] = tempA;	//menukar nilai dari nilai yang ditukar di atas

        tempB = b.berat[i];		//untuk menyimpan sementara dari nilai b.berat[i]
		b.berat[i] = b.berat[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		b.berat[indeks] = tempB;	//menukar nilai dari nilai yang ditukar di atas

        tempC = b.harga[i];		//untuk menyimpan sementara dari nilai b.harga[i]
		b.harga[i] = b.harga[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		b.harga[indeks] = tempC;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, b.makanan[i]);
		strcpy(b.makanan[i], b.makanan[indeks]);
		strcpy(b.makanan[indeks], tempS);

		strcpy(tempNeg, b.n[i]);
		strcpy(b.n[i], b.n[indeks]);
		strcpy(b.n[indeks], tempNeg);
	}

    return b;
}

dessert bubbleSOrt(int n, dessert a, float k[]){
	int i;

	int tukar;
	float tempN;
	int tempA, tempB, tempC;
	char tempNeg[100];
	char tempS[100];
	dessert b;

	for(i=0; i<n; i++){
		b.kalori[i] = a.kalori[i];
        b.berat[i] = a.berat[i];
        b.harga[i] = a.harga[i];
		strcpy(b.makanan[i], a.makanan[i]);
		strcpy(b.n[i],a.negara);
	}
	do{
		tukar = 0;
		for(i=0; i<n-1; i++){
			if(k[i+1] >k[i]){

 				tempN = k[i+1];
				k[i+1] =k[i];
				k[i] = tempN;

				tempA = b.kalori[i+1];
				b.kalori[i+1] =b.kalori[i];
				b.kalori[i] = tempA;

				tempB = b.berat[i+1];
				b.berat[i+1] =b.berat[i];
				b.berat[i] = tempB;

				tempC = b.harga[i+1];
				b.harga[i+1] =b.harga[i];
				b.harga[i] = tempC;

				strcpy(tempS, b.makanan[i+1]);
                strcpy(b.makanan[i+1], b.makanan[i]);
                strcpy(b.makanan[i], tempS);

				strcpy(tempNeg, b.n[i+1]);
                strcpy(b.n[i+1], b.n[i]);
                strcpy(b.n[i], tempNeg);
				tukar = 1;

 			}
		}
	}while(tukar == 1);
	
    return b;
}

dessert quickSort(int n, dessert a, int kiri, int kanan, float k[]){
	int i,j;
	//membuat variabel tempN bernilai double untuk menampung masukan.waktu sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
	//membuat nilai awal dari iterator i dan j sebagai pivot dengan i = kiri dan j = kanan
	float tempN;
	int tempA, tempB, tempC;
	char tempS[100];
	char tempNeg[100];
	i = kiri;
	j = kanan;
	dessert b;
	for(i=0; i<n; i++){
		b.kalori[i] = a.kalori[i];
        b.berat[i] = a.berat[i];
        b.harga[i] = a.harga[i];
		strcpy(b.makanan[i], a.makanan[i]);
		strcpy(b.n[i], b.negara);
	}
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
			tempA =b.kalori[i];
			b.kalori[i] =b.kalori[j];
			b.kalori[j] = tempA;

			tempB = b.berat[i];
			b.berat[i] =b.berat[j];
			b.berat[j] = tempB;

			tempC =b.harga[i];
			b.harga[i] =b.harga[j];
			b.harga[j] = tempC;

			strcpy(tempS, b.makanan[i]);
            strcpy(b.makanan[i], b.makanan[j]);
            strcpy(b.makanan[j], tempS);

			strcpy(tempNeg, b.n[i]);
            strcpy(b.n[i], b.n[j]);
            strcpy(b.n[j], tempNeg);
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

    return b;
}
