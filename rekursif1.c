#include <stdio.h>

void tulis(int n){
	
	if(n > 0){
		printf("proses rekursif dengan nilai counter : %d\n",n );
		tulis(n-1);
	}	
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	tulis(n);
	return 0;
}