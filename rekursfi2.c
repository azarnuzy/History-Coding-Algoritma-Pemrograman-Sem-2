#include <stdio.h>

int faktorial(int n){

	if(n > 1){
		return  n * faktorial(n-1);
	}
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	int hasil = faktorial(n);

	printf("%d\n",hasil );
	return 0;
}