#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char judulFilm[100][100];
    char id_s[100][100];
    char id_g[100][100];
    char id_b[100][100];
    char n_s[100][100];
    char n_g[100][100];
    char n_b[100][100];
}film;

int maxJudul;
int maxSut;
int maxGen;
int maxBio;
int maxTot;

film searchIdGenre(char idCari[], int itr){
    int i=0;
    FILE *Genre;
    char id_g[100], n_g[100];
    film genre;

    Genre = fopen("Genre.dat", "r");

    fscanf(Genre, "%s %s", id_g, n_g);  

    while(strcmp(id_g, idCari) != 0 && strcmp(id_g, "####") != 0){
        i++;
        fscanf(Genre, "%s %s", id_g, n_g);
    }

    if(strcmp(id_g, idCari) != 0){
        strcpy(n_g, "####");  
    }

    fclose(Genre);
    strcpy(genre.n_g[itr], n_g);
    return genre;
}

film searchIdSutradara(char idCari[], int itr){
    int i = 0;
    FILE *Sutradara;
    char id_s[100], n_s[100];
    film sutradara;

    Sutradara = fopen("Sutradara.dat", "r");

    fscanf(Sutradara, "%s %s", id_s, n_s);  

    while(strcmp(id_s, idCari) != 0 && strcmp(id_s, "####") != 0){
        i++;
        fscanf(Sutradara, "%s %s", id_s, n_s);
    }

    if(strcmp(id_s, idCari) != 0){
        strcpy(n_s, "####");
    }

    fclose(Sutradara);
    strcpy(sutradara.n_s[itr], n_s);
    return sutradara;
}


film searchIdBioskop(char idCari[], int itr){
    int i = 0;
    FILE *Bioskop;
    char id_b[100], n_b[100];
    film bioskop;

    Bioskop = fopen("Bioskop.dat", "r");

    fscanf(Bioskop, "%s %s", id_b, n_b);  

    while(strcmp(id_b, idCari) != 0 && strcmp(id_b, "####") != 0){
        i++;
        fscanf(Bioskop, "%s %s", id_b, n_b);
    }

    if(strcmp(id_b, idCari) != 0){
        strcpy(n_b, "####");
    }

    fclose(Bioskop);
    strcpy(bioskop.n_b[itr], n_b);
    return bioskop;
}

void getMax(film list, film fullList, int n){
    int i;
    maxJudul = strlen(list.judulFilm[0]);
    maxSut = strlen(fullList.n_s[0]);
    maxGen = strlen(fullList.n_g[0]);
    maxBio = strlen(fullList.n_b[0]);
    
    for(i=0; i<n; i++){
        if(maxJudul < strlen(list.judulFilm[i])){
            maxJudul = strlen(list.judulFilm[i]);
        }

        if(maxSut < strlen(fullList.n_s[i])){
            maxSut = strlen(fullList.n_s[i]);
        }

        if(maxGen < strlen(fullList.n_g[i])){
            maxGen = strlen(fullList.n_g[i]);
        }
        
        if(maxBio < strlen(fullList.n_b[i])){
            maxBio = strlen(fullList.n_b[i]);
        }
    }

    maxTot = maxJudul + maxSut + maxGen + maxBio;
}

