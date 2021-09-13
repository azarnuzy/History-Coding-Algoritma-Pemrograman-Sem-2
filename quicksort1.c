#include <stdio.h>

void quickSort1(int data[], int n, int kiri, int kanan){
	int i,j,temp;

	i = kiri;
	j = kanan;

	do{
		while((data[i] < data[kanan]) && (i <= j)){
			i++;
		}

		while((data[j] > data[kiri]) && (i <= j)){
			j--;
		}

		if(i < j){
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;

			i++;
			j--;
		}


	}while(i < j);

	if(kiri < j){
		quickSort1(data, n, kiri, j);
	}

	if(i < kanan){
		quickSort1(data, n, i, kanan);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int data[n];

	int i;

	for(i=0; i<n;i++){
		scanf("%d", &data[i]);
	}


	quickSort1(data,n,0, n-1);

	for(i=0; i<n; i++){
		printf("%d ",data[i] );
	}
	return 0;
}