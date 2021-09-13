#include <stdio.h>

void sorting(int n, int bil[]){
	int i,j;
	int minIndex;
	int temp;

	for(i=0; i<n-1; i++){
		minIndex = i;

		for(j=i+1; j<n; j++){
			if(bil[minIndex] > bil[j]){
				minIndex = j;
			}
		}
		
		temp = bil[i];
		bil[i] = bil[minIndex];
		bil[minIndex] = temp;
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

	int i;
	int bil[n];

	for(i=0; i<n; i++){
		scanf("%d", &bil[i]);
	}

	sorting(n,bil);
	tampil(n,bil);
	return 0;
}