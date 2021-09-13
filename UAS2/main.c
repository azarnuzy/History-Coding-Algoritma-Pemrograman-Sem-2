#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UAS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{
    char pita[300];     //sebagai variabel dari kalimat yang akan dibuat

    scanf(" %299[^\n]s", &pita);    //sebagai masukan dari kalimat 

    STARTKATA(pita);        //memanggil prosedur startkata untuk memulai program 
    if(GETPANJANGKATA() > 4) {      //kondisi jika panjang kata lebih dari empat
        CARIVOKAL(GETCKATA(pita));  //memanggil prosedur untuk mencari kata dengan spesifikasi yang sesuai 
    }

    while(EOPKATA(pita) == 0){      //perulangan dengan . sebagai akhir dari kata tersebut
        INCKATA(pita);              //kata akan terus bergeser pada setiap pengulangan terjadi 

        if(GETPANJANGKATA() > 4) {       //kondisi jika panjang kata lebih dari tiga huruf
            CARIVOKAL(GETCKATA(pita));  //memanggil prosedur untuk mencari kata dengan spesifikasi yang sesuai 
        }
    }
    
    TAMPIL();                            //menampilkan tampilan

    return 0;
}
