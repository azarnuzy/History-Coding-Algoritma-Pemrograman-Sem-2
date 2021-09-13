#include <stdio.h>

int getFPB(int n, int m){
	if(m == 0){
		return n;
	}else{
		int temp = n % m;
		printf("%d %d\n",n,m );
		return getFPB(m,temp);
	}
}

int main(int argc, char const *argv[])
{
	int n,m;

	scanf("%d %d", &n, &m);

	printf("%d\n",getFPB(n,m) );

	return 0;
}