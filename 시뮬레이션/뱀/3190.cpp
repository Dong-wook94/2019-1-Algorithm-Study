#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;
typedef struct Snake {
	int row;
	int col;
	Snake(int r, int c) {
		row = r;
		col = c;
	}
}Snake;

queue<Snake> snake;
int N;//����ũ��
int K;//�������
int n_turn;
int Map[101][101];
int dir=0;
int dir_row[4] = {0,1,0,-1};
int dir_col[4] = {1,0,-1,0};
int total_sec=0;
void MoveSnake(int second);
int main() {
	int row, col, sec;
	char turn;
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &row, &col);
		Map[row][col] = 2;//�����  2
	}
	snake.push(Snake(1, 1));
	Map[1][1] = 1;
	scanf("%d", &n_turn);
	for (int i = 0; i <n_turn; i++) {
		scanf("%d %c", &sec, &turn);
		switch (turn) {
		case 'L':
			MoveSnake(sec-total_sec);
			dir = (dir + 3) % 4;
			break;
		case 'D':
			MoveSnake(sec-total_sec);
			dir = (dir + 1) % 4;
			break;
		}
	}
	MoveSnake(100000);
}
void MoveSnake(int second) {
	int next_row, next_col;
	for (int i = 0; i < second; i++) {
		total_sec++;
		next_row = snake.back().row + dir_row[dir];
		next_col = snake.back().col + dir_col[dir];
		snake.push(Snake(next_row,next_col));
		if (next_row<1 || next_col<1 || next_row>N || next_col>N) {
			printf("%d", total_sec);
			exit(0);
		}
		else if(Map[next_row][next_col] == 2) {
			Map[next_row][next_col] = 1;
		}
		else if (Map[next_row][next_col] == 1) {
			printf("%d", total_sec);
			exit(0);
		}
		else if (Map[next_row][next_col] == 0) {
			Map[next_row][next_col] = 1;
			Map[snake.front().row][snake.front().col] = 0;
			snake.pop();
		}
		//�� ����غ���
		/*printf("\nsec :%d\n",total_sec);
		for (int k = 1; k <=N; k++) {
			for (int j = 1; j <=N; j++) {
				printf("%d ", Map[k][j]);
			}
			printf("\n");
		}*/
	}
}
