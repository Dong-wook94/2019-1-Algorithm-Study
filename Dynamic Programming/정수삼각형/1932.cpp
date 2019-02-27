#include <stdio.h>
#include <stdlib.h>
int **triangle;
int max(int a, int b);

int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;    // 오름차순
}

int main() {
	int size;
	
	int i,j;
	int Max;
	scanf("%d", &size);
	triangle = (int**)calloc(1,sizeof(int*)*size+1);
	triangle[0] = (int*)calloc(3, sizeof(int));
	for (i = 1; i <=size; i++) {
		triangle[i] = (int*)calloc(1,sizeof(int)*(i+2));//인덱스가 0인것과 그보다 큰값일때 0으로 초기화해주기위해
	}
	for (i = 1; i <=size; i++) {
		triangle[i][0] = 0;
		for (j = 1; j <=i; j++) {
			scanf("%d", &triangle[i][j]);
		}
		for (j = 1; j <= i; j++) {
			triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
		}
		triangle[i][j] = 0;
	}
	qsort(triangle[size], size+1, sizeof(int), compare);

	printf("%d", triangle[size][0]);//마지막값중 가장 큰값
	
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}