#include <stdio.h>
#include <string.h>

typedef struct {
    char judulFilm[100][100];
    char id_s[100][100];
    char id_g[100][100];
    char id_b[100][100];
    char n_s[100][100];
    char n_g[100][100];
    char n_b[100][100];
}film;

film masukan(film subFilm){

} 

int main(int argc, char const *argv[])
{
    film list,genre, sutradara, bioskop, fullList;
    FILE *listFilm;
    FILE *Genre;
    FILE *Sutradara;
    FILE *Bioskop;
    FILE *FullList;
    int i = 0, j = 0, k = 0, l = 0, m = 0;

    listFilm = fopen("ListFilm.dat", "r");
    Genre = fopen("Genre.dat", "r");
    Sutradara = fopen("Sutradara.dat", "r");
    Bioskop = fopen("Bioskop.dat", "r");
    FullList = fopen("FullListName.dat", "w");

    fscanf(listFilm, "%s", list.judulFilm[i]);
    while(strcmp(list.judulFilm[i], "####") != 0 ){
        fscanf(listFilm, "%s %s %s %s", list.id_s[i], list.id_g[i], list.id_b[i], list.judulFilm[i+1]);
        i++;
    }

    fscanf(Genre, "%s", genre.id_g[j]);
    while(strcmp(genre.id_g[j], "####") != 0 ){
        fscanf(Genre, "%s %s", genre.n_g[j], genre.id_g[j+1]);
        j++;
    }

    fscanf(Sutradara, "%s", sutradara.id_s[k]);
    while(strcmp(sutradara.id_s[k], "####") != 0 ){
        fscanf(Sutradara, "%s %s", sutradara.n_s[k], sutradara.id_s[k+1]);
        k++;
    }

    fscanf(Bioskop, "%s", bioskop.id_b[l]);
    while(strcmp(bioskop.id_b[l], "####") != 0 ){
        fscanf(Bioskop, "%s %s", bioskop.n_b[l], bioskop.id_b[l+1]);
        l++;
    }
    return 0;
}
