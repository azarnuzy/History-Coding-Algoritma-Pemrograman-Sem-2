#include <stdio.h>

typedef struct{
	int panjang,lebar, tinggi, volume;
}balok;

int main(int argc, char const *argv[])
{
	int r,c;
	int n;

	scanf("%d %d", &r, &c);
	scanf("%d", &n);

	balok matriks[r][c];
	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			matriks[i][j].panjang = 0;
			matriks[i][j].lebar = 0;
			matriks[i][j].tinggi = 0;
			matriks[i][j].volume = 0;
		}
	}

	char mtemp[r][c];
	int iarr[n];
	int jarr[n];

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			mtemp[i][j] = '0';
		}
	}

	int panjang,lebar,tinggi;
	int pRow, pCol;
	int volume;

	for(i=0; i<n; i++){
		scanf("%d %d %d %d %d", &pRow, &pCol, &panjang, &lebar, &tinggi);

		matriks[pRow - 1][pCol - 1].panjang = panjang;
		matriks[pRow - 1][pCol - 1].lebar = lebar;
		matriks[pRow - 1][pCol - 1].tinggi = tinggi;
		matriks[pRow - 1][pCol - 1].volume = panjang * lebar * tinggi;
		mtemp[pRow - 1][pCol - 1] = '1';
		iarr[i] = pRow - 1;
		jarr[i] = pCol - 1;
	}

	int check1=0,check2=0;

	for(i=0; i<n-2; i++){
		check1 = matriks[iarr[i]][jarr[i]].volume;
		check2 = matriks[iarr[i+1]][jarr[i+1]].volume;

		for(j=i+2; j<n-1; j++){
			if((check1 + check2) == matriks[iarr[j]][jarr[j]].volume){
				mtemp[iarr[i]][jarr[i]] = 'x';
				mtemp[iarr[i+1]][jarr[i+1]] = 'x';
				mtemp[iarr[j]][jarr[j]] = 'x';
			}
		}
	}

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%c ",mtemp[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}