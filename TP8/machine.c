#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi TP8 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
//fungsi untuk mencari nama genre
film searchIdGenre(char idCari[], int itr){
    int i=0;
    FILE *Genre;                //tempat penampung sementara untuk file genre
    char id_g[100], n_g[100];   //tempat penampung sementara untuk id dan nama genre
    film genre;                 //variabel dari tipe data terstruktur berupa  genre

    Genre = fopen("Genre.dat", "r");    //membuka file Genre.dat dengan format read

    fscanf(Genre, "%s %s", id_g, n_g);  //mengambil nilai awal dari id dan nama genre 

    //membuat perulangan untuk mengambil nilai id genre dengan nilai id yang dicari
    while(strcmp(id_g, idCari) != 0 && strcmp(id_g, "####") != 0){
        i++;
        fscanf(Genre, "%s %s", id_g, n_g);
    }
    //membuat syarat jika nilai tidak ditemukan maka nilai dari nama genre = ####
    if(strcmp(id_g, idCari) != 0){
        strcpy(n_g, "####");  
    }
    
    fclose(Genre);                  //menutup file Genre
    strcpy(genre.n_g[itr], n_g);    //menyalin nilai dari tampungan nama genre sementara ke nilai tipe data genre
    return genre;                   //mengembalikan tipe data genre
}

film searchIdSutradara(char idCari[], int itr){
    int i = 0;
    FILE *Sutradara;            //tempat penampung sementara untuk file sutradara
    char id_s[100], n_s[100];   //tempat penampung sementara untuk id dan nama sutradara
    film sutradara;             //variabel dari tipe data terstruktur berupa  sutradara

    Sutradara = fopen("Sutradara.dat", "r");    //membuka file sutradara.dat dengan format read

    fscanf(Sutradara, "%s %s", id_s, n_s);      //mengambil nilai awal dari id dan nama sutradara 

    //membuat perulangan untuk mengambil nilai id sutradara dengan nilai id yang dicari
    while(strcmp(id_s, idCari) != 0 && strcmp(id_s, "####") != 0){
        i++;
        fscanf(Sutradara, "%s %s", id_s, n_s);
    }
    //membuat syarat jika nilai tidak ditemukan maka nilai dari nama sutradara = ####
    if(strcmp(id_s, idCari) != 0){
        strcpy(n_s, "####");
    }

    fclose(Sutradara);                  //menutup file sutradara
    strcpy(sutradara.n_s[itr], n_s);    //menyalin nilai dari tampungan nama sutradara sementara ke nilai tipe data sutradara
    return sutradara;                   //mengembalikan tipe data sutradara
}


film searchIdBioskop(char idCari[], int itr){
    int i = 0;
    FILE *Bioskop;              //tempat penampung sementara untuk file bioskop
    char id_b[100], n_b[100];   //tempat penampung sementara untuk id dan nama bioskop
    film bioskop;               //variabel dari tipe data terstruktur berupa  bioskop

    Bioskop = fopen("Bioskop.dat", "r");    //membuka file bioskop.dat dengan format read

    fscanf(Bioskop, "%s %s", id_b, n_b);    //mengambil nilai awal dari id dan nama bioskop 

    //membuat perulangan untuk mengambil nilai id bioskop dengan nilai id yang dicari
    while(strcmp(id_b, idCari) != 0 && strcmp(id_b, "####") != 0){
        i++;
        fscanf(Bioskop, "%s %s", id_b, n_b);
    }
    //membuat syarat jika nilai tidak ditemukan maka nilai dari nama bioskop = ####
    if(strcmp(id_b, idCari) != 0){
        strcpy(n_b, "####");
    }

    fclose(Bioskop);                    //menutup file bioskop
    strcpy(bioskop.n_b[itr], n_b);      //menyalin nilai dari tampungan nama bioskop sementara ke nilai tipe data bioskop
    return bioskop;                     //mengembalikan tipe data bioskop
}

void getMax(film list, film fullList, int n){
    int i;
    maxJudul = strlen(list.judulFilm[0]);   //menyimpan nilai awal panjang judul
    maxSut = strlen(fullList.n_s[0]);       //menyimpan nilai awal panjang sutradara
    maxGen = strlen(fullList.n_g[0]);       //menyimpan nilai awal panjang genre
    maxBio = strlen(fullList.n_b[0]);       //menyimpan nilai awal panjang bioskop
    
    //perulangan untuk mendapatkan nilai judul berdasarkan banyaknya nilai pada lisfilm
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
    //menyimpan nilai dari semua nilai maximal
    maxTot = maxJudul + maxSut + maxGen + maxBio;
}

void tampilanDat(film list, film fullList, int n){
    int i,j;
    FILE *FullList;                             //tempat menampung sementara untuk file yang berisi full list dari film 
    FullList =  fopen("FullList.dat", "w");     //membuat file fulllist.dat dengan format w
    //membuat perulangan untuk menampilkan setiap sub film dari full dengan tampilan tabel
    for(i=0; i<n; i++){
        //setiap nilai dari tempJ adalah panjang dari setiap kolom pada tabel
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
    //membuat perulangan untuk tampilan setiap sub film pada console dalam bentuk tabel
    for(i=0; i<n; i++){
        //setiap nilai tempJ adalah batas dari setiap kolom pada tabel film 
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