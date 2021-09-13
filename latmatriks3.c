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
	int arah;

	scanf("%d", &arah);

	int putaran;

	scanf("%d", &putaran);

	if((arah == 1 && putaran % 4 == 1) || (arah == 2 && putaran % 4 == 3)){
		for(i=0; i<c; i++){
			for(j=r-1; j>=0; j--){
				printf("%d ",matriks[j][i]);
			}
			printf("\n");
		}
	}else if((arah == 2 && putaran % 4 == 1)|| (arah== 1 && putaran % 4 == 3)){
		for(i=c-1; i>=0; i--){
			for(j=0; j<r; j++){
				printf("%d ",matriks[j][i]);
			}
			printf("\n");
		}
	}else if(putaran % 4 == 2){
		for(i=r-1; i>=0; i--){
			for(j=c-1; j>=0; j--){
				printf("%d ",matriks[i][j] );
			}
			printf("\n");
		}
	}else{
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				printf("%d ",matriks[i][j] );
			}
			printf("\n");
		}
	}
	return 0;
}