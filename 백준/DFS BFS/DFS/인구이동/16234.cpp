#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct Pos {
	int row;
	int col;
}Pos;

vector<Pos> Union;

int N, L, R;//N은 줄수, L 과 R은 범위
int A[50][50];
int visited[50][50];
int direction_row[4] = { 1,0,-1,0 };
int direction_col[4] = { 0,1,0,-1 };
void DFS(int row, int col);
int main() {
	Pos p;
	int sum = 0;
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int cnt = 0;
	int prev_A[50][50];
	while (1) {//이전연합수와 같으면 탈출
		for(int i=0;i<N;i++)
			memcpy(prev_A[i], A[i], sizeof(int)*N);
		for (int i = 0; i < N; i++)
			memset(visited[i], 0, sizeof(int)*N);//visited 0으로 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]==0) {
					p.row = i;
					p.col = j;
					Union.push_back(p);
					visited[i][j] = 1;
					DFS(i, j);
					sum = 0;
					for (int k = 0; k < Union.size(); k++) {//연합 총합 구하기
						sum += A[Union[k].row][Union[k].col];
					}
					sum = sum / Union.size();
					for (int k = 0; k < Union.size(); k++) {//연합에 평균 분배
						A[Union[k].row][Union[k].col] = sum;
					}
					Union.clear();
				}
			}
		}
		//printf("\ncnt : %d\n", cnt);
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (prev_A[i][j] != A[i][j]){
					flag = 1;
				}
			}
		}
		if (flag == 0) {
			printf("%d", cnt);
			return 0;
		}
		else {
			cnt++;
		}
	}

}
void DFS(int row, int col) {
	int gap;
	Pos next;
	for (int i = 0; i < 4; i++) {
		next.row = row + direction_row[i];
		next.col = col + direction_col[i];
		if (next.row >= 0 && next.col >= 0 && next.row < N&&next.col < N && visited[next.row][next.col]==0) {
			gap = abs(A[row][col] - A[next.row][next.col]);
			if (gap >= L && gap <= R) {
				Union.push_back(next);
				visited[next.row][next.col] = 1;
				DFS(next.row, next.col);
			}
		}
	}
}