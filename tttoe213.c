#include <stdio.h>
#include <string.h>

int papan[3][3];

int cek(){
	int i,j;
	int count[10];
	int kembali = 0;

	for(i=0; i<10; i++){
		count[i] = 0;
	}

	for(i=0; i<3; i++){

		for(j=0; j<4; j++){
			count[j] = 0;
		}

		kembali = 0;

		for(j=0; j<3;j++){
			if(papan[i][j] == 1){	
				count[0]++;
			} 

			if(papan[j][i] == 1){		
				count[1]++;
			} 

			if(papan[j][i] == 2){	
				count[2]++;
			} 

			if(papan[i][j] == 2){	
				count[3]++;
			} 

			if(papan[i][i] == 1 && kembali != 1){
				kembali = 1;
				count[4]++;
	
			} 

			if(papan[i][2-i] == 1 && kembali != 1){	
				kembali = 1;
				count[5]++;
			} 

			if(papan[i][i] == 2 && kembali != 1){	
				kembali = 1;	
				count[6]++;
			} 

			if(papan[i][2-i] == 2 && kembali != 1){	
				kembali = 1;
				count[7]++;
			}
		}
		
		for(j=0; j<4; j++){
			if(j <2){
				if(count[j] == 3){
					return 1;
				}
			}else{
				if(count[j] == 3){
					return 2;
				}
			}
		}
	}

	for(i=4; i<8; i++){
		if(i < 6){
			if(count[i] == 3){
				return 1;
			}
		}else{
			if(count[i] == 3){
				return 2;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	char pemain[5][100];
	char tanda1[5];
	char nama[100];
	char tanda;
	int r,c;

	int i,j;

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			papan[i][j] = 0;
		}
	}

	for(i=0; i<6; i++){
		scanf("%s", &nama);
		scanf(" %c", &tanda);
		scanf("%d %d", &r,&c);

		if(i == 0){
			strcpy(pemain[0], nama);
			tanda1[0] = tanda;
			papan[r][c] = 1;
		}

		if(tanda1[0] != tanda && i != 0){
			strcpy(pemain[1], nama);
			tanda1[1] = tanda;
			papan[r][c] = 2;
		}else if(i != 0){
			papan[r][c] = 1;
		}
	}

	if(cek() == 1){
		printf("%s\n",pemain[1] );
	}else if(cek() == 2){
		printf("%s\n",pemain[0] );
	}else{
		printf("%s\n",pemain[0] );
		printf("%s\n",pemain[1] );
	}
	return 0;
}