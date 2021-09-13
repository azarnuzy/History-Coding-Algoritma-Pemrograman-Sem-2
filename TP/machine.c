#include "header.h"

void stPos(int r, int c ){
	printf("Posisi Bangku Awal:\n");
	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(j < c-1){
				printf("%s\t",matriks[i][j].nama);
			}else{
				printf("%s\n",matriks[i][j].nama);
			}
		}
	}
}

int cekRata(int x, int y){
	if(x > y){
		return 1;
	}else{
		return 0;
	}
}

void swap(char x[], char y[], float *a, float *b){
	char temp[100];
	strcpy(temp,y);
	strcpy(y, x);
	strcpy(x, temp);
	float temp1 = *b;
	*b = *a;
	*a = temp1;
}

void searchName(int r, int c, char namaKursi[][100], int count){
	int i,j,k;

	j=0;
	k=0;
	int index1[100],index2[100];
	int cek=0;

	for(i=0; i< count ; i++){
		cek = 0;
		j=0;
		while(j < r && cek != 1){
			k=0;
			while(k < c && cek != 1){
				if(strcmp(matriks[j][k].nama, namaKursi[i]) == 0){
					cek = 1;
					index1[i] = j;
					index2[i] = k;
				}
				k++;
			}
			j++;
		}

		if(i % 2 == 1){
			if(cekRata(matriks[index1[i-1]][index2[i-1]].rata2, matriks[index1[i]][index2[i]].rata2) == 1){
				swap(matriks[index1[i-1]][index2[i-1]].nama, matriks[index1[i]][index2[i]].nama, &matriks[index1[i-1]][index2[i-1]].rata2, &matriks[index1[i]][index2[i]].rata2);
			}
		}
	}
}

void scPos(int r,int c){
	int i,j;

	printf("Posisi Bangku Setelah Nilai Dicek:\n");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(j < c-1){
				printf("%s\t",matriks[i][j].nama);
			}else{
				printf("%s\n",matriks[i][j].nama);
			}
		}
	}
}
