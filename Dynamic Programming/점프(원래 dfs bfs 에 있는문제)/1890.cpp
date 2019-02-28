#include <stdio.h>

int N;//게임 판의 크기
int map[100][100];//배열 전부 -1로 초기화
long long dp[100][100];
void DP();
int main() {
	int i,j,jump;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	DP();
	printf("%lld\n", dp[N-1][N-1]);

	return 0;
}

void DP() {
	int i,j,jump;
	dp[0][0] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				continue;
			}
			jump = map[i][j];

			if (i + jump < N) {//i+jump 는 내려가는경우 가능할때체크
				dp[i + jump][j] += dp[i][j];
			}
			if (j + jump < N) {//j+jump는 오른쪽으로 가는 경우 가능할때체크
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
}