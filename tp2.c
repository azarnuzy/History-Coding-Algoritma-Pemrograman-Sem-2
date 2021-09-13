#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    int nilai[3];
    float rata2;
}masukan;

masukan matriks[100][100];

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

void swap(char x[], char y[], float &a, float &b){
	char temp[100];
	strcpy(temp,y);
	strcpy(y, x);
	strcpy(x, temp);
	float temp1 = b;
	b = a;
	a = temp1;
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
			printf("%f %f\n",matriks[index1[i-1]][index2[i-1]].rata2, matriks[index1[i]][index2[i]].rata2 );
			if(cekRata(matriks[index1[i-1]][index2[i-1]].rata2, matriks[index1[i]][index2[i]].rata2) == 1){
				swap(matriks[index1[i-1]][index2[i-1]].nama, matriks[index1[i]][index2[i]].nama, matriks[index1[i-1]][index2[i-1]].rata2, matriks[index1[i]][index2[i]].rata2);
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

int main(int argc, char const *argv[])
{

    int r, c, i, j, k;

    scanf("%d%d", &r, &c);


    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            scanf("%s", matriks[i][j].nama);
            for( k = 0; k < 3; k++){
                scanf("%d", &matriks[i][j].nilai[k]);
            }
            matriks[i][j].rata2 = (matriks[i][j].nilai[0] + matriks[i][j].nilai[1] + matriks[i][j].nilai[2]) / 3 + .5; 
        }
    }

	i=0;
	j=0;

	char namaKursi[100][100];

	int count = 0;

	while(strcmp(namaKursi[i-1],"stop") != 0){
		scanf("%s", &namaKursi[i]);
		i++;
	}

	count = i;

	stPos(r,c);
	searchName(r,c,namaKursi, count);
	scPos(r,c);
	return 0;
}