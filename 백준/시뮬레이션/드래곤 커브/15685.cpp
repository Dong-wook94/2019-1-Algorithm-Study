#include <stdio.h>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

vector<int> dir_order;
stack<int> s;

int N;//드래곤 커브개수
int generation;
int dir_row[4] = {0,-1,0,1};
int dir_col[4] = {1,0,-1,0};
int Map[101][101];
int cnt = 0;
void make_dir_order();
void MakeDragonCurve(int start_x, int start_y);
void find_square();
int main() {
	int start_x, start_y, dir;//여기서 g는 총 세대
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &start_x, &start_y, &dir, &generation);
		dir_order.push_back(dir);
		make_dir_order();
		MakeDragonCurve(start_x,start_y);
		dir_order.clear();
	}
	find_square();
}
void MakeDragonCurve(int start_x,int start_y) {//g는 총 세대
	int next_x = start_x;
	int next_y = start_y;

	Map[next_y][next_x] = 1;
	for (int i = 0; i < dir_order.size(); i++) {
		next_x = next_x + dir_col[dir_order[i]];
		next_y = next_y + dir_row[dir_order[i]];
		
		Map[next_y][next_x] = 1;
		//printf("(%d %d)\n", next_x, next_y);
	}
}
void find_square() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (Map[j][i] == 1 && Map[j + 1][i]==1 && Map[j][i + 1]==1 && Map[j + 1][i + 1]==1)
				cnt++;
		}
	}
	printf("%d\n", cnt);
}
void make_dir_order() {
	s.push(dir_order[0]);
	for (int i = 0; i <generation; i++) {
		while (!s.empty()) {
			dir_order.push_back((s.top() + 1) % 4);
			s.pop();
		}
		for (int j = 0; j < dir_order.size(); j++)
			s.push(dir_order[j]);
	}
	while (!s.empty())
		s.pop();
	
}