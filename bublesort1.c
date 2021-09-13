#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	int i;
	int arrBil[n];

	for(i=0; i<n; i++){
		scanf("%d", &arrBil[i]);
	}

	int temp, tukar;

	do{
		tukar = 0;
		for (int i = 0; i < n-1; ++i)
		{
			if(arrBil[i] > arrBil[i+1]){
				temp = arrBil[i];
				arrBil[i] = arrBil[i+1];
				arrBil[i+1] = temp;

				tukar = 1;
			}
		}	
	}while(tukar == 1);

	for(i=0; i<n; i++){
		printf("%d ",arrBil[i] );
	}


	return 0;
}