#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
typedef struct Schedule {
	int term;
	int pay;
}Schedule;

Schedule *schedule;
int *dp;
int N;//줄수
int Max=0;
int main() {
	scanf("%d", &N);
	schedule = (Schedule*)malloc(sizeof(Schedule)*(N+1));
	dp = (int*)calloc(N+1, sizeof(int));
	for (int i = 1; i <=N; i++) {
		scanf("%d %d", &schedule[i].term, &schedule[i].pay);
		if (i + schedule[i].term> N+1) {//예외 이때는 이용못함 이때상담은 총상담일을 지나버림
			schedule[i].pay = 0;
		}
	}
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (i - j >= schedule[j].term) {
				dp[i] = max(schedule[i].pay + dp[j], dp[i]);
				if (Max < dp[i])
					Max = dp[i];
			}
		}
		printf("dp[%d] = %d\n", i, dp[i]);
	}
	printf("%d\n",Max);
	
}