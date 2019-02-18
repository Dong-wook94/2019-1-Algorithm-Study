#include <stdio.h>
#include <queue>
typedef struct Tomato {
	int row;
	int col;
	int date;
}Tomato;

using namespace std;

int M, N;//M은 상자 가로칸수, N은 세로칸수
int **box;
queue<Tomato> q;
queue<Tomato> check;
void mem_alloc();
void bfs_tomato();
int check_ripe();
int direction_col[4] = { 1,0,-1,0 };
int direction_row[4] = { 0,1,0,-1 };
int max_date=0;
int main() {
	int i,j;
	scanf("%d %d", &M, &N);
	Tomato t;

	mem_alloc();
	for (j = 0; j < N; j++) {
		for (i = 0; i < M; i++) {
			scanf("%d", &box[j][i]);
			t.row = j;
			t.col = i;
			t.date = 0;
			if (box[j][i] == 1) {
				q.push(t);
			}
			else if (box[j][i] == -1) {
				check.push(t);
			}
		}
	}
	bfs_tomato();
	i=check_ripe();
	if (i == 1)
		printf("%d\n", max_date);
	else
		printf("-1\n");
}

void mem_alloc() {
	int i, j;

	box = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++) {
		box[i] = (int*)malloc(sizeof(int)*M);
	}


}

void bfs_tomato() {//bfs 이용
	Tomato x,t;
	int next_row,next_col,i;
	
	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (i = 0; i < 4; i++) {
			next_row = x.row + direction_row[i];
			next_col = x.col + direction_col[i];
			if (next_row >= 0 && next_col >= 0 && next_row<N && next_col<M && box[next_row][next_col] == 0 ) {
				t.row = next_row;
				t.col = next_col;
				t.date = x.date + 1;
				box[next_row][next_col] = 1;
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
	int next_row, next_col, i;

	while (!check.empty()) {
		x = check.front();
		check.pop();
		for (i = 0; i < 4; i++) {
			next_row = x.row + direction_row[i];
			next_col = x.col + direction_col[i];
			if (next_row >= 0 && next_col >= 0 && next_row<N && next_col<M && box[next_row][next_col] == 0) {
				return -1;
			}

		}
	}
	return 1;
}
