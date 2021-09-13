#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n,m,p;

	scanf("%d %d", &n, &m);
	scanf("%d", &p);

	int i,j,k;

	int matriks1[n][m];
	int matriks2[m][p];

	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &matriks1[i][j]);
		}
	}

	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
			scanf("%d", &matriks2[i][j]);
		}
	}

	int matriks3[n][p];

	for(i=0; i<n; i++){
		for(j=0; j<p; j++){
			matriks3[i][j] = 0;
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<p; j++){
			for(k=0; k<m; k++){
				matriks3[i][j] = matriks1[i][k] * matriks2[k][j] + matriks3[i][j];
			}
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<p; j++){
			printf("%d ",matriks3[i][j] );
		}
		printf("\n");
	}
	return 0;
}