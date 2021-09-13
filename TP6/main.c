#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP6 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{
    int i,j;
    int a,b,c;
    float n1[100], n2[100], n3[100];				//sebagai nilai dari waktu putar
    char s1[100][100], s2[100][100], s3[100][100];	//sebagai nilai dari judul lagu
	//memasukan nilai
    scanf("%d", &a);
    for(i=0; i<a; i++){
        scanf("%f", &n1[i]);
		scanf("%s", &s1[i]);
    }
	//memasukan nilai
    scanf("%d", &b);
    for(i=0; i<b; i++){
        scanf("%f", &n2[i]);
		scanf("%s", &s2[i]);
    }
	//memasukan nilai
    scanf("%d", &c);
    for(i=0; i<c; i++){
        scanf("%f", &n3[i]);
		scanf("%s", &s3[i]);
    }
	//memasukan nilai
    char m1, m2;
    scanf(" %c %c", &m1, &m2);

	//memanggil prosedur sesuai dengan cara pengurutan
	if(m1 == 'i'){
		insertion(a, n1, s1, m2);
		insertion(b, n2, s2, m2);
		insertion(c, n3, s3, m2);
	}else if(m1 == 's'){
		selection(a, n1, s1, m2);
		selection(b, n2, s2, m2);
		selection(c, n3, s3, m2);
	}else if(m1 == 'b'){
		bubbleSOrt(a, n1, s1, m2);
		bubbleSOrt(b, n2, s2, m2);
		bubbleSOrt(c, n3, s3, m2);
	}else{
		quickSort(a,n1,s1,m2,0,a-1);
		quickSort(b,n2,s2,m2,0,b-1);
		quickSort(c,n3,s3,m2,0,c-1);
	} 
	//sebagai nilai untuk menampilkan hasil
	float hasilN1[100], hasilN2[100];
	char hasilS1[100][100], hasilS2[100][100];
	//memanggil prosedur gabung untuk menggabungkan nilai
	gabung(a,n1,s1,b,n2,s2,hasilN1, hasilS1,m2);
	gabung(a+b,hasilN1,hasilS1,c,n3,s3,hasilN2,hasilS2,m2);
	int nilaiTengah = (a+b+c)/2;

	if((a+b+c) % 2 == 1){
		nilaiTengah += 1;
	}
	//memanggil prosedur untuk menampilkan nilai
	tampil(a+b+c, hasilN2, hasilS2);
	cariLagu(nilaiTengah, a, n1,s1,hasilN2,hasilS2);
    return 0;
}
