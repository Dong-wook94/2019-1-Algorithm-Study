#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;
int Map[20][20];//MAP
int visited[20][20];
int N;//������ ũ��

typedef struct Fish {
	int row;
	int col;
	int size;
	int time;
}Fish;
typedef struct Shark {
	int row;
	int col;
	int size;
	int eat_num;
	int time;
}Shark;
Shark shark;
queue<Shark> q;

int direction_col[4] = { 1,0,-1,0 };
int direction_row[4] = { 0,1,0,-1 };
void bfs();
vector<Fish> visit;
bool cmp_time(const Fish &fish1, const Fish &fish2);
bool cmp_row(const Fish &fish1, const Fish &fish2);
bool cmp_col(const Fish &fish1, const Fish &fish2);
int seconds;
int main() {
	int input;

	scanf("%d", &N);//N�Է¹���
	seconds = 0;
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			scanf("%d", &input);
			Map[i][j] = input;
			if (input == 9) {
				shark.row = i;
				shark.col = j;
				shark.size = 2;
				shark.eat_num = 0;
				shark.time = 0;
				Map[i][j] = 0;
				q.push(shark);//�ʱ� shark�� ���� ����
			}
		}
	}
	bfs();
	while(visit.size()) {
		if (visit.size() > 1) {//radix sort ������ ó��
			stable_sort(visit.begin(), visit.end(), cmp_col);
			stable_sort(visit.begin(), visit.end(), cmp_row);
			stable_sort(visit.begin(), visit.end(), cmp_time);
		}
		shark.row = visit[0].row;
		shark.col = visit[0].col;
		shark.time = visit[0].time;
		shark.eat_num++;
		if (shark.eat_num >= shark.size) {
			shark.size++;
			shark.eat_num = 0;
		}
		//printf("row:%d col:%d size:%d eat:%d ����time:%d\n", shark.row, shark.col, shark.size,shark.eat_num,shark.time);
		visit.clear();
		Map[shark.row][shark.col] = 0;
		q.push(shark);
		bfs();
	}
	printf("%d\n", shark.time);
}
void bfs() {
	Shark x, temp;
	Fish info;
	int min_time=INT_MAX;
	for (int i = 0; i < N; i++) {//visited�Լ� 0���� �ʱ�ȭ
		memset(visited[i], 0, sizeof(int)*N);
	}
	while (!q.empty()) {
		x = q.front();
		q.pop();
		visited[x.row][x.col] = 1;//�湮
		if (!visit.empty() && x.time > min_time)
			continue;
		for (int i = 0; i < 4; i++) {
			temp.row = x.row + direction_row[i];
			temp.col = x.col + direction_col[i];
			temp.time = x.time;
			if (temp.row >= 0 && temp.col >= 0 && temp.row < N && temp.col < N &&visited[temp.row][temp.col]==0) {
				temp.eat_num = x.eat_num;
				temp.size = x.size;
				
				if (Map[temp.row][temp.col] == 0) {//������
					temp.time++;
					visited[temp.row][temp.col] = 1;
					q.push(temp);
				}
				else if (Map[temp.row][temp.col] < x.size) {//������
					
					temp.time++;
					info.row = temp.row;
					info.col = temp.col;
					info.time = temp.time;
					info.size = Map[temp.row][temp.col];
					visit.push_back(info);
					visited[temp.row][temp.col] = 1;
					if (min_time < info.time)
						min_time = info.time;
					q.push(temp);
				}
				else if (Map[temp.row][temp.col] == x.size) {//������
					temp.time++;
					visited[temp.row][temp.col] = 1;
					q.push(temp);
				}
				else if (Map[temp.row][temp.col] > x.size) {//Ŭ��
					visited[temp.row][temp.col] = 1;
				}
			}
		}
	}
}

bool cmp_time(const Fish &fish1, const Fish &fish2) {
	return fish1.time < fish2.time;
}
bool cmp_row(const Fish &fish1, const Fish &fish2) {
	return fish1.row < fish2.row;
}
bool cmp_col(const Fish &fish1, const Fish &fish2) {
	return fish1.col < fish2.col;
}