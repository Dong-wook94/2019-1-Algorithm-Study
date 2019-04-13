#include <stdio.h>

int N;//���� ���� ũ��
int map[100][100];//�迭 ���� -1�� �ʱ�ȭ
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

			if (i + jump < N) {//i+jump �� �������°�� �����Ҷ�üũ
				dp[i + jump][j] += dp[i][j];
			}
			if (j + jump < N) {//j+jump�� ���������� ���� ��� �����Ҷ�üũ
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
}