#include <stdio.h>

void urut(int n, int bil[]){
	int i, temp, index, j;
	int cek = 1;

	for(i=1; i<n; i++){
		temp = bil[i];
		j=i-1;
		while(temp < bil[j] && j >= 0){
			bil[j+1] = bil[j];
			j--;

		}
		bil[j+1] = temp; 
	}
}

void tampil(int n, int bil[]){
	int i;

	for(i=0; i<n; i++){
		printf("%d ",bil[i] );
	}
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	int bil[n];

	int i;

	for(i=0; i<n; i++){
		scanf("%d", &bil[i]);
	}

	urut(n,bil);
	tampil(n,bil);
	return 0;
}