#include <stdio.h>

int main(int argc, char const *argv[])
{
	int r1,r2,r3,c1,c2,c3;
	int temp;
	int maks1,maks2,maks3;
	int maks;
	int i,j;

	scanf("%d %d", &r1, &c1);

	int matriks1[r1][c1];
	maks1 = 0;

	for(i=0; i<r1; i++){
		for(j=0; j<c1; j++){
			scanf("%d", &matriks1[i][j]);

			if(maks1 < matriks1[i][j]){
				maks1 = matriks1[i][j];
			}
		}
	}

	scanf("%d", &temp);

	scanf("%d %d", &r2, &c2);

	int matriks2[r2][c2];
	maks2 = 0;

	for(i=0; i<r2; i++){
		for(j=0; j<c2; j++){
			scanf("%d", &matriks2[i][j]);

			if(maks2 < matriks2[i][j]){
				maks2 = matriks2[i][j];
			}
		}
	}

	scanf("%d", &temp);

	scanf("%d %d", &r3, &c3);

	int matriks3[r3][c3];
	maks3 = 0;

	for(i=0; i<r3; i++){
		for(j=0; j<c3; j++){
			scanf("%d", &matriks3[i][j]);

			if(maks3 < matriks3[i][j]){
				maks3 = matriks3[i][j];
			}
		}
	}

	scanf("%d", &temp);

	if(maks1 > maks3 && maks1 > maks2){
		maks = maks1;
	}else if(maks2 > maks1 && maks2 > maks3){
		maks = maks2;
	}else{
		maks = maks3;
	}

	if(maks % 2 == 1){

		for(i= r1-1; i>= 0; i--){
			for(j=0; j<c1; j++){
				printf("%d ", matriks1[j][i]);
			}
			printf("\n");
		}

		for(i=0; i<r2; i++){
			for(j=0; j<c2; j++){
				printf("%d ",matriks2[i][j]);
			}
			printf("\n");
		}

		for(i=0; i<r3; i++){
			for(j=0; j<c3; j++){
				printf("%d ",matriks3[i][j] );
			}
			printf("\n");
		}
	}else{

		for(i=0; i<r1; i++){
			for(j=0; j<c1; j++){
				printf("%d ",matriks1[i][j] );
			}
			printf("\n");
		}

		for(i=r2-1; i>=0; i--){
			for(j=0; j<c2; j++){
				if(j != c2-1){
					printf("%d ",matriks2[i][j+1]);
				}else{
					printf("%d ",matriks2[i][0]);
				}
			}
			printf("\n");
		}

		for(i=0; i<r3; i++){
			for(j=0; j<c3; j++){
				printf("%d ",matriks3[i][j] );
			}
			printf("\n");
		}
	}
	return 0;
}