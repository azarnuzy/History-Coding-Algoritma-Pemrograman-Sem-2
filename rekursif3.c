#include <stdio.h>

int penjumlahan(int m, int n){
	if(m > n){
		return 0;
	}else{
		return m + penjumlahan(m+1, n);
	}
}

int main(int argc, char const *argv[])
{

	int n;
	scanf("%d", &n);

	int hasil = penjumlahan(0, n);

	printf("%d\n", hasil);
	
	return 0;
}