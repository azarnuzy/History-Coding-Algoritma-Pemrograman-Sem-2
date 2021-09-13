#include <stdio.h>
#include <string.h>

/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP6 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

void insertion(int a,float n[], char s[][100], char m2);    //dibuat sebagai prosedur untuk pengurutan secara insertion
void selection(int a,float n[], char s[][100], char m2);    //dibuat sebagai prosedur untuk pengurutan secara selection
void bubbleSOrt(int a, float n[], char s[][100], char m2);  //dibuat sebagai prosedur untuk pengurutan secara bubblesort
void quickSort(int a, float n[], char s[][100], char m2, int kiri, int kanan);  //dibuat sebagai prosedur untuk pengurutan secara qiuck sort
void gabung(int a, float n1[], char s1[][100], int b, float n2[], char s2[][100], float hasilN[], char hasilS[][100],char m2);  //dibuat sebagai prosedur untuk menggabungkan array
void tampil(int n, float hasilN2[], char hasilS2[][100]);   //dibuat sebagai prosedur untuk menampilkan hasil 
void cariLagu(int n,int m, float n1[], char s1[][100], float hasilN2[], char hasilS2[][100]);   //dibuat sebagai prosedur untuk mencari lagu

