#include <stdio.h>
#include <stdlib.h>

int *dp;
int *wine;
int max(int a, int b);
int main() {
	int num,i;
	scanf("%d", &num);

	dp = (int*)calloc(num + 1, sizeof(int));
	wine = (int*)calloc(num + 1, sizeof(int));

	for (i = 1; i <= num; i++) {
		scanf("%d", &wine[i]);
		if (i == 1) {
			dp[1] = wine[1];
		}
		else if(i==2){
			dp[2] = dp[1] + wine[2];
		}
		else if (i == 3) {
			dp[3] = max(dp[2],max(wine[1] + wine[3], wine[2] + wine[3]));
		}
		else {
			dp[i] = max(dp[i-1],max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]) );
		}
	}
	printf("%d\n", dp[num]);
	free(dp);
	free(wine);
}
int max(int a, int b) {
	return a > b ? a : b;
}