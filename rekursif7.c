#include <stdio.h>

void menaraHanoi(int n, char awal, char akhir, char antara){
	if(n == 1){
		printf("Pindahkan balok %d dari %c ke %c\n",n, awal, akhir);
	}else{
		menaraHanoi(n-1, awal, antara, akhir);
		printf("Pindahkan balok %d dari %c ke %c\n",n,awal, antara);
		menaraHanoi(n-1, antara, akhir, awal);
		
	}
}
int main(int argc, char const *argv[])
{
	menaraHanoi(3, 'A', 'C', 'B');

	return 0;
}