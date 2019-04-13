#include <stdio.h>
#include<stdlib.h>
#include <queue>
#define MAX_SIZE 21
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
using namespace std;


int N;
int Map[MAX_SIZE][MAX_SIZE];
void slide_map();
void copy_map(int(*arr)[MAX_SIZE], int(*arr2)[MAX_SIZE]);
void slide_map(int d);
void DFS(int cnt);
int Max_block;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]);
		}
	}
	DFS(0);
	printf("%d\n", Max_block);

	
}
void DFS(int cnt) {
	int temp[MAX_SIZE][MAX_SIZE];
	//5�� �̵������� �ִ밪 ����
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Max_block < Map[i][j])
					Max_block = Map[i][j];
			}
		}
		return;
	}
	
	copy_map(temp, Map);
	
	for (int i = 0; i < 4; i++) {
		slide_map(i);
		DFS(cnt + 1);
		//�ٽ� ���󺹱�
		copy_map(Map, temp);
	}

}
void copy_map(int(*arr)[MAX_SIZE], int(*arr2)[MAX_SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}
void slide_map(int d) {
	queue<int> q;
	int next_row, next_col;
	int index;
	int data;

	switch (d) {
	case UP://��
		for (int i = 0; i < N; i++) {//col�� ������
			for (int j = 0; j < N; j++) {//row�� ������
				if (Map[j][i] != 0) {
					q.push(Map[j][i]);
				}
				Map[j][i] = 0;
			}
			index = 0;

			while (!q.empty()) {
				data = q.front();
				q.pop();

				if (Map[index][i] == 0)
					Map[index][i] = data;
				else if (Map[index][i] == data) {//�����Ͱ��ִµ� ���� ���Ƽ� ���ľߵǴ� ���
					Map[index][i] *= 2;
					index++;//�̰ɷ� ������ �������°� ����
				}
				else {//�����Ͱ� �ִµ� ���� �ٸ����
					index++;
					Map[index][i] = data;
				}
			}
		}
		break;
	case LEFT:
		for (int i = 0; i < N; i++) {//row�� ������
			for (int j = 0; j < N; j++) {//col�� ������
				if (Map[i][j] != 0) {
					q.push(Map[i][j]);
				}
				Map[i][j] = 0;
			}
			index = 0;

			while (!q.empty()) {
				data = q.front();
				q.pop();

				if (Map[i][index] == 0)
					Map[i][index] = data;
				else if (Map[i][index] == data) {//�����Ͱ��ִµ� ���� ���Ƽ� ���ľߵǴ� ���
					Map[i][index] *= 2;
					index++;//�̰ɷ� ������ �������°� ����
				}
				else {//�����Ͱ� �ִµ� ���� �ٸ����
					index++;
					Map[i][index] = data;
				}
			}
		}
		break;
	case RIGHT://����
		for (int i = 0; i < N; i++) {//row�� ������
			for (int j = N-1; j>=0; j--) {//col�� ������
				if (Map[i][j] != 0) {
					q.push(Map[i][j]);
				}
				Map[i][j] = 0;
			}
			index = N-1;

			while (!q.empty()) {
				data = q.front();
				q.pop();

				if (Map[i][index] == 0)
					Map[i][index] = data;
				else if (Map[i][index] == data) {//�����Ͱ��ִµ� ���� ���Ƽ� ���ľߵǴ� ���
					Map[i][index] *= 2;
					index--;//�̰ɷ� ������ �������°� ����
				}
				else {//�����Ͱ� �ִµ� ���� �ٸ����
					index--;
					Map[i][index] = data;
				}
			}
		}
		break;
	case DOWN:
		for (int i = 0; i < N; i++) {//col�� ������
			for (int j = N-1; j>= 0; j--) {//row�� ������
				if (Map[j][i] != 0) {
					q.push(Map[j][i]);
				}
				Map[j][i] = 0;
			}
			index = N-1;

			while (!q.empty()) {
				data = q.front();
				q.pop();

				if (Map[index][i] == 0)
					Map[index][i] = data;
				else if (Map[index][i] == data) {//�����Ͱ��ִµ� ���� ���Ƽ� ���ľߵǴ� ���
					Map[index][i] *= 2;
					index--;//�̰ɷ� ������ �������°� ����
				}
				else {//�����Ͱ� �ִµ� ���� �ٸ����
					index--;
					Map[index][i] = data;
				}
			}
		}
		break;
	default :
		printf("error\n");
		exit(0);
		break;

	}

}
