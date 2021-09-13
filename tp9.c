#include <stdio.h>
#include <string.h>

int indeks;
char cc;
void START(char pita[]);
void INC(char pita[]);
int EOP();
void ADV(char pita[]);
char GETCC();
void SHOW(int cek, char nama[]);

int main(int argc, char const *argv[])
{
    char nama[50];
    char pita[100];
    char temp1, temp2;
    int cek = 0;
    scanf("%s %99[^\n]s", &nama, &pita);
    START(pita);

    while(EOP() == 0 && cek == 0){
        temp1 = GETCC();
        INC(pita);
        temp2 = GETCC();
        INC(pita);

        if(EOP() == 0){
            if((temp1 == 'x') && (temp2 == 'c') && (GETCC() == 'v')){
                cek = 1;
            }

            if((temp1 == 'r') && (temp2 == 'a') && (GETCC() == 'r')){
                cek = 1;
            }

            if((temp1 == 'x') && (temp2 == 'a') && (GETCC() == 'r')){
                cek = 1;
            }
        }
    }

    SHOW(cek, nama);
    return 0;
}


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

void SHOW(int cek, char nama[]) {
    if(cek == 1){
        printf("%s adalah Agen Rahasia.\n", nama);
    }else{
        printf("%s adalah pegawai biasa.\n", nama);
    }
}