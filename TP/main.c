#include "header.h"

int main(int argc, char const *argv[])
{
    int r, c, i, j, k;

    scanf("%d %d", &r, &c);


    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            scanf("%s", matriks[i][j].nama);
            for( k = 0; k < 3; k++){
                scanf("%d", &matriks[i][j].nilai[k]);
            }
            matriks[i][j].rata2 = (matriks[i][j].nilai[0] + matriks[i][j].nilai[1] + matriks[i][j].nilai[2]) / 3 + .5; 
        }
    }

	i=0;
	j=0;

	char namaKursi[100][100];

	int count = 0;

	while(strcmp(namaKursi[i-1],"stop") != 0){
		scanf("%s", &namaKursi[i]);
		i++;
	}

	count = i;

	stPos(r,c);
	searchName(r,c,namaKursi, count);
	scPos(r,c);
	return 0;
}