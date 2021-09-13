#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP8 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{
    film list, fullList;    //sebagai variabel dari tipe data terstruktur film 
    FILE *listFilm;         //sebagai tempat penampung sementara dari file listfilm 
    FILE *FullList;         //sebagai tempat penampung sementara dari file fulllist
    int i = 0;

    listFilm = fopen("ListFilm.dat", "r");  //membuka file list film dalam format r
    FullList = fopen("FullList.dat", "w");  //membuka file fulllist film dalam format w
    //mengambil nilai dari listfilm untuk disimpan di dalam tipe data list
    fscanf(listFilm, "%s %s %s %s", list.judulFilm[i], list.id_s[i], list.id_g[i], list.id_b[i]);
    //membuat perulangan untuk mencari nama dari setiap id sub film sampai ####
    while(strcmp(list.judulFilm[i], "####") != 0 ){
        fullList = searchIdSutradara(list.id_s[i], i);
        fullList = searchIdGenre(list.id_g[i], i);
        fullList = searchIdBioskop(list.id_b[i], i);
        i++;
        //mengambil nilai dari listfilm untuk disimpan di dalam tipe data list
        fscanf(listFilm, "%s %s %s %s", list.judulFilm[i], list.id_s[i], list.id_g[i], list.id_b[i]);
    }

    getMax(list, fullList, i);          //memanggil prosedur untuk mendapatkan nilai maksimal dari setiap  nam sub film
    tampilanDat(list,fullList,i );      //memanggil prosedur untuk menampilkan data pada file.dat
    tampilanConsole(list,fullList,i );  //memanggil prosedur untuk menampilkan data pada console

    fclose(listFilm);   //menutup file listfilm
    fclose(FullList);   //menutup file fulllist
    return 0;
}
