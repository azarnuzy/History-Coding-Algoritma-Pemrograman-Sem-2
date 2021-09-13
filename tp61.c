#include <stdio.h>
#include <string.h>

void insertion(int a,float n[], char s[][100], char m2);
void selection(int a,float n[], char s[][100], char m2);
void bubbleSOrt(int a, float n[], char s[][100], char m2);
void quickSort(int a, float n[], char s[][100], char m2, int kiri, int kanan);
void gabung(int a, float n1[], char s1[][100], int b, float n2[], char s2[][100], float hasilN[], char hasilS[][100],char m2);
void tampil(int n, float hasilN2[], char hasilS2[][100]);
void cariLagu(int n,int m, float n1[], char s1[][100], float hasilN2[], char hasilS2[][100]);

int main(int argc, char const *argv[])
{
    int i,j;
    int a,b,c;
    float n1[100], n2[100], n3[100];
    char s1[100][100], s2[100][100], s3[100][100];

    scanf("%d", &a);
    for(i=0; i<a; i++){
        scanf("%f", &n1[i]);
		scanf("%s", &s1[i]);
    }

    scanf("%d", &b);
    for(i=0; i<b; i++){
        scanf("%f", &n2[i]);
		scanf("%s", &s2[i]);
    }

    scanf("%d", &c);
    for(i=0; i<c; i++){
        scanf("%f", &n3[i]);
		scanf("%s", &s3[i]);
    }
	
    char m1, m2;
    scanf(" %c %c", &m1, &m2);

 
	if(m1 == 'i'){
		insertion(a, n1, s1, m2);
		insertion(b, n2, s2, m2);
		insertion(c, n3, s3, m2);
	}else if(m1 == 's'){
		selection(a, n1, s1, m2);
		selection(b, n2, s2, m2);
		selection(c, n3, s3, m2);
	}else if(m1 == 'b'){
		bubbleSOrt(a, n1, s1, m2);
		bubbleSOrt(b, n2, s2, m2);
		bubbleSOrt(c, n3, s3, m2);
	}else{
		quickSort(a,n1,s1,m2,0,a-1);
		quickSort(b,n2,s2,m2,0,b-1);
		quickSort(c,n3,s3,m2,0,c-1);
	} 

	float hasilN1[100], hasilN2[100];
	char hasilS1[100][100], hasilS2[100][100];
	
	gabung(a,n1,s1,b,n2,s2,hasilN1, hasilS1,m2);
	gabung(a+b,hasilN1,hasilS1,c,n3,s3,hasilN2,hasilS2,m2);
	int nilaiTengah = (a+b+c)/2;

	if((a+b+c) % 2 == 1){
		nilaiTengah += 1;
	}

	tampil(a+b+c, hasilN2, hasilS2);
	cariLagu(nilaiTengah, a, n1,s1,hasilN2,hasilS2);
    return 0;
}

void insertion(int a,float n[], char s[][100], char m2){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
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

	int tukar;
	float tempN;
	char tempS[100];
	do{
		tukar = 0;
		for(i=0; i<a-1; i++){
			if(m2 == 'a' && n[i+1] <n[i]){

				tempN = n[i+1];
				n[i+1] =n[i];
				n[i] = tempN;

				strcpy(tempS, s[i+1]);
                strcpy(s[i+1], s[i]);
                strcpy(s[i], tempS);

				tukar = 1;

 			}else if(m2 == 'd' && n[i+1] >n[i]){

 				tempN = n[i+1];
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
	//membuat variabel tempN bernilai double untuk menampung masukan.waktu sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
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
			//penukaran untuk nilain
			tempN =n[i];
			n[i] =n[j];
			n[j] = tempN;
			//penukaran untuk nilai pembilang
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

	while(i < a && j < b){
		if(m2 == 'a'){
			if(n1[i] < n2[j]){
				hasilN[k] = n1[i];
				strcpy(hasilS[k], s1[i]);
				i++;
				k++;
			}else if(n2[j] < n1[i]){
				hasilN[k] = n2[j];
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}else{
				hasilN[k] = n1[i];
				strcpy(hasilS[k], s1[i]);
				i++;
				k++;
				hasilN[k] = n2[j];
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}
		}else{
			if(n1[i] > n2[j]){
				hasilN[k] = n1[i];
				strcpy(hasilS[k], s1[i]);
				i++;
				k++;
			}else if(n2[j] > n1[i]){
				hasilN[k] = n2[j];
				strcpy(hasilS[k], s2[j]);
				j++;
				k++;
			}else{
				hasilN[k] = n1[i];
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

	if(i < a){
		for(l=i; l<a; l++){
			hasilN[k] = n1[l];
			strcpy(hasilS[k], s1[l]);
			k++;
		}
	}

	if(j < b){
		for(l = j; l < b; l++){
			hasilN[k] = n2[l];
			strcpy(hasilS[k], s2[l]);
			k++;
		}
	}
}

void tampil(int n, float hasilN2[], char hasilS2[][100]){
	int i;
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
	for(i=0; i<m; i++){
		strcpy(temp, s1[i]);
		cek= 0;
		j=0;
		while(cek == 0 && j < n){
			if(strcmp(temp, hasilS2[j]) == 0){
				cek = 1;
				count++;
			}
			j++;
		}

		if(cek == 1){
			printf("%s\n",hasilS2[j-1] );
		} 
	}

	if(count == 0){
		printf("Tidak memutar lagu Ibnu");
	}

}