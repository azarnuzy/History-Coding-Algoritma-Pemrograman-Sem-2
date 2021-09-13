#include "mesinkarakter2.h"

void STARTKATA(char pita[]){
    indeks = 0;
    panjangKata = 0;

    while(pita[indeks] == ' '){
        indeks++;
    }

    while((pita[indeks] != ' ') && (pita[indeks] != '.')) {
        ckata[panjangKata] = pita[indeks];
        printf("%c", ckata[panjangKata]);
        indeks++;
        panjangKata++;
    }

    ckata[panjangKata] = '\0';
}

void RESETKATA() {
    panjangKata = 0;
    ckata[panjangKata] = '\0';
}

int EOPKATA(char pita[]) {
    if(pita[indeks] == '.') {
        return 1;
    }else{
        return 0;
    }
}

void INCKATA(char pita[]){
    panjangKata = 0;
    while(pita[indeks] == ' ') {
        indeks++;
    }
    
    while((pita[indeks] != ' ') && (pita[indeks] != '.')){
        ckata[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }

    ckata[panjangKata] = '\0';
}

char* GETCKATA() {
    return ckata;
}

int GETPANJANGKATA() {
    return panjangKata;
}