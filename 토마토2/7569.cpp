#include <stdio.h>
#include <stdlib.h>
#include <queue>
typedef struct Tomato {
	int row;
	int col;
	int height;
	int date;
}Tomato;

using namespace std;

int M, N,H ;//M은 상자 가로칸수, N은 세로칸수, H는 높이
int ***box;
queue<Tomato> q;
queue<Tomato> check;
void mem_alloc();
void bfs_tomato();
int check_ripe();
int direction_col[6] = { 1,0,-1,0,0,0 };
int direction_row[6] = { 0,1,0,-1,0,0 };
int direction_height[6] = { 0,0,0,0,1,-1 };
int max_date = 0;
int main() {
	int i, j,k;
	scanf("%d %d %d", &M, &N, &H);
	Tomato t;

	mem_alloc();
	for (k = 0; k < H; k++) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < M; i++) {
				scanf("%d", &box[i][j][k]);
				t.row = i;
				t.col = j;
				t.height = k;
				t.date = 0;
				if (box[i][j][k] == 1) {
					q.push(t);
				}
				else if (box[i][j][k] == -1) {
					check.push(t);
				}
			}
		}
	}
	bfs_tomato();
	i = check_ripe();
	if (i == 1)
		printf("%d\n", max_date);
	else
		printf("-1\n");
}

void mem_alloc() {//3차원 배열 동적할당
	int i,j;

	box = (int***)malloc(sizeof(int**)*M);
	for (i = 0; i < M; i++) {
		box[i] = (int**)malloc(sizeof(int*)*N);
		for (j = 0; j < N; j++) {
			box[i][j] = (int*)malloc(sizeof(int)*H);
		}
	}


}

void bfs_tomato() {//bfs 이용
	Tomato x, t;
	int next_row, next_col, next_height,i;

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (i = 0; i < 6; i++) {
			next_row = x.row + direction_row[i];
			next_col = x.col + direction_col[i];
			next_height = x.height + direction_height[i];
			if (next_row >= 0 && next_col >= 0 &&next_height>=0 && next_row<M && next_col<N && next_height<H && box[next_row][next_col][next_height] == 0) {
				t.row = next_row;
				t.col = next_col;
				t.height = next_height;
				t.date = x.date + 1;
				box[next_row][next_col][next_height] = 1;
				if (max_date < t.date) {
					max_date = t.date;
				}
				q.push(t);
			}

		}
	}
}
int check_ripe() {
	Tomato x;
	int next_row, next_col,next_height, i;

	while (!check.empty()) {
		x = check.front();
		check.pop();
		for (i = 0; i < 6; i++) {
			next_row = x.row + direction_row[i];
			next_col = x.col + direction_col[i];
			next_height = x.height + direction_height[i];
			if (next_row >= 0 && next_col >= 0 && next_height>=0 && next_row<M && next_col<N && next_height<H && box[next_row][next_col][next_height] == 0) {
				return -1;
			}

		}
	}
	return 1;
}
