#include <stdio.h>

typedef struct Pos {
	int row;
	int col;
}Pos;
typedef struct Dice {
	int up;
	int down;
	int left;
	int right;
	int front;
	int back;
	Pos pos;
}Dice;

Dice dice;
int N, M, x, y, K;
int Map[20][20];
int inst;
int dir_row[4] = {0,0,-1,1};
int dir_col[4] = {1,-1,0,0};
void move_Dice(int dir);
int main() {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	dice.pos.row = x;
	dice.pos.col = y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
			
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &inst);//µ¿ 1 ¼­ 2 ºÏ 3 ³² 4
		move_Dice(inst-1);
	}
	
}

void move_Dice(int dir) {
	int next_row, next_col,temp;
	next_row = dice.pos.row + dir_row[dir];
	next_col = dice.pos.col + dir_col[dir];

	if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M)
		return;
	dice.pos.row = next_row;
	dice.pos.col = next_col;
	switch (dir) {
	case 0://µ¿
		temp = dice.down;
		dice.down = dice.right;
		dice.right = dice.up;
		dice.up = dice.left;
		dice.left = temp;
		break;
	case 1://¼­
		temp = dice.down;
		dice.down = dice.left;
		dice.left = dice.up;
		dice.up = dice.right;
		dice.right = temp;
		break;
	case 2://ºÏ
		temp = dice.down;
		dice.down = dice.back;
		dice.back = dice.up;
		dice.up = dice.front;
		dice.front = temp;
		break;
	case 3://³²
		temp = dice.down;
		dice.down = dice.front;
		dice.front = dice.up;
		dice.up = dice.back;
		dice.back = temp;
		break;
	}
	if (Map[dice.pos.row][dice.pos.col] == 0)
		Map[dice.pos.row][dice.pos.col] = dice.down;
	else {
		dice.down = Map[dice.pos.row][dice.pos.col];
		Map[dice.pos.row][dice.pos.col] = 0;
	}
	printf("(%d,%d)  up:%d down: %d left:%d right:%d front:%d back:%d \n", dice.pos.row,dice.pos.col,dice.up,dice.down,dice.left,dice.right,dice.front,dice.back);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", Map[i][j]);
		}
		printf("\n");
	}
}