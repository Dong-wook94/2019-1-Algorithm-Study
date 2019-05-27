#include <stdio.h>
#include <vector>
#define MAX_SIZE 13
typedef struct Core {
	int row;
	int col;
	Core(int r, int c) {
		row = r;
		col = c;
	}
}Core;


using namespace std;
int N;
int map[MAX_SIZE][MAX_SIZE];

void Testcase();
int dir_row[4] = { 0,1,0,-1 };
int dir_col[4] = { 1,0,-1,0 };
vector<Core> core;
void dfs(int cnt, int wire_num,int disable);
int min_wire = 169;
int min_disable = 12;
int make_wire(Core core, int dir);
void MapCopy(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE]);
int count_wire();

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		scanf("%d", &N);
		min_wire = 169;
		min_disable = 12;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1 && i != 0 && j != 0 && j != N - 1 && i != N - 1) {
					core.push_back(Core(i, j));
				}

			}
		}
		dfs(0, 0,0);
		core.clear();
		printf("#%d %d\n", t + 1, min_wire);
	}
}


void dfs(int cnt, int wire_num,int disable) {
	int temp[MAX_SIZE][MAX_SIZE];
	int num;
	int wire_count;
	int flag;
	if (cnt >= core.size()) {
		wire_count = count_wire();
		/*if (min_wire > wire_count&&min_disable>disable) {
			min_wire = wire_count;
			min_disable = disable;
		}*/
		if (min_disable > disable) {
			min_wire = wire_count;
			min_disable = disable;
		}
		else if (min_disable == disable && min_wire > wire_count) {
			min_wire = wire_count;
		}
		return;
	}

	MapCopy(temp, map);
	flag = 1;
	for (int i = 0; i < 4; i++) {
		num = make_wire(core[cnt], i);
		if (num != -1) {
			flag = 0;
			num += wire_num;
			dfs(cnt + 1, num,disable);
		}
		MapCopy(map, temp);
	}
	if (flag == 1) {
		dfs(cnt + 1, wire_num,disable+1);
		MapCopy(map, temp);
	}

}
void MapCopy(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}
int make_wire(Core c, int dir) {
	int next_row = c.row;
	int next_col = c.col;
	int cnt = 0;
	next_row += dir_row[dir];
	next_col += dir_col[dir];

	for (; next_row >= 0 && next_row < N&&next_col >= 0 && next_col < N;) {

		if (map[next_row][next_col] == 0) {
			map[next_row][next_col] = 2;
			cnt++;
		}
		else if (map[next_row][next_col] == 1) {
			cnt = -1;
			break;
		}
		else {
			cnt = -1;
			break;
		}
			

		next_row += dir_row[dir];
		next_col += dir_col[dir];
	}
	//print_map();
	//printf("추가된거:%d\n", cnt);
	return cnt;
}
int count_wire() {
	int cnt = 0;
	//printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//printf("%d ", map[i][j]);
			if (map[i][j] == 2)
				cnt++;
		}
		//printf("\n");
	}
	//printf("cnt : %d \n",cnt);
	return cnt;
}
