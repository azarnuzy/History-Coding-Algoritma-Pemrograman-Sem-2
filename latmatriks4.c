#include <stdio.h>

typedef struct{
	int red;
	int green;
	int blue;
}piksel;

int main(int argc, char const *argv[])
{
	int r,c;

	scanf("%d %d", &r, &c);

	piksel arr[r][c];

	int i,j;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			arr[i][j].red = 255;
			arr[i][j].green = 255;
			arr[i][j].blue = 255;
		}
	}

	arr[0][1].red = 0;
	arr[0][1].green = 255;
	arr[0][1].blue = 0;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if((arr[i][j].red == 255) && (arr[i][j].green == 255) && (arr[i][j].blue == 255)){
				printf("putih ");
			}else if((arr[i][j].red == 0) && (arr[i][j].green == 255) && (arr[i][j].blue == 0)){
				printf("hijau ");
			}
		}
		printf("\n");
	}
	return 0;
}