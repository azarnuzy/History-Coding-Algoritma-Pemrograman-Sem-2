#include <stdio.h>

int fibbonaci(int n, int x, int y){

	int temp1, temp2;

	if(x <= n){
		return 1;
	}else if(y % 2 == 0 && temp2 != 0){
		temp1 = y;
		temp2 = 0;
		return fibbonaci(n, x+1, y)
	}else if(){

	}
}

int main(int argc, char const *argv[])
{

	int n;
	scanf("%d", &n);

	fibbonaci(n, 0, 0 );
	return 0;
}