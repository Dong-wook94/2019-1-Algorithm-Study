#include <stdio.h>
#include <stdlib.h>

int ladder[31][11];
int N, H, M;//N 세로선 개수, M 가로선 개수, H가로선 놓을수 있는 위치의 개수
int correct_check();
void dfs(int row_start, int end_time, int cur_time);
int main() {
	int a, b;
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		ladder[a][b]=1;
	}
	for (int i = 0; i <=3; i++) {
		dfs(1,i, 0);
	}
	printf("-1\n");
}
void dfs(int row_start,int end_time,int cur_time) {
	int next_row;
	int next_col;
	if (cur_time == end_time) {
		if (correct_check()) {
			printf("%d\n", cur_time);//최소값 갱신필요없이
			exit(0);
		}
		return; //dfs 종료
	}
	for (int next_row = row_start; next_row <=H; next_row++) {
		for (int next_col = 1; next_col < N; next_col++) {
			if (ladder[next_row][next_col - 1] == 0 && ladder[next_row][next_col] == 0 && ladder[next_row][next_col + 1]==0) {
				ladder[next_row][next_col] = 1;
				dfs(next_row,end_time, cur_time + 1);
				ladder[next_row][next_col] = 0;
			}
		}
	}

}

int correct_check() {
	int cur;
	for (int i = 1; i <= N; i++) {
		cur = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][cur] == 1)
				cur++;
			else if (ladder[j][cur - 1] == 1)
				cur--;
		}
		if (cur != i)
			return 0;
	}
	return 1;
}
