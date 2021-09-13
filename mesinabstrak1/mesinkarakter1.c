#include "mesinkarakter1.h"

void START(char pita[]){
    indeks = 0;
    cc = pita[indeks];
}

void INC(char pita[]){
    indeks++;
    cc = pita[indeks];
}

int EOP() {
    if(cc == '.'){
        return 1;
    }else{
        return 0;
    }
}

void ADV(char pita[]){
    INC(pita);
    while(cc == ' ' && (EOP() == 0)) {
        INC(pita);
    }
}

char GETCC() {
    return cc;
}