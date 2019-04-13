#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct Pos {
	int row;
	int col;
}Pos;

queue<Pos> q;
vector<Pos> s;//�����Ѱ���
vector<Pos> v;//���̷���
int direction_col[4] = { 1,0,-1,0 };
int direction_row[4] = { 0,1,0,-1 };

void bfs();
void copyMap();
void buildWall();
void queue_init();
int safe_cnt;//���ϴ¼�
int max_cnt=0;
int Map[8][8];//���� Map
void print_map();
int tempMap[8][8];//�����ﶧ���� ���ϴ� Map
int visited[8][8];//�湮Ȯ��
int N, M;//N�� ����ũ��, M�� ����ũ��
int main() {
	Pos temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 0) {
				temp.row = i;
				temp.col = j;
				s.push_back(temp);
			}
			else if (Map[i][j] == 2) {
				temp.row = i;
				temp.col = j;
				v.push_back(temp);
			}
		}
	}


	buildWall();
	printf("%d\n", max_cnt);
}
void buildWall() {
	for (int i = 0; i < s.size(); i++) {//����� �������
		for (int j = i+1; j < s.size(); j++) {
			for (int k = j + 1; k < s.size(); k++) {
				copyMap();
				tempMap[s[i].row][s[i].col] = 1;
				tempMap[s[j].row][s[j].col] = 1;
				tempMap[s[k].row][s[k].col] = 1;
				safe_cnt = s.size()-3;
				queue_init();
				bfs();
				if (max_cnt <safe_cnt) {
					max_cnt = safe_cnt;
					//print_map();
				}
				//print_map();
			}
		}
	}
}
void queue_init() {
	while (!q.empty()) {//q�ʱ�ȭ
		q.pop();
	}
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}
}

void bfs() {//���̷��� �۶߸���
	Pos x, next;
	for (int i = 0; i < N; i++) {//visited �ʱ�ȭ
		memset(visited[i], 0, sizeof(int)*M);
	}
	while (!q.empty()) {
		x = q.front();
		q.pop();
		//printf("(%d,%d)\n", x.row, x.col);
		for (int i = 0; i < 4; i++) {
			next.row = x.row + direction_row[i];
			next.col = x.col + direction_col[i];

			if (next.row >= 0 && next.col >= 0 && next.row<N&&next.col<M&&visited[next.row][next.col]==0){
				if (tempMap[next.row][next.col] == 0) {
					tempMap[next.row][next.col] = 2;
					visited[next.row][next.col] = 1;
					safe_cnt--;
					//printf("\n(%d,%d) %d", next.row, next.col, safe_cnt);
					//print_map();
					q.push(next);
				}
			}
		}
	}
	
}

void copyMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tempMap[i][j] = Map[i][j];
		}
	}
}

void print_map() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", tempMap[i][j]);
		}
		printf("\n");
	}
	printf("safe : %d\n", safe_cnt);
}