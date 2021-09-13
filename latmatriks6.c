#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wait(float x){
	//this is the procedure for making delay
	time_t start;//start time
	time_t current;//current time
	time(&start);//making the start time

	do{
		time(&current);
	}while(difftime(current, start) < x);
}

int main(int argc, char const *argv[])
{
	char arr[6][6];

	int i,j, x=-1, y=-1, jalan=1;

	for(i=0; i<6; i++){
		for(j=0; j<6; j++){
			arr[i][j] = '-';
		}
	}

	while(1){
		system("cls");

		if(x >= 0 && y == 6){
			//bottom border as the mark of going up
			jalan = -1;
			x = x - 1;
			y = y - 1;
		}else if(x == - 1 && y == -1){
			//upper border as the mark of going up
			x += 1;
			jalan = 1;
			y += 1;
		}else if(jalan == 1){
			//if the direction is still going down
			x += 1;
			y += 1;
		}else{
			//if the direction is still going up
			x -= 1;
			y -= 1;
		}

		//fill the cell with B
		if(x >= 0 && x < 6){
			arr[x][y] = 'B';
		}

		//draw to the screen 
		for(i=0; i<6; i++){
			for(j=0; j<6; j++){
				if(arr[i][j] == '-'){
					printf("   ");
				}else{
					printf(" %c ",arr[i][j] );
				}
			}
			printf("\n");
		}

		//the delay procedure for 1 second
		wait(1);
	}
	return 0;
}