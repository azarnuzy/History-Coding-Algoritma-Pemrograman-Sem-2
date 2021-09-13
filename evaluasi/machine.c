#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi evaluasi 1 Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
mahasiswa insertion(int n, mahasiswa in){			//membuat prosedur untuk mengurutkan nilai dengan cara insertion
	int i,j;     //sebagai iterator
	 //seabagi tempat penampungan dari nilai yang akan di urutkan
     /* 
     **  tempS sebagai penampung nama
     **  tempA sebagai penampung nilai1
     **  tempB sebagai penampung nilai2
     **  mahasiswa b sebagai variabel untuk dijadikan nilai dan dapat dikembalikan 
      */
    char tempS[100];
    int tempA, tempB;
    mahasiswa b;
    
    //membuat pengulangan untuk menduplikat nilai dari nilai awal ke nilai b
	for(i=0; i<n; i++){
		b.nilai1[i] = in.nilai1[i];
        b.nilai2[i] = in.nilai2[i];
		strcpy(b.nama[i], in.nama[i]);
	}

	

	for(i=1; i<n; i++){		//membuat perulangan untuk mengurutkan nilai 
		//membuat penampungan sementara untuk nilai yang akan di bandingkan
        tempA = b.nilai1[i];
        tempB = b.nilai2[i];
		strcpy(tempS, b.nama[i]);
		j=i-1;
	
		while(tempS[0] < b.nama[j][0] && j >= 0){	
            //membuat perulangan dengan syarat jika nilai penampung lebih kecil dari nilai yang dibandingkan maka akan masuk dalam perulangan tersebut
			//nilai di depan akan menyimpan nilai sebelmnya 
            b.nilai1[j+1] = b.nilai1[j];
            b.nilai2[j+1] = b.nilai2[j];
			strcpy(b.nama[j+1], b.nama[j]);
			j--;
		}
		//menyimpan nilai dari tampungan sementara
        b.nilai1[j+1] = tempA;
        b.nilai2[j+1] = tempB;
		strcpy(b.nama[j+1], tempS);
	}

    return b;
}

void tampil(int n, mahasiswa out){
    int i;
    printf("================\n");
    //sebagai keluaran dari nilai gabungan
    for(i=0; i<n; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
    printf("================\n");
    //sebagai keluaran dari nilai awal gabungan 
    for(i=0; i<n/2; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
    printf("================\n");
    //sebagai keluaran dari nilai akhir gabungan 
    for(i=n/2; i<n; i++){
        printf("%s %d %d\n", out.nama[i], out.nilai1[i], out.nilai2[i]);
    }
}

mahasiswa gabungTerurut(int n, mahasiswa in1, int m, mahasiswa in2){
    /* 
    ** i,j,k,l, dan count sebagai iterator dari nilai2 
    **  cek sebagai keluaran jika terdapat huruf awal yang sama
    **  mahasiswa c sebagai tempat tampungan dan dapat dikembalikan nilainya
     */
	int i=0, j=0, count=0, l=0, k=0;
    int cek = 0;
    mahasiswa c;
    //perulangan untuk menggabungkan kelompok 1 dan kelompok 2
	while(i < n && j < m){
        //k dijadikan 0 untuk membandingkan jika terdapat huruf yang sama, k sebagai iterator
        k = 0;
        /* 
        1. syarat pertama jika kel1 < kel2, maka di masukan nilai kel1
        2. syarat kedua jika kel2 < kel1, maka di masukan nilai kel2
        3. syarat ketiga jika ditemukan huruf yang sama maka akan terus bergeser sampai ke huruf 
           yang berbeda
         */

        /* 
        ** dilakukan pemasukan nama, nila1, nilai2 ke 'c'
        ** jika kel1 dimasukan maka iterator i akan bertambah
        ** jika kel2 dimasukan maka iterator j akan bertambah
         */
		if(in1.nama[i][0] < in2.nama[j][0]){    
            strcpy(c.nama[count],in1.nama[i] );
			c.nilai1[count] = in1.nilai1[i];
			c.nilai2[count] = in1.nilai2[i];
			i++;
			count++;
		}else if(in2.nama[j][0] < in1.nama[i][0]){
            strcpy(c.nama[count], in2.nama[j]);
			c.nilai1[count] = in2.nilai1[j];
			c.nilai2[count] = in2.nilai2[j];
			j++;
			count++;
		}else{
            //membuat perulangan untuk menemukan huruf yang berbeda dan dibandingkan
            while(in1.nama[i][k-1] == in2.nama[j][k-1] && cek == 0 && (k + i < n || k + j < m)){
                if(in1.nama[i][k] < in2.nama[j][k]){
                    strcpy(c.nama[count],in1.nama[i] );
                    c.nilai1[count] = in1.nilai1[i];
                    c.nilai2[count] = in1.nilai2[i];
                    cek = 1;
                    i++;
                    count++;
                }else if(in2.nama[j][k] < in1.nama[i][k]){
                    strcpy(c.nama[count], in2.nama[j]);
                    c.nilai1[count] = in2.nilai1[j];
                    c.nilai2[count] = in2.nilai2[j];
                    cek = 1;
                    j++;
                    count++;
                }
                k++;
            }
            if(cek == 0){
                strcpy(c.nama[count],in1.nama[i] );
                c.nilai1[count] = in1.nilai1[i];
                c.nilai2[count] = in1.nilai2[i];
                i++;
                count++;

                strcpy(c.nama[count], in2.nama[j]);
                c.nilai1[count] = in2.nilai1[j];
                c.nilai2[count] = in2.nilai2[j];
                j++;
                count++;
            }
		}
	}

    //jika masih ada sisa dari salah satu kelompok maka dimasukan sisanya
	if(i < n){
		for(l=i; l<n; l++){
            strcpy(c.nama[count],in1.nama[l] );
			c.nilai1[count] = in1.nilai1[l];
			c.nilai2[count] = in1.nilai2[l];
			count++;
		}
	}

	if(j < m){
		for(l = j; l < m; l++){
            strcpy(c.nama[count], in2.nama[l]);
			c.nilai1[count] = in2.nilai1[l];
			c.nilai2[count] = in2.nilai2[l];
			count++;
		}
	}
    return c;
}