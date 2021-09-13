#include <stdio.h>

typedef struct{
	int alas, tinggi, volume;
}segitiga;

int main(int argc, char const *argv[])
{	
	int i,j;
	int r,c;
	scanf("%d %d", &r, &c);

	int n;
	scanf("%d", &n);

	segitiga matriks[r][c];

	int pRow, pCol, alas, tinggi;

	int mTemp[r][c];

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			mTemp[i][j] = '0';
			matriks[i][j].alas = 0;
			matriks[i][j].tinggi = 0;
		}
	}

	int iArr[n], jArr[n];

	for(i=0; i<n; i++){
		scanf("%d %d %d %d", &pRow, &pCol, &alas, &tinggi);
		matriks[pRow-1][pCol-1].alas = alas;
		matriks[pRow-1][pCol-1].tinggi = tinggi;
		mTemp[pRow-1][pCol-1] = '1';
		iArr[i] = pRow-1;
		jArr[i] = pCol-1;
	}

	int count = 0;
	int status = 0;
	i=0;
	while(status == 0 && i < n){

		count = 1;

		for(j=i+1; j<n; j++){
			if((0.5 * matriks[iArr[i]][jArr[i]].alas * matriks[iArr[i]][jArr[i]].tinggi ) == (0.5 * matriks[iArr[j]][jArr[j]].alas * matriks[iArr[j]][jArr[j]].tinggi)){
				count++;
			}
		}

		if(count == 3){
			status = 1;
		}else{
			i++;
		}
	}

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%c ",mTemp[i][j]);
		}
		printf("\n");
	}

	if(status == 1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
