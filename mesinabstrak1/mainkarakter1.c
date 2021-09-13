#include <stdio.h>
#include "mesinkarakter1.h"

int main(int argc, char const *argv[])
{
    char pita[50];
    printf("masukkan kalimat pada pita\n");
    scanf("%49[^\n]s", &pita);
    START(pita);

    while(EOP() == 0){
        printf("%c\n", GETCC());
        INC(pita);
    }

    return 0;
}
