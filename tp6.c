#include <stdio.h>
#include <string.h>

typedef struct {
    float waktu[100];
    char judul[100][100];
}musik;
musik masukan[10];
int count = 0;
float arr3[100];
char arr4[100][100];
char arr6[100][100];

void insertion(int n, char urut, int x);
void selection(int n, char urut, int x);
void bubbleSOrt(int n, char urut, int x);
void quickSort(int n, char urut, int kiri, int kanan, int x);
void gabungTerurut(int n,float arr5[], int m,int x);
void tampungAwal(int n);

int main(int argc, char const *argv[])
{
    float arr5[100];
    int i,j;
	int banyak[5];
    scanf("%d", &banyak[0]);

    for(i=0; i<banyak[0]; i++){
        scanf("%f", &masukan[0].waktu[i]);
        scanf("%s", &masukan[0].judul[i]);
    }

    scanf("%d", &banyak[1]);

    for(i=0; i<banyak[1]; i++){
        scanf("%f", &masukan[1].waktu[i]);
        scanf("%s", &masukan[1].judul[i]);
    }

    scanf("%d", &banyak[2]);

    for(i=0; i<banyak[2]; i++){
        scanf("%f", &masukan[2].waktu[i]);
        scanf("%s", &masukan[2].judul[i]);
    }
    
    char method, urut;

    scanf(" %c %c", &method, &urut);

    if(method == 'i'){
        for(i=0; i<3; i++){
            insertion(banyak[i], urut, i);
        }
    }else if(method == 's'){
        for(i=0; i<3; i++){
            selection(banyak[i], urut,i);
        }
    }else if(method == 'q'){
        for(i=0; i<3; i++){
            quickSort(banyak[i], urut, 0, banyak[i]-1, i);
        }
    }else{
        for(i=0; i<3; i++){
            bubbleSOrt(banyak[i], urut, i);
        }
    } 

	tampungAwal(banyak[0]);

	/* for(i=0; i<3; i++){
		for(j=0; j< banyak[i]; j++){
			printf("%0.2f\n", masukan[i].waktu[j]);
		}
	} */
	gabungTerurut(banyak[0], banyak[1], 0);
	gabungTerurut(banyak[0]+banyak[1], banyak[2], 1);

	for(i=0; i<3; i++){
		count += banyak[i];
	}

	/* for(i=0; i<count; i++){
		printf("%0.2f %s\n", arr5[i], arr4[i]);
	} */
    return 0;
}

void insertion(int n, char urut, int x){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
	int i,j,k;		//sebagai iterator
	float temp;		//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempJudul[100];
	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		temp = masukan[x].waktu[i];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
        strcpy(tempJudul, masukan[x].judul[i]);
		j=i-1;

		if(urut == 'a'){		//membuat pengkondisian untuk cara mengurutkan dari kecil ke besar
			
			while(temp < masukan[x].waktu[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih kecil dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				masukan[x].waktu[j+1] = masukan[x].waktu[j];				//nilai di depan akan menyimpan nilai sebelmnya 
                strcpy(masukan[x].judul[j+1], masukan[x].judul[j]);
				j--;						
			}	
		}else{								//membuat pengkondisian untuk cara mengurutkan dari besar ke kecil
	
			while(temp > masukan[x].waktu[j] && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
				masukan[x].waktu[j+1] = masukan[x].waktu[j];				//nilai di depan akan menyimpan nilai sebelmnya 
                strcpy(masukan[x].judul[j+1], masukan[x].judul[j]);
				j--;
			}
		}

		masukan[x].waktu[j+1] = temp;							//menyimpan nilai dari keluaran sementara
        strcpy(masukan[x].judul[j+1], tempJudul);
 	}

}

void selection(int n, char urut, int x){
	int i,j;
	int indeks;
	float temp;				//seabagi tempat penampungan dari nilai yang akan di urutkan
	char tempJudul[100];


	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
			if(masukan[x].waktu[indeks] < masukan[x].waktu[j] && urut == 'a'){ 			//sebagai pengkondisian untuk mencari nilai yang lebih kecil
				indeks = j;											//untuk menyimpan nilai dari indeks nilai yang lebih kecil
			}else if(masukan[x].waktu[indeks] > masukan[x].waktu[j] && urut == 'd'){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
				indeks = j;											//untuk menyimpan nilai dari indeks nilai yang lebih kecil
			}
		}
		
		temp = masukan[x].waktu[i];		//untuk menyimpan sementara dari nilai masukan[x].waktu[i]
		masukan[x].waktu[i] = masukan[x].waktu[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		masukan[x].waktu[indeks] = temp;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempJudul, masukan[x].judul[i]);
		strcpy(masukan[x].judul[i], masukan[x].judul[indeks]);
		strcpy(masukan[x].judul[indeks], tempJudul);
	}
}

