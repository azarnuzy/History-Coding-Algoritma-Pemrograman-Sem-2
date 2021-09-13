#include <stdio.h>

int jumlah(int a, int b, int c, int x){//sebagai fungsi untuk menghitung jumlah bakteri

	int temp;//sebagai variabel untuk menyimpan nilai dari jumlah bakteri

	if(x == c-2){//sebagai kondisi ketika jam yang diinginkan
		temp = a*a + 2*b;//sebagai operasi dari jumlah bakteri 
		return temp;//mengembalikan jumlah bakteri sesuai dengan operasi di atas
	}else{
		temp = (a*a) + (2*b);//sebagai operasi dari jumlah bakteri
		return jumlah(b, temp, c, x+1);//mengembalikan nilai sebagai rekursif dari jumlah bakteri selanjutnya
	}
}

int main(int argc, char const *argv[])
{
	int n;//sebagai banyaknya bakteri yang ingin di cek

	scanf("%d", &n);//memberi masukan dari banyaknya bakteri

	int a[n],b[n],c[n];//membuat array of integer sebagai nilai dari a = jam ke-0, b= jam ke-1, dan c = jumlah jam

	int i;//sebagai variabel untuk perulangan

	for(i=0; i<n; i++){//membuat perulangan untuk masukan jam
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}

	int temp = 0;//sebagai nilai sementara dari fungsi jumlah

	for(i=0 ; i< n; i++){//sebagai perulangan untuk mendapatkan jumlah bakteri 
		temp = jumlah(a[i], b[i], c[i], 0);//sebagai nilai sementara dari jumlah bakteri
		printf("%d\n",temp );//mengeluarkan nilai dari jumlah bakteri
	}
	return 0;
}