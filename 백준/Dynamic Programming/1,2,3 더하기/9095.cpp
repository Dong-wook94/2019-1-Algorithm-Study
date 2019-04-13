#include <stdio.h>

int T;
int dp[11];
int main() {
	int input;
	scanf("%d",&T);
	dp[0] = 1;
	for (int i = 1; i < 11; i++) {
		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
	}
	for (int i=0; i < T; i++) {
		scanf("%d", &input);
		printf("%d\n", dp[input]);
	}

}