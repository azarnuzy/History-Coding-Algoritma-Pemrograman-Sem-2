#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP10 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{
    char pita[300];     //sebagai variabel dari kalimat yang akan dibuat

    scanf(" %299[^\n]s", &pita);    //sebagai masukan dari kalimat 

    STARTKATA(pita);        //memanggil prosedur startkata untuk memulai program 
    if(hitungKata(ckata, panjangKata) % 2 == 0){        //sebagi kondisi jika jumlah kata ascii adalah genap
        strcpy(kataBaku[indeksBaku++], GETCKATA());     //mendapatkan kata baku
    }else{                                              //sebagai kondisi juka jumlah kata ascii adlaah ganjil
        strcpy(kataTidakBaku[indeksTidakBaku++], GETCKATA());   //medapatkan kata tidak baku
    }

    while(EOPKATA(pita) == 0){      //perulangan untuk menelusuri setiap kata dalam kalimat
        INCKATA(pita);              //fungsi untuk mendapatkan kata dari kalimat

        if(GETPANJANGKATA() > 0) {  //kondisi jika terdapat kata di dalam kalimat
            if(hitungKata(ckata, panjangKata) % 2 == 0){    //sebagi kondisi jika jumlah kata ascii adalah genap
                strcpy(kataBaku[indeksBaku++], GETCKATA()); //mendapatkan kata baku
            }else{                                          //sebagai kondisi juka jumlah kata ascii adlaah ganjil
                strcpy(kataTidakBaku[indeksTidakBaku++], GETCKATA());   //medapatkan kata tidak baku
            }
        }
    }

    printf("KATA BAKU:\n");
    if(indeksBaku > 0){                     //sebagai kondisi jika terdapat kata baku 
        insertion(indeksBaku, kataBaku);    //mengurutkan kata baku berdasarkan abjad
        for(int i=0; i<indeksBaku; i++){    //pengulangan untuk menampilkan keluaran kata baku
            printf("%s\n", kataBaku[i]);    
        }
    }else{                                  //sebagai kondisi jika tidak terdapat kata baku
        printf("TIDAK ADA.\n");
    }

    printf("\nKATA NON BAKU:\n");
    if(indeksTidakBaku > 0){                        //sebagai kondisi jika terdapat kata tidak baku 
        insertion(indeksTidakBaku, kataTidakBaku);  //mengurutkan kata tidak baku berdasarkan abjad
        for(int i=0; i<indeksTidakBaku; i++) {      //pengulangan untuk menampilkan keluaran kata tidak baku
            printf("%s\n", kataTidakBaku[i]);
        }
    }else{                      //sebagai kondisi jika tidak terdapat kata tidak baku
        printf("TIDAK ADA.\n");
    }

    return 0;
}
