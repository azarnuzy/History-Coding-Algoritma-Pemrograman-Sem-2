#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void qsPinggir(int data[], int kiri, int kanan){
    int i, j, temp;
    i = kiri;
    j = kanan;

    do{
        while((data[i] < data[kanan]) && (i <= j)){
            i++;
        }
        while((data[j] > data[kiri]) && (i <= j)){
            j--;
        }

        if(i < j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            
            i++;
            j--;
        }

    }while(i < j);

    if(kiri < j){
        qsPinggir(data, kiri, j);
    }
    if(i < kanan){
        qsPinggir(data, i, kanan);
    }
}

void qsTengah(int data[], int kiri, int kanan){
    int i, j, temp;
    i=kiri;
    j=kanan;
    int pivot = data[(kanan+kiri)/2];//pivot adalah setengah dari panjang data
    
    do{
        while((data[i] < pivot) && (i <= j)){
            i++;
        }
        while((data[j] > pivot) && (i <= j)){
            j--;
        }

        if(i < j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            
            i++;
            j--;
        }
    }while(i < j);

    if((kiri < j) && (j < kanan)){
        qsTengah(data, kiri, j);
    }
    if((i < kanan) && (i > kiri)){
        qsTengah(data, i, kanan);
    }
}

void bubbleSort(int data[], int n){
    int i, temp, swap;

    // Perulangan sampai seluruh data tidak ada yang ditukar
    do{
        swap = 0; // Penanda pertukaran data
        // Cek semua data
        for(i = 0; i < n-1; i++){
            // Jika data ke i lebih besar daripada data ke i+1
            if(data[i] > data[i+1]){
                // Tukar data
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                // Tandai ada data yang ditukar
                swap = 1;
            }
        }
    }while(swap == 1);
}

void printData(int data[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(i != n-1) printf("%d ", data[i]);
        else printf("%d\n", data[i]);
    }
}

void randomArr(int data[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        data[i] = rand() % 99;   
    }
}

int main(){
    // int data[] = {64, 34, 25, 12, 22, 90, 11};
    int n = 9;
    int data[n];

    // Isi array dengan random number
    randomArr(data, n);

    // Print data awal
    printData(data, n);
    
    // Panggil prosedur qSort
    qsTengah(data, 0, n-1);
    // Print data akhir (setelah disorting)
    printData(data, n);
 
    return 0;
}