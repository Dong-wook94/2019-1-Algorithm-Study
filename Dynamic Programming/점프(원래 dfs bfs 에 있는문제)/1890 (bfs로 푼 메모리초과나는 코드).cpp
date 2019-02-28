#include <stdio.h>
#include <queue>

using namespace std;

typedef struct location {
	int row;
	int col;
}location;


queue<location> q;
int N;//게임 판의 크기
int map[100][100] = { -1, };//배열 전부 -1로 초기화
int cnt = 0;
void bfs();
int main() {
	int i, j;
	location start;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	start.row = 0;
	start.col = 0;
	q.push(start);
	bfs();
	printf("%d\n", cnt);
}

void bfs() {
	location next, cur;
	int i, jump;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		jump = map[cur.row][cur.col];

		if (cur.row == N - 1 && cur.col == N - 1) {
			cnt++;
			continue;
		}
		if (jump == 0) {
			continue;
		}

		if (cur.row + jump < N) {//가로로 점프가능할때
			next.row = cur.row + jump;
			next.col = cur.col;
			q.push(next);
		}
		if (cur.col + jump < N) {//세로로 점프 가능할때
			next.row = cur.row;
			next.col = cur.col + jump;
			q.push(next);
		}
	}
}