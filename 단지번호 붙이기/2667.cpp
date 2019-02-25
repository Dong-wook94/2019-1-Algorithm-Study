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
			if (map[i][j] == 1) {//0�� ��x 1�� �湮������ �湮������ �������� ���ʷ� 2�̻��Ǽ� �ο�
				num++;
				cnt = 0;
				DFS(i,j);//1���͸��� 2���� �����ϱ�����
				
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
	map[row][col] = num;//2�̻��Ǽ��� �ٲٸ� ��������
	
	for (i = 0; i < 4; i++) {
		next_row = row + direction_row[i];
		next_col = col + direction_col[i];

		if (next_row >= 0 && next_col >= 0 && next_row < N && next_col < N&&map[next_row][next_col]==1) {
			//cnt++;
			//map[next_row][next_col] = num;//2�̻��Ǽ��� �ٲٸ� ��������
			DFS(next_row, next_col);
		}
	}
	
}