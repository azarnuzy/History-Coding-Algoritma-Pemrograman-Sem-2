#include "header.h"

void startKata(char pita[]){
    indeks = 0;
    panjangKata = 0;

    while (pita[indeks] == ' ')
    {
        indeks++;
    }

    while(pita[indeks] != ' ' && eopKata(pita) == 0) {
        currentKata[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }

    currentKata[panjangKata] = '\0';
}

void resetKata() {
    panjangKata = 0;
    currentKata[panjangKata] = '\0';
}

void incKata(char pita[]){
    panjangKata = 0;
    while(pita[indeks] == ' ') {
        indeks++;
    }

    while (pita[indeks] != ' ' && eopKata(pita) == 0)
    {
        currentKata[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }

    currentKata[panjangKata] = '\0'; 
}

char *getCurrentKata() {
    return currentKata;
}

int getPanjangKata() {
    return panjangKata;
}

int eopKata(char pita[]) {
    if(pita[indeks] == ';'){
        return 1;
    }else{
        return 0;
    }
}

void insertData(char pita[], mahasiswa *data) {
    int countLen = 0;
    startKata(pita);

    while(eopKata(pita) == 0){
        if((strcmp(getCurrentKata(), "INSERT") != 0) && (strcmp(getCurrentKata(), "mahasiswa") != 0)) {
            if(countLen == 0) {
                strcpy(data->nim, getCurrentKata());
            }else if(countLen == 1){
                strcpy(data->nama, getCurrentKata());
            }
            countLen++;
        }

        incKata(pita);
    }

    strcpy(data->nilai, getCurrentKata());
}