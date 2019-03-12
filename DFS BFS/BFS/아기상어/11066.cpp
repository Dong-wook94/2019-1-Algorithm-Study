#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[501][501];
int sum[501];
int T;//테스트 데이터 수
int K;//소설을 구성하는 장의수 

void Test();

int main() {
	int i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		Test();
	}
}

void Test() {
	int i, input, j;

	scanf("%d", &K);

	for (i = 1; i <= K; i++) {
		scanf("%d", &input);
		sum[i] = sum[i - 1] + input;
	}
	for (i = 1; i < K; i++) {//차이
		for (j = 1; j + i <= K; j++) {

			dp[j][j + i] = INT_MAX;
			for (int m = j; m < j + i; m++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][m] + dp[m + 1][j + i] + sum[j + i] - sum[j - 1]);
			}
		}
	}

	printf("%d\n", dp[1][K]);
}