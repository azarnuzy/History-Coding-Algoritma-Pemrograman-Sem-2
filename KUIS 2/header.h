#include <stdio.h>
#include <string.h>

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi KUIS2 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

typedef struct {
    char nama[100][100];    //sebagai variabel untuk nama kurma
    int berat[100];         //sebagai varibael untuk berat kurma
    int harga[100];         //sebagai variabel untuk harga kurma
    char status[100][100];  //sebagai variabel untuk status kurma
    int cariHargaGram;      //sebagai variabel untuk harga per gram yang akan dicari
    int hargaGram[100];     //sebagai variabel untuk menampung harga per gram 
    int ketemu;             //sebagai variabel untuk nilai yang dicari apakah ketemu atau tidak ketemu
}kurma;

kurma tempHargaGram(int n, kurma a);                    //fungsi untuk menentukan dan menyimpan harga per gram 
kurma selection(int n,kurma b, kurma a);                //fungsi untuk sorting berdasarkan harga per gram dari besar ke kecil
int binarySearch(int i, int j, int bilCari, kurma c);   //fungsi untuk meencari nilai harga per gram yang diinginkan 
void tampil(int n, kurma c);                            //fungsi untuk menampilkan nilai berdasarkan soal