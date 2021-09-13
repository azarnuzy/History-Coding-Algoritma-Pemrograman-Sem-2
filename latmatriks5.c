#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	system("cls");
	int papan[3][3];

	int i,j,k;

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			papan[i][j] = 0;
		}
	}

	int pemain = -1;
	int x = -1, y = -1;

	for(i=0; i<9; i++){
		if((x != -1) && (y != -1)){
			papan[x][y] = pemain;
		}

		printf("kondisi papan:\n");
		printf("-------------\n");
		for(j=0; j<3; j++){
			printf("| ");
			for(k=0; k<3; k++){
				if(papan[k][j] == 0){
					printf("  | ");
				}else if(papan[k][j] == 1){
					printf("O | ");
				}else if(papan[k][j] == 2){
					printf("X | ");
				}
			}
			printf("\n-------------\n");
		}
		printf("\n");

		if(pemain == 1){
			pemain = 2;
		}else{
			pemain = 1;
		}

		printf("Masukkan X,Y (Pemain %d): ", pemain );
		scanf("%d %d", &x, &y);

		system("cls");
	}
	return 0;
}