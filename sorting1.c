#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	int i,j;

	int tabInt[n];

	for(i=0; i<n; i++){
		scanf("%d", &tabInt[i]);
	}

	int temp;

	for(i=1; i<n; i++){

		temp = tabInt[i];
		j = i - 1;

		while(temp < tabInt[j] && j >= 0){
			tabInt[j+1] = tabInt[j];
			j= j-1;
		}

		tabInt[j+1] = temp;

	}

	for(i=0; i<n ; i++){
		printf("%d ",tabInt[i] );
	}
	return 0;
}