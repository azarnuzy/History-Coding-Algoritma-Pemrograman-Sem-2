#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Saya M. Azar Nuzy mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
// Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak 
// melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

//tipe data terstruktur untuk menyimpan record dari 3 tabel
typedef struct {
    char id[10];       //-> nilai id/no
    char data1[20];    //-> nilai nama/judul 
    char data2[20];    //-> nilai kota/pengarang
    char data3[20];    //-> nilai jenis kelamin/jenis buku/tgl pinjam
    char data4[20];    //-> nilai no telp/tahun terbit/tgl kembali
}tabel;
//tipe data terstruktur untuk menyimpan record dengan format 2 dimensi 
typedef struct {
    char id[100][10];      //-> nilai id/no
    char data1[100][20];   //-> nilai nama/judul 
    char data2[100][20];   //-> nilai kota/pengarang
    char data3[100][20];   //-> nilai jenis kelamin/jenis buku/tgl pinjam
    char data4[100][20];   //-> nilai no telp/tahun terbit/tgl kembali
}tabel2D;

//variabel global dari mesin kata
int indeks;             //-> nilai untuk menggeser setiap huruf pada query
int panjangKata;        //-> nilai untuk menentukan panjang kata setiap kata
char currentKata[20];  //-> nilai untuk menyimpan kata yang ada di posisi saat itu 

//variabel global dari indeks record tabel
int indeksAnggota;
int indeksBuku;
int indeksPinjam;
int indeksSearch;

//varibael global dari panjang kata pada setiap kolom record
int maksId, maksData1, maksData2, maksData3, maksData4; 

//prosedur/fungsi mesin kata
void startKata(char pita[]);    //-> memulai query
void resetKata();               //-> mereset nilai query
void incKata(char pita[]);      //-> menelusuri setiap kata pada query
char *getCurrentKata();         //-> mengembalikan kata yang ada di posisi saat itu    
int getPanjangKata();           //-> mendapatkan panjang dari kata
int eopKata(char pita[]);       //-> mendapatkan akhir dari query

//prosedur dari menu utama dari program 
void welcome();     //-> berisi mengenai pembuka dan versi dari program
void mainProgram(char query[], tabel tanggota[], tabel tbuku[], tabel tpinjam[]);   //-> menu utama yang berisi alur hampir keseluruhan program

//fungsi pengecekan
int DMLCheck(char perintah[]);          //-> pengecekan dari DML (Data Manipulation Languange) = INSERT, UPDATE, DELETE, SELECT
int tableCheck(char perintah[]);        //-> pengecekan tabel 
int checkQuery(char query[]);           //-> pengecekan query
int checkLenQuery(char query[]);        //-> pengecekan panjang kata pada query
int checkInsertUpdate(char query[]);    //-> pengecekan untuk DML INSERT UPDATE
int CheckError(char query[], int len);  //-> pengecekan untuk query yang tidak memiliki titik koma

//fungsi dan prosedur membaca dan menulis FILE
void salinData(tabel2D tempData, tabel *data, int indeksData);          //-> menyalin data dari tipe data tersturktur 2d menuju ke tipe data terstruktur biasa
void salinProgram(tabel tanggota[], tabel tbuku[], tabel tpinjam[]);    //-> menyalin data pada setiap tabel
tabel2D getAnggotaFile();   //-> mendapatkan nilai dari FILE anggota
tabel2D getBukuFile();      //-> mendapatkan nilai dari FILE buku
tabel2D getPinjamFile();    //-> mendapatkan nilai dari FILE pinjam

//fungsi dan prosedur proses DML (Data Manipulation Language)
int sequentialSearch(int indeksData, char idData[], tabel data[]);  //-> mencari id/no pada tabel
void DMLDelete(int indeksData, tabel data[]);                       //-> menghapus sebuah record pada tabel
void deleteData(tabel *data1, tabel *data2);                        //-> menghapus sebuah record pada tabel                                     

//prosedur untuk mendapatkan nilai tabel
void DMLData(char pita[], tabel *data, char table[], char DMLQuery[]);  //-> mendapatkan nilai dari query                 
void currentData(tabel data[], int indeksTabel, char namaFile[]);       //-> menulis nilai dari query ke FILE

//prosedur untuk menampilkan tabel
void tampilData(tabel data[], int i, int tabel);    //-> menampilkan tabel
void getMaxLen(tabel data[], int indeksData);       //-> mendapatkan panjang max dari setiap kolom
void judulTabel(char jId[], char jData1[], char jData2[], char jData3[], char jData4[]);  //-> menampilkan heading pada tabel  

//prosedur untuk menampilkan kondisi error
void dataExist();
void errorAlert();
void DatanotFoundAlert();
void tableNotFoundAlert();
void errorLenQuery(int row);
void exitAlert();

//prosedur untuk menampilkan seluruh tabel
void batasTabel();
void tampilTData(tabel data[], int indeksData);
void BatasSemuaTabel(tabel tbuku[], tabel tanggota[], tabel tpinjam[]);
void judulSemuaTabel(tabel tbuku[], tabel tanggota[], tabel tpinjam[]);
void batasTabelPinjam(int batas);
void getLenJudul(char jId[], char jData1[], char jData2[], char jData3[], char jData4[]);
int selectAllTable(char query[]);
void showAllTable(tabel tanggota[], tabel tbuku[], tabel tpinjam[]);
void stripTabel(int len);
void containtTabel(int len, char containt[]);
void containtJudulTable(char jId[], char jData1[], char jData2[], char jData3[], char jData4[], int tabel);