void tampilanDat(film list, film fullList, int n){
    int i,j;
    FILE *FullList;
    FullList =  fopen("FullList.dat", "w");   

    for(i=0; i<n; i++){
        int tempJ;
        if(i == 0){
            for(j=0; j<maxTot + 14; j++){
                fprintf(FullList,"-");
            }
            fprintf(FullList,"\n");
            fprintf(FullList,"|");
            fprintf(FullList,"JUDUL FILM");
            if(maxJudul <= 10){
                maxJudul = 10;
            }
            tempJ = maxJudul - 10 + 3;
            for(j=0; j<tempJ; j++){
                fprintf(FullList," ");
            }
            fprintf(FullList,"SUTRADARA");
            if(maxSut <= 9){
                maxSut = 9;
            }
            tempJ = maxSut - 9 + 3;
            for(j=0; j<tempJ; j++){
                fprintf(FullList," ");
            }
            fprintf(FullList,"GENRE");
            if(maxGen <= 5 ){
                maxGen = 5;
            }
            tempJ = maxGen - 5 + 3;
            for(j=0; j<tempJ; j++){
                fprintf(FullList," ");
            }
            fprintf(FullList,"BIOSKOP");
            if(maxBio <= 8){
                maxBio = 8;
            }
            tempJ = maxBio - 7 + 3;
            for(j=0; j<tempJ; j++){
                fprintf(FullList," ");
            }
            fprintf(FullList,"|\n");
            for(j=0; j<maxTot + 14; j++){
                fprintf(FullList,"-");
            }
            fprintf(FullList,"\n");
        }
        fprintf(FullList,"|");
        tempJ = maxJudul - strlen(list.judulFilm[i]) + 3;
        fprintf(FullList,"%s", list.judulFilm[i]);
        for(j=0; j<tempJ; j++){
            fprintf(FullList," ");
        }

        tempJ = maxSut - strlen(fullList.n_s[i]) + 3;
        fprintf(FullList,"%s", fullList.n_s[i]);
        for(j=0; j<tempJ; j++){
            fprintf(FullList," ");
        }

        tempJ = maxGen - strlen(fullList.n_g[i]) + 3;
        fprintf(FullList,"%s", fullList.n_g[i]);
        for(j=0; j<tempJ; j++){
            fprintf(FullList," ");
        }

        tempJ = maxBio - strlen(fullList.n_b[i]) + 3;
        fprintf(FullList,"%s", fullList.n_b[i]);
        for(j=0; j<tempJ; j++){
            fprintf(FullList," ");
        }

        fprintf(FullList,"|\n");
        for(j=0; j<maxTot + 14; j++){
                fprintf(FullList,"-");
            }
            fprintf(FullList,"\n");
    }

    fclose(FullList);
}

void tampilanConsole(film list, film fullList, int n){
    int i,j;

    for(i=0; i<n; i++){
        int tempJ;
        if(i == 0){
            for(j=0; j<maxTot + 14; j++){
                printf("-");
            }
            printf("\n");
            printf("|");
            printf("JUDUL FILM");
            if(maxJudul <= 10){
                maxJudul = 10;
            }
            tempJ = maxJudul - 10 + 3;
            for(j=0; j<tempJ; j++){
                printf(" ");
            }
            printf("SUTRADARA");
            if(maxSut <= 9){
                maxSut = 9;
            }
            tempJ = maxSut - 9 + 3;
            for(j=0; j<tempJ; j++){
                printf(" ");
            }
            printf("GENRE");
            if(maxGen <= 5 ){
                maxGen = 5;
            }
            tempJ = maxGen - 5 + 3;
            for(j=0; j<tempJ; j++){
                printf(" ");
            }
            printf("BIOSKOP");
            if(maxBio <= 8){
                maxBio = 8;
            }
            tempJ = maxBio - 7 + 3;
            for(j=0; j<tempJ; j++){
                printf(" ");
            }
            printf("|\n");
            for(j=0; j<maxTot + 14; j++){
                printf("-");
            }
            printf("\n");
        }
        printf("|");
        tempJ = maxJudul - strlen(list.judulFilm[i]) + 3;
        printf("%s", list.judulFilm[i]);
        for(j=0; j<tempJ; j++){
            printf(" ");
        }

        tempJ = maxSut - strlen(fullList.n_s[i]) + 3;
        printf("%s", fullList.n_s[i]);
        for(j=0; j<tempJ; j++){
            printf(" ");
        }

        tempJ = maxGen - strlen(fullList.n_g[i]) + 3;
        printf("%s", fullList.n_g[i]);
        for(j=0; j<tempJ; j++){
            printf(" ");
        }

        tempJ = maxBio - strlen(fullList.n_b[i]) + 3;
        printf("%s", fullList.n_b[i]);
        for(j=0; j<tempJ; j++){
            printf(" ");
        }

        printf("|\n");
        for(j=0; j<maxTot + 14; j++){
                printf("-");
            }
            printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    film list, fullList;
    FILE *listFilm;
    FILE *FullList;
    int i = 0;

    listFilm = fopen("ListFilm.dat", "r");
    FullList = fopen("FullList.dat", "w");
    fscanf(listFilm, "%s %s %s %s", list.judulFilm[i], list.id_s[i], list.id_g[i], list.id_b[i]);

    while(strcmp(list.judulFilm[i], "####") != 0 ){
        fullList = searchIdSutradara(list.id_s[i], i);
        fullList = searchIdGenre(list.id_g[i], i);
        fullList = searchIdBioskop(list.id_b[i], i);
        i++;
        fscanf(listFilm, "%s %s %s %s", list.judulFilm[i], list.id_s[i], list.id_g[i], list.id_b[i]);
    }

    getMax(list, fullList, i);
    tampilanDat(list,fullList,i );
    tampilanConsole(list,fullList,i );

    fclose(listFilm);
    fclose(FullList);
    return 0;
}
