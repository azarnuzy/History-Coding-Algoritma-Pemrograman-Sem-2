#include <stdio.h>

void gabungTidakTerurut(int n, int arr1[], int m, int arr2[], int arr3[]){
	int i,j=0;

	for(i=0; i<n; i++){
		arr3[j] = arr1[i];
		j++;
	}


	for(i=0; i<m; i++){
		arr3[j] = arr2[i];
		j++;
	}

	for(i=0; i<n+m; i++){
		printf("%d ",arr3[i] );
	}
}

void tampil(int n, int arr3[]){
	int i;
	for(i=0; i<n; i++){
		printf("%d ",arr3[i] );
	}
}

void gabungTerurut(int n, int arr1[], int m, int arr2[], int arr3[]){
	int i=0, j=0, k=0, l=0;

	while(i < n && j < m){
		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			i++;
			k++;
		}else if(arr2[j] < arr1[i]){
			arr3[k] = arr2[j];
			j++;
			k++;
		}else{
			arr3[k] = arr1[i];
			i++;
			k++;

			arr3[k] = arr2[j];
			j++;
			k++;
		}
	}

	if(i < n){
		for(l=i; l<n; l++){
			arr3[k] = arr1[l];
			k++;
		}
	}

	if(j < m){
		for(l = j; l < m; l++){
			arr3[k] = arr2[l];
			k++;
		}
	}
}

void qsPinggir(int arr[], int kiri, int kanan){
    int i, j, temp;
    i = kiri;
    j = kanan;

    do{
        while((arr[i] < arr[kanan]) && (i <= j)){
            i++;
        }
        while((arr[j] > arr[kiri]) && (i <= j)){
            j--;
        }

        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            i++;
            j--;
        }

    }while(i < j);

    if(kiri < j){
        qsPinggir(arr, kiri, j);
    }
    if(i < kanan){
        qsPinggir(arr, i, kanan);
    }
}

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d", &n, &m);

	int arr1[n], arr2[n];

	int i,j;

	for(i=0; i<n; i++){
		scanf("%d", &arr1[i]);
	}

	for(i=0; i<m; i++){
		scanf("%d", &arr2[i]);
	}

	int arr3[n+m];

	/*gabungTidakTerurut(n, arr1, m, arr2, arr3);*/
	qsPinggir(arr1, 0, n-1);
	qsPinggir(arr2, 0, m-1);
	gabungTerurut(n, arr1,m,arr2,arr3);
	tampil(n+m,arr3);
	return 0;
}