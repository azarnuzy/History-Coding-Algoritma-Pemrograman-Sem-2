#include "mesinkarakter2.h"

int main(int argc, char const *argv[])
{
    char pita[300];

    printf("masukkan pada kalimat pada pita\n");

    scanf("%299[^\n]s", &pita);

    STARTKATA(pita);

    if(GETPANJANGKATA() > 0 ){
        printf("%s\n",GETCKATA() );
    }

    while(EOPKATA(pita) == 0){
        INCKATA(pita);

        if(GETPANJANGKATA() > 0) {
            printf("%s\n", GETCKATA());
        }
    }
    return 0;
}
