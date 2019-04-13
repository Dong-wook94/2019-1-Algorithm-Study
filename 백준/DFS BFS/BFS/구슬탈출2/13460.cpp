#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;
                 
typedef struct Pos {
	int row;
	int col;
}Pos;
typedef struct State {
	Pos R;
	Pos B;
	int cnt;
	int visit[10][10][10][10] = { 0 };
}State;

State Cur;
Pos Hole;
queue<State> q;

int N, M;//N :�ళ�� M:������
//# : �� , . :��ĭ , O : ���� , R : ��������, B : �Ķ�����
//�迭�� �Է½�(1:���� -1 : �� 0 : ��ĭ
int board[10][10];

int direction_col[4] = { 1,-1,0,0 };
int direction_row[4] = { 0,0,1,-1 };
int min_cnt=11;
void BFS();
int main() {
	int flag;
	char input;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &input);
			switch (input)
			{
			case 'R'://������
				board[i][j] = 0;
				Cur.R.row = i;
				Cur.R.col = j;
				break;
			case 'B'://�Ķ���
				board[i][j] = 0;
				Cur.B.row = i;
				Cur.B.col = j;
				break;
			case 'O'://����
				board[i][j] = 1;
				Hole.row = i;
				Hole.col = j;
				break;
			case '.'://��ĭ
				board[i][j] = 0;
				break;
			case '#'://��
				board[i][j] = -1;
				break;
			default://�����Է�
				j--;
				break;
			}

		}
	}
	Cur.cnt = 0;//ī��Ʈ �ʱ�ȭ
	q.push(Cur);//���ۻ��� ť�� ����
	BFS();//BFS�̿�
	if (min_cnt>10)
		printf("-1\n");
	else
		printf("%d\n", min_cnt);
}

void BFS() {
	State x, temp;
	int flag;
	
	while (!q.empty()) {
		x = q.front();
		q.pop();
		temp.cnt = x.cnt + 1;
	
		
		if (temp.cnt > 10)
			return;

		for (int i = 0; i < 4; i++) {//4�������� ��￴������
			flag = 0;
			//������ ������ ����
			for (int n = 0; ; n++) {//n�� �󸶳� �̵��ϴ� ĭ�� 
				temp.R.row = x.R.row + direction_row[i] * n;
				temp.R.col = x.R.col + direction_col[i] * n;
				if (temp.R.row >= 0 &&temp.R.col >= 0 && temp.R.row < N&&temp.R.col < M)
				{
					if (board[temp.R.row][temp.R.col]==-1) {
						temp.R.row = x.R.row + direction_row[i] * (n - 1);
						temp.R.col = x.R.col + direction_col[i] * (n - 1);
						break;//����������
					}
					if (temp.R.row ==x.B.row &&temp.R.col==x.B.col)//�������� ���ٰ� �Ķ����� �������
					{
						flag = 1;
						//�����ϴٰ� �Ķ��� ��������
						//�Ķ�������������
						break;
					}
					if (board[temp.R.row][temp.R.col] == 1) {//��ǥ���� �� �Ķ���ó��
						for (int n = 0; ; n++) {//n�� �󸶳� �̵��ϴ� ĭ�� 
							temp.B.row = x.B.row + direction_row[i] * n;
							temp.B.col = x.B.col + direction_col[i] * n;
							if (temp.B.row >= 0 && temp.B.col >= 0 && temp.B.row < N&&temp.B.col < M)
							{
								
								if (board[temp.B.row][temp.B.col] == 1) {//�Ķ����� ���°��
									flag = 3;
									break;
								}
								if (board[temp.B.row][temp.B.col] == -1) {
									printf("��ǥ���� : %d\n", temp.cnt);
									if (min_cnt > temp.cnt)
										min_cnt = temp.cnt;
									break;
								}
							}
							else break;
						}
					}
				}
				else break;
				if (flag == 3) {
					break;
				}
			}
			//�Ķ��� ���� 
			if (flag == 3)
				continue;
			if (flag == 0) {//�������� ���ٰ� �Ķ����� ������ �������
				for (int n = 0; ; n++) {//n�� �󸶳� �̵��ϴ� ĭ�� 
					temp.B.row = x.B.row + direction_row[i] * n;
					temp.B.col = x.B.col + direction_col[i] * n;
					if (temp.B.row >= 0 && temp.B.col >= 0 && temp.B.row < N&&temp.B.col < M)
					{
						if (board[temp.B.row][temp.B.col] == -1|| (temp.R.row == temp.B.row &&temp.R.col == temp.B.col)) {
							temp.B.row = x.B.row + direction_row[i] * (n - 1);
							temp.B.col = x.B.col + direction_col[i] * (n - 1);
							if (x.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col]!=1) {//�湮���ߴ����϶�
								temp.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col] = 1;
								temp.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col] = 1;
								printf("\n�湮 : R(%d,%d),B(%d,%d) cnt : %d\n", temp.R.row, temp.R.col, temp.B.row, temp.B.col,temp.cnt);

								q.push(temp);
							}
							break;//����������
						}
						if (board[temp.B.row][temp.B.col] == 1) {//�Ķ����� ���°��
							break;
						}
					}
					else break;
				}
			}
			else{//�������� ���ٰ� �Ķ����� ������� �Ķ����� �������°��
				for (int n = 0; ; n++) {//n�� �󸶳� �̵��ϴ� ĭ�� 
					temp.B.row = x.B.row + direction_row[i] * n;
					temp.B.col = x.B.col + direction_col[i] * n;
					if (temp.B.row >= 0 && temp.B.col >= 0 && temp.B.row < N&&temp.B.col < M)
					{
						if (board[temp.B.row][temp.B.col] == -1) {
							temp.B.row = x.B.row + direction_row[i] * (n - 1);
							temp.B.col = x.B.col + direction_col[i] * (n - 1);
							break;//����������
						}
						if (board[temp.B.row][temp.B.col] == 1) {//�Ķ����� ��ǥ�� �������°�� ����ó��
							flag = 2;
							break;
						}
					}
					else break;
				}
				if (flag != 2) {//�Ķ����� ���� �������� �������
					for (int n = 0; ; n++) {//n�� �󸶳� �̵��ϴ� ĭ�� 
						temp.R.row = x.R.row + direction_row[i] * n;
						temp.R.col = x.R.col + direction_col[i] * n;
						if (temp.R.row >= 0 && temp.R.col >= 0 && temp.R.row < N&&temp.R.col < M)
						{
							if ((temp.R.row == temp.B.row &&temp.R.col == temp.B.col) || board[temp.R.row][temp.R.col]==-1) {
								temp.R.row = x.R.row + direction_row[i] * (n - 1);
								temp.R.col = x.R.col + direction_col[i] * (n - 1);
								if (x.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col]!=1) {//�湮���ߴ����϶�
									temp.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col] = 1;
									temp.visit[temp.R.row][temp.R.col][temp.B.row][temp.B.col] = 1;
									printf("\n�湮 : R(%d,%d),B(%d,%d) cnt : %d\n", temp.R.row, temp.R.col, temp.B.row, temp.B.col,temp.cnt);
									q.push(temp);
								}
								break;//�Ķ�����������
							}
						}
						else break;
					}
				}
				
			}
		}
	}
}
