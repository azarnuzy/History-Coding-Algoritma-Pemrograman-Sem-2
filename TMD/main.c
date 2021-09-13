#include "header.h"

int main(int argc, char const *argv[])
{
    int tampilan = 0;   //sebagai nilai untuk dapat keluar dari program
    char query[300];    //nilai dari query 
    tabel tanggota[100];    //tipe struct tabel anggota
    tabel tbuku[100];       //tipe struct tabel buku
    tabel tpinjam[100];     //tipe struct tabel pinjam
    
    system("cls");  //membersihkan tampilan pada console
    salinProgram(tanggota, tbuku, tpinjam);     //menyalin nilai yang ada pada FILE ke tipe struct tabel
    while(tampilan == 0){       //perulangan dengan kondisi tampilan 0
        welcome();  //sebagai pembuka dari program
        scanf(" %299[^\n]s", query);    //memasukan query

        if(checkQuery(query) == 0){     //kondisi untuk pengecekan dengan kondisi query yang salah
            errorAlert();
        }else{  //kondisi jika query telah memenuhi
            if(strcmp(query, "exit") == 0){ //kondisi jika query bertuliskan exit maka keluar program
                exitAlert();
                tampilan = 1;   //membuat nilai tampilan bernilai 1 untuk keluar dari program
            }else{      //kondisi untuk mengeksekosi query
                mainProgram(query,tanggota, tbuku, tpinjam);    //sebagai alur utama dari program 
                printf("\n");
            }
        }
    }
    return 0;
}
