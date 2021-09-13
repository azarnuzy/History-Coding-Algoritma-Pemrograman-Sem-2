#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100][100];
	int harga[100];
	float nilai[100];
}laporan;

char metode[100],urut[100],patokan[100];

void insertion(int n,laporan masukan){
	int i,j;
	int temp;
	char tempNama[100][100]; 
	int tempHarga[100]; 
	float tempNilai[100];

	int cek = 1;

	for(i=1; i<n; i++){
		if(strcmp(urut, "asc") == 0){
			if(strcmp(patokan, "nama") == 0){

				j=i-1;
				temp = masukan.nama[i][0];

				while(temp < masukan.nama[j][0] && j >= 0){
					masukan.nama[j+1][0] = masukan.nama[j][0];
					j--;
				}

				masukan.nama[j+1] = masukan.nama[i];
				masukan.harga[j+1] = masukan.harga[i];
				masukan.nilai[j+1] = masukan.nilai[i];

			}else if(strcmp(patokan, "harga") == 0){
				
				j=i-1;
				temp = masukan.harga[i];
				while(temp < masukan.harga[j] && j >= 0){
					masukan.harga[j+1] = masukan.harga[j];
					j--;
				}
				masukan.nama[j+1] = masukan.nama[i];
				masukan.harga[j+1] = masukan.harga[i];
				masukan.nilai[j+1] = masukan.nilai[i];
			}else{
				j = i-1;
				temp = masukan.nilai[i] * 100 + .5;
				while(temp < masukan.nilai[j] && j >= 0){
					j=i-1;
					masukan.nilai[j+1] = masukan.nilai[j];
					j--;
				}
				masukan.nama[j+1] = masukan.nama[i];
				masukan.harga[j+1] = masukan.harga[i];
				masukan.nilai[j+1] = masukan.nilai[i];
			}
		}else{
			if(strcmp(patokan, "nama") == 0){
				j=i-1;
				temp = masukan.nama[i][0];
				while(temp > masukan.nama[j] && j >= 0){
					masukan.nama[j+1] = masukan.nama[j];
					j--;
				}
				masukan.nama[j+1] = temp;
			}else if(strcmp(patokan, "harga") == 0){
				j=i-1;
				temp = masukan.harga[i];
				while(temp > masukan.harga[j] && j >= 0){
					masukan.harga[j+1] = masukan.harga[j];
					j--;
				}
				masukan.harga[j+1] = temp;
			}else{
				j = i-1;
				temp = masukan.nilai[i] * 100 + 0.5;
				while(temp > masukan.nilai[j] && j >= 0){
					masukan.nilai[j+1] = masukan.nilai[j];
					j--;
				}
				masukan.nilai[j+1] = temp;
			}
		}
	}
}

void selection(int n, int x[]){
	int i,j;
	int index1;
	int temp;
	
	int tempX[n];
	int cek = 1;

	for(i=0; i<n; i++){
		tempX[i] = x[i];
	}

	for(i=0; i<n-1; i++){
		index1 = i;

		for(j=i+1; j<n; j++){
			if(x[index1] <= x[j] && strcmp(urut, "asc")){
				index1 = j;
			}else if(x[index1] >= x[j] && strcmp(urut, "desc")){
				index1 = j;
			}
		}
		
		temp = x[i];
		x[i] = x[index1];
		x[index1] = temp;
	}

	for(i=0; i<n; i++){
		j=n-1;
		cek = 1;
		while(cek == 1 && j>=0){
			if(x[i] == tempX[j]){
				index[i] = j;
				tempX[j] = -1;
				cek = 0;
			}
			j--;
		}
	}
}

void tampil(int n, laporan masukan){
	int i;
	for(i=0; i<n; i++){
		int harga1 = masukan.harga[index[i]];
		float nilai1 = masukan.nilai[index[i]];
		printf("%s %d %0.1f\n", masukan.nama[index[i]], harga1, nilai1);
	}
}



int main(int argc, char const *argv[])
{
	int n; 
	scanf("%d", &n);

	int i;
	
	laporan masukan;

	for(i=0; i<n; i++){
		scanf("%s", &masukan.nama[i]);
		scanf("%d %f", &masukan.harga[i], &masukan.nilai[i]);
	}

	scanf("%s", &metode);
	scanf("%s", &urut);
	scanf("%s", &patokan);

	ubahNilai(n,masukan);

	printf("%s\n",metode );
	if(strcmp(metode, "insertion") == 0){
		if(strcmp(patokan, "nama") == 0 ){
			insertion(n, tempNama);
		}else if(strcmp(patokan, "harga") == 0){
			insertion(n, tempHarga);
		}else{
			insertion(n, tempNilai);
		}
	}else{
		if(strcmp(patokan, "nama") == 0 ){
			selection(n, tempNama);
		}else if(strcmp(patokan, "harga") == 0){
			selection(n, tempHarga);
		}else{
			selection(n, tempNilai);
		}
	}

	tampil(n,masukan);
	return 0;
}