#include <stdio.h>
int main(int argc, char const *argv[])
{
	int r,c;

	scanf("%d %d", &r, &c);

	int matriks[r][c];

	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks[i][j]);
		}
	}

	for(i=0; i<c; i++){
		for(j=0; j<r; j++){
			printf("%d ",matriks[j][i] );
		}
		printf("\n");
	}
	return 0;
}