#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[100][100];
    int jmlh[100];
    int nilai[100][100];
    float rata2[100];
}data;

data selection(int n,data masukan);
void binarySearch(int i, int j, data masukan, data urut, int indeks);
void sequentialSearch(int n,data masukan, data urut, int index);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int i,j;
    float max;
    data masukan;

    for(i=0; i<n; i++){

        int temp = 0;
        scanf("%s", &masukan.nama[i]);
        scanf("%d", &masukan.jmlh[i]);

        for(j=0; j<masukan.jmlh[i]; j++){
            scanf("%d", &masukan.nilai[i][j]);
            temp += masukan.nilai[i][j];
        }

        masukan.rata2[i] = (float) temp / masukan.jmlh[i];
        max = masukan.rata2[0];

        if(max < masukan.rata2[i]){
            max = masukan.rata2[i];
        }
    }

    int inx; 
    scanf("%d", &inx);

    data urut;
    urut = selection(n, masukan);

    for(i=0; i<n; i++){
        printf("%s\n", urut.nama[i]);
    }
    printf("\n");

    if(max == urut.rata2[n-1]){
        binarySearch(0, n-1, masukan, urut, inx);
    }else{
        sequentialSearch(n, masukan, urut, inx);
    }
    return 0;
}


void binarySearch(int i, int j, data masukan, data urut, int indeks){
    int k;
    int ketemu = 0;

    while(ketemu == 0 && i<= j){
        k = (int) (i+j) / 2;
        if(strcmp(masukan.nama[k], urut.nama[indeks]) == 0){
            printf("Yang Diminta : %s\n", masukan.nama[k]);
            ketemu = 1;
        }else{
            if(masukan.nama[k] > urut.nama[indeks]){
                j = k - 1;
            }else{
                i = k + 1;
            }
        }
    }
} 

void sequentialSearch(int n,data masukan, data urut, int indeks){
    int i=0;
    int ketemu = 0;
    while(i < n && ketemu == 0){
        if(strcmp(masukan.nama[i], urut.nama[indeks]) == 0){
            printf("Yang Diminta : %s\n", masukan.nama[i]);
            ketemu = 1;
        }else {
            i++;
        }
    }
}
data selection(int n,data masukan){
	int i,j;
	int indeks;
	float tempN;				//seabagi tempat penampungan dari nilai yang akan di urutkan
	char tempS[100];

    data urut;

    for(i=0; i<n; i++){
        urut.rata2[i] = masukan.rata2[i];
        strcpy(urut.nama[i], masukan.nama[i]);
    }

	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
            if(urut.rata2[indeks] > urut.rata2[j]){	//sebagai pengkondisian untuk mencari nilai yang lebih besar
                indeks = j;						            //untuk menyimpan nilai dari inden2 nilai yang lebih kecil
            }
		}
		
		tempN = urut.rata2[i];		//untuk menyimpan sementara dari nilai urut.rata2[i]
		urut.rata2[i] = urut.rata2[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		urut.rata2[indeks] = tempN;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, urut.nama[i]);
		strcpy(urut.nama[i], urut.nama[indeks]);
		strcpy(urut.nama[indeks], tempS);
	}

    return urut;
    
}
