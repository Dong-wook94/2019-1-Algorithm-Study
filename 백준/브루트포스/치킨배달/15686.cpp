#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

typedef struct Pos {
	int row;
	int col;
}Pos;

using namespace std;
int N, M;//N : ���μ� , M : ġŲ�� �ִ밳��

vector<Pos> house;
vector<Pos> chicken;
vector<int> Select;
vector<Pos> comb_chicken;
int result=INT_MAX;
int chicken_distance();
void combination();
int main() {
	Pos temp;
	int input;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input);
			temp.row = i;
			temp.col = j;
			if (input == 1) {//��
				house.push_back(temp);
			}
			else if (input == 2) {//chicken
				chicken.push_back(temp);
			}
		}	
	}
	combination();
	printf("%d\n", result);
}
void combination() {//���ձ��ϱ� ��Ʈ����ũ���� �������� ������ ���Ͽ���.
	for (int i = 0; i < M; i++)
		Select.push_back(1);
	for (int i = 0; i < (chicken.size() - M); i++)
		Select.push_back(0);
	sort(Select.begin(), Select.end());

	do {
		for (int i = 0; i < Select.size(); i++) {
			if (Select[i] == 1) {
				comb_chicken.push_back(chicken[i]);
			}
		}
		result = min(result, chicken_distance());//�����߿����� �ּҰŸ��� ã������.

		comb_chicken.clear();//�ʱ�ȭ����ߵ�.
	} while (next_permutation(Select.begin(), Select.end()));

}

int chicken_distance() {//�������� ���� ġŲ�迭�� �������� �ּҰŸ��� ���Ѵ�. 
	int sum = 0;
	int distance,temp;
	for (int i = 0; i < house.size(); i++) {//house�� ġŲ�� �ٺ�
		distance = INT_MAX;
		for (int j = 0; j < comb_chicken.size(); j++) {
			temp = abs(house[i].row - comb_chicken[j].row) + abs(house[i].col - comb_chicken[j].col);
			distance = min(distance, temp);
		}
		sum += distance;
	}
	return sum;
}