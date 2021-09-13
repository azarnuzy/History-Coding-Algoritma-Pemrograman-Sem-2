#include <stdio.h>

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

int main(){
    int data[] = {64, 34, 25, 12, 22, 90, 11};
    int n = 7;
    // Print data awal
    printData(data, n);
    // Panggil prosedur BubbleSort
    bubbleSort(data, n);
    // Print data akhir (setelah disorting)
    printData(data, n);

    return 0;
}