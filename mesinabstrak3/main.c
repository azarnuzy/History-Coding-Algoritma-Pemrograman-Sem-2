#include "header.h"

int main(int argc, char const *argv[])
{
    int n,i;
    char pita[200];
    printf("Masukan banyak data:\n");
    scanf("%d", &n);

    mahasiswa datamhs[n];

    for(i=0; i<n; i++) {
        scanf(" %199[^\n]s", pita);
        insertData(pita, &datamhs[i]);
    }

    printf("Data Mahasiswa: \n");
    for(i=0; i<n; i++) {
        printf("%d. %s %s %s\n", i+1, datamhs[i].nim, datamhs[i].nama, datamhs[i].nilai);
    }
    return 0;
}
