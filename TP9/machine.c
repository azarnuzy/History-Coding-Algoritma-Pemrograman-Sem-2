#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP9 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//prosedur sebagai permulaan dari mesin pencari id
void START(char id[]){
    indeks = 0;         
    cc = id[indeks];    //membuat nilai karakter menjadi awal huruf dari id
}

//prosedur sebagai penambahan indeks dari id agen rahasia
void INC(char id[]){    
    indeks++;
    cc = id[indeks];    //membuat nilai karakter menjadi huruf sesuai dengan indeks
}

//prosedur untuk menemukan akhir dari id
int EOP() {
    if(cc == '.'){      //kondisi ketika berada di akhir kata akan mengembalikan nilai 1
        return 1;
    }else{              //kondisi ketika belum di akhir kata akan mengembalikan nilai 0
        return 0;
    }
}

//prosedur untuk menemukan spasi di dalam kalimat
void ADV(char id[]){
    INC(id);
    while(cc == ' ' && (EOP() == 0)) { //perulangan jika terdapat spasi di dalam kalimat maka akan terus berulang 
        INC(id);
    }
}

//fungsi untuk mengembalikan nilai dari karakter 
char GETCC() {
    return cc;
}
