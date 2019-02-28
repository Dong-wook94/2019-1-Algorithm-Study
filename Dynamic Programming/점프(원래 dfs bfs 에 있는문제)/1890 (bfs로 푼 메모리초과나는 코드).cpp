#include <stdio.h>
#include <queue>

using namespace std;

typedef struct location {
	int row;
	int col;
}location;


queue<location> q;
int N;//���� ���� ũ��
int map[100][100] = { -1, };//�迭 ���� -1�� �ʱ�ȭ
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

		if (cur.row + jump < N) {//���η� ���������Ҷ�
			next.row = cur.row + jump;
			next.col = cur.col;
			q.push(next);
		}
		if (cur.col + jump < N) {//���η� ���� �����Ҷ�
			next.row = cur.row;
			next.col = cur.col + jump;
			q.push(next);
		}
	}
}