void bubbleSOrt(int n, char urut, int x){
	int i;

	int tukar;
	float temp1;
	char tempJudul[100];
	do{
		tukar = 0;
		for(i=0; i<n-1; i++){
			if(urut == 'a' && masukan[x].waktu[i+1] < masukan[x].waktu[i]){

				temp1 = masukan[x].waktu[i+1];
				masukan[x].waktu[i+1] = masukan[x].waktu[i];
				masukan[x].waktu[i] = temp1;

				strcpy(tempJudul, masukan[x].judul[i+1]);
                strcpy(masukan[x].judul[i+1], masukan[x].judul[i]);
                strcpy(masukan[x].judul[i], tempJudul);

				tukar = 1;

 			}else if(urut == 'd' && masukan[x].waktu[i+1] > masukan[x].waktu[i]){

 				temp1 = masukan[x].waktu[i+1];
				masukan[x].waktu[i+1] = masukan[x].waktu[i];
				masukan[x].waktu[i] = temp1;

				strcpy(tempJudul, masukan[x].judul[i+1]);
                strcpy(masukan[x].judul[i+1], masukan[x].judul[i]);
                strcpy(masukan[x].judul[i], tempJudul);

				tukar = 1;

 			}
		}
	}while(tukar == 1);
    
}

void quickSort(int n, char urut, int kiri, int kanan, int x){
	int i,j;
	//membuat variabel temp1 bernilai double untuk menampung masukan.waktu sementara
	//temp2,temp3 untuk menampung nilai pembilang dan penyebut sementara
	//membuat nilai awal dari iterator i dan j sebagai pivot dengan i = kiri dan j = kanan
	float temp1;
	char tempJudul[100];
	i = kiri;
	j = kanan;

	//membuat perulangan jika nilai i <= j 
	//perulangan dilakukan secara quicksort bagian pinggir sebagai pivotnya
	do{
		//dilakukan syarat jika pengurutan yang dingiinkan secara ascending
		if(urut == 'a'){
			//membuat perulanganketika nilai dari masukan.waktu yang berada pada sisi kiri lebih kecil
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((masukan[x].waktu[i] < masukan[x].waktu[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai dari masukan[x].waktu yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((masukan[x].waktu[j] > masukan[x].waktu[kiri]) && (i <= j)){
				j--;
			}
		}
		//dilakukan syarat jika pengurutan yang dingiinkan secara descending
		else{
			//membuat perulanganketika nilai dari masukan[x].waktu yang berada pada sisi kiri lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kanan
			while((masukan[x].waktu[i] > masukan[x].waktu[kanan]) && (i <= j)){
				i++;
			}
			//membuat perulanganketika nilai dari masukan[x].waktu yang berada pada sisi kanan lebih besar
			//maka posisi dari nilai yang dibandingkan akan terus maju ke arah kiri
			while((masukan[x].waktu[j] < masukan[x].waktu[kiri]) && (i <= j)){
				j--;
			}
		}
		//jika nilai i < j, maka dilakukan pertukaran nilai dari sisi kiri dan sisi kanan
		if(i < j){
			//penukaran untuk nilai masukan[x].waktu
			temp1 = masukan[x].waktu[i];
			masukan[x].waktu[i] = masukan[x].waktu[j];
			masukan[x].waktu[j] = temp1;
			//penukaran untuk nilai pembilang
			strcpy(tempJudul, masukan[x].judul[i]);
            strcpy(masukan[x].judul[i], masukan[x].judul[j]);
            strcpy(masukan[x].judul[j], tempJudul);
			//nilai i dan j akan berubah ke kanan dan ke kiri
			i++;
			j--;
		}

	}while(i <= j);//perulangan akan dilakukan jika nilai dari i <= j
	//jika nilai dari sisi kiri masih < j maka dilakukan rekursif
	if(kiri < j){
		//dengan nilai dari sisi kanan di ubah menjadi j
		quickSort(n,urut, kiri, j, x);
	}
	//jika nilai dari sisi kanan > i maka dilakukan rekursif
	if(i < kanan){
		//dengan nilai dari sisi kiri di ubah menjadi i
		quickSort(n,urut, i, kanan, x);
	}
}

void gabungTerurut(int n,float arr5[], int m,int x){
	int i=0, j=0, l=0, k=0;

	while(i < n && j < m){
		if(arr5[i] < masukan[x+1].waktu[j]){
			arr3[k] = arr5[i];
			strcpy(arr4[k], arr6[i]);
			i++;
			k++;
		}else if(masukan[x+1].waktu[j] < arr5[i]){
			arr3[k] = masukan[x+1].waktu[j];
			strcpy(arr4[k], masukan[x+1].judul[j]);
			j++;
			k++;
		}else{
			arr3[k] = arr5[i];
			strcpy(arr4[k], arr6[i]);
			i++;
			k++;

			arr3[k] = masukan[x+1].waktu[j];
			strcpy(arr4[k], masukan[x+1].judul[j]);
			j++;
			k++;
		}
	}
	if(i < n){
		for(l=i; l<n; l++){
			arr3[k] = arr5[l];
			strcpy(arr4[k], arr6[l]);
			k++;
		}
	}

	if(j < m){
		for(l = j; l < m; l++){
			arr3[k] = masukan[x+1].waktu[l];
			strcpy(arr4[k], masukan[x+1].judul[l]);
			k++;
		}
	}

	for(i=0; i<n+m; i++){
		arr5[i] = arr3[i];
		strcpy(arr6[i], arr4[i]);
	}

	for(i=0; i<n+m; i++){
		printf("%0.2f\n", arr3[i]);
	}

	printf("=======\n");
}

void tampungAwal(int n){
	int i;
	
	for(i=count; i<n; i++){
		arr5[i] = masukan[0].waktu[i];
		strcpy(arr6[i], masukan[0].judul[i]);
	}

}
