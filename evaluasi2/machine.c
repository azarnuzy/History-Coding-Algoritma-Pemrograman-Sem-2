#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
void STARTKATA(char pita[]){       
    indeks = 0;         //memulai indeks dengan nilai 0
    panjangKata = 0;    //memulai panjang kata dengan nilai 0
    while(pita[indeks] == ' '){     //membuat perulangan jika terdapat spasi pada kalimat
        indeks++;       //nilai indeks akan selalu bertambah seiring adanya spasi
    }

    while((pita[indeks] != ' ') && (pita[indeks] != ';')) { //membuat perulangan untuk menelusuri huruf dalam sebuah kata
        ckata[panjangKata] = pita[indeks];  //memasukan kata ke variabel ckata dari kalimat
        indeks++;           //nilai indeks naik agar dapat berpindah ke huruf berikutnya
        panjangKata++;      //nilai panjang kata naik agar dapat mengisi tempat berikutnya
    }

    ckata[panjangKata] = '\0';  //nilai dari akhir ckata adalah \0 

}

void RESETKATA() {              
    panjangKata = 0;            //menjadikan panjang kata menjadi 0
    ckata[panjangKata] = '\0';  //membuat nilai ckata menjadi \0 artinya bahwa nilai tersebut kosong
}

int EOPKATA(char pita[]) {      
    if(pita[indeks] == ';') {   //membuat kondisi jika bertemu dengan titik sebagai akhir dari kalimat
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
    
    while((pita[indeks] != ' ') && (pita[indeks] != ';')){  //membuat perulangan untuk menelusuri setiap huruf dalam sebuah kata
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

void insertData(char pita[], transportasi *data) {  
    int countLen = 0;   //sebagai penghitung untuk menentukan query yang akan dimasukan
    STARTKATA(pita);    //memulai query dan dapat kata awal

    while(EOPKATA(pita) == 0){  //kondisi akhir dari query ";"
        if((strcmp(GETCKATA(), "INSERT") != 0)) {   //kondisi jika kata pada query != insert
            if(countLen == 0) {         //kondisi untuk id
                strcpy(data->id, GETCKATA());
            }else if(countLen == 1){    //kondisi untuk nama
                strcpy(data->nama, GETCKATA());
            }
            countLen++;
        }
        //menggeser kata pada query
        INCKATA(pita);
    }
    //kondisi untuk kelas
    strcpy(data->kelas, GETCKATA());
}

int sequentialSearch(int indeksData,char atribut[], char cariKata[], transportasi data[]){
    int i=0;
    int ketemu = 0; //nilai awal untuk dijadikan sebagai pengecekan
    while(i < indeksData){       //kondisi untuk perulangan 
        ketemu = 0;
        if(strcmp(atribut, "id") == 0){    
            if(strcmp(data[i].id, cariKata) == 0){    //kondisi disaat nilai yang dicari ketemu
                ketemu = 1;

            }
        }else if(strcmp(atribut, "kelas") == 0) {
            if(strcmp(data[i].kelas, cariKata) == 0){    //kondisi disaat nilai yang dicari ketemu
                ketemu = 1;
            }  
        }else{
            if(strcmp(data[i].nama, cariKata) == 0){    //kondisi disaat nilai yang dicari ketemu
                ketemu = 1;
            }
        }
        //kondisi jika nilai ketemu maka akan disalin ke type struct kereta hasil
        if(ketemu == 1){
            strcpy(keretahasil[indeksKereta].id, data[i].id);
            strcpy(keretahasil[indeksKereta].nama, data[i].nama);
            strcpy(keretahasil[indeksKereta].kelas, data[i].kelas);
            indeksKereta++;
        }
        i++;
    }
}

void getMaxLen(transportasi data[], int indeksData) {
    //membuat nilai maks awal = 0

    //perulangan untuk mencari nilai maksimal yang ada pada tipe struct 
    for(int i=0; i<indeksData; i++) {
        //kondisi untuk panjang judul id
        if(judul1 < strlen(data[i].id)) {
            judul1 = strlen(data[i].id);       
        }
        //kondisi untuk panjang judul nama
        if(judul2 < strlen(data[i].nama)) {
            judul2 = strlen(data[i].nama);
        }
        //kondisi untuk panjang judul kelas
        if(judul3 < strlen(data[i].kelas)) {
            judul3 = strlen(data[i].kelas);
        }
    }
}

void stripTabel(int len) {
    int i;
    for(i=0; i<len+10; i++) {   //perulangan untuk strip pada tabel
        printf("=");
    }
    printf("\n");
}

void containtJudulTable(char jId[], char jNama[], char jKelas[]) {
    //berisi mengenai tampilan judul pada tabel
    printf("| ");
    containtTabel (judul1, jId);
    printf(" | ");
    containtTabel(judul2, jNama);
    printf(" | ");
    containtTabel(judul3, jKelas);
    printf(" |\n");
}

void containtTabel(int len, char containt[]) {
    //berisi mengenai tampilan data pada tabel
    printf("%s", containt);
    int i;
    for(i=0; i<len-strlen(containt); i++) { //perulangan untuk memberikan spasi pada kolom yang tersisa
        printf(" ");
    }
}

void tampilData(transportasi data[], int i) {
    //berisi untuk menapilkan data padatabel
    printf("| ");
    containtTabel(judul1, data[i].id);
    printf(" | ");
    containtTabel(judul2, data[i].nama);
    printf(" | ");
    containtTabel(judul3, data[i].kelas);
    printf(" |\n");
}

//prosedur untuk menampilkan data pada suatu file berupa tabel
void tampilTData(transportasi data[], int indeksData) {
    int i; 
    int maksLen = judul1 + judul2 + judul3; //sebagai panjang dari strip 
    printf("TABEL HASIL PENCARIAN\n");
    if(indeksData > 0){
        stripTabel(maksLen);    //strip sebagai atas tabel
        containtJudulTable("ID Kereta", "Nama Kereta", "Kelas"); //prosedur judul tabel
        stripTabel(maksLen);    //strip sebagai batas antar judul dan isi
        for(i=0; i<indeksData; i++) {   //perulangan untuk menampilkan data
            tampilData(data, i);
        }
        
        stripTabel(maksLen);    //strip sebagai bawah tabel
    }
    printf("%d data dalam tabel.\n", indeksData);
}
