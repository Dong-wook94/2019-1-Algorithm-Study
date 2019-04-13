#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct Pos {
	int row;
	int col;
	Pos(int r, int c) {
		row = r;
		col = c;
	}
}Pos;
vector<Pos> top;//봉우리

int T;
int N, K;//N은 지도 한변 길이, K는 최대 공사가능 깊이
int map[8][8];
int visited[8][8];
int dir_row[4] = {0,1,0,-1};
int dir_col[4] = { 1,0,-1,0 };
int max_height = 1;
int max_length = 0;
void dfs(int row, int col, int chance, int length, int height);
int main() {
	
	scanf("%d", &T);
	for (int t = 1; t <=T; t++) {
		max_height = 1;
		max_length = 0;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (max_height < map[i][j]) {
					max_height = map[i][j];
					top.clear();
					top.push_back(Pos(i,j));
				}
				else if (map[i][j] == max_height) {
					top.push_back(Pos(i, j));
				}
			}
		}
		for (int i = 0; i < top.size(); i++) {
			visited[top[i].row][top[i].col] = 1;
			dfs(top[i].row, top[i].col, 1, 1, max_height);
			visited[top[i].row][top[i].col] = 0;
		}
		printf("#%d %d\n", t,max_length);
		top.clear();
	}	
	
	
}

void dfs(int row,int col,int chance, int length,int height) {
	int next_row, next_col;

	if (max_length < length)
		max_length = length;
	for (int i = 0; i < 4; i++) {
		next_row = row + dir_row[i];
		next_col = col + dir_col[i];
		if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= N)
			continue;
		if (visited[next_row][next_col] == 0) {
			if (height > map[next_row][next_col]) {
				visited[next_row][next_col] = 1;
				dfs(next_row, next_col, chance, length + 1, map[next_row][next_col]);
				visited[next_row][next_col] = 0;
			}
			else if (height + K > map[next_row][next_col] && chance == 1) {
				int temp;
				visited[next_row][next_col] = 1;
				temp = map[next_row][next_col];
				map[next_row][next_col] = height - 1;
				dfs(next_row, next_col, 0, length + 1, map[next_row][next_col]);
				map[next_row][next_col] = temp;
				visited[next_row][next_col] = 0;
			}
			
		}
	}
	
}