#include <stdio.h>

double pecahan[1000];

void tampunganPecahan(int n, int pembilang[], int penyebut[]){
	int i;
	for(i=0; i<n; i++){
		pecahan[i] = (double)pembilang[i] / penyebut[i];
	}
}

void bubbleSOrt(int n, int pembilang[], int penyebut[], char z){
	int i;

	int tukar;
	double temp1;
	int temp2,temp3;
	do{
		tukar = 0;
		for(i=0; i<n-1; i++){
			if(z == 'a' && pecahan[i+1] < pecahan[i]){

				temp1 = pecahan[i+1];
				pecahan[i+1] = pecahan[i];
				pecahan[i] = temp1;

				temp2 = pembilang[i+1];
				pembilang[i+1] = pembilang[i];
				pembilang[i] = temp2;

				temp3 = penyebut[i+1];
				penyebut[i+1] = penyebut[i];
				penyebut[i] = temp3;

				tukar = 1;

 			}else if(z == 'd' && pecahan[i+1] > pecahan[i]){

 				temp1 = pecahan[i+1];
				pecahan[i+1] = pecahan[i];
				pecahan[i] = temp1;

				temp2 = pembilang[i+1];
				pembilang[i+1] = pembilang[i];
				pembilang[i] = temp2;

				temp3 = penyebut[i+1];
				penyebut[i+1] = penyebut[i];
				penyebut[i] = temp3;

				tukar = 1;

 			}
		}
	}while(tukar == 1);
}

void quickSort(int n, int pembilang[], int penyebut[], char z, int kiri, int kanan){
	int i,j;
	double temp1;
	int temp2, temp3;

	i = kiri;
	j = kanan;

	do{
		if(z == 'a'){
			while((pecahan[i] < pecahan[kanan]) && (i <= j)){
				i++;
			}

			while((pecahan[j] > pecahan[kiri]) && (i <= j)){
				j--;
			}
		}else{
			while((pecahan[i] > pecahan[kanan]) && (i <= j)){
				i++;
			}

			while((pecahan[j] < pecahan[kiri]) && (i <= j)){
				j--;
			}
		}

		if(i < j){
			temp1 = pecahan[i];
			pecahan[i] = pecahan[j];
			pecahan[j] = temp1;

			temp2 = pembilang[i];
			pembilang[i] = pembilang[j];
			pembilang[j] = temp2;

			temp3 = penyebut[i];
			penyebut[i] = penyebut[j];
			penyebut[j] = temp3;

			i++;
			j--;
		}

	}while(i <= j);

	if(kiri < j){
		quickSort(n, pembilang, penyebut, z, kiri, j);
	}

	if(i < kanan){
		quickSort(n, pembilang, penyebut, z, i, kanan);
	}
}

void tampil(int n, int pembilang[], int penyebut[]){
	int i;
	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%d   ", pembilang[i]);
		}else{
			printf("%d\n",pembilang[i] );
		}
	}

	for(i=0; i<n; i++){
		if(i<n-1){
			printf("- , ");
		}else{
			printf("-\n");
		}
	}

	for(i=0; i<n; i++){
		if(i < n-1){
			printf("%d   ",penyebut[i] );
		}else{
			printf("%d\n",penyebut[i] );
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i;
	int pembilang[n], penyebut[n];

	for(i=0; i<n; i++){
		scanf("%d %d", &pembilang[i], &penyebut[i]);
	}

	char m,z;
	scanf(" %c %c", &m, &z);

	tampunganPecahan(n, pembilang, penyebut);

	if(m == 'q'){
		quickSort(n, pembilang, penyebut, z, 0, n-1);
	}else{
		bubbleSOrt(n, pembilang, penyebut, z);
	}

	tampil(n, pembilang, penyebut);
	return 0;
}