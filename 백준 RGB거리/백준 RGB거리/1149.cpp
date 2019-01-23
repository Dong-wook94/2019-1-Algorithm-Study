#include <stdio.h>
#include <stdlib.h>
#define MAX 1000 
typedef struct RGB {
	int color[3];
}RGB;

RGB *house;
int Min(int a, int b);
int min;
int main() {
	int house_num;
	int i,j,r,g,b;
	int min;
	scanf("%d", &house_num);


	house = (RGB*)malloc(sizeof(RGB)*house_num);
	scanf("%d %d %d", &r, &g, &b);
	house[0].color[0] = r;
	house[0].color[1] = g;
	house[0].color[2] = b;
	for (i = 1; i < house_num; i++) {
		scanf("%d %d %d", &r, &g, &b);
		house[i].color[0] = Min(house[i-1].color[1],house[i-1].color[2])+r;
		house[i].color[1] = Min(house[i - 1].color[0], house[i - 1].color[2])+g;
		house[i].color[2] = Min(house[i - 1].color[0], house[i - 1].color[1])+b;
		
	}
	
	min = Min(Min(house[i-1].color[0],house[i-1].color[1]),house[i-1].color[2]);
	printf("%d", min);

}

int Min(int a,int b) {
	return a > b ? b : a;
}