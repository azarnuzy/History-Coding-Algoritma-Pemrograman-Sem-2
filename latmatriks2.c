#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c,r;

	scanf("%d %d", &r, &c);

	int matriks[r][c];

	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks[i][j]);
		}
	}

	for(i=0; i<r; i++){
		for(j=c-1; j>=0; j--){
			printf("%d ",matriks[i][j] );
		}
		printf("\n");
	}
	return 0;
}