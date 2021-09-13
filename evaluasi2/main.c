#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{
    char pita[300];     //sebagai variabel dari kalimat yang akan dibuat
    int cek = 1;        //untuk melakukan pengecekan pada query yang dimasukan
    int i = 0;          //iterator
    indeksKereta = 0;   //indeks pada hasil kereta
    transportasi kereta[100];   //tampungan dari semua query
    judul1 = 9, judul2 = 11, judul3 = 5;    //sebagai nilai awal dari panjang judul
    char temp1[100];    //sebagai tampungan untuk atribut
    char temp2[100];    //sebagai tampungan untuk nilai
    do {
        scanf(" %299[^\n]s", &pita);    //sebagai masukan dari kalimat 
        
        STARTKATA(pita);    //memulai query dan mendapatkan kata ke-1
        if(strcmp(GETCKATA(), "TAMPILKAN") == 0) {  //kondisi jika query tampilkan maka cek = 0 dan selesai
            cek = 0;
        }else if(strcmp(GETCKATA(), "CARI") == 0){  //kondisi jika query cari maka akan melakukan pencarian pada query yang telah ditulis sebelumnya
            INCKATA(pita);
            strcpy(temp1, GETCKATA());
            INCKATA(pita);
            strcpy(temp2, GETCKATA());
            sequentialSearch(i,temp1, temp2, kereta);
        }else{  //kondisi jika query insert
            insertData(pita, &kereta[i++]);
        }
    }while(cek == 1);

    getMaxLen(keretahasil, indeksKereta);   //mendapatkan panjang dari setiap atribut data
    tampilTData(keretahasil, indeksKereta); //menampilkan tabel data kereta
    return 0;
}
