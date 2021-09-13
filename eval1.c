#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[100][100];
    int nilai1[100];
    int nilai2[100];
}mahasiswa;

mahasiswa selection(int n,mahasiswa in);
mahasiswa insertion(int n,mahasiswa in);
mahasiswa gabungTerurut(int n, mahasiswa in1, int m, mahasiswa in2);
void tampil(int n, mahasiswa out);

int main(int argc, char const *argv[])
{
    int n1,n2;
    mahasiswa in1, in2;
    int i;

    scanf("%d",&n1 );
    for(i=0; i<n1; i++){
        scanf("%s", &in1.nama[i]);
        scanf("%d %d", &in1.nilai1[i], &in1.nilai2[i]);
    }

    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%s", &in2.nama[i]);
        scanf("%d %d", &in2.nilai1[i], &in2.nilai2[i]);
    }


    in1 = insertion(n1, in1);
    in2 = insertion(n2, in2);
    
    mahasiswa out1;
    out1 = gabungTerurut(n1, in1, n2, in2);

    tampil(n1+n2, out1); 
    return 0;
}

mahasiswa insertion(int n, mahasiswa in){			//membuat prosedur untuk mengurutkan laporan dengan cara insertion
	int i,j;		//sebagai iterator
	//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempS[100];
    int tempA, tempB;
    mahasiswa b;

	for(i=0; i<n; i++){
		b.nilai1[i] = in.nilai1[i];
        b.nilai2[i] = in.nilai2[i];
		strcpy(b.nama[i], in.nama[i]);
	}

	

	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		//membuat penampungan sementara untuk nilai yang akan di bandingkan
        tempA = b.nilai1[i];
        tempB = b.nilai2[i];
		strcpy(tempS, b.nama[i]);
		j=i-1;
	
		while(tempS[0] < b.nama[j][0] && j >= 0){	
            //membuat perulangan dengan syarat jika nilai penampung lebih besar dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
			//nilai di depan akan menyimpan nilai sebelmnya 
            b.nilai1[j+1] = b.nilai1[j];
            b.nilai2[j+1] = b.nilai2[j];
			strcpy(b.nama[j+1], b.nama[j]);
			j--;
		}
						//menyimpan nilai dari tampungan sementara
        b.nilai1[j+1] = tempA;
        b.nilai2[j+1] = tempB;
		strcpy(b.nama[j+1], tempS);
	}

    return b;
}


void tampil(int n, mahasiswa out){
    int i;
    printf("================\n");
    for(i=0; i<n; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
    printf("================\n");
    for(i=0; i<n/2; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
    printf("================\n");
    for(i=n/2; i<n; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
}

mahasiswa gabungTerurut(int n, mahasiswa in1, int m, mahasiswa in2){
	int i=0, j=0, count=0, l=0, k=0;
    int cek = 0;
    mahasiswa c;
	while(i < n && j < m){
        k = 0;
		if(in1.nama[i][0] < in2.nama[j][0]){
            strcpy(c.nama[count],in1.nama[i] );
			c.nilai1[count] = in1.nilai1[i];
			c.nilai2[count] = in1.nilai2[i];
			i++;
			count++;
		}else if(in2.nama[j][0] < in1.nama[i][0]){
            strcpy(c.nama[count], in2.nama[j]);
			c.nilai1[count] = in2.nilai1[j];
			c.nilai2[count] = in2.nilai2[j];
			j++;
			count++;
		}else{
            while(in1.nama[i][k-1] == in2.nama[j][k-1] && cek == 0 && (k + i < n || k + j < m)){
                if(in1.nama[i][k] < in2.nama[j][k]){
                    strcpy(c.nama[count],in1.nama[i] );
                    c.nilai1[count] = in1.nilai1[i];
                    c.nilai2[count] = in1.nilai2[i];
                    cek = 1;
                    i++;
                    count++;
                }else if(in2.nama[j][k] < in1.nama[i][k]){
                    strcpy(c.nama[count], in2.nama[j]);
                    c.nilai1[count] = in2.nilai1[j];
                    c.nilai2[count] = in2.nilai2[j];
                    cek = 1;
                    j++;
                    count++;
                }
                k++;
            }
            if(cek == 0){
                strcpy(c.nama[count],in1.nama[i] );
                c.nilai1[count] = in1.nilai1[i];
                c.nilai2[count] = in1.nilai2[i];
                i++;
                count++;

                strcpy(c.nama[count], in2.nama[j]);
                c.nilai1[count] = in2.nilai1[j];
                c.nilai2[count] = in2.nilai2[j];
                j++;
                count++;
            }
		}
	}

	if(i < n){
		for(l=i; l<n; l++){
            strcpy(c.nama[count],in1.nama[l] );
			c.nilai1[count] = in1.nilai1[l];
			c.nilai2[count] = in1.nilai2[l];
			count++;
		}
	}

	if(j < m){
		for(l = j; l < m; l++){
            strcpy(c.nama[count], in2.nama[l]);
			c.nilai1[count] = in2.nilai1[l];
			c.nilai2[count] = in2.nilai2[l];
			count++;
		}
	}
    return c;
}

mahasiswa selection(int n,mahasiswa in){
	int i,j;
	int indeks;
	//seabagi tempat penampungan dari nilai yang akan di urutkan
    int tempA, tempB;
	char tempS[100];

    mahasiswa b;

	for(i=0; i<n; i++){
		b.nilai1[i] = in.nilai1[i];
        b.nilai2[i] = in.nilai2[i];
		strcpy(b.nama[i], in.nama[i]);
	}

	for(i=0; i<n-1; i++){	//membuat perulangan untuk mengurutkan nilai dengan cara selection
		indeks = i;

		for(j=i+1; j<n; j++){	
			if(b.nama[indeks][0] > b.nama[j][0]){ 			//sebagai pengkondisian untuk mencari nilai yang lebih kecil
				indeks = j;											//untuk menyimpan nilai dari inden2 nilai yang lebih kecil
			}
		}
		
        tempA = b.nilai1[i];		//untuk menyimpan sementara dari nilai b.nilai1[i]
		b.nilai1[i] = b.nilai1[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		b.nilai1[indeks] = tempA;	//menukar nilai dari nilai yang ditukar di atas

        tempB = b.nilai2[i];		//untuk menyimpan sementara dari nilai b.nilai2[i]
		b.nilai2[i] = b.nilai2[indeks];	//menyimpan nilai sesuai dengan yang telah diubah dari perulangan di atas
		b.nilai2[indeks] = tempB;	//menukar nilai dari nilai yang ditukar di atas

		strcpy(tempS, b.nama[i]);
		strcpy(b.nama[i], b.nama[indeks]);
		strcpy(b.nama[indeks], tempS);

	}

    return b;
}

