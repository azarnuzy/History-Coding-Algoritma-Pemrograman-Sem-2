#include <stdio.h>


int main(int argc, char const *argv[])
{
	int limit;

	scanf("%d", &limit);

	int r,c;

	scanf("%d %d", &r, &c);

	int matriks1[r][c], matriks2[r][c];

	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks1[i][j]);
		}
	}

	for(i=0;i <r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks2[i][j]);
		}
	}

	int maks;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if((matriks1[i][j] > matriks2[i][j])){
				maks = matriks1[i][j];
			}else{
				maks = matriks2[i][j];
			}

			if(maks > limit){
				printf("%d ",maks);
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}