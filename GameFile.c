#include <stdio.h>
#include <stdlib.h>

char cellTest (char *board, int w, int h, int x, int y);

void conwayStep (char *board, int w, int h);
int returnCell(char *board, int w, int h, int x, int y);

char cellTest (char *board, int w, int h, int x, int y) {
	int adjacent = 0;
	int i,j;
	for(j = 0; j < h; j++){
		for(i = 0; i < w; i++){

			if((abs(j-y) == 1 && (abs(i-x) <= 1)) || (abs(i-x) == 1 && abs(j-y) <= 1 )){
				int alive = returnCell(board, w, h, i, j);
				if(alive){
					adjacent+= 1;
				}
			}
		}
	}

	if(returnCell(board, w, h, x ,y)){
		
		if(adjacent < 2){
			return 0;
		}
		else if(adjacent > 3){

			return 0;
		}
		else if(adjacent == 2 || adjacent == 3){
			return 1;
		}
	}else{
		if(adjacent == 3){
			return 1;
		}
		else{
			return 0;

		}
	}

	
}
int returnCell(char *board, int w, int h, int x, int y){
	
	int j;
	for (j = 0; j < h; j++) {
		int i;
		for (i = 0; i < w; i++) {
			
			if (*(board + j*w + i) == '1') {
				if(i == x && y == j){
					return 1;
				}
			} else if (*(board + j*w + i) == '0') {
				if(i == x && y == j){
					return 0;
				}
			}		
		}
	}
	return 0;
}


void conwayStep (char *board, int w, int h){
	char *tempboard;
	tempboard = (char*)malloc(h*w*sizeof(char));
	int j, i;
	for (j = 0; j < h; j++) {
		for (i = 0; i < w; i++) {
			if (cellTest(board, w, h, i, j)){
				*(tempboard + j*w + i) = '1';
			} else {
				*(tempboard + j*w + i) = '0';
			}	
		
		}

	}
	int k;
	for(k = 0; k<w*h; k++){
		*(board+k) = *(tempboard + k);
	}

}


void printConway (char *board, int w, int h) {
	int j;
	for (j = 0; j < h; j++) {
		if (j == 0) {
			printf(" ");
			int i;
			for (i = 0; i < w; i++) {
				printf("%1d",i);
			}
		}
		
		printf("\n%1d",j);
		int i;
		for (i = 0; i < w; i++) {
			if (*(board + j*w + i) == '1') {
				printf("█");
			} else if (*(board + j*w + i) == '0') {
				printf(" ");
			}	
		
		}

	}
	printf("\n\n");
}

int main () {
	char *board;  
	
	FILE *f1 = fopen("gameinput.txt", "r");
	int size_w;
	int size_h;
	fscanf(f1, "%d\n", &size_w);
	fscanf(f1, "%d\n", &size_h);
	
	printf("w = %d\n", size_w);
	printf("h = %d\n", size_h);
	
	board = (char*)malloc(size_h*size_w*sizeof(char));
	if (board == NULL) {
		printf("Runtime Error: Not Enough Memory!\n");
	}
	fread(board, sizeof(char), size_w*size_h, f1);
	//printf("%s ", board);
	printConway(board, size_w, size_h);

	int q;
	for (q = 0; q < 26; q++) {
		printf(">><<>><<>><<>><<>><<\n");
		conwayStep(board, size_w, size_h);
		printf("After conway step %d:\n", q);
		printConway(board, size_w, size_h);
	}
	
		
	free(board);
	fclose(f1);
}
