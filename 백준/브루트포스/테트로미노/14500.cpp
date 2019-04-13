#include <stdio.h>

int N, M;
int map[500][500];
int visited[500][500];
int dir_row[4] = { 1,0,-1,0 };
int dir_col[4] = { 0,1,0,1 };
int sum = 0;
int max_sum=0;
void dfs(int row, int col, int block_cnt, int sum);
void exception_shape();
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum = 0;
			visited[i][j] = 1;
			dfs(i, j, 0,map[i][j]);
		}
	}

	exception_shape();
	printf("%d\n", max_sum);

}

void dfs(int row, int col,int block_cnt,int sum) {
	int next_row;
	int next_col;
	//visited[row][col] = 1;
	if (block_cnt == 3) {
		if (max_sum < sum)
			max_sum = sum;
		return;
	}
	visited[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		next_row = row + dir_row[i];
		next_col = col + dir_col[i];
		if (next_row >= 0 && next_col >= 0 && next_row < N&&next_col < M&&visited[next_row][next_col]==0) {
			//visited[next_row][next_col] = 1;
			dfs(next_row, next_col, block_cnt + 1, sum + map[next_row][next_col]);
			//visited[next_row][next_col]=0;
		}
		
	}
	visited[row][col] = 0;
}
void exception_shape() {//¤Ç¸ð¾ç
	//¤¿
	for (int i = 0; i < N - 2; i++) {

		for (int j = 0; j < M - 1; j++) {
			sum = 0;
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			sum += map[i + 1][j + 1];
			if (max_sum < sum) {
				max_sum = sum;
			}
			sum = 0;
			sum += map[i + 1][j];
			sum += map[i][j + 1];
			sum += map[i + 1][j + 1];
			sum += map[i + 2][j + 1];
			if (max_sum < sum) {
				max_sum = sum;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {

		for (int j = 0; j < M - 2; j++) {
			sum = 0;
			sum += map[i][j + 1];
			sum += map[i + 1][j];
			sum += map[i + 1][j + 1];
			sum += map[i + 1][j + 2];
			if (max_sum < sum) {
				max_sum = sum;
			}
			sum = 0;
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i][j + 2];
			sum += map[i + 1][j + 1];
			if (max_sum < sum) {
				max_sum = sum;
			}
		}
	}
}
		