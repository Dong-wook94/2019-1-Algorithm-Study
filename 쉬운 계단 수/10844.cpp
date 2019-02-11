#include <stdio.h>
#include <stdlib.h>

int **dp;

void memory_alloc(int n);
void init_first_step();
int cal_step(int n);
int main() {
	int n,i;

	scanf("%d", &n);
	memory_alloc(n);
	
	printf("%d",cal_step(n));
	
}

void memory_alloc(int n) {
	int i;
	dp = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++) {
		dp[i] = (int*)calloc(10, sizeof(int));
	}
}
int cal_step(int n) {
	int i,j;
	int total=0;
	init_first_step();

	for (i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1]%1000000000;
		for (j = 1; j < 9; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] = dp[i][j] % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}
	for (i = 0; i < 10; i++) {
		total = (total+ dp[n - 1][i]) % 1000000000;
	}
	total = total % 1000000000;
	return total;
}
void init_first_step() {
	int i;

	for (i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
}