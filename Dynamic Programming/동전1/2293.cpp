#include <stdio.h>

int N, K;//N은 동전의 종류수, K는 총가치의합
int dp[10001];
//int coin[100];
int main() {
	int i,j,coin;
	scanf("%d %d", &N, &K);
	dp[0] = 1;
	for (j = 0; j < N; j++) {
		scanf("%d", &coin);
		for (i = 1; i <= K; i++) {
			if (i -coin >= 0)
				dp[i] += dp[i - coin];
		}
		
	}
	printf("%d\n", dp[K]);
}
