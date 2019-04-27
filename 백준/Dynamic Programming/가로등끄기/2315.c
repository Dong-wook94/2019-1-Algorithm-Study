#include <stdio.h>
#include <stdlib.h>
#define INFI 1000000000

typedef struct InfoArr {
	long int EE;
	int PP;
}InfoArr;
typedef struct InfoLight{
	int D;
	int W;
}InfoLight;
int N, M;//N�� ���ε�� M�� ��¡�� ó���� ��ġ�ϴ� ���ε��ȣ.
InfoLight *light;
InfoArr **left;
InfoArr **right;
int *WS;

void input_data();
int calMinEnergy();
void memory_allocation();
int Min(int a, int b, int L, int R, int dir);

int main() {
	input_data();
	printf("%d\n", calMinEnergy());
}

void input_data() {
	scanf("%d %d", &N, &M);
	memory_allocation();
	for (int i = 1; i <=N; i++) {
		scanf("%d %d", &light[i].D, &light[i].W);
	}
	WS[1] = light[1].W;
	for (int i = 2; i <=N; i++) {
		WS[i] = WS[i - 1] + light[i].W;
	}
}
void memory_allocation() {
	WS = (int*)malloc(sizeof(int)*(N + 1));
	light = (InfoLight*)malloc(sizeof(InfoLight)*(N + 1));
	left = (InfoArr **)malloc(sizeof(InfoArr*)*(N + 1));
	right = (InfoArr **)malloc(sizeof(InfoArr*)*(N + 1));
	for (int i = 1; i <= N; i++) {
		left[i] = (InfoArr*)malloc(sizeof(InfoArr)*(N + 1));
		right[i] = (InfoArr*)malloc(sizeof(InfoArr)*(N + 1));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//EE�� min���� ���ؾ� �ϹǷ� �ʱⰪ max������ 
			if (i == M && j == M) {//�ʱ���ġ�� ���� 0
				left[i][j].EE = 0;
				right[i][j].EE = 0;
			}
			else {
				left[i][j].EE = INFI;
				right[i][j].EE = INFI;
			}
			
			//�������迭 �ʱ�ȭ
			left[i][j].PP = 0;
			right[i][j].PP = 0;
		}
	}
}

int Min(int a, int b,int L,int R,int dir) {//a�� ������ a b�� ������ b����
	if (dir == 0) {//��
		if (a <= b) {
			left[L][R].PP = L + 1;
			return a;
		}
		else {
			left[L][R].PP = R;
			return b;
		}
	}
	else {//��
		if (a <= b) {
			right[L][R].PP = L;
			return a;
		}
		else {
			left[L][R].PP = R-1;
			return b;
		}
	}
}

int calMinEnergy() {
	int L, R;
	int choice;
	for (int diagonal = 1; diagonal < N; diagonal++) {
		for (L = 1; L <= N - diagonal; L++) {
			R = L + diagonal;
			left[L][R].EE = Min(left[L + 1][R].EE + (light[L + 1].D - light[L].D)*(WS[N] - (WS[R] - WS[L])), right[L + 1][R].EE + (light[R].D - light[L].D)*(WS[N] - (WS[R] - WS[L])), L, R, 0);
			right[L][R].EE = Min(left[L][R - 1].EE + (light[R].D - light[L].D)*(WS[N] - (WS[R - 1] - WS[L - 1])), right[L][R - 1].EE + (light[R].D - light[R - 1].D)*(WS[N] - (WS[R - 1] - WS[L - 1])), L, R, 1);
		}
	}
	return (left[1][N].EE <= right[1][N].EE) ? left[1][N].EE : right[1][N].EE;
}

