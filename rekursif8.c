#include <stdio.h>

int min(int a, int b){

	if(a > b){
		return a;
	}else{
		return b;
	}

}

int coin(int tukar[], int n, int memo[], int nilai){
	if(memo[nilai] == -1){
		if(nilai == 0){
			memo[nilai] = 0;
		}else{
			int i;
			memo[nilai] = 10000;

			for(i=0; i<n-1; i++){
				if(nilai - tukar[i] >= 0){
					memo[nilai] = min(memo[nilai], coin(tukar, n, memo, nilai-tukar[i] + 1));
				}
			}
		}
	}
	return memo[nilai];
}

int main(int argc, char const *argv[])
{
	int nilai, i,n;

	scanf("%d %d", &nilai, &n);

	int tukar[n];
	int memo[nilai+1];

	for(i=0; i<n; i++){
		scanf("%d", &tukar[i]);
	}

	for(i=0; i<=nilai; i++){
		memo[i] = -1;
	}

	printf("%d\n",coin(tukar,n,memo,nilai));
	return 0;
}