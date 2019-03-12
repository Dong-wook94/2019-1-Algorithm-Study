#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Location {
	int row;
	int col;
	int cnt;
}Location;

queue<Location> q;
void bfs(int row, int col);
int direction_col[4] = { 1,0,-1,0 };
int direction_row[4] = { 0,1,0,-1 };
int N, M;
int **map;
int min_cnt = 99999;
int main() {
	int i, j;
	char input;

	scanf("%d %d", &N, &M);
	map = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int)*M);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%c", &input);
			if (input<'0' || input>'1') {
				j--;
				continue;
			}
			map[i][j] = input - '0';
		}
	}
	bfs(0, 0);
	printf("%d\n", min_cnt);
	for (i = 0; i < N; i++) {
		free(map[i]);
	}
	free(map);
}
void bfs(int row, int col) {
	Location x, n;
	int i, next_row, next_col;
	map[row][col] = -1;
	if (row == N - 1 && col == M - 1)
		return;
	x.row = row;
	x.col = col;
	x.cnt = 1;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x.row == N - 1 && x.col == M - 1) {
			if (min_cnt > x.cnt)//도착점에 오는 방법중 가장 작은방법 갱신
				min_cnt = x.cnt;
			continue;
		}
		for (i = 0; i < 4; i++) {//4방향 탐색
			next_row = x.row + direction_row[i];
			next_col = x.col + direction_col[i];
			if (next_row >= 0 && next_col >= 0 && next_row < N && next_col < M && map[next_row][next_col] == 1) {//길인지 확인
				n.row = next_row;
				n.col = next_col;
				n.cnt = x.cnt + 1;
				map[next_row][next_col] = -1;

				q.push(n);
			}
		}
	}
}
