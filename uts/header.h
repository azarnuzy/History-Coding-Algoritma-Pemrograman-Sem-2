#include <stdio.h>
#include <string.h>
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
typedef struct{
    char makanan[100][100];
    char negara[100];
    int kalori[100];
    int berat[100];
    int harga[100];
	char hasilN1[100][100];
}dessert;

char hasilMak[100][100];
char hasilNeg[100][100];
int hasilKal[100];
int hasilBer[100];
int hasilHar[100];

void kalPerGram(int n, dessert a, float k[]);
void insertion(int n,dessert a, float k[]);
void selection(int n,dessert a ,float k[]);
void bubbleSOrt(int n, dessert a ,float k[]);
void quickSort(int n, dessert a, int kiri, int kanan,float k[]);
void gabung(int n,float k1[], int m, float k2[], dessert a, dessert b, dessert hasil, float k3[]);
void tampung(int n, dessert a);
void tampil(int n, float hasilK2[]);
void tampilNegara(int n, dessert a, float k[]);
