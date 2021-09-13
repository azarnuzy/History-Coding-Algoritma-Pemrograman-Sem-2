#include <stdio.h>

typedef struct{
	char jenis[100];
	int harga;
}makanan;

int main(int argc, char const *argv[])
{
	int b,k;
	scanf("%d %d", &b, &k);

	int n;
	scanf("%d", &n);

	makanan matriks[100][100];

	int i,j;

	for(i=0; i<b; i++){
		for(j=0; j<k; j++){
			matriks[i][j].harga = 0;
		}
	}

	int b1, k1;

	for(i=0; i<n; i++){
		scanf("%d %d", &b1, &k1);
		scanf("%s", &matriks[b1][k1].jenis);
		scanf("%d", &matriks[b1][k1].harga);
	}

	int m;
	scanf("%d", &m);

	int indexI[m], indexJ[m];

	for(i=0; i<m; i++){
		scanf("%d %d", &indexI[i], indexJ[i]);
	}
	return 0;
}