#include <stdio.h>

int power(int n, int pow2, int m){
	if(m >= pow2){
		return 1;
	}else{
		return n * power(n,pow2,m+1);
	}
}

int main(int argc, char const *argv[])
{
	int n,pow2;

	scanf("%d %d", &n, &pow2);

	int hasil = power(n,pow2,0);

	printf("%d\n",hasil);
	return 0;
}