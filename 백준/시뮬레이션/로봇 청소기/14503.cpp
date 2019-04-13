#include <stdio.h>

typedef struct Robot {
	int row;
	int col;
	//0북1동2남3서순
	int direction;
	int cnt=0;
}Robot;
Robot robot;
int direction_row[4] = { -1,0,1,0 };
int direction_col[4] = { 0,1,0,-1 };
int N, M;
int Map[51][51];
int cleaned[51][51];
void cleaning();
int main() {
	//printf("%d",  5% 4);
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot.row, &robot.col, &robot.direction);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cleaned[i][j] = Map[i][j];
		}
	}
	cleaned[robot.row][robot.col] = 2;
	robot.cnt++;
	cleaning();
	printf("%d\n", robot.cnt);
}

void cleaning() {
	int left,back;
	int next_row, next_col;
	/*printf("\ncnt : %d\n", robot.cnt);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", cleaned[i][j]);
		}
		printf("\n");
	}*/
	left = (robot.direction + 3) % 4;//시작했을때 왼쪽 바라보도록
	for (int i = 0; i < 4; i++) {
		
		next_row = robot.row + direction_row[left];
		next_col = robot.col + direction_col[left];
		if (next_row >= 0 && next_col >= 0 && next_row < N&&next_col < M) {
			if (Map[next_row][next_col] == 0 && cleaned[next_row][next_col] == 0) {
				robot.row = next_row;
				robot.col = next_col;
				robot.direction = left;
				cleaned[robot.row][robot.col] = 2;
				robot.cnt++;
				cleaning();
			}
		}
		left = (left + 3) % 4;
	}
	back = (robot.direction + 2) % 4;
	next_row = robot.row + direction_row[back];
	next_col = robot.col + direction_col[back];
	if (next_row >= 0 && next_col >= 0 && next_row < N&&next_col < M&&Map[next_row][next_col] == 0) {
		robot.row = next_row;
		robot.col = next_col;
		cleaning();
	}
}