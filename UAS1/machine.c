#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UAS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
void STARTKATA(char pita[]){       
    indeks = 0;                     //memulai indeks dengan nilai 0
    indeksSubKata = 0;
    panjangKata = 0;                //memulai panjang kata dengan nilai 0
    while(pita[indeks] == ' '){     //membuat perulangan jika terdapat spasi pada kalimat
        indeks++;                   //nilai indeks akan selalu bertambah seiring adanya spasi
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '.')) { //membuat perulangan untuk menelusuri huruf dalam sebuah kata
        ckata[panjangKata] = pita[indeks];                  //memasukan kata ke variabel ckata dari kalimat
        indeks++;                                           //nilai indeks naik agar dapat berpindah ke huruf berikutnya
        panjangKata++;                                      //nilai panjang kata naik agar dapat mengisi tempat berikutnya
    }

    ckata[panjangKata] = '\0';  //nilai dari akhir ckata adalah \0 
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
        ckata[panjangKata] = pita[indeks];                  //memasukan kata dari kalimat kedalam variabel ckata
        indeks++;                                           //nilai indeks akan selalu bertambah
        panjangKata++;                                      //nilai panjang kata akan selalu bertambah
    }

    ckata[panjangKata] = '\0';  //menjadikan nilai akhir dari ckata \0
}

char* GETCKATA() {
    return ckata;       //mengembalikan nilai dari ckata
}

int GETPANJANGKATA() {
    return panjangKata; //mengembalikan nilai dari panjang kata
}

int CHECKHURUF(char churuf) {
    if(churuf == 'a' || churuf == 'i' || churuf == 'u' || churuf == 'e' || churuf == 'o'){  //kondisi huruf vokal
        return 1;
    }else {         //kondisi huruf konsonan
        return 0;
    }
}

int CHECKSUBKATA(char kata[]) {
    if(strcmp(kata, "1001") == 0){  //kondisi untuk mengecek jika vokal konsonan konsonan vokal maka nilai dari kata = "1001"
        return 1;
    }

    return 0;
}

char* GETSUBKATA() {
    return subKata;                 //mengembalikan nilai dari subkata yang telah ditentukan dari prosedur cari vokal
}

void CARIVOKAL(char pita[]) {
    int i,j, k;                     //sebagai iterator
    int len = strlen(pita);         //sebagai nilai panjang dari setiap kata
    int leng = len - 4 + 1;         //sebagai panjang dari perulangan yang akan dilakukan 
    for(i=0; i<leng; i++) {         //perulangan untuk mencari subkata sesuai dengan spesifikasi 
        k=0;
        for(j=i; j<4+i; j++) {              
            if(CHECKHURUF(pita[j]) == 1){   //kondisi jika huruf vokal
                subKata[k++] = '1';
            }else {                         //kondisi jika huruf konsonan
                subKata[k++] = '0';
            }
        }

        if(CHECKSUBKATA(GETSUBKATA()) == 1){        //kondisi jika memenuhi spesifikasi
            k = 0;
            for(j=i; j<4+i; j++) {                  //perulangan untuk mendapatkan nilai dari subkata
                subKata[k++] = pita[j];
            }
            strcpy(subsKata[indeksSubKata], GETSUBKATA());      //menyalin subkata ke subskata
            indeksSubKata++;                                    //sebagai iterator untuk bertambahnya indeks pada subskata
            i += 3;                                             //bertambah 3 huruf ke depan agar huruf yang telah terpakai tidak dihitung
        }
    }
}



void TAMPIL() {
    int i;
    if(indeksSubKata > 0){                  //jika tidak ada satupun sub kata yang sesuai 
        for(i=0; i<indeksSubKata; i++) {
            printf("%s\n", subsKata[i]);    //menampilkan subkata
        }
    }
    printf("%d\n", indeksSubKata);          //menampilkan banyaknya subkata
}