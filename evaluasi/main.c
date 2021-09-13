#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(int argc, char const *argv[])
{   
    /* 
    **  n1,n2 sebagai variabel dari kelompok 1 dan 2
    **  in1, in2 sebagai tipe data terstruktur untuk kelompok 1 dan kelompok 2
    */
    int n1,n2;
    mahasiswa in1, in2;
    int i;
    //memanggil masukan untuk kelompok 1
    scanf("%d",&n1 );
    for(i=0; i<n1; i++){
        scanf("%s", &in1.nama[i]);
        scanf("%d %d", &in1.nilai1[i], &in1.nilai2[i]);
    }
    //memanggil masukan untuk kelompok 2
    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%s", &in2.nama[i]);
        scanf("%d %d", &in2.nilai1[i], &in2.nilai2[i]);
    }

    //mengembalikan nilai dari fungsi pengurutan kepada in1 dan in2
    in1 = insertion(n1, in1);
    in2 = insertion(n2, in2);

    //  out1 sebagai variabel untuk gabungan 
    mahasiswa out1;

    //mengembalikan nilai dari fungsi gabungan ke out1
    out1 = gabungTerurut(n1, in1, n2, in2);
    
    //prosedur menampilkan nilai
    tampil(n1+n2, out1); 
    return 0;
}