#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int **map;
vector<int> cnt_group;
void DFS(int a, int b);
int direction_col[4] = { 1,0,-1,0 };
int direction_row[4] = { 0,1,0,-1 };
int cnt=0, num = 1;
int main() {
	int i,j,row,col;
	char input;
	scanf("%d", &N);
	
	map = (int**)malloc(sizeof(int*)*N);

	for (i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int)*N);
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%c", &input);
			if (input<'0' || input>'1') {
				j--;
				continue;
			}
			map[i][j] = input - '0';
			
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			if (map[i][j] == 1) {//0은 집x 1은 방문안한집 방문한집은 단지마다 차례로 2이상의수 부여
				num++;
				cnt = 0;
				DFS(i,j);//1부터말고 2부터 시작하기위해
				
				cnt_group.push_back(cnt);
				
			}
		}
	}
	sort(cnt_group.begin(), cnt_group.end());
	printf("%d\n", cnt_group.size());
	for (i = 0; i < cnt_group.size(); i++) {
		printf("%d\n", cnt_group[i]);
	}

}

void DFS(int row,int col) {
	int i;
	int next_row, next_col;
	cnt++;
	map[row][col] = num;//2이상의수로 바꾸며 번지구분
	
	for (i = 0; i < 4; i++) {
		next_row = row + direction_row[i];
		next_col = col + direction_col[i];

		if (next_row >= 0 && next_col >= 0 && next_row < N && next_col < N&&map[next_row][next_col]==1) {
			//cnt++;
			//map[next_row][next_col] = num;//2이상의수로 바꾸며 번지구분
			DFS(next_row, next_col);
		}
	}
	
}