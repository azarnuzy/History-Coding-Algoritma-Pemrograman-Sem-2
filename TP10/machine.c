#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP10 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
void STARTKATA(char pita[]){       
    indeks = 0;         //memulai indeks dengan nilai 0
    panjangKata = 0;    //memulai panjang kata dengan nilai 0
    while(pita[indeks] == ' '){     //membuat perulangan jika terdapat spasi pada kalimat
        indeks++;       //nilai indeks akan selalu bertambah seiring adanya spasi
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '.')) { //membuat perulangan untuk menelusuri huruf dalam sebuah kata
        ckata[panjangKata] = pita[indeks];  //memasukan kata ke variabel ckata dari kalimat
        indeks++;           //nilai indeks naik agar dapat berpindah ke huruf berikutnya
        panjangKata++;      //nilai panjang kata naik agar dapat mengisi tempat berikutnya
    }

    ckata[panjangKata] = '\0';  //nilai dari akhir ckata adalah \0 

}

int hitungKata(char kata[], int panjangKata) {
    int i = 0;                  //membuat iterator i dengan nilai 0
    int jumlahKata = 0;         //membuat jumlah kata ascii menjadi 0
    while(kata[i] != '\0') {    //perulangan untuk menelusuri setiap huruf dalam sebuah kata
        jumlahKata += kata[i];  //membuat operasi untuk menjumlahkan huruf dalam kata
        i++;                    //nilai iterotor akan selalu naik
    }
    
    return jumlahKata;          //mengembalikan nilai dari jumlah kata
}   

void RESETKATA() {              
    panjangKata = 0;            //menjadikan panjang kata menjadi 0
    ckata[panjangKata] = '\0';  //membuat nilai ckata menjadi \0 artinya bahwa nilai tersebut kosong
}

int EOPKATA(char pita[]) {      
    if(pita[indeks] == '.') {   //membuat kondisi jika bertemu dengan titik sebagai akhir dari kalimat
        return 1;               //mengembalikan nilai 1
    }else{                      //kondisi jika kalimat belum berakhir
        return 0;               //mengembalikan nilai 0
    }
}

void INCKATA(char pita[]){
    panjangKata = 0;                //membuat nilai panjang kata menjadi 0
    while(pita[indeks] == ' ') {    //perulangan untuk menelusuri setiap spasi
        indeks++;                   //nilai indeks akan selalu bertambah
    }
    
    while((pita[indeks] != ' ') && (pita[indeks] != '.')){  //membuat perulangan untuk menelusuri setiap huruf dalam sebuah kata
        ckata[panjangKata] = pita[indeks];      //memasukan kata dari kalimat kedalam variabel ckata
        indeks++;       //nilai indeks akan selalu bertambah
        panjangKata++;  //nilai panjang kata akan selalu bertambah
    }

    ckata[panjangKata] = '\0';  //menjadikan nilai akhir dari ckata \0
}

char* GETCKATA() {
    return ckata;       //mengembalikan nilai dari ckata
}

int GETPANJANGKATA() {
    return panjangKata; //mengembalikan nilai dari panjang kata
}

void insertion(int a,char s[][100]){			//membuat prosedur untuk mengurutkan nilai dengan cara insertion
	int i,j, k;		//sebagai iterator
	char tempN;		//seabagi tempat penampungan dari nilai yang akan di urutkan
    char tempS[100];    //sebagai penampung dari kata

	for(i=1; i<a; i++){		//membuat perulangan untuk mengurutkan nilai dari yang terkecil
		tempN = s[i][0];		//membuat penampungan sementara untuk nilai yang akan di bandingkan
		strcpy(tempS, s[i]);    //membuat penampungan sementara untuk nilai kata 
		j=i-1;

			
		while((tempN < s[j][0]) && j >= 0){	//membuat perulangan dengan syarat jika nilai penampung lebih kecil dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
 
            s[j+1][0] = s[j][0];				//nilai di depan akan menyimpan nilai sebelmnya 
            strcpy(s[j+1], s[j]);
            j--;						
		}	

        if(tempN == s[j][0]) {
            k = 0;
            while(tempS[k] == s[j][k] && k < strlen(s[j])) {
                k++;
            }
            if(tempS[k] < s[j][k]){
                s[j+1][0] = s[j][0];				//nilai di depan akan menyimpan nilai sebelmnya 
                strcpy(s[j+1], s[j]);
                j--;
            }
        }
		s[j+1][0] = tempN;							//menyimpan nilai dari tampungan sementara
		strcpy(s[j+1], tempS);
	}
}