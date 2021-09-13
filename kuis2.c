#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[100][100];
    int berat[100];
    int harga[100];
    char status[100][100];
    int cariHargaGram;
    int hargaGram[100];
    int ketemu;
}kurma;

kurma tempHargaGram(int n, kurma a){
    int i;
    kurma b;
    for(i=0; i<n; i++){
        b.hargaGram[i] = a.harga[i] / a.berat[i];
    }

    return b;
}

kurma selection(int n,kurma b, kurma a){
	int i,j;
	int indeks;
	int tempHargaGram;				//seabagi tempat penampungan dari nilai yang akan di uruutkan
	char tempNama[100];
    char tempStatus[100];
    int tempBerat;
    int tempHarga;

    kurma c;

    for(i=0; i<n; i++){
        c.hargaGram[i] = b.hargaGram[i];
        c.berat[i] = a.berat[i];
        c.harga[i] = a.harga[i];
        strcpy(c.nama[i], a.nama[i]);
        strcpy(c.status[i], a.status[i]);
    }


	for(i=0; i<n-1; i++){	//membuat perulangan untuk menguruutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
            if(c.hargaGram[indeks] < c.hargaGram[j]){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
                indeks = j;						            //untuk menyimpan nilai dari inden2 nilai yang lebih kecil
            }
		}
		
		tempHargaGram = c.hargaGram[i];		//untuk menyimpan sementara dari nilai c.hargaGram[i]
		c.hargaGram[i] = c.hargaGram[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		c.hargaGram[indeks] = tempHargaGram;	//menukar nilai dari nilai yang ditukar di atas

        tempBerat = c.berat[i];
        c.berat[i] = c.berat[indeks];
        c.berat[indeks] = tempBerat;

        tempHarga = c.harga[i];
        c.harga[i] = c.harga[indeks];
        c.harga[indeks] = tempHarga;

        strcpy(tempStatus, c.status[i]);
        strcpy(c.status[i], c.status[indeks]);
        strcpy(c.status[indeks], tempStatus);

		strcpy(tempNama, c.nama[i]);
		strcpy(c.nama[i], c.nama[indeks]);
		strcpy(c.nama[indeks], tempNama);
	}

    return c;
    
}

int binarySearch(int i, int j, int bilCari, kurma c){
    int k;
    int ketemu = 0;

    while(ketemu == 0 && i<= j){
        k = (int) (i+j) / 2;

        if(c.hargaGram[k] == bilCari){
            ketemu = 1;
            c.ketemu = k;
        }else{
            if(c.hargaGram[k] < bilCari){
                j = k - 1;
            }else{
                i = k + 1;
            }
        }
    }

    if(ketemu != 1){
        c.ketemu = -1;
    }

    return c.ketemu;
}

void tampil(int n, kurma c){
    int status1;

    if(c.ketemu == -1){
        printf("tidak ditemukan\n");
    }else{

        if(strcmp(c.status[c.ketemu], "standar") == 0){
            status1 = 0;
        }else{
            status1 = 1;
        }

        printf("nama kurma: %s\n", c.nama[c.ketemu]);
        printf("berat: %d gram\n", c.berat[c.ketemu]);
        printf("harga: %d\n", c.harga[c.ketemu]);
        printf("harga per berat: %d\n", c.hargaGram[c.ketemu]);
        printf("status premium: ");
        if(status1 == 0){
            printf("tidak\n");
        }else{
            printf("ya\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int i,j;

    kurma a;

    for(i=0; i<n; i++){
        scanf("%s %d %d %s", &a.nama[i], &a.berat[i], &a.harga[i], &a.status[i]);
    }

    scanf("%d", &a.cariHargaGram);

    kurma b = tempHargaGram(n, a);
    kurma c = selection(n, b, a);
    c.ketemu = binarySearch(0, n-1, a.cariHargaGram, c);

    for(i=0 ; i<n; i++){
        printf("%d %d %d %s %s\n", c.berat[i], c.harga[i], c.hargaGram[i], c.nama[i], c.status[i]);
    } 
    tampil(n, c);

    return 0;
}
