#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	int nilai[100];
	float rata2;
	char namaKiri[100];
	char namaKanan[100];
}masukan;

int main(int argc, char const *argv[])
{
	int r,c,i,j,k;
	masukan matriks1[100][100];
	masukan pertukaran[100];

	scanf("%d %d", &r, &c);

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%s", &matriks1[i][j].nama);
			for(k=0; k<3; k++){
				scanf("%d", &matriks1[i][j].nilai[k]);
			}
		}
	}

	char cek[100];

	i=0;

	while(strcmp(cek, "stop") != 0){
		scanf(" %s", &pertukaran[i].namaKiri);
		scanf(" %s", &pertukaran[i].namaKanan);
		i++;
	}

	return 0;
}