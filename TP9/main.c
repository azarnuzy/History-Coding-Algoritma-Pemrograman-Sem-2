#include "header.h"

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP9 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

int main(int argc, char const *argv[])
{   
    char nama[50];                      //sebagai variabel untuk nama 
    char id[100];                       //sebagai variabel untuk id 
    scanf("%s %99[^\n]s", &nama, &id);  //membuat masukan untuk memanggil nama dan id 
    START(id);                          //memanggil prosedur start untuk memulai program
    int cek = 0;                        //sebagai variabel untuk melakukan pengecekan

    while(EOP() == 0 && cek == 0){      //sebagai perulangan untuk menemukan suku kata xcv, rar, tau xar
        char temp1 = GETCC();           //sebagai variabel untuk menampung nilai huruf id dan dijadikan sebagai huruf awal dari suku yang dicari
        INC(id);                        //memanggil prosedur untuk menambah indeks pada id

        if(temp1 == 'r' || temp1 == 'x'){   //kondisi jika huruf pada id adalah r atau x maka akan lanjut
            char temp2 = GETCC();       //sebagai variabel untuk menampung nilai huruf id dan dijadikan sebagai huruf awal dari suku yang dicari
            INC(id);                   //memanggil prosedur untuk menambah indeks pada id

            //kondisi untuk suku kata xcv
            if((temp1 == 'x') && (temp2 == 'c') && (GETCC() == 'v')){
                cek = 1;
            }

            //kondisi untuk suku kata rar
            if((temp1 == 'r') && (temp2 == 'a') && (GETCC() == 'r')){
                cek = 1;
            }

            //kondisi untuk suku kata xar
            if((temp1 == 'x') && (temp2 == 'a') && (GETCC() == 'r')){
                cek = 1;
            }
        }

    }

    //kondisi jika suku yang idcari ditemukan
    if(cek == 1){
        printf("%s adalah Agen Rahasia.\n", nama);
    }else{  //kondisi jika suku yang dicari tidak ditemukan
        printf("%s adalah pegawai biasa.\n", nama);
    }
    return 0;
}