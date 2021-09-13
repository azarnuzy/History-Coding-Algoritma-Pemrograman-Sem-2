#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int tabInt[n];
	int i,j;

	for(i=0; i<n; i++){
		scanf("%d", &tabInt[i]);
	}

	int temp;
	int minIndeks;

	for(i=0; i<n-1; i++){
		minIndeks = i;

		for(j=i+1; j<n; j++){
			if(tabInt[minIndeks] > tabInt[j]){
				minIndeks = j;
			}
		}
			temp = tabInt[i];
			tabInt[i] = tabInt[minIndeks];
			tabInt[minIndeks] = temp;
	}

	for(i=0; i<n; i++){
		printf("%d ",tabInt[i]);
	}
	return 0;
}