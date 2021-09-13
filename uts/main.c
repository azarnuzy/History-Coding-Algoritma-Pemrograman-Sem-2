#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS Alpro2 2021 C1 dalam 
mata kuliah Algoritma dan Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main(){
    int i;
    dessert a,b,c;
    int n1,n2,n3;
    char m[100];
    scanf("%s", m);

    scanf("%s", &a.negara);
    scanf("%d", &n1);
    for(i=0; i<n1; i++){
        scanf("%s", &a.makanan[i]);
        scanf("%d %d %d", &a.kalori[i], &a.berat[i], &a.harga[i]);
    }

    scanf("%s", &b.negara);
    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%s", &b.makanan[i]);
        scanf("%d %d %d", &b.kalori[i], &b.berat[i], &b.harga[i]);
    }

    scanf("%s", &c.negara);
    scanf("%d", &n3);
    for(i=0; i<n3; i++){
        scanf("%s", &c.makanan[i]);
        scanf("%d %d %d", &c.kalori[i], &c.berat[i], &c.harga[i]);
    }

    float k1[100], k2[100], k3[100];
    float hasilK1[100], hasilK2[100];
	dessert hasil1, hasil2;

    kalPerGram(n1, a, k1);
    kalPerGram(n2, b, k2);
    kalPerGram(n3, c, k3);

    printf("Per Negara:\n");
	if(strcmp(m, "is") == 0){
        printf("%s:\n",a.negara );
		insertion(n1, a, k1);
        tampilNegara(n1, a, k1);
        printf("%s:\n",b.negara);
		insertion(n2, b, k2);
        tampilNegara(n2, b, k2);
        printf("%s:\n",c.negara);
		insertion(n3, c, k3);
        tampilNegara(n3, c, k3);
	}else if(strcmp(m, "ss") == 0){
        printf("%s:\n",a.negara );
		selection(n1, a, k1);
        tampilNegara(n1, a, k1);
        printf("%s:\n",b.negara);
		selection(n2, b, k2);
        tampilNegara(n2, b, k2);
        printf("%s:\n",c.negara);
		selection(n3, c, k3);
        tampilNegara(n3, c, k3);
    }else if(strcmp(m, "bs") == 0){
        printf("%s:\n",a.negara );
		bubbleSOrt(n1, a, k1);
        tampilNegara(n1, a, k1);
        printf("%s:\n",b.negara);
		bubbleSOrt(n2, b, k2);
        tampilNegara(n2, b, k2);
		bubbleSOrt(n3, c, k3);
        printf("%s:\n",c.negara);
        tampilNegara(n3, c, k3);
    }else{
       printf("%s:\n",a.negara );
		quickSort(n1, a, 0, n1-1, k1);
        tampilNegara(n1, a, k1);
		quickSort(n2, b, 0, n2-1, k2);
        printf("%s:\n",b.negara);
        tampilNegara(n2, b, k2);
		quickSort(n3, c, 0, n3-1, k3);
        printf("%s:\n",c.negara);
        tampilNegara(n3, c, k3);
    }
	

    tampung(n1, a);

	gabung(n1, k1, n2, k2, a,b,hasil1, hasilK1);

    for(i=0; i<n1+n2; i++){
        strcpy(hasil1.makanan[i], hasilMak[i]);
        strcpy(hasil1.hasilN1[i], hasilNeg[i]);
        hasil1.kalori[i] = hasilKal[i];
        hasil1.berat[i] = hasilBer[i];
        hasil1.harga[i] = hasilHar[i];
    }



	gabung(n1+n2+n3, hasilK1, n3, k3, hasil1, c, hasil2, hasilK2);
    printf("\nSemua:\n");
    tampil(n1+n2+n3, hasilK2); 
    return 0;
}
