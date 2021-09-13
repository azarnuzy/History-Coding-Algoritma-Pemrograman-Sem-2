#include <stdio.h>

int fibonacci(int n){
	if(n<=1){
		return n;
	}else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	int hasil = fibonacci(n);

	printf("%d\n",hasil );
	return 0;
}