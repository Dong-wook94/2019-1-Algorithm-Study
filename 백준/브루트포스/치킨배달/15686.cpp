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
int N, M;//N : 라인수 , M : 치킨집 최대개수

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
			if (input == 1) {//집
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
void combination() {//조합구하기 비트마스크같은 느낌으로 조합을 구하였다.
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
		result = min(result, chicken_distance());//조합중에서도 최소거리를 찾기위함.

		comb_chicken.clear();//초기화해줘야됨.
	} while (next_permutation(Select.begin(), Select.end()));

}

int chicken_distance() {//조합으로 구한 치킨배열과 집사이의 최소거리를 구한다. 
	int sum = 0;
	int distance,temp;
	for (int i = 0; i < house.size(); i++) {//house와 치킨집 다비교
		distance = INT_MAX;
		for (int j = 0; j < comb_chicken.size(); j++) {
			temp = abs(house[i].row - comb_chicken[j].row) + abs(house[i].col - comb_chicken[j].col);
			distance = min(distance, temp);
		}
		sum += distance;
	}
	return sum;
}