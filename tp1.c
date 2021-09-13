#include <stdio.h>

int jumlahCol(int c, int matriks[][100]){
	int i;
	int total=0;

	for(i=0; i<c; i++){
		total = total + matriks[0][i];
	}
	return total;
}

void result(int r, int c, int matriks[][100]){
	int i,j;

	int arah = jumlahCol(c, matriks) % 2;
	int rotasi = jumlahCol(c, matriks) % 4;

	if((arah == 1 && rotasi == 3) || (arah == 2 && rotasi == 1)){
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				if(j < c-1){
					printf("%d ",matriks[i][j]);
				}else{
					printf("%d\n",matriks[i][j]);
				}
			}
		}

		printf("Coba lagi besok!\n");
	}else if((arah == 1 && rotasi == 1) || (arah == 2 && rotasi == 3)){
		for(i=r-1; i>=0; i--){
			for(j=c-1; j>=0; j--){
				if(j > 0){
					printf("%d ",matriks[i][j]);
				}else{
					printf("%d\n",matriks[i][j]);
				}
			}
		}
		printf("Wihh matrix yang seru!\n");
	}else if((rotasi == 0)){
		for(i=0; i<c; i++){
			for(j=r-1; j>=0; j--){
				if(j > 0){
					printf("%d ",matriks[j][i]);
				}else{
					printf("%d\n",matriks[j][i]);
				}
			}
		}
		printf("Wihh matrix yang seru!\n");
	}else{
		for(i=c-1; i>=0; i--){
			for(j=0; j<r; j++){
				if(j < r-1){
					printf("%d ",matriks[j][i]);
				}else{
					printf("%d\n",matriks[j][i]);
				}
			}
		}
		printf("Wihh matrix yang seru!\n");
	}

}

int main(int argc, char const *argv[])
{
	int r,c;
	int i,j;

	scanf("%d %d", &r, &c);

	int matriks[100][100];
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	
	result(r,c,matriks);
	return 0;
}